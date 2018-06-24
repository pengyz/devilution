//HEADER_GOES_HERE
#ifndef __TOWNERS_H__
#define __TOWNERS_H__

extern int storeflag; // weak
extern int sgnCowMsg; // weak
extern int numtowners; // idb
extern int sgdwCowClicks; // weak
extern int bannerflag; // weak // unused 0x6AAC28
extern int boyloadflag; // weak
extern void *pCowCels; // idb
extern TownerStruct towner[16];

int GetActiveTowner(int t);
void SetTownerGPtrs(void *pData, void **pAnim);
void NewTownerAnim(int tnum, void *pAnim, int numFrames, int Delay);
void InitTownerInfo(int i, int w, bool sel, int t, int x, int y, int ao, int tp);
void InitQstSnds(int i);
void InitSmith();
void InitBarOwner();
void InitTownDead();
void InitWitch();
void InitBarmaid();
void InitBoy();
void InitHealer();
void InitTeller();
void InitDrunk();
void InitCows();
void InitTowners();
void FreeTownerGFX();
void TownCtrlMsg(int i);
void TownBlackSmith();
void TownBarOwner();
void TownDead();
void TownHealer();
void TownStory();
void TownDrunk();
void TownBoy();
void TownWitch();
void TownBarMaid();
void TownCow();
void ProcessTowners();
ItemStruct *PlrHasItem(int pnum, int item, int *i);
void TownerTalk(int t);
void TalkToTowner(int p, int t);
void CowSFX(int pnum);

/* data */

extern int snSFX[3][3];

/* rdata */

extern char AnimOrder[6][148];
extern int TownCowX[3];
extern int TownCowY[3];
extern int TownCowDir[3];
extern int cowoffx[8];
extern int cowoffy[8];
extern QuestTalkData Qtalklist[11];
extern int CowPlaying;

#endif /* __TOWNERS_H__ */
