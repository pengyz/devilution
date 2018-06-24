//HEADER_GOES_HERE
#ifndef __OBJECTS_H__
#define __OBJECTS_H__

extern int trapid; // weak
extern int trapdir; // weak
extern int pObjCels[40];
extern char ObjFileList[40];
extern int objectactive[127];
extern int nobjects; // idb
extern int leverid; // idb
extern int objectavail[127];
extern ObjectStruct object[127];
extern int InitObjFlag; // weak
extern int numobjfiles; // weak

void InitObjectGFX();
void FreeObjectGFX();
bool RndLocOk(int xp, int yp);
void InitRndLocObj(int min, int max, int objtype);
void InitRndLocBigObj(int min, int max, int objtype);
void InitRndLocObj5x5(int min, int max, int objtype);
void ClrAllObjects();
void AddTortures();
void AddCandles();
void AddBookLever(int lx1, int ly1, int lx2, int ly2, int x1, int y1, int x2, int y2, int msg);
void InitRndBarrels();
void AddL1Objs(int x1, int y1, int x2, int y2);
void AddL2Objs(int x1, int y1, int x2, int y2);
void AddL3Objs(int x1, int y1, int x2, int y2);
bool WallTrapLocOk(int xp, int yp);
void AddL2Torches();
bool TorchLocOK(int xp, int yp);
void AddObjTraps();
void AddChestTraps();
void LoadMapObjects(unsigned char *pMap, int startx, int starty, int x1, int y1, int w, int h, int leveridx);
void LoadMapObjs(unsigned char *pMap, int startx, int starty);
void AddDiabObjs();
void AddStoryBooks();
void AddHookedBodies(int freq);
void AddL4Goodies();
void AddLazStand();
void InitObjects(int a1);
void SetMapObjects(char *pMap, int startx, int starty);
void DeleteObject(int oi, int i);
void SetupObject(int i, int x, int y, int ot);
void SetObjMapRange(int i, int x1, int y1, int x2, int y2, int v);
void SetBookMsg(int i, int msg);
void AddL1Door(int i, int x, int y, int ot);
void AddSCambBook(int i);
void AddChest(int i, int t);
void AddL2Door(int i, int x, int y, int ot);
void AddL3Door(int i, int x, int y, int ot);
void AddSarc(int i);
void AddFlameTrap(int i);
void AddFlameLvr(int i);
void AddTrap(int i);
void AddObjLight(int i, int r);
void AddBarrel(int i);
void AddShrine(int i);
void AddBookcase(int i);
void AddPurifyingFountain(int i);
void AddArmorStand(int i);
void AddDecap(int i);
void AddVilebook(int i);
void AddMagicCircle(int i);
void AddBookstand(int i);
void AddPedistal(int i);
void AddStoryBook(int i);
void AddWeaponRack(int i);
void AddTorturedBody(int i);
void GetRndObjLoc(int randarea, int *xx, int *yy);
void AddMushPatch();
void AddSlainHero();
void AddObject(int ot, int ox, int oy);
void Obj_Light(int i, int lr);
void Obj_Circle(int i);
void Obj_StopAnim(int i);
void Obj_Door(int i);
void Obj_Sarc(int i);
void ActivateTrapLine(int ttype, int tid);
void Obj_FlameTrap(int i);
void Obj_Trap(int i);
void Obj_BCrossDamage(int i);
void ProcessObjects();
void ObjSetMicro(int dx, int dy, int pn);
void objects_set_door_piece(int x, int y);
void ObjSetMini(int x, int y, int v);
void ObjL1Special(int x1, int y1, int x2, int y2);
void ObjL2Special(int x1, int y1, int x2, int y2);
void DoorSet(int oi, int dx, int dy);
void RedoPlayerVision();
void OperateL1RDoor(int pnum, int oi, unsigned char sendflag);
void OperateL1LDoor(int pnum, int oi, unsigned char sendflag);
void OperateL2RDoor(int pnum, int oi, unsigned char sendflag);
void OperateL2LDoor(int pnum, int oi, unsigned char sendflag);
void OperateL3RDoor(int pnum, int oi, unsigned char sendflag);
void OperateL3LDoor(int pnum, int oi, unsigned char sendflag);
void MonstCheckDoors(int m);
void ObjChangeMap(int x1, int y1, int x2, int y2);
void ObjChangeMapResync(int x1, int y1, int x2, int y2);
void OperateL1Door(int pnum, int i, unsigned char sendflag);
void OperateLever(int pnum, int i);
void OperateBook(int pnum, int i);
void OperateBookLever(int pnum, int i);
void OperateSChambBk(int pnum, int i);
void OperateChest(int pnum, int i, unsigned char sendmsg);
void OperateMushPatch(int pnum, int i);
void OperateInnSignChest(int pnum, int i);
void OperateSlainHero(int pnum, int i, unsigned char sendmsg);
void OperateTrapLvr(int i);
void OperateSarc(int pnum, int i, unsigned char sendmsg);
void OperateL2Door(int pnum, int i, unsigned char sendflag);
void OperateL3Door(int pnum, int i, unsigned char sendflag);
void OperatePedistal(int pnum, int i);
void TryDisarm(int pnum, int i);
int ItemMiscIdIdx(int imiscid);
void OperateShrine(int pnum, int i, int sType);
void OperateSkelBook(int pnum, int i, unsigned char sendmsg);
void OperateBookCase(int pnum, int i, unsigned char sendmsg);
void OperateDecap(int pnum, int i, unsigned char sendmsg);
void OperateArmorStand(int pnum, int i, unsigned char sendmsg);
int FindValidShrine(int i);
void OperateGoatShrine(int pnum, int i, int sType);
void OperateCauldron(int pnum, int i, int sType);
bool OperateFountains(int pnum, int i);
void OperateWeaponRack(int pnum, int i, unsigned char sendmsg);
void OperateStoryBook(int pnum, int i);
void OperateLazStand(int pnum, int i);
void OperateObject(int pnum, int i, unsigned char TeleFlag);
void SyncOpL1Door(int pnum, int cmd, int i);
void SyncOpL2Door(int pnum, int cmd, int i);
void SyncOpL3Door(int pnum, int cmd, int i);
void SyncOpObject(int pnum, int cmd, int i);
void BreakCrux(int i);
void BreakBarrel(int pnum, int i, int dam, unsigned char forcebreak, int sendmsg);
void BreakObject(int pnum, int oi);
void SyncBreakObj(int pnum, int oi);
void SyncL1Doors(int i);
void SyncCrux(int i);
void SyncLever(int i);
void SyncQSTLever(int i);
void SyncPedistal(int i);
void SyncL2Doors(int i);
void SyncL3Doors(int i);
void SyncObjectAnim(int o);
void GetObjectStr(int i);

/* rdata */

extern int ObjTypeConv[113];
extern ObjDataStruct AllObjects[99];
extern char *ObjMasterLoadList[56];
extern int bxadd[8];
extern int byadd[8];
extern char *shrinestrs[26];
extern unsigned char shrinemin[26];
extern unsigned char shrinemax[26];
extern unsigned char shrineavail[26];
extern char *StoryBookName[9];
extern int StoryText[3][3];

#endif /* __OBJECTS_H__ */
