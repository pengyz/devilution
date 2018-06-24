//HEADER_GOES_HERE
#ifndef __FAULT_H__
#define __FAULT_H__

//int dword_52B9F4;
extern LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter; // idb

void exception_cpp_init();
void exception_install_filter();
void j_exception_init_filter();
void exception_init_filter();
LONG __stdcall TopLevelExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo);
void exception_hex_format(char *a1, char a2);
void exception_unknown_module(LPCVOID lpAddress, LPSTR lpString1, int iMaxLength, int a4, int a5);
void exception_call_stack(void *a1, LPVOID lp);
char *exception_get_error_type(DWORD dwMessageId, LPSTR lpString1, DWORD nSize);
void exception_set_filter();
LPTOP_LEVEL_EXCEPTION_FILTER exception_set_filter_ptr();
LPTOP_LEVEL_EXCEPTION_FILTER exception_get_filter();

#endif /* __FAULT_H__ */
