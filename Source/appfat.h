//HEADER_GOES_HERE
#ifndef __APPFAT_H__
#define __APPFAT_H__

extern int appfat_terminated; // weak
extern char sz_error_buf[256];
extern int terminating; // weak
extern int cleanup_thread_id; // weak
extern char empty_string;

char *GetErr(int error_code);
void GetDDErr(int error_code, char *error_buf, int error_buf_len);
void GetDSErr(int error_code, char *error_buf, int error_buf_len);
char *GetLastErr();
void TermMsg(char *pszFmt, ...);
void MsgBox(char *pszFmt, va_list va);
void FreeDlg();
void DrawDlg(char *pszFmt, ...);
void DDErrDlg(int error_code, int log_line_nr, char *log_file_path);
void DSErrDlg(int error_code, int log_line_nr, char *log_file_path);
void CenterDlg(HWND hDlg);
void TermDlg(int template_id, int error_code, char *log_file_path, int log_line_nr);
bool __stdcall FuncDlg(HWND hDlg, UINT uMsg, WPARAM wParam, char *text);
void TextDlg(HWND hDlg, char *text);
void ErrDlg(template_id template_id, int error_code, char *log_file_path, int log_line_nr);
void FileErrDlg(char *error);
void DiskFreeDlg(char *error);
bool InsertCDDlg();
void DirErrDlg(char *error);

#endif /* __APPFAT_H__ */
