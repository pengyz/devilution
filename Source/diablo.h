//HEADER_GOES_HERE
#ifndef __DIABLO_H__
#define __DIABLO_H__

LRESULT __stdcall DisableInputWndProc(HWND hWnd, int uMsg, int wParam, int lParam);
int __stdcall GM_Game(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


class Diablo{
public:
	~Diablo();
	static Diablo* get();
private:
	Diablo();
	static Diablo* m_Instance;


public:
	HWND ghMainWnd;
	int glMid1Seed[17];
	int glMid2Seed[17];
	int gnLevelTypeTbl[17];
	int MouseY; // idb
	int MouseX; // idb
	bool gbGameLoopStartup; // idb
	int glSeedTbl[17];
	int gbRunGame; // weak
	int glMid3Seed[17];
	int gbRunGameResult; // weak
	int zoomflag; // weak
	int gbProcessPlayers; // weak
	int glEndSeed[17];
	int dword_5256E8; // weak
	HINSTANCE ghInst; // idb
	int DebugMonsters[10];
	char cineflag; // weak
	int drawpanflag; // weak
	int visiondebug; // weak
	int scrollflag; /* unused */
	int light4flag; // weak
	int leveldebug; // weak
	int monstdebug; // weak
	int trigdebug; /* unused */
	int setseed; // weak
	int debugmonsttypes; // weak
	int PauseMode; // weak
	int sgnTimeoutCurs;
	char sgbMouseDown; // weak
	int color_cycle_timer; // weak

public:
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

public:
	/* rdata */
	int fullscreen; // weak
#ifdef _DEBUG
	int showintrodebug;
	int questdebug;
	int debug_mode_key_s;
	int debug_mode_key_w;
	int debug_mode_key_inverted_v;
	int debug_mode_dollar_sign;
	int debug_mode_key_d;
	int debug_mode_key_i;
	int dbgplr;
	int dbgqst;
	int dbgmon;
	int frameflag;
	int frameend;
	int framerate;
	int framestart;
#endif
	int FriendlyMode; // weak
	char *spszMsgTbl[4]; // weak
	char *spszMsgKeyTbl[4]; // weak
};

#endif /* __DIABLO_H__ */
