//HEADER_GOES_HERE
#ifndef __TMSG_H__
#define __TMSG_H__

extern TMsg *sgpTimedMsgHead;

int tmsg_get(unsigned char *pbMsg, char bLen);
void tmsg_add(unsigned char *pbMsg, char bLen);
void tmsg_cleanup();

#endif /* __TMSG_H__ */
