//HEADER_GOES_HERE
#ifndef __CONTROL_H__
#define __CONTROL_H__

extern char sgbNextTalkSave; // weak
extern char sgbTalkSavePos; // weak
extern void *pDurIcons;
extern void *pChrButtons;
extern int drawhpflag; // idb
extern int dropGoldFlag; // weak
extern int panbtn[8];
extern int chrbtn[4];
extern void *pMultiBtns;
extern void *pPanelButtons;
extern void *pChrPanel;
extern int lvlbtndown; // weak
extern char sgszTalkSave[8][80];
extern int dropGoldValue; // idb
extern int drawmanaflag; // idb
extern int chrbtnactive; // weak
extern char sgszTalkMsg[80];
extern void *pPanelText;
extern int frame_4B8800; // idb
extern void *pLifeBuff;
extern void *pBtmBuff;
extern void *pTalkBtns;
extern int pstrjust[4];
extern int pnumlines; // idb
extern int pinfoflag; // weak
extern int talkbtndown[3];
extern int pSpell; // weak
extern void *pManaBuff;
extern int infoclr; // weak
extern int sgbPlrTalkTbl; // weak // should be char [4]
extern void *pGBoxBuff;
extern void *pSBkBtnCel;
extern char tempstr[260];
extern int sbooktab; // weak
extern int pSplType; // weak
extern int frame; // idb
extern int initialDropGoldIndex; // idb
extern int talkflag; // weak
extern void *pSBkIconCels;
extern int sbookflag; // weak
extern int chrflag;
extern int drawbtnflag; // idb
extern void *pSpellBkCel;
extern char infostr[260];
extern int numpanbtns; // weak
extern void *pStatusPanel;
extern char panelstr[256];
extern int panelflag; // weak
extern char byte_4B8B88[256];
extern int initialDropGoldValue; // idb
extern void *pSpellCels;
extern int panbtndown; // weak
extern void *pTalkPanel; // idb
extern int spselflag; // weak

void DrawSpellCel(int xp, int yp, char *Trans, int nCel, int w);
void SetSpellTrans(char t);
void DrawSpell();
void DrawSpellList();
void SetSpell();
void SetSpeedSpell(int slot);
void ToggleSpell(int slot);
void CPrintString(int No, unsigned char pszStr, int Just);
void AddPanelString(char *str, int just);
void ClearPanel();
void DrawPanelBox(int x, int y, int w, int h, int sx, int sy);
void InitPanelStr();
void SetFlaskHeight(char *buf, int min, int max, int c, int r);
void DrawFlask(void *a1, int a2, int a3, void *a4, int a5, int a6);
void DrawLifeFlask();
void UpdateLifeFlask();
void DrawManaFlask();
void control_update_life_mana();
void UpdateManaFlask();
void InitControlPan();
void ClearCtrlPan();
void DrawCtrlPan();
void DoSpeedBook();
void DoPanBtn();
void control_set_button_down(int btn_id);
void control_check_btn_press();
void DoAutoMap();
void CheckPanelInfo();
void CheckBtnUp();
void FreeControlPan();
int control_WriteStringToBuffer(char *str);
void DrawInfoBox();
void control_print_info_str(int y, char *str, bool center, int lines);
void PrintGameStr(int x, int y, char *str, int color);
void DrawChr();
void ADD_PlrStringXY(int x, int y, int width, char *pszStr, char col);
void MY_PlrStringXY(int x, int y, int width, char *pszStr, char col, int base);
void CheckLvlBtn();
void ReleaseLvlBtn();
void DrawLevelUpIcon();
void CheckChrBtns();
void ReleaseChrBtns();
void DrawDurIcon();
int DrawDurIcon4Item(ItemStruct *pItem, int x, int c);
void RedBack();
int GetSBookTrans(int ii, unsigned char townok);
void DrawSpellBook();
void PrintSBookStr(int x, int y, bool cjustflag, char *pszStr, int bright);
void CheckSBook();
char *get_pieces_str(int nGold);
void DrawGoldSplit(int amount);
void control_drop_gold(int vkey);
void control_remove_gold(int pnum, int gold_index);
void control_set_gold_curs(int pnum);
void DrawTalkPan();
char *control_print_talk_msg(char *msg, int x, int y, int *a4, int just);
int control_check_talk_btn();
void control_release_talk_btn();
void control_reset_talk_msg();
void control_type_message();
void control_reset_talk();
int control_talk_last_key(int a1);
int control_presskeys(int a1);
void control_press_enter();
void control_up_down(char a1);

/* data */
extern unsigned char fontframe[127];
extern unsigned char fontkern[68];
extern int lineoffset[25];
extern unsigned char fontidx[256];

/* rdata */

extern unsigned char SpellITbl[37];
extern int PanBtnPos[8][5];
extern char *PanBtnHotKey[8];
extern char *PanBtnStr[8];
extern RECT32 attribute_inc_rects[4];
extern int SpellPages[6][7];

#endif /* __CONTROL_H__ */
