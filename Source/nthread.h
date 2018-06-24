//HEADER_GOES_HERE
#ifndef __NTHREAD_H__
#define __NTHREAD_H__

extern int nthread_cpp_init_value; // weak
extern char byte_679704; // weak
extern int gdwMsgLenTbl[4];
extern int gdwDeltaBytesSec; // weak
extern char byte_679734; // weak
extern int gdwTurnsInTransit; // weak
extern int glpMsgTbl[4];
extern unsigned int glpNThreadId;
extern char sgbSyncCountdown; // weak
extern int dword_679754; // weak
extern char byte_679758; // weak
extern char sgbPacketCountdown; // weak
extern char sgbThreadIsRunning; // weak
extern int gdwLargestMsgSize; // weak
extern int gdwNormalMsgSize; // weak
extern int dword_679764; // weak

void nthread_cpp_init_1();
void nthread_cpp_init_2();
void nthread_init_mutex();
void nthread_cleanup_mutex_atexit();
void nthread_cleanup_mutex();
void nthread_terminate_game(char *pszFcn);
int nthread_send_and_recv_turn(int cur_turn, int turn_delta);
int nthread_recv_turns(int *pfSendAsync);
void nthread_set_turn_upper_bit();
void nthread_start(bool set_turn_upper_bit);
unsigned int __stdcall nthread_handler(void *a1);
void nthread_cleanup();
void nthread_ignore_mutex(bool bStart);
bool nthread_has_500ms_passed();

/* data */

extern int nthread_inf; // weak

#endif /* __NTHREAD_H__ */
