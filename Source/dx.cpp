//HEADER_GOES_HERE

#include "../types.h"

DxInterface* DxInterface::m_instance = nullptr;


// 47A464: using guessed type int dx_inf;
// 52A514: using guessed type int dx_cpp_init_value;

DxInterface* DxInterface::get()
{
    if (!m_instance)
        m_instance = new DxInterface();
    return m_instance;
}

void DxInterface::dx_init(HWND hWnd)
{
    SetFocus(hWnd);
    ShowWindow(hWnd, SW_SHOWNORMAL);
    GUID * guid = NULL;
    if (gbEmulate)
        guid = (GUID *)DDCREATE_EMULATIONONLY;
    HRESULT hr = dx_DirectDrawCreate(guid, &lpDDInterface, NULL);
    if (hr)
        TermDlg(104, hr, __FILE__, __LINE__);
    fullscreen = 1;
    hr = lpDDInterface->SetCooperativeLevel(hWnd, DDSCL_EXCLUSIVE | DDSCL_ALLOWREBOOT | DDSCL_FULLSCREEN);
    if (hr == DDERR_EXCLUSIVEMODEALREADYSET)
    {
        MI_Dummy(0); // v5
    }
    else if (hr)
    {
        TermDlg(104, hr, __FILE__, __LINE__);
    }
    if (lpDDInterface->SetDisplayMode(640, 480, 8))
    {
        int xMetrics = GetSystemMetrics(SM_CXSCREEN);
        int yMetrics = GetSystemMetrics(SM_CYSCREEN);
        hr = lpDDInterface->SetDisplayMode(xMetrics, yMetrics, 8);
        if (hr)
            TermDlg(104, hr, __FILE__, __LINE__);
    }
    dx_create_primary_surface();
    palette_init();
    GdiSetBatchLimit(1);
    dx_create_back_buffer();
    SDrawManualInitialize(hWnd, lpDDInterface, lpDDSPrimary, 0, 0, lpDDSBackBuf, lpDDPalette, 0);
}
// 484364: using guessed type int fullscreen;
// 52A549: using guessed type char gbEmulate;

void DxInterface::dx_create_back_buffer()
{
    int v0; // eax
    int v1; // eax
    int v2; // eax
    int v3; // eax
    DDSURFACEDESC v4; // [esp+Ch] [ebp-70h]
    DDSCAPS v5; // [esp+78h] [ebp-4h]

    v0 = lpDDSPrimary->GetCaps(&v5);
    if (v0)
        DDErrDlg(v0, __LINE__, __FILE__);
    if (!gbBackBuf)
    {
        v4.dwSize = 108;
        v1 = lpDDSPrimary->Lock(NULL, &v4, DDLOCK_WRITEONLY | DDLOCK_WAIT, NULL);
        if (!v1)
        {
            lpDDSPrimary->Unlock(NULL);
            sgpBackBuf = DiabloAllocPtr(0x7B000);
            return;
        }
        if (v1 != DDERR_CANTLOCKSURFACE)
            TermDlg(104, v1, __FILE__, __LINE__);
    }
    memset(&v4, 0, 0x6Cu);
    v4.dwWidth = 768;
    v4.lPitch = 768;
    v4.dwSize = 108;
    v4.dwFlags = DDSD_PIXELFORMAT | DDSD_PITCH | DDSD_WIDTH | DDSD_HEIGHT | DDSD_CAPS;
    v4.ddsCaps.dwCaps = DDSCAPS_SYSTEMMEMORY | DDSCAPS_OFFSCREENPLAIN;
    v4.dwHeight = 656;
    v4.ddpfPixelFormat.dwSize = 32;
    v2 = lpDDSPrimary->GetPixelFormat(&v4.ddpfPixelFormat);
    if (v2)
        TermDlg(104, v2, __FILE__, __LINE__);
    v3 = lpDDInterface->CreateSurface(&v4, &lpDDSBackBuf, NULL);
    if (v3)
        TermDlg(104, v3, __FILE__, __LINE__);
}
// 52A548: using guessed type char gbBackBuf;

void DxInterface::dx_create_primary_surface()
{
    int v0; // eax
    DDSURFACEDESC v1; // [esp+0h] [ebp-6Ch]

    memset(&v1, 0, 0x6Cu);
    v1.dwSize = 108;
    v1.dwFlags = DDSD_CAPS;
    v1.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
    v0 = lpDDInterface->CreateSurface(&v1, &lpDDSPrimary, NULL);
    if (v0)
        TermDlg(104, v0, __FILE__, __LINE__);
}

HRESULT DxInterface::dx_DirectDrawCreate(GUID *guid, IDirectDraw **DD, void *unknown)
{
    IDirectDraw **v3; // ebp
    int v4; // eax
    FARPROC v5; // ebx
    int v6; // eax
    GUID *v8; // [esp+10h] [ebp-4h]

    v3 = DD;
    v8 = guid;
    if (!ghDiabMod)
    {
        ghDiabMod = LoadLibraryA("ddraw.dll");
        if (!ghDiabMod)
        {
            v4 = GetLastError();
            TermDlg(107, v4, __FILE__, __LINE__);
        }
    }
    v5 = GetProcAddress(ghDiabMod, "DirectDrawCreate");
    if (!v5)
    {
        v6 = GetLastError();
        TermDlg(107, v6, __FILE__, __LINE__);
    }
    return ((int(__stdcall *)(GUID *, IDirectDraw **, void *))v5)(v8, v3, unknown);
}

void DxInterface::dx_lock_mutex()
{
    Screen *v0; // eax
    int v1; // eax
    DDSURFACEDESC v2; // [esp+0h] [ebp-6Ch]

    m_mutex.lock();
    v0 = (Screen *)sgpBackBuf;
    if (sgpBackBuf)
        goto LABEL_8;
    if (lpDDSBackBuf)
    {
        if (sgdwLockCount)
            goto LABEL_9;
        v2.dwSize = 108;
        v1 = lpDDSBackBuf->Lock(NULL, &v2, DDLOCK_WAIT, NULL);
        if (v1)
            DDErrDlg(v1, __LINE__, __FILE__);
        v0 = (Screen *)v2.lpSurface;
        screen_buf_end += (int)v2.lpSurface;
    LABEL_8:
        gpBuffer = v0;
        goto LABEL_9;
    }
    Sleep(20000);
    TermMsg("lock_buf_priv");
LABEL_9:
    ++sgdwLockCount;
}
// 69CF0C: using guessed type int screen_buf_end;

void DxInterface::dx_unlock_mutex()
{
    Screen *v0; // eax
    int v1; // eax

    if (!sgdwLockCount)
        TermMsg("draw main unlock error");
    if (!gpBuffer)
        TermMsg("draw consistency error");
    if (!--sgdwLockCount)
    {
        v0 = gpBuffer;
        gpBuffer = 0;
        screen_buf_end -= (signed int)v0;
        if (!sgpBackBuf)
        {
            v1 = lpDDSBackBuf->Unlock(NULL);
            if (v1)
                DDErrDlg(v1, __LINE__, __FILE__);
        }
    }
    m_mutex.unlock();
}
// 69CF0C: using guessed type int screen_buf_end;

void DxInterface::dx_cleanup()
{
    void *v0; // ecx

    if (ghMainWnd)
        ShowWindow(ghMainWnd, SW_HIDE);
    SDrawDestroy();
    m_mutex.lock();
    if (sgpBackBuf)
    {
        v0 = sgpBackBuf;
        sgpBackBuf = 0;
        mem_free_dbg(v0);
    }
    else if (lpDDSBackBuf)
    {
        lpDDSBackBuf->Release();
        lpDDSBackBuf = 0;
    }
    sgdwLockCount = 0;
    gpBuffer = 0;
    m_mutex.lock();
    if (lpDDSPrimary)
    {
        lpDDSPrimary->Release();
        lpDDSPrimary = 0;
    }
    if (lpDDPalette)
    {
        lpDDPalette->Release();
        lpDDPalette = 0;
    }
    if (lpDDInterface)
    {
        lpDDInterface->Release();
        lpDDInterface = 0;
    }
}

void DxInterface::dx_reinit()
{
    int v0; // esi

    m_mutex.lock();
    ClearCursor();
    v0 = sgdwLockCount;
    while (sgdwLockCount)
        dx_unlock_mutex();
    dx_cleanup();
    drawpanflag = 255;
    dx_init(ghMainWnd);
    for (; v0; --v0)
        dx_lock_mutex();
    m_mutex.unlock();
}
// 52571C: using guessed type int drawpanflag;