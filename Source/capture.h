//HEADER_GOES_HERE
#ifndef __CAPTURE_H__
#define __CAPTURE_H__

void CaptureScreen();
bool CaptureHdr(HANDLE hFile, short width, int height);
bool CapturePal(HANDLE hFile, PALETTEENTRY *palette);
bool CapturePix(HANDLE hFile, short width, short height, short stride, char *pixels);
char *CaptureEnc(char *src, char *dst, int width);
HANDLE CaptureFile(char *dst_path);
void RedPalette(PALETTEENTRY *pal);

#endif /* __CAPTURE_H__ */
