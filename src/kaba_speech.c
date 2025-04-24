#include "global.h"
#include "main.h"
#include "bg.h"
#include "gpu_regs.h"
#include "sprite.h"
#include "window.h"
#include "decompress.h"
#include "text.h"
#include "constants/characters.h"
#include "string_util.h"
#include "palette.h"
#include "palette_util.h"
#include "malloc.h"
#include "task.h"
#include "menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "strings.h"
#include "trainer_pokemon_sprites.h"
#include "pokeball.h"
#include "naming_screen.h"
#include "overworld.h"
#include "kaba_speech.h"
#include "constants/rgb.h"
#include "constants/songs.h"

/*! @brief
 * This file controls Elder Kaba's speech sequence, made
 * seperately from src/main_menu.c to avoid too big of
 * conflicts and just makes the sequence much cleaner to
 * read.
 *
 * Below is the order of functions that'll run the intro.
 * 
 * DoKabaSpeech
 *      Move the game state into Elder Kaba's Speech.
 * 
 * Task_KabaSpeech_Begin
 *      Basic UI-loading code, so stuff like initializing
 *      registers settings, bgs, windows and sprites goes
 *      here.
 *      There's two functions that do this, but
 *      Task_KabaSpeech_Begin is only for loading
 *      the intro the first time.
 * 
 * Task_KabaSpeech_FadeInEverything
 *      Waits for the palette fading from black
 *      (by Task_KabaSpeech_Begin) to slowly
 *      fades in Kaba's mugshot and the messagebox
 *      Also delays by 30 frames to perfectly
 *      prints sKabaSpeech_Greetings.
 * 
 * Task_KabaSpeech_GreetingsTraveler
 *      Waits for sKabaSpeech_Greetings to be done
 *      printing. When its completely done, it'll
 *      print sKabaSpeech_AndThis and continue to the
 *      next function below.
 * 
 * Task_KabaSpeech_AndThis
 *      Waits for sKabaSpeech_AndThis to be done
 *      printing. When its completely done, it'll
 *      starts the Joltik sequence.
 * 
 * Task_KabaSpeech_ReleaseJoltikFromPokeball
 *      Delay 30 frames before releasing Joltik.
 * 
 * Task_KabaSpeech_JoltikAPokemon
 *      Wait for Joltik's cry finished and delay for
 *      192+ frames. After that, it'll print
 *      sKabaSpeech_JoltikAPokemon and continue on.
 * 
 * Task_KabaSpeech_MainTalk
 *      Waits for sKabaSpeech_JoltikAPokemon to be
 *      done printing. When its completely done,
 *      it'll print sKabaSpeech_MainTalk.
 * 
 * Task_KabaSpeech_ReturnJoltik
 *      Waits for sKabaSpeech_MainTalk to be done
 *      printing, Once its completely done, it'll
 *      begin to do Joltik returning to its
 *      Pokeball's sequence.
 * 
 * Task_KabaSpeech_FadeOutPokeball
 *      Waits for the Joltik returning to its
 *      Pokeball's sequence to be done. Once the
 *      Pokeball sprite has SpriteCallbackDummy as
 *      its sprite callback, begin fading out everything.
 *      (except the background, of course)
 * 
 * Task_KabaSpeech_FadeOutEverything
 *      Waits for sKabaSpeech->fadeFinished to be TRUE.
 *      Once it is TRUE, it'll remove the Joltik and
 *      Pokeball sprites, messagebox and Kaba's mugshot.
 *      It'll also spawn Ao and Aka's mugshots. Everything
 *      currently is faded out at this point aka unseen so
 *      its "safe" to do.
 * 
 * Task_KabaSpeech_FadeInPlayerMugshotChoice
 *      Starts fading in the player gender choice with a
 *      delay of 60 frames. Also sets up delay to 60 frames.
 * 
 * Task_KabaSpeech_SetupPlayerMugshotChoice
 *      Waits for the previous fade to finish with
 *      fadeFinished. Once it is done, it'll first delay
 *      by 60 frames and then prints sKabaSpeech_GenderChoice,
 *      set MUGSHOT_AO as the chosenMugshot and set delay to 30
 *      frames.
 * 
 * Task_KabaSpeech_WaitForPlayerMugshotChoice
 *      Waits for player's input for selecting the gender.
 *      However, it'll first delay by 30 frames prior once.
 *      DPAD_LEFT/RIGHT for selecting between Ao and Aka
 *      (wrapped selection so if you go DPAD_LEFT from Ao,
 *      it'll go to Aka etc), and A_BUTTON to confirm
 *      selection.
 * 
 * Task_KabaSpeech_MoveChosenMugshot
 *      Move and fade away the unchosen mugshot, while also
 *      moving the chosen mugshot to the center of the screen.
 *      After all that cool jazz is done, print
 *      sKabaSpeech_ConfirmChosenGender.
 * 
 * Task_KabaSpeech_SpawnYesNoMenuForPlayerMugshot
 *      Spawns in the Yes/No menu for confirming chosen
 *      gender mugshot, with a delay for 15 frames first.
 *      Also sets sKabaSpeech->playerHasName to FALSE
 *      for "safety".
 * 
 * Task_KabaSpeech_HandleConfirmChosenMugshotInput
 *      Handles the Yes/No menu input. if YES, continue
 *      to naming the player. Otherwise if NO/pressed B,
 *      go back to the choosing gender mugshot sequence.
 * 
 * Task_KabaSpeech_AskForName
 *      Either prints sKabaSpeech_ThisIsChildhoodFriend or
 *      sKabaSpeech_AskPlayerName depending if the player
 *      has already been named or not.
 * 
 * Task_KabaSpeech_MoveMugshotsBack
 *      Similar to Task_KabaSpeech_MoveChosenMugshot, but
 *      it restores back to the original position of the
 *      character's pics for gender selection.
 * 
 * Task_KabaSpeech_WaitBeforeNamingScreen
 *      Waits for the player to press the A/B button. If one
 *      of them pressed, it'll fade the screen to back
 * 
 * Task_KabaSpeech_DoNamingScreen
 *      Waits for the fade to black to be finished to
 *      call the naming screen for either rival or player
 *      depending if the player has a name yet, also sets
 *      a default name for both to avoid having a null name
 *      when the player is not writing anything in the
 *      naming screen. This also destroys the platform
 *      sprites and destroys the entire task.
 * 
 * Task_KabaSpeech_ConfirmChosenName
 *      Returns from the naming screen, print either
 *      sKabaSpeech_SoThisIsRival or sKabaSpeech_SoYourePlayer
 *      depending on who is being named. Also creates the
 *      Yes/No menu again, this time for confirming the
 *      player's name.
 * 
 * Task_KabaSpeech_HandleConfirmNameInput
 *      Handles player's input for confirming the rival/
 *      player's name choice.
 *      If YES, continue to name Rival or finishing both.
 *      Otherwise if NO/B button pressed, do naming
 *      sequence from the start again
 * 
 * Task_KabaSpeech_ConfirmPlayerName
 *      Waits for sKabaSpeech_ConfirmPlayerName to be finished
 *      AND also pressing either the A/B button. If conditions
 *      were met, clear the messagebox and fade out player to
 *      name rival.
 * 
 * Task_KabaSpeech_YourJourneyStartsHere
 *      Delays for 30 frames, and then starts to print
 *      sKabaSpeech_YourJourneyStartsHere.
 * 
 * Task_KabaSpeech_CloseMsgbox
 *      Waits for sKabaSpeech_YourJourneyStartsHere to be
 *      finished AND also pressing either the A/B button. If
 *      conditions were met, clear the messagebox and fade
 *      away.
 * 
 * Task_KabaSpeech_FadeAwayEverything
 *      Waits for 40 frames delay, then fade everything
 *      to black whilst playing SE_EXIT.
 * 
 * Task_KabaSpeech_Cleanup
 *      When the fading is done, waits for 30 frames and
 *      clean up everything and warp to new game to finish
 *      off the intro.
 * 
 * Finally, here is the helper functions.
 * 
 * KabaSpeech_DrawCharacterMugshot (u8 id)
 *      Draws the mugshot of either Kaba, Ao and Aka
 *      depending on the `id` argument.
 *      The way I did them is making them tilemaps.
 * 
 * KabaSpeech_PrintMessageBox (const u8 *str)
 *      Prints a message from `str` to the messagebox's
 *      window (WIN_TEXT) and copy everything to VRAM.
 * 
 * KabaSpeech_CreateMonSprite (void)
 *      Creates a sprite of Joltik and hides it.
 * 
 * KabaSpeech_CreatePlatformSprites (bool32 hide)
 *      Creates a platform consisting of 2 64x32 sprites.
 *      Set `hide` to TRUE to hide these sprites, the reason
 *      is because they can be both visible and invisible.
 * 
 * KabaSpeech_DestroyPlatformSprites (void)
 *      Destroys the platform sprites, and set the spriteIds
 *      to SPRITE_NONE.
 * 
 * KabaSpeech_BeginFade (u8 fadeOut, u8 delay, u8 spriteType)
 *      A basic function taken from FRLG to either fade in or
 *      fade out depending if `fadeOut` is set. It can also
 *      delays for several frames before the fading. `spriteType`
 *      indicates what value to be used for the
 *      REG_OFFSET_BLDCNT register.
 * 
 * KabaSpeech_SetDefaultName
 *      Sets a default name for both Player and Rival.
 *      "Aka" for male, "Ao" for female.
 * 
 * CB2_KabaSpeech_ReturnFromNamingScreen
 *      This basically does what Task_KabaSpeech_Begin did,
 *      but as a callback2 and returns with either Aka/Ao
 *      shown on a platform instead of Kaba.
 * 
 */

// Define, enum, struct definitions

// If you want to edit these sprite pos defines, dont touch the `+ 32`!
// positions for joltik + pokeball
#define MON_POS_X 54 + 32
#define MON_POS_Y 66 + 32
// positions for platform (they're split into two sprites!)
#define PLAT_POS_X 56 + 32
#define PLAT_POS_Y 83 + 16
// this is pos difference for the second platform sprite
#define PLAT_POS_X2 64

// bg pos
#define AKA_MUGSHOT_CENTER_POS 30
#define AO_MUGSHOT_CENTER_POS  29

#define PLAT_SPRITE_ID_COUNT 2

// tSpriteType, for fade in/out
enum SpriteTypes
{
    SPRITE_TYPE_PLATFORM = 0,
    SPRITE_TYPE_POKE_BALL,
    // these arent technically sprites but close nuff :)
    SPRITE_TYPE_MUGSHOT_1,
    SPRITE_TYPE_MUGSHOT_2,
    // similar to above but not quite
    SPRITE_TYPE_PLAYER,
    SPRITE_TYPE_RIVAL,
    SPRITE_TYPE_NONE,
};

enum SpriteTags
{
    TAG_PLATFORM = 0x9000,
};

enum Bgs
{
    // self explanatory
    BG_TEXT = 0,
    // generic names as their usage is both for
    // kaba and player/rival sprites
    BG_MUGSHOT_1,
    BG_MUGSHOT_2,
    // BG_BG feels stupid but this isn't any better either,
    // suggestions welcome (for context this is for the red bg)
    BG_INTRO,
    BG_COUNT,
};

enum WindowIds
{
    WIN_TEXT = 0,
    WIN_COUNT,
};

enum SpeechLoadStates
{
    STATE_RESET = 0,
    STATE_ALLOC,
    STATE_REGS,
    STATE_BGS,
    STATE_BG_GFX,
    STATE_WINDOWS,
    STATE_FINISH,
    STATE_COUNT,
};

enum PicIds
{
    MUGSHOT_AKA = 0,
    MUGSHOT_AO,
    MUGSHOT_KABA,
    MUGSHOT_COUNT
};

struct KabaSpeech
{
    u16 introTilemapBuffer[0x800];
    u16 pic1TilemapBuffer[0x800];
    u16 pic2TilemapBuffer[0x800];
    u8 monSpriteId;
    u8 ballSpriteId;
    u8 platformSpriteIds[PLAT_SPRITE_ID_COUNT]; // the platform is made out of 2 64x32sprites
    s16 alphaCoeff;
    s16 alphaCoeff2;
    s16 timer;
    s16 fadeTimer;
    s16 counter;
    bool32 fadeFinished:1;
    bool32 playerHasName:1;
    u8 chosenMugshot:1;
};

// EWRAM data
static EWRAM_DATA struct KabaSpeech *sKabaSpeech = NULL;

// Function declarations
static void Task_KabaSpeech_Begin(u8);
static void Task_KabaSpeech_FadeInEverything(u8);
static void Task_KabaSpeech_GreetingsTraveler(u8);
static void Task_KabaSpeech_AndThis(u8);
static void Task_KabaSpeech_ReleaseJoltikFromPokeball(u8);
static void Task_KabaSpeech_JoltikAPokemon(u8);
static void Task_KabaSpeech_MainTalk(u8);
static void Task_KabaSpeech_ReturnJoltik(u8);
static void Task_KabaSpeech_FadeOutPokeball(u8);
static void Task_KabaSpeech_FadeOutEverything(u8);
static void Task_KabaSpeech_FadeInPlayerMugshotChoice(u8);
static void Task_KabaSpeech_SetupPlayerMugshotChoice(u8);
static void Task_KabaSpeech_WaitForPlayerMugshotChoice(u8);
static void Task_KabaSpeech_MoveChosenMugshot(u8);
static void Task_KabaSpeech_SpawnYesNoMenuForPlayerMugshot(u8);
static void Task_KabaSpeech_HandleConfirmChosenMugshotInput(u8);
static void Task_KabaSpeech_MoveMugshotsBack(u8);
static void Task_KabaSpeech_AskForName(u8);
static void Task_KabaSpeech_WaitBeforeNamingScreen(u8);
static void Task_KabaSpeech_DoNamingScreen(u8);
static void Task_KabaSpeech_ConfirmChosenName(u8);
static void Task_KabaSpeech_HandleConfirmNameInput(u8);
static void Task_KabaSpeech_ConfirmPlayerName(u8);
static void Task_KabaSpeech_YourJourneyStartsHere(u8);
static void Task_KabaSpeech_CloseMsgbox(u8);
static void Task_KabaSpeech_FadeAwayEverything(u8);
static void Task_KabaSpeech_Cleanup(u8);

static void KabaSpeech_DrawCharacterMugshot(u8);
static inline void KabaSpeech_PrintMessageBox(const u8 *);
static void KabaSpeech_CreateMonSprite(void);
static void KabaSpeech_CreatePlatformSprites(bool32 hide);
static void KabaSpeech_DestroyPlatformSprites(void);
static void KabaSpeech_BeginFade(u8, u8, u8);
static void KabaSpeech_SetDefaultName(void);
static void CB2_KabaSpeech_ReturnFromNamingScreen(void);

// Const data
static const u8 sKabaSpeech_Aka[] = _("Aka");
static const u8 sKabaSpeech_Ao[]  = _("Ao");

static const u8 sKabaSpeech_Greetings[] = _(
    "Greetings, child.\n"
    "Welcome to the world of Pokémon!\p"
    "I am Kaba, one of the Elders of\n"
    "the Council of the Toku Region.\l"
    "Does that not instill respect\l"
    "and fear in you?\p"
    "(Pah! As if… Youths nowadays have\n"
    "no respect for their elders…)\p"
);
static const u8 sKabaSpeech_AndThis[] = _(
    "Ahem. I got sidetracked.\n"
    "Let me show you what we call…"
);
static const u8 sKabaSpeech_JoltikAPokemon[] = _(
    "…A Pokémon!{PAUSE 30}\p"
);
static const u8 sKabaSpeech_MainTalk[] = _(
    "Fascinating creature, is it not?\p"
    "This one is tiny, but Pokémon come\n"
    "in all shapes and sizes!\p"
    "We found a way to capture and\n"
    "befriend these creatures with a\l"
    "special device we call a Pokéball.\p"
    "Enough about this for now, though.\n"
    "Tell me about you!\p"
);
static const u8 sKabaSpeech_GenderChoice[] = _(
    "Are you a boy?\n"
    "Or are you a girl?"
);
static const u8 sKabaSpeech_ConfirmChosenGender[] = _(
    "So this is how you look?\p"
);
static const u8 sKabaSpeech_GenderConfirmed[] = _(
    "(Children used to dress respectfully\n"
    "back in my day…)\p"
);
static const u8 sKabaSpeech_AskPlayerName[] = _(
    "And what would your name be?"
);
static const u8 sKabaSpeech_CancelChosenGender[] = _(
    "You whippersnapper, trying to\n"
    "confuse an old lady!"
);
static const u8 sKabaSpeech_SoYourePlayer[] = _(
    "Your name is {PLAYER}?\n"
    "(That's a real name…?)"
);
static const u8 sKabaSpeech_ConfirmPlayerName[] = _(
    "Alright! {PLAYER}!"
);
static const u8 sKabaSpeech_ThisIsChildhoodFriend[] = _(
    "who tf is this"
);
static const u8 sKabaSpeech_SoThisIsRival[] = _(
    "ohh its {RIVAL} ?"
);
static const u8 sKabaSpeech_ConfirmRivalName[] = _(
    "ah mb"
);
static const u8 sKabaSpeech_YourJourneyStartsHere[] = _(
    "Listen to me.\p"
    "You are about to embark on a great\n"
    "adventure!\p"
    "How do I know that?\n"
    "Don't question me!\p"
    "A world of wonders, friendship,\n"
    "surprises and Pokémon awaits you!"
);

static const u16 sKabaSpeech_BgGfx[] = INCBIN_U16("graphics/kaba_speech/bg.4bpp");
static const u16 sKabaSpeech_BgPal[] = INCBIN_U16("graphics/kaba_speech/bg.gbapal");
static const u32 sKabaSpeech_BgMap[] = INCBIN_U32("graphics/kaba_speech/bg.bin.lz");

static const u16 sKabaSpeech_KabaPicGfx[] = INCBIN_U16("graphics/kaba_speech/pics/kaba.4bpp");
static const u16 sKabaSpeech_KabaPicPal[] = INCBIN_U16("graphics/kaba_speech/pics/kaba.gbapal");
static const u32 sKabaSpeech_KabaPicMap[] = INCBIN_U32("graphics/kaba_speech/pics/kaba.bin.lz");

//! NOTE: both aka and ao has the same palette as of writing
static const u16 sKabaSpeech_PlayerPicPal[] = INCBIN_U16("graphics/kaba_speech/pics/ao.gbapal");

static const u16 sKabaSpeech_AkaPicGfx[] = INCBIN_U16("graphics/kaba_speech/pics/aka.4bpp");
static const u8 sKabaSpeech_AkaPicMap[] = INCBIN_U8("graphics/kaba_speech/pics/aka.bin");

static const u16 sKabaSpeech_AoPicGfx[] = INCBIN_U16("graphics/kaba_speech/pics/ao.4bpp");
static const u8 sKabaSpeech_AoPicMap[] = INCBIN_U8("graphics/kaba_speech/pics/ao.bin");

static const u16 sKabaSpeech_PlatformGfx[] = INCBIN_U16("graphics/kaba_speech/platform.4bpp");
static const u16 sKabaSpeech_PlatformPal[] = INCBIN_U16("graphics/kaba_speech/platform.gbapal");

static const struct BgTemplate sKabaSpeech_BgTemplates[BG_COUNT] =
{
    [BG_TEXT] = {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 0,
        // other unspecified attributes defaults to 0
    },
    [BG_MUGSHOT_1] = {
        .bg = 1,
        .charBaseIndex = 2,
        .mapBaseIndex = 30,
        .priority = 1,
    },
    [BG_MUGSHOT_2] = {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .priority = 2,
    },
    [BG_INTRO] = {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 27,
        .priority = 3,
    },
};

static const struct WindowTemplate sKabaSpeech_WindowTemplates[] =
{
    [WIN_TEXT] =
    {
        .bg = BG_TEXT,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x1,
    },
    DUMMY_WIN_TEMPLATE,
};

static const struct WindowTemplate sKabaSpeech_YesNoWindow =
{
    .bg = BG_TEXT,
    .tilemapLeft = 21,
    .tilemapTop = 9,
    .width = 5,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = (26*4)+1,
};

static const struct SpriteSheet sKabaSpeech_PlatformSpriteSheet = 
{
    .data = sKabaSpeech_PlatformGfx,
    .size = 2048, // 64x128/2
    .tag = TAG_PLATFORM,
};

static const struct SpritePalette sKabaSpeech_PlatformSpritePalette =
{
    .data = sKabaSpeech_PlatformPal,
    .tag = TAG_PLATFORM,
};

static const struct OamData sKabaSpeech_PlatformOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sKabaSpeech_PlatformLeft[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sKabaSpeech_PlatformRight[] =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sKabaSpeech_PlatformAnims[] =
{
    sKabaSpeech_PlatformLeft,
    sKabaSpeech_PlatformRight
};

static const struct SpriteTemplate sKabaSpeech_PlatformTemplate =
{
    .tileTag = TAG_PLATFORM,
    .paletteTag = TAG_PLATFORM,
    .oam = &sKabaSpeech_PlatformOamData,
    .anims = sKabaSpeech_PlatformAnims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// Code
void CB2_KabaSpeech(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void VBlankCB_KabaSpeech(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void DoKabaSpeech(void)
{
    CreateTask(Task_KabaSpeech_Begin, 0);
    SetMainCallback2(CB2_KabaSpeech);
}

static void Task_KabaSpeech_Begin(u8 taskId)
{
    switch(gMain.state)
    {
        case STATE_RESET:
            SetVBlankCallback(NULL);
            SetHBlankCallback(NULL);
            DmaFill16(3, 0, VRAM, VRAM_SIZE);
            ResetPaletteFade();
            ScanlineEffect_Stop();
            ResetSpriteData();
            FreeAllSpritePalettes();
            ResetTempTileDataBuffers();
            break;
        case STATE_ALLOC:
            sKabaSpeech = AllocZeroed(sizeof(*sKabaSpeech));
            break;
        case STATE_REGS:
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WIN1H, 0);
            SetGpuReg(REG_OFFSET_WIN1V, 0);
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, 0);
            break;
        case STATE_BGS:
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sKabaSpeech_BgTemplates, ARRAY_COUNT(sKabaSpeech_BgTemplates));
            SetBgTilemapBuffer(BG_INTRO, sKabaSpeech->introTilemapBuffer);
            SetBgTilemapBuffer(BG_MUGSHOT_1, sKabaSpeech->pic1TilemapBuffer);
            SetBgTilemapBuffer(BG_MUGSHOT_2, sKabaSpeech->pic2TilemapBuffer);
            ResetBgPositions();
            break;
        case STATE_BG_GFX:
            KabaSpeech_CreateMonSprite();
            KabaSpeech_CreatePlatformSprites(TRUE);
            LoadPalette(sKabaSpeech_BgPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            LoadBgTiles(BG_INTRO, sKabaSpeech_BgGfx, sizeof(sKabaSpeech_BgGfx), 0);
            CopyToBgTilemapBuffer(BG_INTRO, sKabaSpeech_BgMap, 0, 0);
            CopyBgTilemapBufferToVram(BG_INTRO);
            KabaSpeech_DrawCharacterMugshot(MUGSHOT_KABA);
            break;
        case STATE_WINDOWS:
            InitWindows(sKabaSpeech_WindowTemplates);
            InitTextBoxGfxAndPrinters();
            Menu_LoadStdPalAt(BG_PLTT_ID(13));
            DrawDialogueFrame(WIN_TEXT, TRUE);
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            break;
        case STATE_FINISH:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
            SetGpuReg(REG_OFFSET_BLDY, 0);
            ShowBg(BG_INTRO);
            ShowBg(BG_MUGSHOT_1);
            ShowBg(BG_MUGSHOT_2);
            ShowBg(BG_TEXT);
            SetVBlankCallback(VBlankCB_KabaSpeech);
            PlayBGM(MUS_GSC_ROUTE38);
            gTasks[taskId].func = Task_KabaSpeech_FadeInEverything;
            gMain.state = 0;
            return;
    }
    DebugPrintf("state: %d", gMain.state);
    gMain.state++;
}

static void Task_KabaSpeech_FadeInEverything(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        sKabaSpeech->timer = 30;
        KabaSpeech_BeginFade(FALSE, 0xd8, SPRITE_TYPE_NONE);
        gTasks[taskId].func = Task_KabaSpeech_GreetingsTraveler;
    }
}

static void Task_KabaSpeech_GreetingsTraveler(u8 taskId)
{
    if (sKabaSpeech->fadeFinished)
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
            return;
        }

        KabaSpeech_PrintMessageBox(sKabaSpeech_Greetings);
        gTasks[taskId].func = Task_KabaSpeech_AndThis;
    }
}

static void Task_KabaSpeech_AndThis(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        KabaSpeech_PrintMessageBox(sKabaSpeech_AndThis);
        sKabaSpeech->timer = 30;
        gTasks[taskId].func = Task_KabaSpeech_ReleaseJoltikFromPokeball;
    }
}

static void Task_KabaSpeech_ReleaseJoltikFromPokeball(u8 taskId)
{
    u32 spriteId;
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
            return;
        }

        spriteId = sKabaSpeech->monSpriteId;
        gSprites[spriteId].invisible = FALSE;
        CreateKababallSpriteToReleaseMon(spriteId, gSprites[spriteId].oam.paletteNum, MON_POS_X, MON_POS_Y, 0, 0, 32, 0x00007FFF, SPECIES_JOLTIK);
        gTasks[taskId].func = Task_KabaSpeech_JoltikAPokemon;
        sKabaSpeech->timer = 0;
    }
}

static void Task_KabaSpeech_JoltikAPokemon(u8 taskId)
{
    sKabaSpeech->timer++;
    if (IsCryFinished())
    {
        if (sKabaSpeech->timer >= 192)
        {
            KabaSpeech_PrintMessageBox(sKabaSpeech_JoltikAPokemon);
            gTasks[taskId].func = Task_KabaSpeech_MainTalk;
        }
    }
}

static void Task_KabaSpeech_MainTalk(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        KabaSpeech_PrintMessageBox(sKabaSpeech_MainTalk);
        gTasks[taskId].func = Task_KabaSpeech_ReturnJoltik;
    }
}

static void Task_KabaSpeech_ReturnJoltik(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        u32 spriteId = sKabaSpeech->monSpriteId;
        sKabaSpeech->ballSpriteId = CreateIntroPokeballSprite(spriteId, gSprites[spriteId].oam.paletteNum, MON_POS_X, MON_POS_Y, 0, 0, 32, 0x00007FFF);
        gTasks[taskId].func = Task_KabaSpeech_FadeOutPokeball;
    }
}

static void Task_KabaSpeech_FadeOutPokeball(u8 taskId)
{
    // the ball callback ends its functionality with SpriteCallbackDummy
    if (gSprites[sKabaSpeech->ballSpriteId].callback == SpriteCallbackDummy)
    {
        KabaSpeech_BeginFade(TRUE, 0, SPRITE_TYPE_POKE_BALL);
        gTasks[taskId].func = Task_KabaSpeech_FadeOutEverything;
    }
}

static void Task_KabaSpeech_FadeOutEverything(u8 taskId)
{
    if (sKabaSpeech->fadeFinished)
    {
        DestroySprite(&gSprites[sKabaSpeech->monSpriteId]);
        DestroySprite(&gSprites[sKabaSpeech->ballSpriteId]);
        ClearDialogWindowAndFrameToTransparent(WIN_TEXT, TRUE);
        FillBgTilemapBufferRect_Palette0(BG_MUGSHOT_1, 0, 0, 0, 32, 32);
        CopyBgTilemapBufferToVram(BG_MUGSHOT_1);
        KabaSpeech_DrawCharacterMugshot(MUGSHOT_AO);
        KabaSpeech_DrawCharacterMugshot(MUGSHOT_AKA);
        gTasks[taskId].func = Task_KabaSpeech_FadeInPlayerMugshotChoice;
    }
}

static void Task_KabaSpeech_FadeInPlayerMugshotChoice(u8 taskId)
{
    sKabaSpeech->timer = 60;
    KabaSpeech_BeginFade(FALSE, 60, SPRITE_TYPE_PLATFORM);
    gTasks[taskId].func = Task_KabaSpeech_SetupPlayerMugshotChoice;

}

static void Task_KabaSpeech_SetupPlayerMugshotChoice(u8 taskId)
{
    if (sKabaSpeech->fadeFinished)
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
            return;
        }

        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        KabaSpeech_PrintMessageBox(sKabaSpeech_GenderChoice);
        sKabaSpeech->chosenMugshot = MUGSHOT_AO;
        sKabaSpeech->timer = 30;
        gTasks[taskId].func = Task_KabaSpeech_WaitForPlayerMugshotChoice;
    }
}

static void Task_KabaSpeech_WaitForPlayerMugshotChoice(u8 taskId)
{
    if (sKabaSpeech->timer)
    {
        sKabaSpeech->timer--;
        return;
    }

    switch (sKabaSpeech->chosenMugshot)
    {
    default:
    case MUGSHOT_AO: // female
        SetGpuReg(REG_OFFSET_BLDCNT,
            BLDCNT_TGT1_BG2 |
            BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 |
            BLDCNT_EFFECT_BLEND);
        break;
    case MUGSHOT_AKA: // male
        SetGpuReg(REG_OFFSET_BLDCNT,
            BLDCNT_TGT1_BG1 |
            BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 |
            BLDCNT_EFFECT_BLEND);
        break;
    }
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));

    if (JOY_NEW(DPAD_LEFT))
    {
        if (sKabaSpeech->chosenMugshot > 0)
            sKabaSpeech->chosenMugshot--;
        else
            sKabaSpeech->chosenMugshot++;
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        if (sKabaSpeech->chosenMugshot < 1)
            sKabaSpeech->chosenMugshot++;
        else
            sKabaSpeech->chosenMugshot--;
    }

    if (JOY_NEW(A_BUTTON))
    {
        u32 blend1 = (sKabaSpeech->chosenMugshot == MUGSHOT_AO) ? BLDCNT_TGT1_BG2 : BLDCNT_TGT1_BG1;

        SetGpuReg(REG_OFFSET_BLDCNT,
            blend1 |
            BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 |
            BLDCNT_EFFECT_BLEND);
        DebugPrintf("%d is chosen", sKabaSpeech->chosenMugshot);
        sKabaSpeech->counter = 0;
        KabaSpeech_BeginFade(TRUE, 0, (sKabaSpeech->chosenMugshot == MUGSHOT_AO) ? SPRITE_TYPE_MUGSHOT_2 : SPRITE_TYPE_MUGSHOT_1);
        gTasks[taskId].func = Task_KabaSpeech_MoveChosenMugshot;
    }
}

static void Task_KabaSpeech_MoveChosenMugshot(u8 taskId)
{
    u32 limit = (sKabaSpeech->chosenMugshot == MUGSHOT_AO) ? AO_MUGSHOT_CENTER_POS : AKA_MUGSHOT_CENTER_POS;
    if (sKabaSpeech->counter == limit)
    {
        KabaSpeech_PrintMessageBox(sKabaSpeech_ConfirmChosenGender);
        sKabaSpeech->timer = 15;
        gTasks[taskId].func = Task_KabaSpeech_SpawnYesNoMenuForPlayerMugshot;
    }
    else
    {
        s32 counter = (sKabaSpeech->chosenMugshot == MUGSHOT_AO) ? -sKabaSpeech->counter : sKabaSpeech->counter;
        sKabaSpeech->counter++;
        SetGpuReg(REG_OFFSET_BG1HOFS, counter);
        SetGpuReg(REG_OFFSET_BG2HOFS, counter);
    }
}

static void Task_KabaSpeech_SpawnYesNoMenuForPlayerMugshot(u8 taskId)
{
    if (sKabaSpeech->timer)
    {
        sKabaSpeech->timer--;
    }
    else
    {
        sKabaSpeech->playerHasName = FALSE;
        CreateYesNoMenu(&sKabaSpeech_YesNoWindow, 0x214, 14, 0);
        gTasks[taskId].func = Task_KabaSpeech_HandleConfirmChosenMugshotInput;
    }
}

static void Task_KabaSpeech_HandleConfirmChosenMugshotInput(u8 taskId)
{
    s32 input = Menu_ProcessInputNoWrapClearOnChoose();

    switch(input)
    {
    case 0: // YES
        PlaySE(SE_SELECT);
        KabaSpeech_PrintMessageBox(sKabaSpeech_GenderConfirmed);
        gTasks[taskId].func = Task_KabaSpeech_AskForName;
        break;
    case 1: // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        KabaSpeech_PrintMessageBox(sKabaSpeech_CancelChosenGender);
        KabaSpeech_BeginFade(FALSE, 0, (sKabaSpeech->chosenMugshot == MUGSHOT_AO) ? SPRITE_TYPE_MUGSHOT_2 : SPRITE_TYPE_MUGSHOT_1);
        gTasks[taskId].func = Task_KabaSpeech_MoveMugshotsBack;
        break;
    }
}

static void Task_KabaSpeech_MoveMugshotsBack(u8 taskId)
{
    u32 limit = 0;
    if (sKabaSpeech->counter == limit)
    {
        sKabaSpeech->timer = 60;
        gTasks[taskId].func = Task_KabaSpeech_SetupPlayerMugshotChoice;
    }
    else
    {
        s32 counter = (sKabaSpeech->chosenMugshot == MUGSHOT_AO) ? -sKabaSpeech->counter : sKabaSpeech->counter;
        sKabaSpeech->counter--;
        SetGpuReg(REG_OFFSET_BG1HOFS, counter);
        SetGpuReg(REG_OFFSET_BG2HOFS, counter);
    }
}

static void Task_KabaSpeech_AskForName(u8 taskId)
{
    if (!IsTextPrinterActive(WIN_TEXT))
    {
        sKabaSpeech->timer = 60;
    
        KabaSpeech_PrintMessageBox(sKabaSpeech_AskPlayerName);
        gTasks[taskId].func = Task_KabaSpeech_WaitBeforeNamingScreen;
    }
}

static void Task_KabaSpeech_WaitBeforeNamingScreen(u8 taskId)
{
    if ((!IsTextPrinterActive(WIN_TEXT)) && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON)))
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_KabaSpeech_DoNamingScreen;
    }
}

static void Task_KabaSpeech_DoNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        KabaSpeech_SetDefaultName();
        DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, sKabaSpeech->chosenMugshot, 0, 0, CB2_KabaSpeech_ReturnFromNamingScreen);
        KabaSpeech_DestroyPlatformSprites();
        FreeAllWindowBuffers();
        DestroyTask(taskId);
    }
}

// .. actual naming screen menu here ..

static void Task_KabaSpeech_ConfirmChosenName(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
        }
        else
        {
            KabaSpeech_PrintMessageBox(sKabaSpeech_SoYourePlayer);
            CreateYesNoMenu(&sKabaSpeech_YesNoWindow, 0x214, 14, 0);
            gTasks[taskId].func = Task_KabaSpeech_HandleConfirmNameInput;
        }
    }
}

static void Task_KabaSpeech_HandleConfirmNameInput(u8 taskId)
{
    s32 input = Menu_ProcessInputNoWrapClearOnChoose();

    switch(input)
    {
    case 0: // YES
    {
        PlaySE(SE_SELECT);
        sKabaSpeech->timer = 40;
        
        sKabaSpeech->playerHasName = TRUE;
        KabaSpeech_PrintMessageBox(sKabaSpeech_ConfirmPlayerName);
        gTasks[taskId].func = Task_KabaSpeech_ConfirmPlayerName;
        
        break;
    }
    case 1: // NO
    case MENU_B_PRESSED:
        PlaySE(SE_SELECT);
        gTasks[taskId].func = Task_KabaSpeech_AskForName;
        break;
    }
}

static void Task_KabaSpeech_ConfirmPlayerName(u8 taskId)
{
    if ((!IsTextPrinterActive(WIN_TEXT)) && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON)))
    {
        ClearDialogWindowAndFrameToTransparent(WIN_TEXT, TRUE);
        gTasks[taskId].func = Task_KabaSpeech_YourJourneyStartsHere;
    }
}

static void Task_KabaSpeech_YourJourneyStartsHere(u8 taskId)
{
    if (sKabaSpeech->timer)
    {
        sKabaSpeech->timer--;
    }
    else
    {
        sKabaSpeech->timer = 40;
        KabaSpeech_PrintMessageBox(sKabaSpeech_YourJourneyStartsHere);
        gTasks[taskId].func = Task_KabaSpeech_CloseMsgbox;
    }
}

static void Task_KabaSpeech_CloseMsgbox(u8 taskId)
{
    if ((!IsTextPrinterActive(WIN_TEXT)) && (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON)))
    {
        ClearDialogWindowAndFrameToTransparent(WIN_TEXT, TRUE);
        gTasks[taskId].func = Task_KabaSpeech_FadeAwayEverything;
    }
}

static void Task_KabaSpeech_FadeAwayEverything(u8 taskId)
{
    if (sKabaSpeech->timer)
    {
        sKabaSpeech->timer--;
    }
    else
    {
        PlaySE(SE_EXIT);
        sKabaSpeech->timer = 60;
        BeginNormalPaletteFade(0xEFFFEFFF, 0, 0, 16, RGB_WHITE);
        gTasks[taskId].func = Task_KabaSpeech_Cleanup;
    }
}

static void Task_KabaSpeech_Cleanup(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (sKabaSpeech->timer)
        {
            sKabaSpeech->timer--;
        }
        else
        {
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
            gSaveBlock2Ptr->playerGender = sKabaSpeech->chosenMugshot;
            FreeAllWindowBuffers();
            KabaSpeech_DestroyPlatformSprites();
            FREE_AND_SET_NULL(sKabaSpeech);
            SetMainCallback2(CB2_NewGame);
            DestroyTask(taskId);
        }
    }
}

// misc. helper functions

static void KabaSpeech_DrawCharacterMugshot(u8 id)
{
    switch(id)
    {
        case MUGSHOT_AKA: // male
            LoadPalette(sKabaSpeech_PlayerPicPal, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
            LoadBgTiles(BG_MUGSHOT_2, sKabaSpeech_AkaPicGfx, sizeof(sKabaSpeech_AkaPicGfx), 0);
            CopyToBgTilemapBufferRect(BG_MUGSHOT_2, sKabaSpeech_AkaPicMap, 14, 0, 9, 13);
            CopyBgTilemapBufferToVram(BG_MUGSHOT_2);
            return;
        case MUGSHOT_AO: // female
            LoadPalette(sKabaSpeech_PlayerPicPal, BG_PLTT_ID(3), PLTT_SIZE_4BPP);
            LoadBgTiles(BG_MUGSHOT_1, sKabaSpeech_AoPicGfx, sizeof(sKabaSpeech_AoPicGfx), 0x50);
            CopyToBgTilemapBufferRect(BG_MUGSHOT_1, sKabaSpeech_AoPicMap, 7, 0, 9, 13);
            CopyBgTilemapBufferToVram(BG_MUGSHOT_1);
            return;
        case MUGSHOT_KABA:
            LoadPalette(sKabaSpeech_KabaPicPal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
            LoadBgTiles(BG_MUGSHOT_1, sKabaSpeech_KabaPicGfx, sizeof(sKabaSpeech_KabaPicGfx), 0);
            CopyToBgTilemapBuffer(BG_MUGSHOT_1, sKabaSpeech_KabaPicMap, 0, 0);
            CopyBgTilemapBufferToVram(BG_MUGSHOT_1);
            return;
        default:
            return;
    }
}

static inline void KabaSpeech_PrintMessageBox(const u8 *str)
{
    DrawDialogueFrame(WIN_TEXT, FALSE);
    if (str != gStringVar4)
    {
        StringExpandPlaceholders(gStringVar4, str);
        AddTextPrinterParameterized2(WIN_TEXT, FONT_NORMAL, gStringVar4, GetPlayerTextSpeed(), NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    }
    else
    {
        AddTextPrinterParameterized2(WIN_TEXT, FONT_NORMAL, str, GetPlayerTextSpeed(), NULL, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    }
    CopyWindowToVram(WIN_TEXT, COPYWIN_FULL);
}

static void KabaSpeech_CreateMonSprite(void)
{
    sKabaSpeech->monSpriteId = CreateMonPicSprite_Affine(SPECIES_JOLTIK, FALSE, 0, MON_PIC_AFFINE_FRONT, MON_POS_X, MON_POS_Y, 14, TAG_NONE);
    gSprites[sKabaSpeech->monSpriteId].callback = SpriteCallbackDummy;
    gSprites[sKabaSpeech->monSpriteId].oam.priority = 0;
    gSprites[sKabaSpeech->monSpriteId].invisible = TRUE;
}

static void KabaSpeech_CreatePlatformSprites(bool32 hide)
{
    u32 leftSpriteId, rightSpriteId;
    LoadSpriteSheet(&sKabaSpeech_PlatformSpriteSheet);
    LoadSpritePalette(&sKabaSpeech_PlatformSpritePalette);
    leftSpriteId = CreateSprite(&sKabaSpeech_PlatformTemplate, PLAT_POS_X, PLAT_POS_Y, 0);
    rightSpriteId = CreateSprite(&sKabaSpeech_PlatformTemplate, PLAT_POS_X, PLAT_POS_Y, 0);
    gSprites[rightSpriteId].x2 = PLAT_POS_X2;
    StartSpriteAnim(&gSprites[leftSpriteId], 0);
    StartSpriteAnim(&gSprites[rightSpriteId], 1);
    gSprites[leftSpriteId].invisible = hide;
    gSprites[rightSpriteId].invisible = hide;
    sKabaSpeech->platformSpriteIds[0] = leftSpriteId;
    sKabaSpeech->platformSpriteIds[1] = rightSpriteId;
}

static void KabaSpeech_DestroyPlatformSprites(void)
{
    DestroySprite(&gSprites[sKabaSpeech->platformSpriteIds[1]]);
    DestroySpriteAndFreeResources(&gSprites[sKabaSpeech->platformSpriteIds[0]]);
    sKabaSpeech->platformSpriteIds[0] = SPRITE_NONE;
    sKabaSpeech->platformSpriteIds[1] = SPRITE_NONE;
}

#define tSpriteType data[0]

static void Task_KabaSpeech_FadeOut(u8 taskId)
{
    u32 i = 0;
    if (sKabaSpeech->alphaCoeff == 0)
    {
        sKabaSpeech->fadeFinished = TRUE;
        switch (gTasks[taskId].tSpriteType)
        {
            case SPRITE_TYPE_PLATFORM:
            {
                for (i = 0; i < PLAT_SPRITE_ID_COUNT; i++)
                    gSprites[sKabaSpeech->platformSpriteIds[i]].invisible = TRUE;
            }
                break;
            case SPRITE_TYPE_POKE_BALL:
                gSprites[sKabaSpeech->ballSpriteId].invisible = TRUE;
                break;
            default:
            case SPRITE_TYPE_NONE:
                break;
        }
        DestroyTask(taskId);
    }
    else
    {
        if (sKabaSpeech->fadeTimer != 0)
        {
            sKabaSpeech->fadeTimer--;
        }
        else
        {
            sKabaSpeech->fadeTimer = 0;
            sKabaSpeech->alphaCoeff--;
            sKabaSpeech->alphaCoeff2++;
            if (sKabaSpeech->alphaCoeff == 8)
            {
                switch (gTasks[taskId].tSpriteType)
                {
                    case SPRITE_TYPE_PLATFORM:
                    {
                        for (i = 0; i < PLAT_SPRITE_ID_COUNT; i++)
                            gSprites[sKabaSpeech->platformSpriteIds[i]].invisible ^= TRUE;
                    }
                        break;
                    case SPRITE_TYPE_POKE_BALL:
                        gSprites[sKabaSpeech->ballSpriteId].invisible ^= TRUE;
                        break;
                    default:
                    case SPRITE_TYPE_NONE:
                        break;
                }
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, (sKabaSpeech->alphaCoeff2 * 256) + sKabaSpeech->alphaCoeff);
        }
    }
}

static void Task_KabaSpeech_FadeIn(u8 taskId)
{
    u32 i = 0;

    if (sKabaSpeech->alphaCoeff == 16)
    {
        if (!gPaletteFade.active)
        {
            sKabaSpeech->fadeFinished = TRUE;
            DestroyTask(taskId);
        }
    }
    else
    {
        if (sKabaSpeech->fadeTimer != 0)
        {
            sKabaSpeech->fadeTimer--;
        }
        else
        {
            sKabaSpeech->fadeTimer = 0;
            sKabaSpeech->alphaCoeff++;
            sKabaSpeech->alphaCoeff2--;
            if (sKabaSpeech->alphaCoeff == 8)
            {
                switch (gTasks[taskId].tSpriteType)
                {
                    case SPRITE_TYPE_PLATFORM:
                    {
                        for (i = 0; i < PLAT_SPRITE_ID_COUNT; i++)
                            gSprites[sKabaSpeech->platformSpriteIds[i]].invisible ^= TRUE;
                    }
                        break;
                    case SPRITE_TYPE_POKE_BALL:
                        gSprites[sKabaSpeech->ballSpriteId].invisible ^= TRUE;
                        break;
                    default:
                    case SPRITE_TYPE_NONE:
                        break;
                }
            }
            SetGpuReg(REG_OFFSET_BLDALPHA, (sKabaSpeech->alphaCoeff2 * 256) + sKabaSpeech->alphaCoeff);
        }
    }
}

static void KabaSpeech_BeginFade(u8 fadeOut, u8 delay, u8 spriteType)
{
    u32 taskId;
    u32 bldTarget1, bldTarget2;

    sKabaSpeech->fadeFinished = FALSE;
    if (spriteType == SPRITE_TYPE_MUGSHOT_1 || spriteType == SPRITE_TYPE_MUGSHOT_2)
    {
        bldTarget1 = fadeOut ? 8 : 0;
        bldTarget2 = fadeOut ? 8 : 16;
    }
    else
    {
        bldTarget1 = fadeOut ? 16 : 0;
        bldTarget2 = fadeOut ? 0 : 16;
    }
    sKabaSpeech->alphaCoeff = bldTarget1;
    sKabaSpeech->alphaCoeff2 = bldTarget2;
    sKabaSpeech->fadeTimer = delay;

    if (spriteType == SPRITE_TYPE_PLAYER)
    {
        spriteType = (sKabaSpeech->chosenMugshot == MUGSHOT_AO) ? SPRITE_TYPE_MUGSHOT_1 : SPRITE_TYPE_MUGSHOT_2;
    }
    else if (spriteType == SPRITE_TYPE_RIVAL)
    {
        spriteType = (sKabaSpeech->chosenMugshot == MUGSHOT_AO) ? SPRITE_TYPE_MUGSHOT_2 : SPRITE_TYPE_MUGSHOT_1;
    }

    switch(spriteType)
    {
    case SPRITE_TYPE_PLATFORM:
    case SPRITE_TYPE_POKE_BALL:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
        break;
    case SPRITE_TYPE_MUGSHOT_1:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
        break;
    case SPRITE_TYPE_MUGSHOT_2:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG2 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
        break;
    case SPRITE_TYPE_NONE:
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
        break;
    default:
        break;
    }

    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(bldTarget1, bldTarget2));
    SetGpuReg(REG_OFFSET_BLDY, 0);

    DebugPrintf("fadeOut: %d", fadeOut);
    taskId = CreateTask(fadeOut ? Task_KabaSpeech_FadeOut : Task_KabaSpeech_FadeIn, 0);
    gTasks[taskId].tSpriteType = spriteType;
}

static void KabaSpeech_SetDefaultName(void)
{
    u32 i;
    const u8 *src = NULL;
    u8 *dst = NULL;

    src = (sKabaSpeech->chosenMugshot == MUGSHOT_AO) ? sKabaSpeech_Ao : sKabaSpeech_Aka;
    dst = gSaveBlock2Ptr->playerName;

    for (i = 0; i < PLAYER_NAME_LENGTH && src[i] != EOS; i++)
    {
        dst[i] = src[i];
    }
    for (; i < PLAYER_NAME_LENGTH + 1; i++)
    {
        dst[i] = EOS;
    }
}

static void CB2_KabaSpeech_ReturnFromNamingScreen(void)
{
    switch(gMain.state)
    {
        case STATE_RESET:
            SetVBlankCallback(NULL);
            SetHBlankCallback(NULL);
            DmaFill16(3, 0, VRAM, VRAM_SIZE);
            ResetPaletteFade();
            ScanlineEffect_Stop();
            ResetSpriteData();
            ResetTasks();
            FreeAllSpritePalettes();
            ResetTempTileDataBuffers();
            break;
        case STATE_ALLOC: // unused here
            break;
        case STATE_REGS:
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WIN1H, 0);
            SetGpuReg(REG_OFFSET_WIN1V, 0);
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_DISPCNT, 0);
            break;
        case STATE_BGS:
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sKabaSpeech_BgTemplates, ARRAY_COUNT(sKabaSpeech_BgTemplates));
            SetBgTilemapBuffer(BG_INTRO, sKabaSpeech->introTilemapBuffer);
            SetBgTilemapBuffer(BG_MUGSHOT_1, sKabaSpeech->pic1TilemapBuffer);
            SetBgTilemapBuffer(BG_MUGSHOT_2, sKabaSpeech->pic2TilemapBuffer);
            ResetBgPositions();
            break;
        case STATE_BG_GFX:
            KabaSpeech_CreatePlatformSprites(FALSE);
            LoadPalette(sKabaSpeech_BgPal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            LoadBgTiles(BG_INTRO, sKabaSpeech_BgGfx, sizeof(sKabaSpeech_BgGfx), 0);
            CopyToBgTilemapBuffer(BG_INTRO, sKabaSpeech_BgMap, 0, 0);
            CopyBgTilemapBufferToVram(BG_INTRO);
            // we're still loading both even though
            // only one of them will be shown at this point
            KabaSpeech_DrawCharacterMugshot(MUGSHOT_AO);
            KabaSpeech_DrawCharacterMugshot(MUGSHOT_AKA);
            break;
        case STATE_WINDOWS:
            InitWindows(sKabaSpeech_WindowTemplates);
            InitTextBoxGfxAndPrinters();
            Menu_LoadStdPalAt(BG_PLTT_ID(13));
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            break;
        case STATE_FINISH:
        {
            u32 hideBg, showBg, bldBg;

            if (sKabaSpeech->playerHasName)
            {
                if (sKabaSpeech->chosenMugshot == MUGSHOT_AO)
                {
                    hideBg = BG_MUGSHOT_1;
                    showBg = BG_MUGSHOT_2;
                    bldBg  = BLDCNT_TGT1_BG1;
                }
                else
                {
                    hideBg = BG_MUGSHOT_2;
                    showBg = BG_MUGSHOT_1;
                    bldBg  = BLDCNT_TGT1_BG2;
                }
            }
            else
            {
                if (sKabaSpeech->chosenMugshot == MUGSHOT_AO)
                {
                    hideBg = BG_MUGSHOT_2;
                    showBg = BG_MUGSHOT_1;
                    bldBg  = BLDCNT_TGT1_BG2;
                }
                else
                {
                    hideBg = BG_MUGSHOT_1;
                    showBg = BG_MUGSHOT_2;
                    bldBg  = BLDCNT_TGT1_BG1;
                }
            }

            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BLDCNT,
                bldBg |
                BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BG3 | BLDCNT_EFFECT_BLEND);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
            SetGpuReg(REG_OFFSET_BLDY, 0);
            SetGpuReg(REG_OFFSET_BG1HOFS, -AO_MUGSHOT_CENTER_POS);
            SetGpuReg(REG_OFFSET_BG2HOFS, AKA_MUGSHOT_CENTER_POS);
            ShowBg(BG_INTRO);
            ShowBg(showBg);
            HideBg(hideBg);
            ShowBg(BG_TEXT);
            SetVBlankCallback(VBlankCB_KabaSpeech);
            SetMainCallback2(CB2_KabaSpeech);
            sKabaSpeech->timer = 30;
            CreateTask(Task_KabaSpeech_ConfirmChosenName, 0);
            gMain.state = 0;
            return;
        }
    }
    DebugPrintf("state: %d", gMain.state);
    gMain.state++;
}
