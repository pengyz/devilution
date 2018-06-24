//HEADER_GOES_HERE
#ifndef __LOGGING_H__
#define __LOGGING_H__

extern int log_cpp_init_value; // weak
extern CHAR FileName[260]; // idb
extern char log_buffer[388];
extern LPCVOID lpAddress; // idb
extern DWORD nNumberOfBytesToWrite; // idb

void log_cpp_init_1();
void log_cpp_init_2();
void log_init_mutex();
void j_log_cleanup_mutex();
void log_cleanup_mutex();
void log_flush(bool force_close);
void *log_create(); // should be HANDLE
void log_get_version(VS_FIXEDFILEINFO *file_info);
void log_printf(char *pszFmt, ...); // LogMessage
void log_dump_computer_info();

/* data */

extern int log_inf; // weak

/* rdata */

extern int log_not_created; // weak
extern HANDLE log_file; // idb

#endif /* __LOGGING_H__ */
