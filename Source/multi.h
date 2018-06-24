//HEADER_GOES_HERE
#ifndef __MULTI_H__
#define __MULTI_H__

extern char gbSomebodyWonGameKludge; // weak
extern char pkdata_6761C0[4100];
extern char szPlayerDescript[128];
extern short sgwPackPlrOffsetTbl[4];
extern PkPlayerStruct pkplr[4];
extern char sgbPlayerTurnBitTbl[4];
extern char sgbPlayerLeftGameTbl[4];
extern int multi_cpp_init_value; // weak
extern int sgbSentThisCycle; // idb
extern int dword_678628; // weak
extern char gbActivePlayers; // weak
extern char gbGameDestroyed; // weak
extern char sgbSendDeltaTbl[4];
extern _gamedata sgGameInitInfo;
extern char byte_678640; // weak
extern int sglTimeoutStart; // weak
extern int sgdwPlayerLeftReasonTbl[4];
extern char pkdata_678658[4100];
extern unsigned int sgdwGameLoops; // idb
extern char gbMaxPlayers; // weak
extern char sgbTimeout; // weak
extern char szPlayerName[128];
extern char gbDeltaSender; // weak
extern int sgbNetInited; // weak
extern int player_state[4];

void multi_cpp_init();
void multi_msg_add(unsigned char *a1, unsigned char a2);
void NetSendLoPri(unsigned char *pbMsg, unsigned char bLen);
void multi_copy_packet(void *a1, void *packet, int size);
void multi_send_packet(void *packet, int dwSize);
void NetRecvPlrData(TPkt *pkt);
void NetSendHiPri(unsigned char *pbMsg, unsigned char bLen);
unsigned char *multi_recv_packet(void *packet, unsigned char *a2, int *a3);
void multi_send_msg_packet(int a1, unsigned char *a2, unsigned char len);
void multi_msg_countdown();
void multi_parse_turn(int pnum, int turn);
void multi_handle_turn_upper_bit(int pnum);
void multi_player_left(int pnum, int reason);
void multi_clear_left_tbl();
void multi_player_left_msg(int pnum, int left);
void multi_net_ping();
int multi_handle_delta();
int multi_check_pkt_valid(char *a1);
void multi_mon_seeds();
void multi_begin_timeout();
void multi_check_drop_player();
void multi_process_network_packets();
void multi_handle_all_packets(int players, TPkt *packet, int a3);
void multi_process_tmsgs();
void multi_send_zero_packet(int pnum, char a2, void *pbSrc, int dwLen);
void NetClose();
char multi_event_handler(int a1);
void __stdcall multi_handle_events(_SNETEVENT *pEvt);
int NetInit(int bSinglePlayer, int *pfExitProgram);
void multi_clear_pkt(char *a1);
void multi_send_pinfo(int pnum, TCmdPlrInfoHdr *cmd);
int InitNewSeed(int newseed);
void SetupLocalCoords();
int multi_init_single(_SNETPROGRAMDATA *client_info, _SNETPLAYERDATA *user_info, _SNETUIDATA *ui_info);
int multi_init_multi(_SNETPROGRAMDATA *client_info, _SNETPLAYERDATA *user_info, _SNETUIDATA *ui_info, int *a4);
int multi_upgrade(int *a1);
void multi_player_joins(int pnum, TCmdPlrInfoHdr *cmd, int a3);

/* data */

extern int multi_inf; // weak
extern event_type event_types[3];

#endif /* __MULTI_H__ */
