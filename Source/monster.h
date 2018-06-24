//HEADER_GOES_HERE
#ifndef __MONSTER_H__
#define __MONSTER_H__

extern int MissileFileFlag; // weak
extern int monster_cpp_init_value; // weak
extern int monstkills[200];
extern int monstactive[200];
extern int nummonsters;
extern int sgbSaveSoundOn; // weak
extern MonsterStruct monster[200];
extern int totalmonsters; // weak
extern CMonster Monsters[16];
// int END_Monsters_17; // weak
extern int monstimgtot; // weak
extern int uniquetrans;
extern int nummtypes;

void monster_cpp_init();
void InitMonsterTRN(int monst, int special);
void InitLevelMonsters();
int AddMonsterType(int type, int placeflag);
void GetLevelMTypes();
void InitMonsterGFX(int monst);
void ClearMVars(int i);
void InitMonster(int i, int rd, int mtype, int x, int y);
void ClrAllMonsters();
bool MonstPlace(int xp, int yp);
void PlaceMonster(int i, int mtype, int x, int y);
void PlaceUniqueMonst(int uniqindex, int miniontype, int unpackfilesize);
void PlaceQuestMonsters();
void PlaceGroup(int mtype, int num, unsigned char leaderf, int leader);
void LoadDiabMonsts();
void InitMonsters();
void PlaceUniques();
void SetMapMonsters(char *pMap, int startx, int starty);
void DeleteMonster(int i);
int AddMonster(int x, int y, int dir, int mtype, int InMap);
void NewMonsterAnim(int i, AnimStruct *anim, int md);
bool M_Ranged(int i);
bool M_Talker(int i);
void M_Enemy(int i);
int M_GetDir(int i);
void M_CheckEFlag(int i);
void M_StartStand(int i, int md);
void M_StartDelay(int i, int len);
void M_StartSpStand(int i, int md);
void M_StartWalk(int i, int xvel, int yvel, int xadd, int yadd, int EndDir);
void M_StartWalk2(int i, int xvel, int yvel, int a4, int a5, int a6, int a7, int EndDir);
void M_StartWalk3(int i, int xvel, int yvel, int a4, int a5, int a6, int a7, int a8, int a9, int EndDir);
void M_StartAttack(int i);
void M_StartRAttack(int i, int missile_type, int dam);
void M_StartRSpAttack(int i, int missile_type, int dam);
void M_StartSpAttack(int i);
void M_StartEat(int i);
void M_ClearSquares(int i);
void M_GetKnockback(int i);
void M_StartHit(int i, int pnum, int dam);
void M_DiabloDeath(int i, unsigned char sendmsg);
void M2MStartHit(int mid, int i, int dam);
void MonstStartKill(int i, int pnum, unsigned char sendmsg);
void M2MStartKill(int i, int mid);
void M_StartKill(int i, int pnum);
void M_SyncStartKill(int i, int x, int y, int pnum);
void M_StartFadein(int i, int md, unsigned char backwards);
void M_StartFadeout(int i, int md, unsigned char backwards);
void M_StartHeal(int i);
void M_ChangeLightOffset(int monst);
int M_DoStand(int i);
int M_DoWalk(int i);
int M_DoWalk2(int i);
int M_DoWalk3(int i);
void M_TryM2MHit(int i, int mid, int hper, int mind, int maxd);
void M_TryH2HHit(int i, int pnum, int Hit, int MinDam, int MaxDam);
int M_DoAttack(int i);
int M_DoRAttack(int i);
int M_DoRSpAttack(int i);
int M_DoSAttack(int i);
int M_DoFadein(int i);
int M_DoFadeout(int i);
int M_DoHeal(int i);
int M_DoTalk(int i);
void M_Teleport(int i);
int M_DoGotHit(int i);
void M_UpdateLeader(int i);
void DoEnding();
void PrepDoEnding();
int M_DoDeath(int i);
int M_DoSpStand(int i);
int M_DoDelay(int i);
int M_DoStone(int i);
void M_WalkDir(int i, int md);
void GroupUnity(int i);
bool M_CallWalk(int i, int md);
bool M_PathWalk(int i);
bool M_CallWalk2(int i, int md);
bool M_DumbWalk(int i, int md);
bool M_RoundWalk(int i, int md, int *dir);
void MAI_Zombie(int i);
void MAI_SkelSd(int i);
bool MAI_Path(int i);
void MAI_Snake(int i);
void MAI_Bat(int i);
void MAI_SkelBow(int i);
void MAI_Fat(int i);
void MAI_Sneak(int i);
void MAI_Fireman(int i);
void MAI_Fallen(int i);
void MAI_Cleaver(int i);
void MAI_Round(int i, unsigned char special);
void MAI_GoatMc(int i);
void MAI_Ranged(int i, int missile_type, unsigned char special);
void MAI_GoatBow(int i);
void MAI_Succ(int i);
void MAI_AcidUniq(int i);
void MAI_Scav(int i);
void MAI_Garg(int i);
void MAI_RoundRanged(int i, int missile_type, unsigned char checkdoors, int dam, int lessmissiles);
void MAI_Magma(int i);
void MAI_Storm(int i);
void MAI_Acid(int i);
void MAI_Diablo(int i);
void MAI_RR2(int i, int mistype, int dam);
void MAI_Mega(int i);
void MAI_Golum(int i);
void MAI_SkelKing(int i);
void MAI_Rhino(int i);
void MAI_Counselor(int i);
void MAI_Garbud(int i);
void MAI_Zhar(int i);
void MAI_SnotSpil(int i);
void MAI_Lazurus(int i);
void MAI_Lazhelp(int i);
void MAI_Lachdanan(int i);
void MAI_Warlord(int i);
void DeleteMonsterList();
void ProcessMonsters();
void FreeMonsters();
bool DirOK(int i, int mdir);
bool PosOkMissile(int x, int y);
bool CheckNoSolid(int x, int y);
bool LineClearF(bool (*Clear)(int, int), int x1, int y1, int x2, int y2);
bool LineClear(int x1, int y1, int x2, int y2);
bool LineClearF1(bool (*Clear)(int, int, int), int monst, int x1, int y1, int x2, int y2);
void SyncMonsterAnim(int i);
void M_FallenFear(int x, int y);
void PrintMonstHistory(int mt);
void PrintUniqueHistory();
void MissToMonst(int i, int x, int y);
bool PosOkMonst(int i, int x, int y);
bool PosOkMonst2(int i, int x, int y);
bool PosOkMonst3(int i, int x, int y);
bool IsSkel(int mt);
bool IsGoat(int mt);
int M_SpawnSkel(int x, int y, int dir);
void ActivateSpawn(int i, int x, int y, int dir);
bool SpawnSkeleton(int ii, int x, int y);
int PreSpawnSkeleton();
void TalktoMonster(int i);
void SpawnGolum(int i, int x, int y, int mi);
bool CanTalkToMonst(int m);
bool CheckMonsterHit(int m, bool *ret);
int encode_enemy(int m);
void decode_enemy(int m, int enemy);

/* data */

extern int monster_inf; // weak
extern char plr2monst[9];
extern unsigned char counsmiss[4];

/* rdata */

extern MonsterData monsterdata[112];
extern char MonstConvTbl[128];
extern unsigned char MonstAvailTbl[112];
extern UniqMonstStruct UniqMonst[98];
extern int MWVel[24][3];
extern char animletter[7];
extern int left[8];
extern int right[8];
extern int opposite[8];
extern int offset_x[8];
extern int offset_y[8];

/* unused */
extern int rnd5[4];
extern int rnd10[4];
extern int rnd20[4];
extern int rnd60[4];
//

extern void (*AiProc[])(int i);

#endif /* __MONSTER_H__ */
