//HEADER_GOES_HERE
#ifndef __DX_H__
#define __DX_H__

extern void *sgpBackBuf;
extern int dx_cpp_init_value; // weak
extern IDirectDraw *lpDDInterface;
extern IDirectDrawPalette *lpDDPalette; // idb
extern int sgdwLockCount;
extern Screen *gpBuffer;
extern IDirectDrawSurface *lpDDSBackBuf;
extern IDirectDrawSurface *lpDDSPrimary;
extern char gbBackBuf; // weak
extern char gbEmulate; // weak
extern HMODULE ghDiabMod; // idb

void dx_cpp_init_1();
void dx_cpp_init_2();
void dx_init_mutex();
void dx_cleanup_mutex_atexit();
void dx_cleanup_mutex();
void dx_init(HWND hWnd);
void dx_create_back_buffer();
void dx_create_primary_surface();
HRESULT dx_DirectDrawCreate(GUID *guid, IDirectDraw **DD, void *unknown);
void j_dx_lock_mutex();
void dx_lock_mutex();
void j_dx_unlock_mutex();
void dx_unlock_mutex();
void dx_cleanup();
void dx_reinit();
void j_dx_reinit();

/* data */

extern int dx_inf; // weak

#endif /* __DX_H__ */
