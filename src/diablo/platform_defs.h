#pragma once

#ifdef __GNUC__
#ifndef __stdcall
#define __stdcall       __attribute__((__stdcall__))
#endif
#ifndef __cdecl
#define __cdecl         __attribute__((__cdecl__))
#endif
#ifndef __thiscall
#define __thiscall      __attribute__((__thiscall__))
#endif
#ifndef __fastcall
#define __fastcall      __attribute__((__fastcall__))
#endif
#endif


using DWORD = unsigned int;
using WORD = unsigned short;
using HRESULT = int;             
using BOOL = int;
using HWND = int;
using WAVEFORMATEX = int;
using IDirectSoundBuffer = void*;
using UINT = DWORD;
using WPARAM = DWORD;
using HANDLE = void*;
using BYTE = unsigned char;
using SOCKADDR = void*;



