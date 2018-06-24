//HEADER_GOES_HERE
#ifndef __DEBUG_H__
#define __DEBUG_H__

extern void *pSquareCel;
extern char dMonsDbg[17][112][112];
extern char dFlagDbg[17][112][112];

void LoadDebugGFX();
void FreeDebugGFX();
void CheckDungeonClear();
#ifdef _DEBUG
void GiveGoldCheat();
void StoresCheat();
void TakeGoldCheat();
void MaxSpellsCheat();
void PrintDebugPlayer(bool bNextPlayer);
void PrintDebugQuest();
void PrintDebugMonster(int m);
void GetDebugMonster();
void NextDebugMonster();
#endif

#endif /* __DEBUG_H__ */
