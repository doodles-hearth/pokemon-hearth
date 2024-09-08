enum
{
    PAGE_TITLE,
    PAGE_DIRECTOR,
    PAGE_ART_DIRECTOR,
    PAGE_WORLD_DIRECTOR,
    PAGE_LEAD_PROGRAMMER,
    PAGE_PROGRAMMERS_1,
    PAGE_PROGRAMMERS_2,
    PAGE_PROGRAMMERS_3,
    PAGE_PROGRAMMERS_4,
    PAGE_GRAPHIC_DESIGNERS_1,
    PAGE_GRAPHIC_DESIGNERS_2,
    PAGE_GRAPHIC_DESIGNERS_3,
    PAGE_MUSIC_COMPOSITION,
    PAGE_SOUND_EFFECTS,
    PAGE_GAME_DESIGNERS_1,
    PAGE_GAME_DESIGNERS_2,
    PAGE_GAME_DESIGNERS_3,
    PAGE_SCENARIO_PLOT,
    PAGE_SCENARIO,
    PAGE_SCRIPT_DESIGNERS,
    PAGE_MAP_DESIGNERS,
    PAGE_BATTLE_FRONTIER_DATA,
    PAGE_PARAMETRIC_DESIGNERS,
    PAGE_POKEDEX_TEXT,
    PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_1,
    PAGE_PKMN_DESIGNERS_1,
    PAGE_PKMN_DESIGNERS_2,
    PAGE_PKMN_DESIGNERS_3,
    PAGE_PKMN_DESIGNERS_4,
    PAGE_SUPPORT_PROGRAMMERS,
    PAGE_NCL_PRODUCT_TESTING,
    PAGE_PACKAGE_AND_MANUAL,
    PAGE_SPECIAL_THANKS_1,
    PAGE_SPECIAL_THANKS_2,
    PAGE_SPECIAL_THANKS_3,
    PAGE_SPECIAL_THANKS_4,
    PAGE_INFORMATION_SUPERVISORS,
    PAGE_ARTWORK_1,
    PAGE_ARTWORK_2,
    PAGE_ARTWORK_3,
    PAGE_COORDINATORS,
    PAGE_ENGLISH_VERSION,
    PAGE_TRANSLATOR,
    PAGE_TEXT_EDITOR,
    PAGE_NCL_COORDINATOR,
    PAGE_PROGRAMMERS_5,
    PAGE_GRAPHIC_DESIGNER,
    PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_2,
    PAGE_NOA_TESTING,
    PAGE_BRAILLE_CODE_CHECK_1,
    PAGE_BRAILLE_CODE_CHECK_2,
    PAGE_SPECIAL_THANKS_5,
    PAGE_TASK_MANAGERS,
    PAGE_PRODUCERS,
    PAGE_EXECUTIVE_DIRECTOR,
    PAGE_EXECUTIVE_PRODUCERS_1,
    PAGE_EXECUTIVE_PRODUCERS_2,
    PAGE_COUNT
};

#define ENTRIES_PER_PAGE 5

static const u8 sCreditsText_EmptyString[]                    = _("");
static const u8 sCreditsText_PkmnEmeraldVersion[]             = _("POKéMON SPINSPINSPIN");
static const u8 sCreditsText_Credits[]                        = _("Credits");
static const u8 sCreditsText_ExecutiveDirector[]              = _("Executive Director");
static const u8 sCreditsText_Director[]                       = _("Director");
static const u8 sCreditsText_ArtDirector[]                    = _("Art Director");
static const u8 sCreditsText_BattleDirector[]                 = _("Battle Director");
static const u8 sCreditsText_MainProgrammer[]                 = _("Main Programmer");
static const u8 sCreditsText_BattleSystemPgrms[]              = _("Battle System Programmers");
static const u8 sCreditsText_FieldSystemPgrms[]               = _("Field System Programmer");
static const u8 sCreditsText_Programmers[]                    = _("Programmers");
static const u8 sCreditsText_MainGraphicDesigner[]            = _("Main Graphic Designer");
static const u8 sCreditsText_GraphicDesigners[]               = _("Graphic Designers");
static const u8 sCreditsText_PkmnDesigners[]                  = _("POKéMON Designers");
static const u8 sCreditsText_MusicComposition[]               = _("Music Composition");
static const u8 sCreditsText_SoundEffectsAndPkmnVoices[]      = _("Sound Effects & POKéMON Voices");
static const u8 sCreditsText_GameDesigners[]                  = _("Game Designers");
static const u8 sCreditsText_ScenarioPlot[]                   = _("Scenario Plot");
static const u8 sCreditsText_Scenario[]                       = _("Scenario");
static const u8 sCreditsText_ScriptDesigners[]                = _("Script Designers");
static const u8 sCreditsText_MapDesigners[]                   = _("Map Designers");
static const u8 sCreditsText_MapDataDesigners[]               = _("Map Data Designers");
static const u8 sCreditsText_ParametricDesigners[]            = _("Parametric Designers");
static const u8 sCreditsText_PokedexText[]                    = _("POKéDEX Text");
static const u8 sCreditsText_EnvAndToolPgrms[]                = _("Environment & Tool Programmers");
static const u8 sCreditsText_NCLProductTesting[]              = _("NCL Product Testing");
static const u8 sCreditsText_SpecialThanks[]                  = _("Special Thanks");
static const u8 sCreditsText_Coordinators[]                   = _("Coordinators");
static const u8 sCreditsText_Producers[]                      = _("Producers");
static const u8 sCreditsText_ExecProducers[]                  = _("Executive Producers");
static const u8 sCreditsText_InfoSupervisors[]                = _("Information Supervisors");
static const u8 sCreditsText_TaskManagers[]                   = _("Task Managers");
static const u8 sCreditsText_BrailleCodeCheck[]               = _("Braille Code Check");
static const u8 sCreditsText_WorldDirector[]                  = _("World Director");
static const u8 sCreditsText_BattleFrontierData[]             = _("Battle Frontier Data");
static const u8 sCreditsText_SupportProgrammers[]             = _("Support Programmers");
static const u8 sCreditsText_Artwork[]                        = _("Artwork");
static const u8 sCreditsText_LeadProgrammer[]                 = _("Lead Programmer");
static const u8 sCreditsText_LeadGraphicArtist[]              = _("Lead Graphic Artist");
static const u8 sCreditsText_SatoshiTajiri[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_JunichiMasuda[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_KenSugimori[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_ShigekiMorimoto[]                = _("Spinda");
static const u8 sCreditsText_TetsuyaWatanabe[]                = _("PurrfectDoodle");
static const u8 sCreditsText_HisashiSogabe[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_SosukeTamada[]                   = _("Spinda");
static const u8 sCreditsText_AkitoMori[]                      = _("PurrfectDoodle");
static const u8 sCreditsText_KeitaKagaya[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_YoshinoriMatsuda[]               = _("PurrfectDoodle");
static const u8 sCreditsText_HiroyukiNakamura[]               = _("PurrfectDoodle");
static const u8 sCreditsText_MasaoTaya[]                      = _("Spinda");
static const u8 sCreditsText_SatoshiNohara[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_TomomichiOhta[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_MiyukiIwasawa[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_TakenoriOhta[]                   = _("Spinda");
static const u8 sCreditsText_HironobuYoshida[]                = _("PurrfectDoodle");
static const u8 sCreditsText_MotofumiFujiwara[]               = _("PurrfectDoodle");
static const u8 sCreditsText_SatoshiOhta[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_AsukaIwashita[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_AimiTomita[]                     = _("PurrfectDoodle");
static const u8 sCreditsText_TakaoUnno[]                      = _("PurrfectDoodle");
static const u8 sCreditsText_KanakoEo[]                       = _("PurrfectDoodle");
static const u8 sCreditsText_JunOkutani[]                     = _("PurrfectDoodle");
static const u8 sCreditsText_AtsukoNishida[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_MuneoSaito[]                     = _("PurrfectDoodle");
static const u8 sCreditsText_RenaYoshikawa[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_GoIchinose[]                     = _("PurrfectDoodle");
static const u8 sCreditsText_MorikazuAoki[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_KojiNishino[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_KenjiMatsushima[]                = _("Spinda Spinda");
static const u8 sCreditsText_TetsujiOhta[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_HitomiSato[]                     = _("PurrfectDoodle");
static const u8 sCreditsText_TakeshiKawachimaru[]             = _("PurrfectDoodle");
static const u8 sCreditsText_TeruyukiShimoyamada[]            = _("PurrfectDoodle");
static const u8 sCreditsText_ShigeruOhmori[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_TadashiTakahashi[]               = _("PurrfectDoodle");
static const u8 sCreditsText_ToshinobuMatsumiya[]             = _("PurrfectDoodle");
static const u8 sCreditsText_AkihitoTomisawa[]                = _("PurrfectDoodle");
static const u8 sCreditsText_HirokiEnomoto[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_KazuyukiTerada[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_YuriSakurai[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_HiromiSagawa[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_KenjiTominaga[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_YoshioTajiri[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_TeikoSasaki[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_SachikoHamano[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_ChieMatsumiya[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_AkikoShinozaki[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_AstukoFujii[]                    = _("Spinda");
static const u8 sCreditsText_NozomuSaito[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_KenkichiToyama[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_SuguruNakatsui[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_YumiFunasaka[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_NaokoYanase[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_NCLSuperMarioClub[]              = _("PurrfectDoodle");
static const u8 sCreditsText_AtsushiTada[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_TakahiroOhnishi[]                = _("PurrfectDoodle");
static const u8 sCreditsText_NorihideOkamura[]                = _("PurrfectDoodle");
static const u8 sCreditsText_HiroNakamura[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_HiroyukiUesugi[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_TerukiMurakawa[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_AkiraKinashi[]                   = _("Spinda");
static const u8 sCreditsText_MichikoTakizawa[]                = _("PurrfectDoodle");
static const u8 sCreditsText_MakikoTakada[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_TakanaoKondo[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_AiMashima[]                      = _("PurrfectDoodle");
static const u8 sCreditsText_GakujiNomoto[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_TakehiroIzushi[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_HitoshiYamagami[]                = _("PurrfectDoodle");
static const u8 sCreditsText_KyokoWatanabe[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_TakaoNakano[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_HiroyukiJinnai[]                 = _("Spinda");
static const u8 sCreditsText_HiroakiTsuru[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_TsunekazIshihara[]               = _("PurrfectDoodle");
static const u8 sCreditsText_SatoruIwata[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_KazuyaSuyama[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_SatoshiMitsuhara[]               = _("PurrfectDoodle");
static const u8 sCreditsText_JapanBrailleLibrary[]            = _("PurrfectDoodle");
static const u8 sCreditsText_TomotakaKomura[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_MikikoOhhashi[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_DaisukeHoshino[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_KenjiroIto[]                     = _("Spinda");
static const u8 sCreditsText_RuiKawaguchi[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_ShunsukeKohori[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_SachikoNakamichi[]               = _("PurrfectDoodle");
static const u8 sCreditsText_FujikoNomura[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_KazukiYoshihara[]                = _("PurrfectDoodle");
static const u8 sCreditsText_RetsujiNomoto[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_AzusaTajima[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_ShusakuEgami[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_PackageAndManual[]               = _("Package & Manual Illustration");
static const u8 sCreditsText_EnglishVersion[]                 = _("English Version Coordinators");
static const u8 sCreditsText_Translator[]                     = _("Translator");
static const u8 sCreditsText_TextEditor[]                     = _("Text Editor");
static const u8 sCreditsText_NCLCoordinator[]                 = _("Spinda");
static const u8 sCreditsText_GraphicDesigner[]                = _("Graphic Designer");
static const u8 sCreditsText_NOAProductTesting[]              = _("Spinda");
static const u8 sCreditsText_HideyukiNakajima[]               = _("PurrfectDoodle");
static const u8 sCreditsText_HidenoriSaeki[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_YokoWatanabe[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_SakaeKimura[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_ChiakiShinkai[]                  = _("PurrfectDoodle");
static const u8 sCreditsText_SethMcMahill[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_NobOgasawara[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_TeresaLillygren[]                = _("PurrfectDoodle");
static const u8 sCreditsText_KimikoNakamichi[]                = _("PurrfectDoodle");
static const u8 sCreditsText_SouichiYamamoto[]                = _("PurrfectDoodle");
static const u8 sCreditsText_YuichiroIto[]                    = _("PurrfectDoodle");
static const u8 sCreditsText_ThomasHertzog[]                  = _("Spinda");
static const u8 sCreditsText_MikaKurosawa[]                   = _("PurrfectDoodle");
static const u8 sCreditsText_NationalFederationBlind[]        = _("PurrfectDoodle");
static const u8 sCreditsText_PatriciaAMaurer[]                = _("PurrfectDoodle");
static const u8 sCreditsText_EuropeanBlindUnion[]             = _("PurrfectDoodle");
static const u8 sCreditsText_AustralianBrailleAuthority[]     = _("PurrfectDoodle");
static const u8 sCreditsText_RoyalNewZealandFederationBlind[] = _("PurrfectDoodle");
static const u8 sCreditsText_MotoyasuTojima[]                 = _("PurrfectDoodle");
static const u8 sCreditsText_NicolaPrattBarlow[]              = _("PurrfectDoodle");
static const u8 sCreditsText_ShellieDow[]                     = _("PurrfectDoodle");
static const u8 sCreditsText_ErikJohnson[]                    = _("PurrfectDoodle");
static const struct CreditsEntry sCreditsEntry_EmptyString                      = { 0, FALSE, sCreditsText_EmptyString};
static const struct CreditsEntry sCreditsEntry_PkmnEmeraldVersion               = { 7,  TRUE, sCreditsText_PkmnEmeraldVersion};
static const struct CreditsEntry sCreditsEntry_Credits                          = {11,  TRUE, sCreditsText_Credits};
static const struct CreditsEntry sCreditsEntry_ExecutiveDirector                = { 8,  TRUE, sCreditsText_ExecutiveDirector};
static const struct CreditsEntry sCreditsEntry_Director                         = {12,  TRUE, sCreditsText_Director};
static const struct CreditsEntry sCreditsEntry_ArtDirector                      = {10,  TRUE, sCreditsText_ArtDirector};
static const struct CreditsEntry sCreditsEntry_BattleDirector                   = {10,  TRUE, sCreditsText_BattleDirector};
static const struct CreditsEntry sCreditsEntry_MainProgrammer                   = {10,  TRUE, sCreditsText_MainProgrammer};
static const struct CreditsEntry sCreditsEntry_BattleSystemPgrms                = { 8,  TRUE, sCreditsText_BattleSystemPgrms};
static const struct CreditsEntry sCreditsEntry_FieldSystemPgrms                 = { 7,  TRUE, sCreditsText_FieldSystemPgrms};
static const struct CreditsEntry sCreditsEntry_Programmers                      = {12,  TRUE, sCreditsText_Programmers};
static const struct CreditsEntry sCreditsEntry_MainGraphicDesigner              = { 7,  TRUE, sCreditsText_MainGraphicDesigner};
static const struct CreditsEntry sCreditsEntry_GraphicDesigners                 = { 9,  TRUE, sCreditsText_GraphicDesigners};
static const struct CreditsEntry sCreditsEntry_PkmnDesigners                    = {10,  TRUE, sCreditsText_PkmnDesigners};
static const struct CreditsEntry sCreditsEntry_MusicComposition                 = {13,  TRUE, sCreditsText_MusicComposition};
static const struct CreditsEntry sCreditsEntry_SoundEffectsAndPkmnVoices        = { 4,  TRUE, sCreditsText_SoundEffectsAndPkmnVoices};
static const struct CreditsEntry sCreditsEntry_GameDesigners                    = {11,  TRUE, sCreditsText_GameDesigners};
static const struct CreditsEntry sCreditsEntry_ScenarioPlot                     = {11,  TRUE, sCreditsText_ScenarioPlot};
static const struct CreditsEntry sCreditsEntry_Scenario                         = {13,  TRUE, sCreditsText_Scenario};
static const struct CreditsEntry sCreditsEntry_ScriptDesigners                  = {10,  TRUE, sCreditsText_ScriptDesigners};
static const struct CreditsEntry sCreditsEntry_MapDesigners                     = {11,  TRUE, sCreditsText_MapDesigners};
static const struct CreditsEntry sCreditsEntry_MapDataDesigners                 = { 9,  TRUE, sCreditsText_MapDataDesigners};
static const struct CreditsEntry sCreditsEntry_ParametricDesigners              = { 9,  TRUE, sCreditsText_ParametricDesigners};
static const struct CreditsEntry sCreditsEntry_PokedexText                      = {11,  TRUE, sCreditsText_PokedexText};
static const struct CreditsEntry sCreditsEntry_EnvAndToolPgrms                  = { 6,  TRUE, sCreditsText_EnvAndToolPgrms};
static const struct CreditsEntry sCreditsEntry_NCLProductTesting                = {11,  TRUE, sCreditsText_NCLProductTesting};
static const struct CreditsEntry sCreditsEntry_SpecialThanks                    = {10,  TRUE, sCreditsText_SpecialThanks};
static const struct CreditsEntry sCreditsEntry_Coordinators                     = {11,  TRUE, sCreditsText_Coordinators};
static const struct CreditsEntry sCreditsEntry_Producers                        = {11,  TRUE, sCreditsText_Producers};
static const struct CreditsEntry sCreditsEntry_ExecProducers                    = { 7,  TRUE, sCreditsText_ExecProducers};
static const struct CreditsEntry sCreditsEntry_InfoSupervisors                  = {10,  TRUE, sCreditsText_InfoSupervisors};
static const struct CreditsEntry sCreditsEntry_TaskManagers                     = { 8,  TRUE, sCreditsText_TaskManagers};
static const struct CreditsEntry sCreditsEntry_BrailleCodeCheck                 = {10,  TRUE, sCreditsText_BrailleCodeCheck};
static const struct CreditsEntry sCreditsEntry_WorldDirector                    = {10,  TRUE, sCreditsText_WorldDirector};
static const struct CreditsEntry sCreditsEntry_BattleFrontierData               = { 8,  TRUE, sCreditsText_BattleFrontierData};
static const struct CreditsEntry sCreditsEntry_SupportProgrammers               = {10,  TRUE, sCreditsText_SupportProgrammers};
static const struct CreditsEntry sCreditsEntry_Artwork                          = {12,  TRUE, sCreditsText_Artwork};
static const struct CreditsEntry sCreditsEntry_LeadProgrammer                   = {10,  TRUE, sCreditsText_LeadProgrammer};
static const struct CreditsEntry sCreditsEntry_LeadGraphicArtist                = { 9,  TRUE, sCreditsText_LeadGraphicArtist};
static const struct CreditsEntry sCreditsEntry_SatoshiTajiri                    = {11, FALSE, sCreditsText_SatoshiTajiri};
static const struct CreditsEntry sCreditsEntry_JunichiMasuda                    = {11, FALSE, sCreditsText_JunichiMasuda};
static const struct CreditsEntry sCreditsEntry_KenSugimori                      = {11, FALSE, sCreditsText_KenSugimori};
static const struct CreditsEntry sCreditsEntry_ShigekiMorimoto                  = {11, FALSE, sCreditsText_ShigekiMorimoto};
static const struct CreditsEntry sCreditsEntry_TetsuyaWatanabe                  = {11, FALSE, sCreditsText_TetsuyaWatanabe};
static const struct CreditsEntry sCreditsEntry_HisashiSogabe                    = {11, FALSE, sCreditsText_HisashiSogabe};
static const struct CreditsEntry sCreditsEntry_SosukeTamada                     = {11, FALSE, sCreditsText_SosukeTamada};
static const struct CreditsEntry sCreditsEntry_AkitoMori                        = {11, FALSE, sCreditsText_AkitoMori};
static const struct CreditsEntry sCreditsEntry_KeitaKagaya                      = {11, FALSE, sCreditsText_KeitaKagaya};
static const struct CreditsEntry sCreditsEntry_YoshinoriMatsuda                 = {11, FALSE, sCreditsText_YoshinoriMatsuda};
static const struct CreditsEntry sCreditsEntry_HiroyukiNakamura                 = {11, FALSE, sCreditsText_HiroyukiNakamura};
static const struct CreditsEntry sCreditsEntry_MasaoTaya                        = {11, FALSE, sCreditsText_MasaoTaya};
static const struct CreditsEntry sCreditsEntry_SatoshiNohara                    = {11, FALSE, sCreditsText_SatoshiNohara};
static const struct CreditsEntry sCreditsEntry_TomomichiOhta                    = {11, FALSE, sCreditsText_TomomichiOhta};
static const struct CreditsEntry sCreditsEntry_MiyukiIwasawa                    = {11, FALSE, sCreditsText_MiyukiIwasawa};
static const struct CreditsEntry sCreditsEntry_TakenoriOhta                     = {11, FALSE, sCreditsText_TakenoriOhta};
static const struct CreditsEntry sCreditsEntry_HironobuYoshida                  = {11, FALSE, sCreditsText_HironobuYoshida};
static const struct CreditsEntry sCreditsEntry_MotofumiFujiwara                 = {11, FALSE, sCreditsText_MotofumiFujiwara};
static const struct CreditsEntry sCreditsEntry_SatoshiOhta                      = {11, FALSE, sCreditsText_SatoshiOhta};
static const struct CreditsEntry sCreditsEntry_AsukaIwashita                    = {11, FALSE, sCreditsText_AsukaIwashita};
static const struct CreditsEntry sCreditsEntry_AimiTomita                       = {11, FALSE, sCreditsText_AimiTomita};
static const struct CreditsEntry sCreditsEntry_TakaoUnno                        = {11, FALSE, sCreditsText_TakaoUnno};
static const struct CreditsEntry sCreditsEntry_KanakoEo                         = {11, FALSE, sCreditsText_KanakoEo};
static const struct CreditsEntry sCreditsEntry_JunOkutani                       = {11, FALSE, sCreditsText_JunOkutani};
static const struct CreditsEntry sCreditsEntry_AtsukoNishida                    = {11, FALSE, sCreditsText_AtsukoNishida};
static const struct CreditsEntry sCreditsEntry_MuneoSaito                       = {11, FALSE, sCreditsText_MuneoSaito};
static const struct CreditsEntry sCreditsEntry_RenaYoshikawa                    = {11, FALSE, sCreditsText_RenaYoshikawa};
static const struct CreditsEntry sCreditsEntry_GoIchinose                       = {11, FALSE, sCreditsText_GoIchinose};
static const struct CreditsEntry sCreditsEntry_MorikazuAoki                     = {11, FALSE, sCreditsText_MorikazuAoki};
static const struct CreditsEntry sCreditsEntry_KojiNishino                      = {11, FALSE, sCreditsText_KojiNishino};
static const struct CreditsEntry sCreditsEntry_KenjiMatsushima                  = {11, FALSE, sCreditsText_KenjiMatsushima};
static const struct CreditsEntry sCreditsEntry_TetsujiOhta                      = {11, FALSE, sCreditsText_TetsujiOhta};
static const struct CreditsEntry sCreditsEntry_HitomiSato                       = {11, FALSE, sCreditsText_HitomiSato};
static const struct CreditsEntry sCreditsEntry_TakeshiKawachimaru               = {11, FALSE, sCreditsText_TakeshiKawachimaru};
static const struct CreditsEntry sCreditsEntry_TeruyukiShimoyamada              = {11, FALSE, sCreditsText_TeruyukiShimoyamada};
static const struct CreditsEntry sCreditsEntry_ShigeruOhmori                    = {11, FALSE, sCreditsText_ShigeruOhmori};
static const struct CreditsEntry sCreditsEntry_TadashiTakahashi                 = {11, FALSE, sCreditsText_TadashiTakahashi};
static const struct CreditsEntry sCreditsEntry_ToshinobuMatsumiya               = {11, FALSE, sCreditsText_ToshinobuMatsumiya};
static const struct CreditsEntry sCreditsEntry_AkihitoTomisawa                  = {11, FALSE, sCreditsText_AkihitoTomisawa};
static const struct CreditsEntry sCreditsEntry_HirokiEnomoto                    = {11, FALSE, sCreditsText_HirokiEnomoto};
static const struct CreditsEntry sCreditsEntry_KazuyukiTerada                   = {11, FALSE, sCreditsText_KazuyukiTerada};
static const struct CreditsEntry sCreditsEntry_YuriSakurai                      = {11, FALSE, sCreditsText_YuriSakurai};
static const struct CreditsEntry sCreditsEntry_HiromiSagawa                     = {11, FALSE, sCreditsText_HiromiSagawa};
static const struct CreditsEntry sCreditsEntry_KenjiTominaga                    = {11, FALSE, sCreditsText_KenjiTominaga};
static const struct CreditsEntry sCreditsEntry_YoshioTajiri                     = {11, FALSE, sCreditsText_YoshioTajiri};
static const struct CreditsEntry sCreditsEntry_TeikoSasaki                      = {11, FALSE, sCreditsText_TeikoSasaki};
static const struct CreditsEntry sCreditsEntry_SachikoHamano                    = {11, FALSE, sCreditsText_SachikoHamano};
static const struct CreditsEntry sCreditsEntry_ChieMatsumiya                    = {11, FALSE, sCreditsText_ChieMatsumiya};
static const struct CreditsEntry sCreditsEntry_AkikoShinozaki                   = {11, FALSE, sCreditsText_AkikoShinozaki};
static const struct CreditsEntry sCreditsEntry_AstukoFujii                      = {11, FALSE, sCreditsText_AstukoFujii};
static const struct CreditsEntry sCreditsEntry_NozomuSaito                      = {11, FALSE, sCreditsText_NozomuSaito};
static const struct CreditsEntry sCreditsEntry_KenkichiToyama                   = {11, FALSE, sCreditsText_KenkichiToyama};
static const struct CreditsEntry sCreditsEntry_SuguruNakatsui                   = {11, FALSE, sCreditsText_SuguruNakatsui};
static const struct CreditsEntry sCreditsEntry_YumiFunasaka                     = {11, FALSE, sCreditsText_YumiFunasaka};
static const struct CreditsEntry sCreditsEntry_NaokoYanase                      = {11, FALSE, sCreditsText_NaokoYanase};
static const struct CreditsEntry sCreditsEntry_NCLSuperMarioClub                = {11, FALSE, sCreditsText_NCLSuperMarioClub};
static const struct CreditsEntry sCreditsEntry_AtsushiTada                      = {11, FALSE, sCreditsText_AtsushiTada};
static const struct CreditsEntry sCreditsEntry_TakahiroOhnishi                  = {11, FALSE, sCreditsText_TakahiroOhnishi};
static const struct CreditsEntry sCreditsEntry_NorihideOkamura                  = {11, FALSE, sCreditsText_NorihideOkamura};
static const struct CreditsEntry sCreditsEntry_HiroNakamura                     = {11, FALSE, sCreditsText_HiroNakamura};
static const struct CreditsEntry sCreditsEntry_HiroyukiUesugi                   = {11, FALSE, sCreditsText_HiroyukiUesugi};
static const struct CreditsEntry sCreditsEntry_TerukiMurakawa                   = {11, FALSE, sCreditsText_TerukiMurakawa};
static const struct CreditsEntry sCreditsEntry_AkiraKinashi                     = {11, FALSE, sCreditsText_AkiraKinashi};
static const struct CreditsEntry sCreditsEntry_MichikoTakizawa                  = {11, FALSE, sCreditsText_MichikoTakizawa};
static const struct CreditsEntry sCreditsEntry_MakikoTakada                     = {11, FALSE, sCreditsText_MakikoTakada};
static const struct CreditsEntry sCreditsEntry_TakanaoKondo                     = {11, FALSE, sCreditsText_TakanaoKondo};
static const struct CreditsEntry sCreditsEntry_AiMashima                        = {11, FALSE, sCreditsText_AiMashima};
static const struct CreditsEntry sCreditsEntry_GakujiNomoto                     = {11, FALSE, sCreditsText_GakujiNomoto};
static const struct CreditsEntry sCreditsEntry_TakehiroIzushi                   = {11, FALSE, sCreditsText_TakehiroIzushi};
static const struct CreditsEntry sCreditsEntry_HitoshiYamagami                  = {11, FALSE, sCreditsText_HitoshiYamagami};
static const struct CreditsEntry sCreditsEntry_KyokoWatanabe                    = {11, FALSE, sCreditsText_KyokoWatanabe};
static const struct CreditsEntry sCreditsEntry_TakaoNakano                      = {11, FALSE, sCreditsText_TakaoNakano};
static const struct CreditsEntry sCreditsEntry_HiroyukiJinnai                   = {11, FALSE, sCreditsText_HiroyukiJinnai};
static const struct CreditsEntry sCreditsEntry_HiroakiTsuru                     = {11, FALSE, sCreditsText_HiroakiTsuru};
static const struct CreditsEntry sCreditsEntry_TsunekazIshihara                 = {11, FALSE, sCreditsText_TsunekazIshihara};
static const struct CreditsEntry sCreditsEntry_SatoruIwata                      = {11, FALSE, sCreditsText_SatoruIwata};
static const struct CreditsEntry sCreditsEntry_KazuyaSuyama                     = {11, FALSE, sCreditsText_KazuyaSuyama};
static const struct CreditsEntry sCreditsEntry_SatoshiMitsuhara                 = {11, FALSE, sCreditsText_SatoshiMitsuhara};
static const struct CreditsEntry sCreditsEntry_JapanBrailleLibrary              = { 9, FALSE, sCreditsText_JapanBrailleLibrary};
static const struct CreditsEntry sCreditsEntry_TomotakaKomura                   = {11, FALSE, sCreditsText_TomotakaKomura};
static const struct CreditsEntry sCreditsEntry_MikikoOhhashi                    = {11, FALSE, sCreditsText_MikikoOhhashi};
static const struct CreditsEntry sCreditsEntry_DaisukeHoshino                   = {11, FALSE, sCreditsText_DaisukeHoshino};
static const struct CreditsEntry sCreditsEntry_KenjiroIto                       = {11, FALSE, sCreditsText_KenjiroIto};
static const struct CreditsEntry sCreditsEntry_RuiKawaguchi                     = {11, FALSE, sCreditsText_RuiKawaguchi};
static const struct CreditsEntry sCreditsEntry_ShunsukeKohori                   = {11, FALSE, sCreditsText_ShunsukeKohori};
static const struct CreditsEntry sCreditsEntry_SachikoNakamichi                 = {11, FALSE, sCreditsText_SachikoNakamichi};
static const struct CreditsEntry sCreditsEntry_FujikoNomura                     = {11, FALSE, sCreditsText_FujikoNomura};
static const struct CreditsEntry sCreditsEntry_KazukiYoshihara                  = {11, FALSE, sCreditsText_KazukiYoshihara};
static const struct CreditsEntry sCreditsEntry_RetsujiNomoto                    = {11, FALSE, sCreditsText_RetsujiNomoto};
static const struct CreditsEntry sCreditsEntry_AzusaTajima                      = {11, FALSE, sCreditsText_AzusaTajima};
static const struct CreditsEntry sCreditsEntry_ShusakuEgami                     = {11, FALSE, sCreditsText_ShusakuEgami};
static const struct CreditsEntry sCreditsEntry_PackageAndManual                 = { 0,  TRUE, sCreditsText_PackageAndManual};
static const struct CreditsEntry sCreditsEntry_EnglishVersion                   = { 0,  TRUE, sCreditsText_EnglishVersion};
static const struct CreditsEntry sCreditsEntry_Translator                       = { 0,  TRUE, sCreditsText_Translator};
static const struct CreditsEntry sCreditsEntry_TextEditor                       = { 0,  TRUE, sCreditsText_TextEditor};
static const struct CreditsEntry sCreditsEntry_NCLCoordinator                   = { 0,  TRUE, sCreditsText_NCLCoordinator};
static const struct CreditsEntry sCreditsEntry_GraphicDesigner                  = { 0,  TRUE, sCreditsText_GraphicDesigner};
static const struct CreditsEntry sCreditsEntry_NOAProductTesting                = { 0,  TRUE, sCreditsText_NOAProductTesting};
static const struct CreditsEntry sCreditsEntry_HideyukiNakajima                 = { 0, FALSE, sCreditsText_HideyukiNakajima};
static const struct CreditsEntry sCreditsEntry_HidenoriSaeki                    = { 0, FALSE, sCreditsText_HidenoriSaeki};
static const struct CreditsEntry sCreditsEntry_YokoWatanabe                     = { 0, FALSE, sCreditsText_YokoWatanabe};
static const struct CreditsEntry sCreditsEntry_SakaeKimura                      = { 0, FALSE, sCreditsText_SakaeKimura};
static const struct CreditsEntry sCreditsEntry_ChiakiShinkai                    = { 0, FALSE, sCreditsText_ChiakiShinkai};
static const struct CreditsEntry sCreditsEntry_SethMcMahill                     = { 0, FALSE, sCreditsText_SethMcMahill};
static const struct CreditsEntry sCreditsEntry_NobOgasawara                     = { 0, FALSE, sCreditsText_NobOgasawara};
static const struct CreditsEntry sCreditsEntry_TeresaLillygren                  = { 0, FALSE, sCreditsText_TeresaLillygren};
static const struct CreditsEntry sCreditsEntry_KimikoNakamichi                  = { 0, FALSE, sCreditsText_KimikoNakamichi};
static const struct CreditsEntry sCreditsEntry_SouichiYamamoto                  = { 0, FALSE, sCreditsText_SouichiYamamoto};
static const struct CreditsEntry sCreditsEntry_YuichiroIto                      = { 0, FALSE, sCreditsText_YuichiroIto};
static const struct CreditsEntry sCreditsEntry_ThomasHertzog                    = { 0, FALSE, sCreditsText_ThomasHertzog};
static const struct CreditsEntry sCreditsEntry_MikaKurosawa                     = { 0, FALSE, sCreditsText_MikaKurosawa};
static const struct CreditsEntry sCreditsEntry_NationalFederationBlind          = { 0, FALSE, sCreditsText_NationalFederationBlind};
static const struct CreditsEntry sCreditsEntry_PatriciaAMaurer                  = { 0, FALSE, sCreditsText_PatriciaAMaurer};
static const struct CreditsEntry sCreditsEntry_EuropeanBlindUnion               = { 0, FALSE, sCreditsText_EuropeanBlindUnion};
static const struct CreditsEntry sCreditsEntry_AustralianBrailleAuthority       = { 0, FALSE, sCreditsText_AustralianBrailleAuthority};
static const struct CreditsEntry sCreditsEntry_RoyalNewZealandFederationBlind   = { 0, FALSE, sCreditsText_RoyalNewZealandFederationBlind};
static const struct CreditsEntry sCreditsEntry_MotoyasuTojima                   = { 0, FALSE, sCreditsText_MotoyasuTojima};
static const struct CreditsEntry sCreditsEntry_NicolaPrattBarlow                = { 0, FALSE, sCreditsText_NicolaPrattBarlow};
static const struct CreditsEntry sCreditsEntry_ShellieDow                       = { 0, FALSE, sCreditsText_ShellieDow};
static const struct CreditsEntry sCreditsEntry_ErikJohnson                      = { 0, FALSE, sCreditsText_ErikJohnson};

#define _ &sCreditsEntry_EmptyString
static const struct CreditsEntry *const sCreditsEntryPointerTable[PAGE_COUNT][ENTRIES_PER_PAGE] =
{
    [PAGE_TITLE] = {
        _,
        &sCreditsEntry_PkmnEmeraldVersion,
        &sCreditsEntry_Credits,
        _,
        _
    },
    [PAGE_DIRECTOR] = {
        _,
        &sCreditsEntry_Director,
        &sCreditsEntry_ShigekiMorimoto,
        _,
        _,
    },
    [PAGE_ART_DIRECTOR] = {
        _,
        &sCreditsEntry_ArtDirector,
        &sCreditsEntry_KenSugimori,
        _,
        _,
    },
    [PAGE_WORLD_DIRECTOR] = {
        _,
        &sCreditsEntry_WorldDirector,
        &sCreditsEntry_JunichiMasuda,
        _,
        _,
    },
    [PAGE_LEAD_PROGRAMMER] = {
        &sCreditsEntry_LeadProgrammer,
        &sCreditsEntry_HisashiSogabe,
        &sCreditsEntry_LeadGraphicArtist,
        &sCreditsEntry_MotofumiFujiwara,
        _,
    },
    [PAGE_PROGRAMMERS_1] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_HisashiSogabe,
        &sCreditsEntry_TomomichiOhta,
        &sCreditsEntry_NozomuSaito,
        _,
    },
    [PAGE_PROGRAMMERS_2] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_AkitoMori,
        &sCreditsEntry_HiroyukiNakamura,
        &sCreditsEntry_MasaoTaya,
        _,
    },
    [PAGE_PROGRAMMERS_3] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_SatoshiNohara,
        &sCreditsEntry_MiyukiIwasawa,
        &sCreditsEntry_YoshinoriMatsuda,
        &sCreditsEntry_KeitaKagaya,
    },
    [PAGE_PROGRAMMERS_4] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_TetsuyaWatanabe,
        &sCreditsEntry_SosukeTamada,
        &sCreditsEntry_TakenoriOhta,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_1] = {
        _,
        &sCreditsEntry_GraphicDesigners,
        &sCreditsEntry_MotofumiFujiwara,
        &sCreditsEntry_SatoshiOhta,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_2] = {
        &sCreditsEntry_GraphicDesigners,
        &sCreditsEntry_KenkichiToyama,
        &sCreditsEntry_AsukaIwashita,
        &sCreditsEntry_TakaoUnno,
        _,
    },
    [PAGE_GRAPHIC_DESIGNERS_3] = {
        &sCreditsEntry_GraphicDesigners,
        &sCreditsEntry_KenSugimori,
        &sCreditsEntry_HironobuYoshida,
        &sCreditsEntry_AimiTomita,
        &sCreditsEntry_KanakoEo,
    },
    [PAGE_MUSIC_COMPOSITION] = {
        &sCreditsEntry_MusicComposition,
        &sCreditsEntry_GoIchinose,
        &sCreditsEntry_JunichiMasuda,
        &sCreditsEntry_MorikazuAoki,
        &sCreditsEntry_HitomiSato,
    },
    [PAGE_SOUND_EFFECTS] = {
        _,
        &sCreditsEntry_SoundEffectsAndPkmnVoices,
        &sCreditsEntry_GoIchinose,
        &sCreditsEntry_MorikazuAoki,
        _,
    },
    [PAGE_GAME_DESIGNERS_1] = {
        &sCreditsEntry_GameDesigners,
        &sCreditsEntry_ShigekiMorimoto,
        &sCreditsEntry_TeruyukiShimoyamada,
        &sCreditsEntry_TakeshiKawachimaru,
        &sCreditsEntry_AkihitoTomisawa,
    },
    [PAGE_GAME_DESIGNERS_2] = {
        &sCreditsEntry_GameDesigners,
        &sCreditsEntry_SuguruNakatsui,
        &sCreditsEntry_TetsujiOhta,
        &sCreditsEntry_HitomiSato,
        &sCreditsEntry_KenjiMatsushima,
    },
    [PAGE_GAME_DESIGNERS_3] = {
        &sCreditsEntry_GameDesigners,
        &sCreditsEntry_JunichiMasuda,
        &sCreditsEntry_KojiNishino,
        &sCreditsEntry_ShigeruOhmori,
        &sCreditsEntry_TadashiTakahashi,
    },
    [PAGE_SCENARIO_PLOT] = {
        &sCreditsEntry_ScenarioPlot,
        &sCreditsEntry_AkihitoTomisawa,
        &sCreditsEntry_JunichiMasuda,
        &sCreditsEntry_KojiNishino,
        _,
    },
    [PAGE_SCENARIO] = {
        &sCreditsEntry_Scenario,
        &sCreditsEntry_AkihitoTomisawa,
        &sCreditsEntry_HitomiSato,
        &sCreditsEntry_ToshinobuMatsumiya,
        _,
    },
    [PAGE_SCRIPT_DESIGNERS] = {
        &sCreditsEntry_ScriptDesigners,
        &sCreditsEntry_TomomichiOhta,
        &sCreditsEntry_SatoshiNohara,
        _,
        _,
    },
    [PAGE_MAP_DESIGNERS] = {
        &sCreditsEntry_MapDesigners,
        &sCreditsEntry_SuguruNakatsui,
        &sCreditsEntry_TeruyukiShimoyamada,
        &sCreditsEntry_ShigeruOhmori,
        &sCreditsEntry_TetsujiOhta,
    },
    [PAGE_BATTLE_FRONTIER_DATA] = {
        _,
        &sCreditsEntry_BattleFrontierData,
        &sCreditsEntry_TetsujiOhta,
        _,
        _,
    },
    [PAGE_PARAMETRIC_DESIGNERS] = {
        &sCreditsEntry_ParametricDesigners,
        &sCreditsEntry_TeruyukiShimoyamada,
        &sCreditsEntry_ShigekiMorimoto,
        &sCreditsEntry_TetsujiOhta,
        &sCreditsEntry_KojiNishino,
    },
    [PAGE_POKEDEX_TEXT] = {
        _,
        &sCreditsEntry_PokedexText,
        &sCreditsEntry_KenjiMatsushima,
        _,
        _,
    },
    [PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_1] = {
        &sCreditsEntry_EnvAndToolPgrms,
        &sCreditsEntry_HisashiSogabe,
        &sCreditsEntry_SosukeTamada,
        &sCreditsEntry_HiroyukiNakamura,
        &sCreditsEntry_AkitoMori,
    },
    [PAGE_PKMN_DESIGNERS_1] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_KenSugimori,
        &sCreditsEntry_MotofumiFujiwara,
        &sCreditsEntry_ShigekiMorimoto,
        _,
    },
    [PAGE_PKMN_DESIGNERS_2] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_HironobuYoshida,
        &sCreditsEntry_SatoshiOhta,
        &sCreditsEntry_AsukaIwashita,
        _,
    },
    [PAGE_PKMN_DESIGNERS_3] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_TakaoUnno,
        &sCreditsEntry_KanakoEo,
        &sCreditsEntry_AimiTomita,
        _,
    },
    [PAGE_PKMN_DESIGNERS_4] = {
        &sCreditsEntry_PkmnDesigners,
        &sCreditsEntry_AtsukoNishida,
        &sCreditsEntry_MuneoSaito,
        &sCreditsEntry_RenaYoshikawa,
        &sCreditsEntry_JunOkutani,
    },
    [PAGE_SUPPORT_PROGRAMMERS] = {
        _,
        &sCreditsEntry_SupportProgrammers,
        &sCreditsEntry_SatoshiMitsuhara,
        &sCreditsEntry_DaisukeHoshino,
        _,
    },
    [PAGE_NCL_PRODUCT_TESTING] = {
        _,
        &sCreditsEntry_NCLProductTesting,
        &sCreditsEntry_NCLSuperMarioClub,
        _,
        _,
    },
    [PAGE_PACKAGE_AND_MANUAL] = {
        _,
        &sCreditsEntry_PackageAndManual,
        &sCreditsEntry_KenSugimori,
        _,
        _,
    },
    [PAGE_SPECIAL_THANKS_1] = {
        _,
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_KenjiTominaga,
        &sCreditsEntry_HirokiEnomoto,
        _,
    },
    [PAGE_SPECIAL_THANKS_2] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_KazuyaSuyama,
        &sCreditsEntry_KenjiroIto,
        &sCreditsEntry_MichikoTakizawa,
        &sCreditsEntry_MakikoTakada,
    },
    [PAGE_SPECIAL_THANKS_3] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_MikikoOhhashi,
        &sCreditsEntry_TakanaoKondo,
        &sCreditsEntry_RuiKawaguchi,
        _,
    },
    [PAGE_SPECIAL_THANKS_4] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_TakahiroOhnishi,
        &sCreditsEntry_NorihideOkamura,
        &sCreditsEntry_ShunsukeKohori,
        _,
    },
    [PAGE_INFORMATION_SUPERVISORS] = {
        &sCreditsEntry_InfoSupervisors,
        &sCreditsEntry_KazuyukiTerada,
        &sCreditsEntry_YuriSakurai,
        &sCreditsEntry_YumiFunasaka,
        &sCreditsEntry_NaokoYanase,
    },
    [PAGE_ARTWORK_1] = {
        _,
        &sCreditsEntry_Artwork,
        &sCreditsEntry_SachikoNakamichi,
        &sCreditsEntry_FujikoNomura,
        _,
    },
    [PAGE_ARTWORK_2] = {
        _,
        &sCreditsEntry_Artwork,
        &sCreditsEntry_HideyukiNakajima,
        &sCreditsEntry_HidenoriSaeki,
        _,
    },
    [PAGE_ARTWORK_3] = {
        &sCreditsEntry_Artwork,
        &sCreditsEntry_YokoWatanabe,
        &sCreditsEntry_SakaeKimura,
        &sCreditsEntry_ChiakiShinkai,
        _,
    },
    [PAGE_COORDINATORS] = {
        &sCreditsEntry_Coordinators,
        &sCreditsEntry_KazukiYoshihara,
        &sCreditsEntry_AkiraKinashi,
        &sCreditsEntry_RetsujiNomoto,
        _,
    },
    [PAGE_ENGLISH_VERSION] = {
        _,
        &sCreditsEntry_EnglishVersion,
        &sCreditsEntry_HiroNakamura,
        &sCreditsEntry_SethMcMahill,
        _,
    },
    [PAGE_TRANSLATOR] = {
        _,
        &sCreditsEntry_Translator,
        &sCreditsEntry_NobOgasawara,
        _,
        _,
    },
    [PAGE_TEXT_EDITOR] = {
        _,
        &sCreditsEntry_TextEditor,
        &sCreditsEntry_TeresaLillygren,
        _,
        _,
    },
    [PAGE_NCL_COORDINATOR] = {
        _,
        &sCreditsEntry_NCLCoordinator,
        &sCreditsEntry_KimikoNakamichi,
        _,
        _,
    },
    [PAGE_PROGRAMMERS_5] = {
        &sCreditsEntry_Programmers,
        &sCreditsEntry_TerukiMurakawa,
        &sCreditsEntry_SouichiYamamoto,
        &sCreditsEntry_YuichiroIto,
        &sCreditsEntry_AkiraKinashi,
    },
    [PAGE_GRAPHIC_DESIGNER] = {
        _,
        &sCreditsEntry_GraphicDesigner,
        &sCreditsEntry_AkiraKinashi,
        _,
        _,
    },
    [PAGE_ENVIRONMENT_AND_TOOL_PROGRAMS_2] = {
        &sCreditsEntry_EnvAndToolPgrms,
        &sCreditsEntry_TerukiMurakawa,
        &sCreditsEntry_SouichiYamamoto,
        &sCreditsEntry_KimikoNakamichi,
        _,
    },
    [PAGE_NOA_TESTING] = {
        &sCreditsEntry_NOAProductTesting,
        &sCreditsEntry_ThomasHertzog,
        &sCreditsEntry_ErikJohnson,
        &sCreditsEntry_MikaKurosawa,
        _,
    },
    [PAGE_BRAILLE_CODE_CHECK_1] = {
        &sCreditsEntry_BrailleCodeCheck,
        &sCreditsEntry_NationalFederationBlind,
        &sCreditsEntry_PatriciaAMaurer,
        &sCreditsEntry_JapanBrailleLibrary,
        &sCreditsEntry_EuropeanBlindUnion,
    },
    [PAGE_BRAILLE_CODE_CHECK_2] = {
        _,
        &sCreditsEntry_BrailleCodeCheck,
        &sCreditsEntry_AustralianBrailleAuthority,
        &sCreditsEntry_RoyalNewZealandFederationBlind,
        _,
    },
    [PAGE_SPECIAL_THANKS_5] = {
        &sCreditsEntry_SpecialThanks,
        &sCreditsEntry_HiroyukiUesugi,
        &sCreditsEntry_MotoyasuTojima,
        &sCreditsEntry_NicolaPrattBarlow,
        &sCreditsEntry_ShellieDow,
    },
    [PAGE_TASK_MANAGERS] = {
        _,
        &sCreditsEntry_TaskManagers,
        &sCreditsEntry_AzusaTajima,
        &sCreditsEntry_ShusakuEgami,
        _,
    },
    [PAGE_PRODUCERS] = {
        &sCreditsEntry_Producers,
        &sCreditsEntry_HiroyukiJinnai,
        &sCreditsEntry_HitoshiYamagami,
        &sCreditsEntry_GakujiNomoto,
        &sCreditsEntry_HiroakiTsuru,
    },
    [PAGE_EXECUTIVE_DIRECTOR] = {
        _,
        &sCreditsEntry_ExecutiveDirector,
        &sCreditsEntry_SatoshiTajiri,
        _,
        _,
    },
    [PAGE_EXECUTIVE_PRODUCERS_1] = {
        _,
        &sCreditsEntry_ExecProducers,
        &sCreditsEntry_SatoruIwata,
        _,
        _,
    },
    [PAGE_EXECUTIVE_PRODUCERS_2] = {
        _,
        &sCreditsEntry_ExecProducers,
        &sCreditsEntry_TsunekazIshihara,
        _,
        _,
    },
};
#undef _
