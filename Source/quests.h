//HEADER_GOES_HERE
#ifndef __QUESTS_H__
#define __QUESTS_H__

extern int qtopline; // idb
extern int questlog; // weak
extern void *pQLogCel;
extern QuestStruct quests[16];
extern int qline; // weak
extern int qlist[16];
extern int numqlines; // weak
extern int WaterDone; // idb
extern int ReturnLvlY; // idb
extern int ReturnLvlX; // idb
extern int ReturnLvlT; // idb
extern int ALLQUESTS; // idb
extern int ReturnLvl; // idb

void InitQuests();
void CheckQuests();
bool ForceQuests();
bool QuestStatus(int i);
void CheckQuestKill(int m, unsigned char sendmsg);
void DrawButcher();
void DrawSkelKing(int quest_id, int xx, int yy);
void DrawWarLord(int xx, int yy);
void DrawSChamber(int quest_id, int xx, int yy);
void DrawLTBanner(int xx, int yy);
void DrawBlind(int xx, int yy);
void DrawBlood(int xx, int yy);
void DRLG_CheckQuests(int xx, int yy);
void SetReturnLvlPos();
void GetReturnLvlPos();
void ResyncMPQuests();
void ResyncQuests();
void PrintQLString(int x, int y, unsigned char cjustflag, char *str, int col);
void DrawQuestLog();
void StartQuestlog();
void QuestlogUp();
void QuestlogDown();
void QuestlogEnter();
void QuestlogESC();
void SetMultiQuest(int q, int s, unsigned char l, int v1);

/* rdata */
extern QuestData questlist[16];
extern char questxoff[7];
extern char questyoff[7];
extern char *questtrigstr[5];
extern int QuestGroup1[3];
extern int QuestGroup2[3];
extern int QuestGroup3[3];
extern int QuestGroup4[2];

#endif /* __QUESTS_H__ */
