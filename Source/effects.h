//HEADER_GOES_HERE
#ifndef __EFFECTS_H__
#define __EFFECTS_H__

extern int effects_cpp_init_value; // weak
extern int sfxdelay; // weak
extern int sfxdnum;
extern void *sfx_stream;
extern TSFX *sfx_data_cur;

void effects_cpp_init();
bool effect_is_playing(int nSFX);
void sfx_stop();
void InitMonsterSND(int monst);
void FreeEffects();
void PlayEffect(int i, int mode);
int calc_snd_position(int x, int y, int *plVolume, int *plPan);
void PlaySFX(int psfx);
void PlaySFX_priv(TSFX *pSFX, char loc, int x, int y);
void stream_play(TSFX *pSFX, int lVolume, int lPan);
int RndSFX(int psfx);
void PlaySfxLoc(int psfx, int x, int y);
void FreeMonsterSnd();
void sound_stop();
void sound_update();
void effects_cleanup_sfx();
void stream_update();
void priv_sound_init(int bLoadMask);
void sound_init();
void __stdcall effects_play_sound(char *snd_file);

/* data */

extern int effects_inf; // weak
extern char monster_action_sounds[]; // idb

/* rdata */

extern TSFX sgSFX[858];

#endif /* __EFFECTS_H__ */
