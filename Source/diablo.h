//HEADER_GOES_HERE
#ifndef __DIABLO_H__
#define __DIABLO_H__

extern int diablo_cpp_init_value; // weak
extern HWND ghMainWnd;
extern int glMid1Seed[17];
extern int glMid2Seed[17];
extern int gnLevelTypeTbl[17];
extern int MouseY; // idb
extern int MouseX; // idb
extern bool gbGameLoopStartup; // idb
extern int glSeedTbl[17];
extern int gbRunGame; // weak
extern int glMid3Seed[17];
extern int gbRunGameResult; // weak
extern int zoomflag; // weak
extern int gbProcessPlayers; // weak
extern int glEndSeed[17];
extern int dword_5256E8; // weak
extern HINSTANCE ghInst; // idb
extern int DebugMonsters[10];
extern char cineflag; // weak
extern int drawpanflag; // weak
extern int visiondebug; // weak
extern int scrollflag; /* unused */
extern int light4flag; // weak
extern int leveldebug; // weak
extern int monstdebug; // weak
extern int trigdebug; /* unused */
extern int setseed; // weak
extern int debugmonsttypes; // weak
extern int PauseMode; // weak
extern int sgnTimeoutCurs;
extern char sgbMouseDown; // weak
extern int color_cycle_timer; // weak

void diablo_cpp_init();
void FreeGameMem();
int diablo_init_menu(int a1, int bSinglePlayer);
void run_game_loop(int uMsg);
void start_game(int uMsg);
void free_game();
bool diablo_get_not_running();
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd);
void diablo_parse_flags(char *args);
void diablo_init_screen();
HWND diablo_find_window(LPCSTR lpClassName);
void diablo_reload_process(HMODULE hModule);
int PressEscKey();
LRESULT __stdcall DisableInputWndProc(HWND hWnd, int uMsg, int wParam, int lParam);
int __stdcall GM_Game(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool LeftMouseDown(int a1);
bool TryIconCurs();
void LeftMouseUp();
void RightMouseDown();
void j_gmenu_on_mouse_move(LPARAM lParam);
bool PressSysKey(int wParam);
void diablo_hotkey_msg(int dwMsg);
void ReleaseKey(int vkey);
void PressKey(int vkey);
void diablo_pause_game();
void PressChar(int vkey);
void LoadLvlGFX();
void LoadAllGFX();
void CreateLevel(int lvldir);
void LoadGameLevel(bool firstflag, int lvldir);
void game_loop(bool startup);
void game_logic();
void timeout_cursor(bool timeout);
void diablo_color_cyc_logic();

/* data */

extern int diablo_inf; // weak

/* rdata */

extern int fullscreen; // weak
#ifdef _DEBUG
extern int showintrodebug;
extern int questdebug;
extern int debug_mode_key_s;
extern int debug_mode_key_w;
extern int debug_mode_key_inverted_v;
extern int debug_mode_dollar_sign;
extern int debug_mode_key_d;
extern int debug_mode_key_i;
extern int dbgplr;
extern int dbgqst;
extern int dbgmon;
extern int frameflag;
extern int frameend;
extern int framerate;
extern int framestart;
#endif
extern int FriendlyMode; // weak
extern char *spszMsgTbl[4]; // weak
extern char *spszMsgKeyTbl[4]; // weak

#endif /* __DIABLO_H__ */
