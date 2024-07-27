#include "global.h"
#include "blit.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "constants/mugshots.h"

#define MUGSHOT_PALETTE_NUM 13

struct Mugshot{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32* image;
    const u16* palette;
};

void DrawMugshot(void); //VAR_0x8000 = mugshot id
void DrawMugshotAtPos(void); //VAR_0x8000 = mugshot id, VAR_0x8001 = x, VAR_0x8002 = y
void ClearMugshot(void);

static const u32 sMugshotImg_Ao[] = INCBIN_U32("graphics/mugshots/ao.4bpp.lz");
static const u16 sMugshotPal_Ao[] = INCBIN_U16("graphics/mugshots/ao.gbapal");

static const u16 sMugshotPal_SpindaIslandNpc_BrownBg[] = INCBIN_U16("graphics/object_events/palettes/comp_npc_brownbg.gbapal");

static const u32 sMugshotImg_Archie[] = INCBIN_U32("graphics/mugshots/archie_normal.4bpp.lz");
static const u32 sMugshotImg_Archie_Happy[] = INCBIN_U32("graphics/mugshots/archie_happy.4bpp.lz");

static const struct Mugshot sMugshots[] = {
    // ADD YOUR MUGSHOTS HERE
    // TODO EVA change XY
    [MUGSHOT_AO] = {.x = 20, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_Ao, .palette = sMugshotPal_Ao},
    [MUGSHOT_ARCHIE] = {.x = 20, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_Archie, .palette = sMugshotPal_SpindaIslandNpc_BrownBg},
    [MUGSHOT_ARCHIE_HAPPY] = {.x = 20, .y = 4, .width = 80, .height = 80, .image = sMugshotImg_Archie_Happy, .palette = sMugshotPal_SpindaIslandNpc_BrownBg},
};


//WindowId + 1, 0 if window is not open
static EWRAM_DATA u8 sMugshotWindow = 0;

void ClearMugshot(void){
    if(sMugshotWindow != 0){
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

static void DrawMugshotCore(const struct Mugshot* const mugshot, int x, int y){
    struct WindowTemplate t;
    u16 windowId;
    
    if(sMugshotWindow != 0){
        ClearMugshot();
    }
    
    SetWindowTemplateFields(&t, 0, x, y, mugshot->width/8, mugshot->height/8, MUGSHOT_PALETTE_NUM, 0x40);
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    
    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void*)mugshot->image, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, mugshot->width/8, mugshot->height/8);
    CopyWindowToVram(windowId, 3);
}

void DrawMugshot(void){
    const struct Mugshot* const mugshot = sMugshots + VarGet(VAR_0x8000);
    DrawMugshotCore(mugshot, mugshot->x, mugshot->y);
}

void DrawMugshotAtPos(void){
    DrawMugshotCore(sMugshots + VarGet(VAR_0x8000), VarGet(VAR_0x8001), VarGet(VAR_0x8002));
}