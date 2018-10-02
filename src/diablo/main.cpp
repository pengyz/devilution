#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <windows.h>

#include "engine/gameengine.h"
#include "engine/window.h"
#include "gui/gamegui.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include "GLFW/glfw3native.h"

#include "defs.h"
#include "structs.h"
#include "diablo.h"
#include "restrict.h"
#include "appfat.h"
#include "resource.h"
#include "encrypt.h"
#include "fault.h"
#include "init.h"
#include "effects.h"
#include "palette.h"
#include "movie.h"
#include "mainmenu.h"
#include "../3rdParty/DiabloUI/diabloui.h"
#include "../3rdParty/Storm/Source/storm.h"


//#include "restrict.h"
//#include "appfat.h"


int main(int argc, char** argv)
{
	//Engine::GameEngine engine(argc, argv);
	//auto mainWindow = engine.initGameWindow(u8"DIABLO", 100, 100, 1024, 768);
	//mainWindow->setResizable(true);
	//assert(engine.initOpenGLFunctions());
	//assert(engine.initWindowGUI());
	////assert(engine.initFont("F:/workspace/devilution/extern/DroidSansFallback.ttf", 18));

	//HWND hWnd = glfwGetWin32Window(mainWindow->getNativeWindow());
	//HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE); // esi
	char Filename[260]; // [esp+8h] [ebp-10Ch]
	char value_name[8]; // [esp+10Ch] [ebp-8h]

	ghInst = /*hInstance*/NULL;
	/*if (RestrictedTest())
		ErrOkDlg(IDD_DIALOG10, 0, "C:\\Src\\Diablo\\Source\\DIABLO.CPP", 877);*/
	if (ReadOnlyTest()) {
		if (!GetModuleFileName(ghInst, Filename, 0x104u))
			*Filename = '\0';
		DirErrorDlg(Filename);
	}
	ShowCursor(FALSE);
	srand(GetTickCount());
	encrypt_init_lookup_table();
	exception_get_filter();
	if (!diablo_find_window("DIABLO") && diablo_get_not_running()) {
		diablo_init_screen();
		diablo_parse_flags("");
		init_create_window(1);
		sound_init();
		UiInitialize();
#ifdef _DEBUG
		if (showintrodebug)
			play_movie("gendata\\logo.smk", 1);
#else
		play_movie("gendata\\logo.smk", 1);
#endif
		strcpy(value_name, "Intro");
		/*if (!SRegLoadValue("Diablo", value_name, 0, (int *)&hInstance))
			hInstance = (HINSTANCE)1;
		if (hInstance)*/
		play_movie("gendata\\diablo1.smk", 1);
		SRegSaveValue("Diablo", value_name, 0, 0);
#ifdef _DEBUG
		if (showintrodebug) {
			UiTitleDialog(7);
			BlackPalette();
		}
#else
		UiTitleDialog(7);
		BlackPalette();
#endif

		BlackPalette();
		gbMaxPlayers = 1;
		{
			int gameStartMode; // ecx
			int pfExitProgram; // [esp+Ch] [ebp-4h]

			byte_678640 = 1;
			while (1) {
				pfExitProgram = 0;
				dword_5256E8 = 0;
				if (!NetInit(true, &pfExitProgram))
					break;
				byte_678640 = 0;

				//initialize
				InitLevels();
				InitQuests();
				InitPortals();
				InitDungMsgs(myplr);
				bool isNewGame = false;
				if ((isNewGame || !*(_DWORD *)&gbValidSaveFile)
					&& (!*(_DWORD *)&gbValidSaveFile)
					|| (gameStartMode = WM_DIABLOADGAME, !dword_5256E8)) {
					gameStartMode = WM_DIABNEWGAME;
				}
				/*run_game_loop(gameStartMode);*/
				{
					//int v3; // eax
					bool v5; // zf
					//int v6; // eax
					signed int v7; // [esp+8h] [ebp-24h]
					WNDPROC saveProc; // [esp+Ch] [ebp-20h]
					struct tagMSG msg; // [esp+10h] [ebp-1Ch]

					nthread_ignore_mutex(1);
					start_game(gameStartMode);
					saveProc = SetWindowProc(GM_Game);
					control_update_life_mana();
					msg_process_net_packets();
					gbRunGame = 1;
					gbProcessPlayers = 1;
					gbRunGameResult = 1;
					drawpanflag = 255;
					DrawAndBlit();
					PaletteFadeIn(8);
					drawpanflag = 255;
					gbGameLoopStartup = 1;
					nthread_ignore_mutex(0);
					while (gbRunGame) {
						diablo_color_cyc_logic();
						if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
							SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL);
							while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
								if (msg.message == WM_QUIT) {
									gbRunGameResult = 0;
									gbRunGame = 0;
									break;
								}
								TranslateMessage(&msg);
								DispatchMessage(&msg);
							}
							if (!gbRunGame || (v7 = 1, !nthread_has_500ms_passed()))
								v7 = 0;
							SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);
							v5 = v7 == 0;
						} else {
							//_LOBYTE(v6) = nthread_has_500ms_passed();
							v5 = nthread_has_500ms_passed() == 0;
						}
						if (!v5) {
							multi_process_network_packets();
							game_loop(gbGameLoopStartup);
							msgcmd_send_chat();
							gbGameLoopStartup = 0;
							DrawAndBlit();
						}
#ifdef SLEEP
						Sleep(1);
#endif
					}
					if ((unsigned char)gbMaxPlayers > 1u)
						pfile_write_hero();
					pfile_flush_W();
					PaletteFadeOut(8);
					SetCursor(0);
					ClearScreenBuffer();
					drawpanflag = 255;
					scrollrt_draw_game_screen(1);
					SetWindowProc(saveProc);
					free_game();
					if (cineflag) {
						cineflag = 0;
						DoEnding();
					}
				}
				NetClose();
				pfile_create_player_description(0, 0);
				if (!gbRunGameResult)
					goto LABEL_11;
			}
			gbRunGameResult = pfExitProgram == 0;
		LABEL_11:
			SNetDestroy();
			return gbRunGameResult;
		}

		mainmenu_loop();
		UiDestroy();
		SaveGamma();
		if (ghMainWnd) {
			Sleep(300);
			DestroyWindow(ghMainWnd);
		}
	}
	return 0;



	//return engine.exec();
}
