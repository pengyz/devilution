//HEADER_GOES_HERE
#ifndef __GAMEMENU_H__
#define __GAMEMENU_H__

void gamemenu_previous();
void gamemenu_enable_single();
void gamemenu_enable_multi();
void gamemenu_off();
void gamemenu_handle_previous();
void gamemenu_new_game();
void gamemenu_quit_game();
void gamemenu_load_game();
void gamemenu_save_game();
void gamemenu_restart_town();
void gamemenu_options();
void gamemenu_get_music();
void gamemenu_sound_music_toggle(char **names, TMenuItem *menu_item, int gamma);
void gamemenu_get_sound();
void gamemenu_get_color_cycling();
void gamemenu_get_gamma();
void gamemenu_music_volume(int a1);
int gamemenu_slider_music_sound(TMenuItem *menu_item);
void gamemenu_sound_volume(int a1);
void gamemenu_gamma(int a1);
int gamemenu_slider_gamma();
void gamemenu_color_cycling();

/* rdata */
extern TMenuItem sgSingleMenu[6];
extern TMenuItem sgMultiMenu[5];
extern TMenuItem sgOptionMenu[6];
extern char *music_toggle_names[];
extern char *sound_toggle_names[];
extern char *color_cycling_toggle_names[];

#endif /* __GAMEMENU_H__ */
