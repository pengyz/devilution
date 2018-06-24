//HEADER_GOES_HERE
#ifndef __AUTOMAP_H__
#define __AUTOMAP_H__

extern short automaptype[512];
extern int AMdword_4B7E40; // weak
extern int AMdword_4B7E44; // weak
extern bool automapflag; // idb
extern char AMbyte_4B7E4C[32];
extern char automapview[40][40];
extern int AutoMapScale; // idb
extern int AutoMapXOfs; // weak
extern int AutoMapYOfs; // weak
extern int AutoMapPosBits; // weak
extern int AutoMapXPos; // weak
extern int AutoMapYPos; // weak
extern int AMPlayerX; // weak
extern int AMPlayerY; // weak

void InitAutomapOnce();
void InitAutomap();
void StartAutomap();
void AutomapUp();
void AutomapDown();
void AutomapLeft();
void AutomapRight();
void AutomapZoomIn();
void AutomapZoomOut();
void DrawAutomap();
void DrawAutomapType(int screen_x, int screen_y, short automap_type);
void DrawAutomapPlr();
short GetAutomapType(int tx, int ty, bool view);
void DrawAutomapGame();
void SetAutomapView(int x, int y);
void AutomapZoomReset();

#endif /* __AUTOMAP_H__ */
