//HEADER_GOES_HERE
#ifndef __SCROLLRT_H__
#define __SCROLLRT_H__

extern int light_table_index; // weak
extern int screen_y_times_768[1024];
extern int scrollrt_cpp_init_value; // weak
extern unsigned int sgdwCursWdtOld; // idb
extern int sgdwCursX; // idb
extern int sgdwCursY; // idb
extern int screen_buf_end; // weak
extern int sgdwCursHgt;
extern int level_cel_block; // weak
extern int sgdwCursXOld; // idb
extern int sgdwCursYOld; // idb
extern char arch_draw_type; // weak
extern DDSURFACEDESC DDS_desc;
extern int cel_transparency_active; // weak
extern int level_piece_id; // weak
extern int sgdwCursWdt;
extern int (*DrawPlrProc)(int player_num, int x, int y, int screen_x, int screen_y, void *cl2_buf, int frame, int frame_width, int a9, int a10);
extern char cursor_draw_back_buffer[8192];
extern int draw_monster_num; // weak
extern int sgdwCursHgtOld; // idb

void scrollrt_cpp_init();
void ClearCursor();
void DrawMissile(int x, int y, int sx, int sy, int a5, int a6, int del_flag);
void DrawClippedMissile(int x, int y, int sx, int sy, int a5, int a6, int a7);
void DrawDeadPlayer(int x, int y, int sx, int sy, int a5, int a6, bool clipped);
void DrawPlayer(int pnum, int x, int y, int px, int py, int animdata, int animframe, int animwidth, int a9, int a10);
void DrawClippedPlayer(int pnum, int x, int y, int px, int py, int animdata, int animframe, int animwidth, int a9, int a10);
void DrawView(int StartX, int StartY);
void DrawGame(int x, int y);
void scrollrt_draw_lower(int x, int y, int sx, int sy, int a5, int some_flag);
void scrollrt_draw_clipped_dungeon(char *a1, int sx, int sy, int a4, int a5, int a6);
void DrawClippedMonster(int x, int y, int a3, int a4, int mon_id, int a6, int a7);
void DrawClippedObject(int x, int y, int a3, int a4, int pre_flag, int a6, int dir);
void scrollrt_draw_clipped_e_flag(char *buffer, int x, int y, int a4, int a5);
void scrollrt_draw_lower_2(int x, int y, int sx, int sy, int a5, int a6, int some_flag);
void scrollrt_draw_clipped_dungeon_2(char *buffer, int x, int y, int a4, int a5, int sx, int sy, int me_flag);
void scrollrt_draw_clipped_e_flag_2(char *buffer, int x, int y, int a4, signed int a5, int sx, int sy);
void scrollrt_draw_upper(int x, int y, int sx, int sy, int a5, int a6, int some_flag);
void scrollrt_draw_dungeon(char *buffer, int x, int y, int a4, int a5, int sx, int sy, int me_flag);
void DrawMonster(int x, int y, int a3, int a4, int mon_id, int a6, int a7);
void DrawObject(int x, int y, int a3, int a4, int pre_flag, int a6, int dir);
void scrollrt_draw_e_flag(char *buffer, int x, int y, int a4, int a5, int sx, int sy);
void DrawZoom(int x, int y);
void ClearScreenBuffer();
#ifdef _DEBUG
void ScrollView();
void EnableFrameCount();
#endif
void scrollrt_draw_game_screen(bool draw_cursor);
void scrollrt_draw_cursor_back_buffer();
void scrollrt_draw_cursor_item();
void DrawMain(int dwHgt, int draw_desc, int draw_hp, int draw_mana, int draw_sbar, int draw_btn);
#ifdef _DEBUG
void DrawFPS();
#endif
void DoBlitScreen(int dwX, int dwY, int dwWdt, int dwHgt);
void DrawAndBlit();

/* data */

extern int scrollrt_inf; // weak

/* rdata */

/* used in 1.00 debug */
extern char *szMonModeAssert[18];
extern char *szPlrModeAssert[12];

#endif /* __SCROLLRT_H__ */
