//HEADER_GOES_HERE
#ifndef __TRACK_H__
#define __TRACK_H__

extern bool sgbIsScrolling; // weak
extern int track_cpp_init_value; // weak
extern int sgdwLastWalk; // weak
extern bool sgbIsWalking; // weak

void track_cpp_init();
void track_process();
void track_repeat_walk(bool rep);
bool track_isscrolling();

/* data */

extern int track_inf; // weak

#endif /* __TRACK_H__ */
