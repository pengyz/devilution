#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <windows.h>

#include "engine/gameengine.h"
#include "engine/window.h"
#include "gui/gamegui.h"

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
	Engine::GameEngine engine(argc, argv);
	auto mainWindow = engine.initGameWindow(u8"DIABLO", 100, 100, 1024, 768);
	mainWindow->setResizable(true);
	assert(engine.initOpenGLFunctions());
	assert(engine.initWindowGUI());
	//assert(engine.initFont("F:/workspace/devilution/extern/DroidSansFallback.ttf", 18));

	HINSTANCE hInstance = NULL; // esi
	char Filename[260]; // [esp+8h] [ebp-10Ch]
	char value_name[8]; // [esp+10Ch] [ebp-8h]

#ifndef DEBUGGER
	diablo_reload_process(hInstance);
#endif
	ghInst = hInstance;
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
		if (!SRegLoadValue("Diablo", value_name, 0, (int *)&hInstance))
			hInstance = (HINSTANCE)1;
		if (hInstance)
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
		mainmenu_loop();
		UiDestroy();
		SaveGamma();
		if (ghMainWnd) {
			Sleep(300);
			DestroyWindow(ghMainWnd);
		}
	}
	return 0;



	return engine.exec();
}
