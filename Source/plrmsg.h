//HEADER_GOES_HERE
#ifndef __PLRMSG_H__
#define __PLRMSG_H__

extern int plrmsg_ticks; // weak
extern char plr_msg_slot; // weak
extern _plrmsg plr_msgs[8];

void plrmsg_delay(int a1);
char *ErrorPlrMsg(char *pszMsg);
size_t EventPlrMsg(char *pszFmt, ...);
void SendPlrMsg(int pnum, const char *pszStr);
void ClearPlrMsg();
void InitPlrMsg();
void DrawPlrMsg();
void PrintPlrMsg(int no, int x, int y, char *str, int just);

/* data */

extern text_color text_color_from_player_num[2];

#endif /* __PLRMSG_H__ */
