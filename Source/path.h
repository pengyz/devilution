//HEADER_GOES_HERE
#ifndef __PATH_H__
#define __PATH_H__

extern PATHNODE path_nodes[300];
extern int gdwCurPathStep;
extern int pnode_vals[26];
extern PATHNODE *pnode_ptr;
extern PATHNODE *pnode_tblptr[300];
extern PATHNODE path_2_nodes[300];

int FindPath(bool (*PosOk)(int, int, int), int PosOkArg, int sx, int sy, int dx, int dy, char *path);
int path_get_h_cost(int sx, int sy, int dx, int dy);
int path_check_equal(PATHNODE *pPath, int dx, int dy);
PATHNODE *GetNextPath();
bool path_solid_pieces(PATHNODE *pPath, int dx, int dy);
int path_get_path(bool (*PosOk)(int, int, int), int PosOkArg, PATHNODE *pPath, int x, int y);
int path_parent_path(PATHNODE *pPath, int dx, int dy, int sx, int sy);
PATHNODE *path_get_node1(int dx, int dy);
PATHNODE *path_get_node2(int dx, int dy);
void path_next_node(PATHNODE *pPath);
void path_set_coords(PATHNODE *pPath);
void path_push_active_step(PATHNODE *pPath);
PATHNODE *path_pop_active_step();
PATHNODE *path_new_step();

/* data */

extern char pathxdir[8];
extern char pathydir[8];

/* rdata */
extern char path_directions[9];

#endif /* __PATH_H__ */
