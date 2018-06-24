//HEADER_GOES_HERE
#ifndef __SPELLS_H__
#define __SPELLS_H__

int GetManaAmount(int id, int sn);
void UseMana(int id, int sn);
bool CheckSpell(int id, int sn, char st, bool manaonly);
void CastSpell(int id, int spl, int sx, int sy, int dx, int dy, int caster, int spllvl);
void DoResurrect(int pnum, int rid);
void PlacePlayer(int pnum);
void DoHealOther(int pnum, int rid);

/* rdata */

extern SpellData spelldata[37];

#endif /* __SPELLS_H__ */
