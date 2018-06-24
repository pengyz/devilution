//HEADER_GOES_HERE
#ifndef __PALETTE_H__
#define __PALETTE_H__

extern PALETTEENTRY logical_palette[256];
extern int palette_cpp_init_value; // weak
extern PALETTEENTRY system_palette[256];
extern PALETTEENTRY orig_palette[256];
extern UINT gdwPalEntries;

void palette_cpp_init();
void palette_save_gamme();
void palette_init();
void palette_load_gamma();
void LoadSysPal();
void LoadPalette(char *pszFileName);
void LoadRndLvlPal(int l);
void ResetPal();
void palette_inc_gamma();
void palette_update();
void palette_apply_gamma_correction(PALETTEENTRY *dst, PALETTEENTRY *src, int n);
void palette_dec_gamma();
int palette_update_gamma(int gamma);
void BlackPalette();
void SetFadeLevel(int brightness);
void PaletteFadeIn(int fr);
void PaletteFadeOut(int fr);
void palette_update_caves();
void palette_update_quest_palette(int n);
bool palette_get_colour_cycling();
void palette_set_color_cycling(bool enabled);

/* data */

extern int palette_inf; // weak

/* rdata */

extern int gamma_correction; // idb
extern int color_cycling_enabled; // idb
extern bool sgbFadedIn;

#endif /* __PALETTE_H__ */
