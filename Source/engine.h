//HEADER_GOES_HERE
#ifndef __ENGINE_H__
#define __ENGINE_H__

//offset 0
//pCelBuff->pFrameTable[0]

extern int engine_cpp_init_value; // weak
extern char byte_52B96C; // automap pixel color 8-bit (palette entry)
extern int dword_52B970; // bool flip - if y < x
extern int orgseed; // weak
extern int sgnWidth;
extern int sglGameSeed; // weak
extern int SeedCount; // weak
extern int dword_52B99C; // bool valid - if x/y are in bounds

void engine_cpp_init_1();
void CelDrawDatOnly(char *pDecodeTo, char *pRLEBytes, int dwRLESize, int dwRLEWdt);
void CelDecodeOnly(int screen_x, int screen_y, void *pCelBuff, int frame, int frame_width);
void CelDecDatOnly(char *pBuff, char *pCelBuff, int frame, int frame_width);
void CelDrawHdrOnly(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int always_0, int direction);
void CelDecodeHdrOnly(char *pBuff, char *pCelBuff, int frame, int frame_width, int always_0, int direction);
void CelDecDatLightOnly(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width);
void CelDecDatLightEntry(int a1, char *a2, char *a3, char *v6);
void CelDecDatLightTrans(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width);
void CelDecodeLightOnly(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width);
void CelDecodeHdrLightOnly(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int always_0, int direction);
void CelDecodeHdrLightTrans(char *pBuff, char *pCelBuff, int frame, int frame_width, int always_0, int direction);
void CelDrawHdrLightRed(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int always_0, int direction, char always_1);
void Cel2DecDatOnly(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width);
void Cel2DrawHdrOnly(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int a6, int direction);
void Cel2DecodeHdrOnly(char *pBuff, char *pCelBuff, int frame, int frame_width, int a5, int direction);
void Cel2DecDatLightOnly(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width);
void Cel2DecDatLightEntry(int a1, int a2);
void Cel2DecDatLightTrans(char *pDecodeTo, char *pRLEBytes, int frame_content_size, int frame_width);
void Cel2DecodeHdrLight(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int a6, int direction);
void Cel2DecodeLightTrans(char *dst_buf, char *pCelBuff, int frame, int frame_width, int a5, int direction);
void Cel2DrawHdrLightRed(int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int always_0, int direction, char always_1);
void CelDecodeRect(char *pBuff, int always_0, int dst_height, int dst_width, char *pCelBuff, int frame, int frame_width);
void CelDecodeClr(char colour, int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int a7, int direction);
void CelDrawHdrClrHL(char colour, int screen_x, int screen_y, char *pCelBuff, int frame, int frame_width, int a7, int direction);
void ENG_set_pixel(int screen_x, int screen_y, char pixel);
void engine_draw_pixel(int x, int y);
void engine_draw_automap_pixels(int x1, int y1, int x2, int y2, char a5);
int GetDirection(int x1, int y1, int x2, int y2);
void SetRndSeed(int s);
int GetRndSeed();
int random(int idx, int v);
void engine_cpp_init_2();
void mem_init_mutex();
void mem_atexit_mutex();
void mem_free_mutex();
void *DiabloAllocPtr(int dwBytes);
void mem_free_dbg(void *ptr);
unsigned char *LoadFileInMem(char *pszName, int *pdwFileLen);
void LoadFileWithMem(char *pszName, void *buf);
void Cl2ApplyTrans(char *p, char *ttbl, int last_frame);
void Cl2DecodeFrm1(int x, int y, char *pCelBuff, int nCel, int width, int dir1, int dir2);
void Cl2DecDatFrm1(char *buffer, char *frame_content, int a3, int width);
void Cl2DecodeFrm2(char colour, int screen_x, int screen_y, char *pCelBuff, int nCel, int frame_width, int a7, int a8);
void Cl2DecDatFrm2(char *buffer, char *a2, int a3, int a4, char a5);
void Cl2DecodeFrm3(int screen_x, int screen_y, char *pCelBuff, int nCel, int frame_width, int a6, int a7, char a8);
void Cl2DecDatLightTbl1(char *a1, char *a2, int a3, int a4, char *unused_lindex);
void Cl2DecodeLightTbl(int screen_x, int screen_y, char *pCelBuff, int nCel, int frame_width, int a6, int a7);
void Cl2DecodeFrm4(int screen_x, int screen_y, char *pCelBuff, int nCel, int frame_width, int a6, int a7);
void Cl2DecDatFrm4(char *buffer, char *a2, int a3, int frame_width);
void Cl2DecodeClrHL(char colour, int screen_x, int screen_y, char *pCelBuff, int nCel, int frame_width, int a7, int a8);
void Cl2DecDatClrHL(char *dst_buf, char *frame_content, int a3, int frame_width, char colour);
void Cl2DecodeFrm5(int screen_x, int screen_y, char *pCelBuff, int nCel, int frame_width, int a6, int a7, char a8);
void Cl2DecDatLightTbl2(char *dst_buf, char *a2, int a3, int frame_width, char *a5);
void Cl2DecodeFrm6(int screen_x, int screen_y, char *pCelBuff, int nCel, int frame_width, int a6, int a7);
void PlayInGameMovie(char *pszMovie);

/* data */

extern int engine_inf; // weak

#endif /* __ENGINE_H__ */
