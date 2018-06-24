//HEADER_GOES_HERE
#ifndef __MSG_H__
#define __MSG_H__

extern int sgdwOwnerWait; // weak
extern int msg_cpp_init_value; // weak
extern int sgdwRecvOffset; // idb
extern int sgnCurrMegaPlayer; // weak
extern DLevel sgLevels[17];
extern char sbLastCmd; // weak
extern TMegaPkt *sgpCurrPkt;
extern char sgRecvBuf[4722];
extern unsigned char sgbRecvCmd; // idb
extern LocalLevel sgLocals[17];
extern DJunk sgJunk[4];
extern TMegaPkt *sgpMegaPkt;
extern char sgbDeltaChanged; // weak
extern char sgbDeltaChunks; // weak
extern int deltaload; // weak
extern char gbBufferMsgs; // weak
extern int dword_676198; // weak
extern int msg_err_timer; // weak

void msg_cpp_init();
void msg_send_drop_pkt(int pnum, int reason);
void msg_send_packet(int pnum, void *packet, int dwSize);
TMegaPkt *msg_get_next_packet();
int msg_wait_resync();
void msg_free_packets();
int msg_wait_for_turns();
void msg_process_net_packets();
void msg_pre_packet();
void DeltaExportData(int pnum);
void *DeltaExportItem(void *dst, void *src);
void *DeltaExportObject(void *dst, void *src);
void *DeltaExportMonster(void *dst, void *src);
char *DeltaExportJunk(char *a1);
int msg_comp_level(char *buffer, int size);
void delta_init();
void delta_kill_monster(int mi, unsigned char x, unsigned char y, unsigned char bLevel);
void delta_monster_hp(int mi, int hp, unsigned char bLevel);
void delta_sync_monster(TCmdLocParam1 *packet, char level);
void delta_sync_golem(TCmdGolem *pG, int pnum, int bLevel);
void delta_leave_sync(unsigned char bLevel);
bool delta_portal_inited(int portal_num);
bool delta_quest_inited(int quest_num);
void DeltaAddItem(int ii);
void DeltaSaveLevel();
void DeltaLoadLevel();
void NetSendCmd(unsigned char bHiPri, unsigned char bCmd);
void NetSendCmdGolem(unsigned char mx, unsigned char my, unsigned char dir, unsigned char menemy, int hp, int cl);
void NetSendCmdLoc(unsigned char bHiPri, unsigned char bCmd, unsigned char x, unsigned char y);
void NetSendCmdLocParam1(unsigned char bHiPri, unsigned char bCmd, unsigned char x, unsigned char y, int wParam1);
void NetSendCmdLocParam2(unsigned char bHiPri, unsigned char bCmd, unsigned char x, unsigned char y, int wParam1, int wParam2);
void NetSendCmdLocParam3(unsigned char bHiPri, unsigned char bCmd, unsigned char x, unsigned char y, int wParam1, int wParam2, int wParam3);
void NetSendCmdParam1(unsigned char bHiPri, unsigned char bCmd, unsigned short wParam1);
void NetSendCmdParam2(unsigned char bHiPri, unsigned char bCmd, unsigned short wParam1, unsigned short wParam2);
void NetSendCmdParam3(unsigned char bHiPri, unsigned char bCmd, unsigned short wParam1, unsigned short wParam2, int wParam3);
void NetSendCmdQuest(unsigned char bHiPri, unsigned char q);
void NetSendCmdGItem(unsigned char bHiPri, unsigned char bCmd, unsigned char mast, unsigned char pnum, int ii);
void NetSendCmdGItem2(unsigned char usonly, unsigned char bCmd, unsigned char mast, unsigned char pnum, struct TCmdGItem *p);
bool NetSendCmdReq2(unsigned char bCmd, unsigned char mast, unsigned char pnum, struct TCmdGItem *p);
void NetSendCmdExtra(struct TCmdGItem *p);
void NetSendCmdPItem(unsigned char bHiPri, unsigned char bCmd, unsigned char x, unsigned char y);
void NetSendCmdChItem(unsigned char bHiPri, unsigned char bLoc);
void NetSendCmdDelItem(unsigned char bHiPri, unsigned char bLoc);
void NetSendCmdDItem(unsigned char bHiPri, int ii);
void NetSendCmdDamage(unsigned char bHiPri, unsigned char bPlr, unsigned int dwDam);
void NetSendCmdString(int a1, const char *pszStr);
void RemovePlrPortal(int pnum);
int ParseCmd(int pnum, TCmd *pCmd);
void DeltaImportData(unsigned char cmd, int recv_offset);
void *DeltaImportItem(void *src, void *dst);
void *DeltaImportObject(void *src, void *dst);
void *DeltaImportMonster(void *src, void *dst);
char DeltaImportJunk(int a1);
int On_SYNCDATA(void *packet, int pnum);
int On_WALKXY(struct TCmdLoc *pCmd, int pnum);
int On_ADDSTR(struct TCmdParam1 *pCmd, int pnum);
int On_ADDMAG(struct TCmdParam1 *pCmd, int pnum);
int On_ADDDEX(struct TCmdParam1 *pCmd, int pnum);
int On_ADDVIT(struct TCmdParam1 *pCmd, int pnum);
int On_SBSPELL(struct TCmdParam1 *pCmd, int pnum);
void msg_errorf(char *pszFmt, ...);
int On_GOTOGETITEM(struct TCmdLocParam1 *pCmd, int pnum);
int On_REQUESTGITEM(struct TCmdGItem *pCmd, int pnum);
bool i_own_level(int nReqLevel);
int On_GETITEM(struct TCmdGItem *pCmd, int pnum);
bool delta_get_item(struct TCmdGItem *pI, unsigned char bLevel);
int On_GOTOAGETITEM(struct TCmdLocParam1 *pCmd, int pnum);
int On_REQUESTAGITEM(struct TCmdGItem *pCmd, int pnum);
int On_AGETITEM(struct TCmdGItem *pCmd, int pnum);
int On_ITEMEXTRA(struct TCmdGItem *pCmd, int pnum);
int On_PUTITEM(struct TCmdPItem *pCmd, int pnum);
void delta_put_item(struct TCmdPItem *pI, int x, int y, unsigned char bLevel);
void check_update_plr(int pnum);
int On_SYNCPUTITEM(struct TCmdPItem *pCmd, int pnum);
int On_RESPAWNITEM(struct TCmdPItem *pCmd, int pnum);
int On_ATTACKXY(struct TCmdLoc *pCmd, int pnum);
int On_SATTACKXY(struct TCmdLoc *pCmd, int pnum);
int On_RATTACKXY(struct TCmdLoc *pCmd, int pnum);
int On_SPELLXYD(struct TCmdLocParam3 *pCmd, int pnum);
int On_SPELLXY(struct TCmdLocParam2 *pCmd, int pnum);
int On_TSPELLXY(struct TCmdLocParam2 *pCmd, int pnum);
int On_OPOBJXY(struct TCmdLocParam1 *pCmd, int pnum);
int On_DISARMXY(struct TCmdLocParam1 *pCmd, int pnum);
int On_OPOBJT(struct TCmdParam1 *pCmd, int pnum);
int On_ATTACKID(struct TCmdParam1 *pCmd, int pnum);
int On_ATTACKPID(struct TCmdParam1 *pCmd, int pnum);
int On_RATTACKID(struct TCmdParam1 *pCmd, int pnum);
int On_RATTACKPID(struct TCmdParam1 *pCmd, int pnum);
int On_SPELLID(struct TCmdLocParam2 *pCmd, int pnum);
int On_SPELLPID(struct TCmdLocParam2 *pCmd, int pnum);
int On_TSPELLID(struct TCmdLocParam2 *pCmd, int pnum);
int On_TSPELLPID(struct TCmdLocParam2 *pCmd, int pnum);
int On_KNOCKBACK(struct TCmdParam1 *pCmd, int pnum);
int On_RESURRECT(struct TCmdParam1 *pCmd, int pnum);
int On_HEALOTHER(struct TCmdParam1 *pCmd, int pnum);
int On_TALKXY(struct TCmdLocParam1 *pCmd, int pnum);
int On_NEWLVL(struct TCmdParam2 *pCmd, int pnum);
int On_WARP(struct TCmdParam1 *pCmd, int pnum);
int On_MONSTDEATH(struct TCmdLocParam1 *pCmd, int pnum);
int On_KILLGOLEM(struct TCmdLocParam1 *pCmd, int pnum);
int On_AWAKEGOLEM(struct TCmdGolem *pCmd, int pnum);
int On_MONSTDAMAGE(struct TCmdLocParam1 *pCmd, int pnum);
int On_PLRDEAD(struct TCmdParam1 *pCmd, int pnum);
int On_PLRDAMAGE(struct TCmdDamage *pCmd, int pnum);
int On_OPENDOOR(struct TCmdParam1 *pCmd, int pnum);
void delta_sync_object(int oi, unsigned char bCmd, unsigned char bLevel);
int On_CLOSEDOOR(struct TCmdParam1 *pCmd, int pnum);
int On_OPERATEOBJ(struct TCmdParam1 *pCmd, int pnum);
int On_PLROPOBJ(struct TCmdParam2 *pCmd, int pnum);
int On_BREAKOBJ(struct TCmdParam2 *pCmd, int pnum);
int On_CHANGEPLRITEMS(struct TCmdChItem *pCmd, int pnum);
int On_DELPLRITEMS(struct TCmdDelItem *pCmd, int pnum);
int On_PLRLEVEL(struct TCmdParam1 *pCmd, int pnum);
int On_DROPITEM(struct TCmdPItem *pCmd, int pnum);
int On_SEND_PLRINFO(struct TCmdPlrInfoHdr *pCmd, int pnum);
int On_ACK_PLRINFO(struct TCmdPlrInfoHdr *pCmd, int pnum);
int On_PLAYER_JOINLEVEL(struct TCmdLocParam1 *pCmd, int pnum);
int On_ACTIVATEPORTAL(DJunk *pCmd, int pnum);
void delta_open_portal(int pnum, int x, int y, int bLevel, int bLType, int bSetLvl);
int On_DEACTIVATEPORTAL(struct TCmd *pCmd, int pnum);
int On_RETOWN(struct TCmd *pCmd, int pnum);
int On_SETSTR(struct TCmdParam1 *pCmd, int pnum);
int On_SETDEX(struct TCmdParam1 *pCmd, int pnum);
int On_SETMAG(struct TCmdParam1 *pCmd, int pnum);
int On_SETVIT(struct TCmdParam1 *pCmd, int pnum);
int On_STRING(struct TCmdString *pCmd, int pnum);
int On_SYNCQUEST(struct TCmdQuest *pCmd, int pnum);
int On_ENDSHIELD(int a1, int pnum);
#ifdef _DEBUG
int On_CHEAT_EXPERIENCE(struct TCmd *pCmd, int pnum);
int On_CHEAT_SPELL_LEVEL(struct TCmd *pCmd, int pnum);
#endif
int On_DEBUG();
int On_NOVA(struct TCmdLoc *pCmd, int pnum);
int On_SETSHIELD(int unused, int pnum);
int On_REMSHIELD(int unused, int pnum);

/* data */

extern int msg_inf; // weak

#endif /* __MSG_H__ */
