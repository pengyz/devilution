//HEADER_GOES_HERE
#ifndef __LIGHTING_H__
#define __LIGHTING_H__

extern LightListStruct VisionList[32];
extern char lightactive[32];
extern LightListStruct LightList[32];
extern int numlights;
extern char dung_map_radius[2048]; /* char [16][128] */
extern int dovision; // weak
extern int numvision;
extern char lightmax; // weak
extern int dolighting; // weak
extern char dung_map_rgba[16384]; /* int [64][64] short [64][128] char [64][256] */
extern int visionid;
extern char *pLightTbl; /* todo: struct? */
extern int lightflag; // weak

void SetLightFX(int *x, int *y, short *s_r, short *s_g, int *s_b, int *d_r, int *d_g, int *d_b);
void DoLighting(int nXPos, int nYPos, int nRadius, int Lnum);
void DoUnLight(int nXPos, int nYPos, int nRadius);
void DoUnVision(int nXPos, int nYPos, int nRadius);
void DoVision(int nXPos, int nYPos, int nRadius, unsigned char doautomap, int visible);
void FreeLightTable();
void InitLightTable();
void MakeLightTable();
#ifdef _DEBUG
void ToggleLighting();
#endif
void InitLightMax();
void InitLighting();
int AddLight(int x, int y, int r);
void AddUnLight(int i);
void ChangeLightRadius(int i, int r);
void ChangeLightXY(int i, int x, int y);
void ChangeLightOff(int i, int x, int y);
void ChangeLight(int i, int x, int y, int r);
void ProcessLightList();
void SavePreLighting();
void InitVision();
int AddVision(int x, int y, int r, bool mine);
void ChangeVisionRadius(int id, int r);
void ChangeVisionXY(int id, int x, int y);
void ProcessVisionList();
void lighting_color_cycling();

/* rdata */

extern CircleCoord CrawlTable;
extern void *pCrawlTable[19];
extern unsigned char vCrawlTable[23][30];
extern unsigned char byte_49463C[18][18];
extern unsigned char RadiusAdj[23];

#endif /* __LIGHTING_H__ */
