//HEADER_GOES_HERE
#ifndef __PORTAL_H__
#define __PORTAL_H__

extern PortalStruct portal[4];
extern int portalindex;
// int END_portalstruct; // weak

void InitPortals();
void SetPortalStats(int i, int o, int x, int y, int lvl, int lvltype);
void AddWarpMissile(int i, int x, int y);
void SyncPortals();
void AddInTownPortal(int i);
void ActivatePortal(int i, int x, int y, int lvl, int lvltype, int sp);
void DeactivatePortal(int i);
bool PortalOnLevel(int i);
void RemovePortalMissile(int id);
void SetCurrentPortal(int p);
void GetPortalLevel();
void GetPortalLvlPos();
bool PosOkPortal(int level, int x, int y);

/* rdata */
extern int WarpDropX[4];
extern int WarpDropY[4];

#endif /* __PORTAL_H__ */
