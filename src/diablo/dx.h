//HEADER_GOES_HERE
#ifndef __DX_H__
#define __DX_H__
#include <mutex>
#include <ddraw.h>

class DxInterface {

private:
    DxInterface() = default;
public:
    virtual ~DxInterface() = default;
    static DxInterface* get();
public:
    void dx_init(HWND hWnd);
    void dx_create_back_buffer();
    void dx_create_primary_surface();
    HRESULT dx_DirectDrawCreate(GUID *guid, IDirectDraw **DD, void *unknown);
    void dx_lock_mutex();
    void dx_unlock_mutex();
    void dx_cleanup();
    void dx_reinit();

public:
    void *sgpBackBuf = nullptr;
    IDirectDraw *lpDDInterface = nullptr;
    IDirectDrawPalette *lpDDPalette = nullptr;
    int sgdwLockCount = 0;
    Screen *gpBuffer = nullptr;
    IDirectDrawSurface *lpDDSBackBuf = nullptr;
    IDirectDrawSurface *lpDDSPrimary = nullptr;
    std::mutex m_mutex;
    char gbBackBuf;
    char gbEmulate;
    HMODULE ghDiabMod;

private:
    static DxInterface* m_instance;
};

#endif /* __DX_H__ */
