//HEADER_GOES_HERE
#ifndef __PACK_H__
#define __PACK_H__

extern int pack_cpp_init_value; // weak

void pack_cpp_init();
void PackPlayer(PkPlayerStruct *pPack, int pnum, bool manashield);
void PackItem(PkItemStruct *id, ItemStruct *is);
void VerifyGoldSeeds(PlayerStruct *pPlayer);
void UnPackPlayer(PkPlayerStruct *pPack, int pnum, bool killok);
void UnPackItem(PkItemStruct *is, ItemStruct *id);

/* data */

extern int pack_inf; // weak

#endif /* __PACK_H__ */
