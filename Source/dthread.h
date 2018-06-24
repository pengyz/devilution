//HEADER_GOES_HERE
#ifndef __DTHREAD_H__
#define __DTHREAD_H__

extern int dthread_cpp_init_value; // weak
extern unsigned int glpDThreadId; // idb
extern TMegaPkt *sgpInfoHead; /* may not be right struct */
extern char byte_52A508; // weak
extern HANDLE sghWorkToDoEvent; // idb

void dthread_cpp_init_1();
void dthread_cpp_init_2();
void dthread_init_mutex();
void dthread_cleanup_mutex_atexit();
void dthread_cleanup_mutex();
void dthread_remove_player(int pnum);
void dthread_send_delta(int pnum, int cmd, void *pbSrc, int dwLen);
void dthread_start();
unsigned int __stdcall dthread_handler(void *a1);
void dthread_cleanup();

/* data */
extern int dthread_inf; // weak

#endif /* __DTHREAD_H__ */
