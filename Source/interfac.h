//HEADER_GOES_HERE
#ifndef __INTERFAC_H__
#define __INTERFAC_H__

extern void *sgpBackCel;
extern float interfac_cpp_init_value;
extern int sgdwProgress;
extern int progress_id; // idb

void interfac_cpp_init();
void interface_msg_pump();
bool IncProgress();
void DrawCutscene();
void DrawProgress(int screen_x, int screen_y, int progress_id);
void ShowProgress(int uMsg);
void FreeInterface();
void InitCutscene(int interface_mode);

/* data */

extern int interfac_inf; // weak
extern unsigned char progress_bar_colours[3];
extern POINT32 progress_bar_screen_pos[3];

#endif /* __INTERFAC_H__ */
