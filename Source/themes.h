//HEADER_GOES_HERE
#ifndef __THEMES_H__
#define __THEMES_H__

extern int numthemes; // idb
extern bool armorFlag; // weak
extern int ThemeGoodIn[4];
extern bool weaponFlag; // weak
extern bool treasureFlag; // weak
extern bool mFountainFlag; // weak
extern bool cauldronFlag; // weak
extern bool tFountainFlag; // weak
extern int zharlib; // weak
extern int themex; // idb
extern int themey; // idb
extern int themeVar1; // idb
extern ThemeStruct themes[50];
extern bool pFountainFlag; // weak
extern bool bFountainFlag; // weak
extern bool bCrossFlag; // weak

bool TFit_Shrine(int i);
bool TFit_Obj5(int t);
bool TFit_SkelRoom(int t);
bool TFit_GoatShrine(int t);
bool CheckThemeObj3(int xp, int yp, int t, int f);
bool TFit_Obj3(int t);
bool CheckThemeReqs(int t);
bool SpecialThemeFit(int i, int t);
bool CheckThemeRoom(int tv);
void InitThemes();
void HoldThemeRooms();
void PlaceThemeMonsts(int t, int f);
void Theme_Barrel(int t);
void Theme_Shrine(int t);
void Theme_MonstPit(int t);
void Theme_SkelRoom(int t);
void Theme_Treasure(int t);
void Theme_Library(int t);
void Theme_Torture(int t);
void Theme_BloodFountain(int t);
void Theme_Decap(int t);
void Theme_PurifyingFountain(int t);
void Theme_ArmorStand(int t);
void Theme_GoatShrine(int t);
void Theme_Cauldron(int t);
void Theme_MurkyFountain(int t);
void Theme_TearFountain(int t);
void Theme_BrnCross(int t);
void Theme_WeaponRack(int t);
void UpdateL4Trans();
void CreateThemeRooms();

/* rdata */

extern int ThemeGood[4];
extern int trm5x[25];
extern int trm5y[25];
extern int trm3x[9];
extern int trm3y[9];

#endif /* __THEMES_H__ */
