//HEADER_GOES_HERE

#include "../types.h"

char chr_name_str[16];

/* rdata */

int menu_music_track_id = 5; // idb

void __cdecl mainmenu_refresh_music()
{
    int tmpMenuMusicId = menu_music_track_id;

    music_start(tmpMenuMusicId);
    do
    {
        if (++tmpMenuMusicId == 6)
            tmpMenuMusicId = 0;
    } while (!tmpMenuMusicId || tmpMenuMusicId == 1);
    menu_music_track_id = tmpMenuMusicId;
}

void __stdcall mainmenu_create_hero(char *szUserName, char *a2)
{
    if (UiValidPlayerName(szUserName))
        pfile_create_save_file(szUserName, a2);
}

int __stdcall mainmenu_select_hero_dialog(int u1, int u2, int u3, int u4, int mode, char *cname, int clen, char *cdesc, int cdlen, int *multi) /* fix args */
{
    int v10; // eax
    int a6; // [esp+8h] [ebp-8h]
    int a5; // [esp+Ch] [ebp-4h]

    a6 = 1;
    a5 = 0;
    if (gbMaxPlayers == 1)
    {
        if (!UiSelHeroSingDialog(
            pfile_ui_set_hero_infos,
            pfile_ui_save_create,
            pfile_delete_save,
            pfile_ui_set_class_stats,
            &a5,
            chr_name_str,
            &gnDifficulty))
            TermMsg("Unable to display SelHeroSing");
        if (a5 == 2)
        {
            dword_5256E8 = 1;
            goto LABEL_6;
        }
        dword_5256E8 = 0;
    }
    else if (!UiSelHeroMultDialog(
        pfile_ui_set_hero_infos,
        pfile_ui_save_create,
        pfile_delete_save,
        pfile_ui_set_class_stats,
        &a5,
        &a6,
        chr_name_str))
    {
        TermMsg("Can't load multiplayer dialog");
    }
    if (a5 == 4)
    {
        SErrSetLastError(1223);
        return 0;
    }
LABEL_6:
    pfile_create_player_description(cdesc, cdlen);
    if (multi)
    {
        if (mode == 'BNET')
            v10 = a6 || !plr[myplr].pBattleNet;
        else
            v10 = a6;
        *multi = v10;
    }
    if (cname)
    {
        if (clen)
            SStrCopy(cname, chr_name_str, clen);
    }
    return 1;
}
// 5256E8: using guessed type int dword_5256E8;
// 679660: using guessed type char gbMaxPlayers;

void __fastcall mainmenu_action(int option)
{
    int iRet; // eax
    bool bExit = false;
    mainmenu_refresh_music();
    while (!bExit && iRet)
    {
        option = 0;
        if (!UiMainMenuDialog("Diablo v1.09", &option, effects_play_sound, 30))
            TermMsg("Unable to display mainmenu");
        switch (option)
        {
            case MAINMENU_SINGLE_PLAYER:
                iRet = mainmenu_single_player();
                break;
            case MAINMENU_MULTIPLAYER:
                iRet = mainmenu_multi_player();
                break;
            case MAINMENU_SHOW_CREDITS:
                UiCreditsDialog(16);
                break;
            case MAINMENU_EXIT_DIABLO:
                bExit = true;
                break;
            case MAINMENU_REPLAY_INTRO:
            case MAINMENU_ATTRACT_MODE:
                if (window_activated)
                    mainmenu_play_intro();
                break;
        }
    }
    music_stop();
}
// 634980: using guessed type int window_activated;

int __cdecl mainmenu_single_player()
{
    gbMaxPlayers = 1;
    return mainmenu_init_menu(1);
}
// 679660: using guessed type char gbMaxPlayers;

int __fastcall mainmenu_init_menu(int a1)
{
    if (a1 == 4)
        return 1;
    music_stop();
    int iRet = diablo_init_menu(a1 != 2, a1 != 3);
    if (iRet)
        mainmenu_refresh_music();
    return iRet;
}

int __cdecl mainmenu_multi_player()
{
    gbMaxPlayers = 4;
    return mainmenu_init_menu(3);
}
// 679660: using guessed type char gbMaxPlayers;

void __cdecl mainmenu_play_intro()
{
    music_stop();
    play_movie("gendata\\diablo1.smk", true);
    mainmenu_refresh_music();
}