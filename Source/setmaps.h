//HEADER_GOES_HERE
#ifndef __SETMAPS_H__
#define __SETMAPS_H__

int ObjIndex(int x, int y);
void AddSKingObjs();
void AddSChamObjs();
void AddVileObjs();
void DRLG_SetMapTrans(char *sFileName);
void LoadSetMap();

/* rdata */
extern RECT8 QSRects[32];
extern char *quest_level_names[];

#endif /* __SETMAPS_H__ */
