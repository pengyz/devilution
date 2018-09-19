// temporary file

#ifndef _TYPES_H
#define _TYPES_H

#define WIN32_LEAN_AND_MEAN

#include "resource.h"

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <ddraw.h>
#include <dsound.h>
#include <io.h>
#include <math.h>
#include <time.h>
#include <process.h>
#include <shlobj.h>
#include <shellapi.h>

#ifdef __GNUC__
#include <ctype.h>
#endif

// tell Visual C++ to shut the hell up
#ifdef _MSC_VER
#pragma warning (disable : 4309) // truncation of constant value
#pragma warning (disable : 4305) // truncation of int
#pragma warning (disable : 4018) // signed/unsigned mismatch
#pragma warning (disable : 4700) // used without having been initialized
#pragma warning (disable : 4804) // unsafe use of type 'bool' in operation
#pragma warning (disable : 4805) // unsafe bool mix
#pragma warning (disable : 4244) // conversion loss
#pragma warning (disable : 4800) // bool perf
#pragma warning (disable : 4146) // negative unsigned
#endif

#include "defs.h"
#include "enums.h"
#include "structs.h"

#include "../../3rdParty/Storm/Source/storm.h"
#include "../../3rdParty/DiabloUI/diabloui.h"
#include "../../3rdParty/PKWare/pkware.h"

// If defined, use copy protection [Default -> Defined]
//#define COPYPROT
// If defined, don't reload for debuggers [Default -> Undefined]
// Note that with patch 1.03 the command line was hosed, this is required to pass arguments to the game
#ifdef _DEBUG
#define DEBUGGER
#endif
// If defined, don't fry the CPU [Default -> Undefined]
#define SLEEP
// If defined, use standard memcpy() in place of qmemcpy() [Default -> Undefined]
// Will be replaced with [rep movsd] if optimization is used
#define FAST_MEMCPY


/* temp macro for asm XLAT */
#define ASM_XLAT(eax,ebx) eax = (eax & 0xFFFFFF00) + LOBYTE(ebx[LOBYTE(eax)])

// header files
#include "appfat.h"
#include "automap.h"
#include "capture.h"
#include "codec.h"
#include "control.h"
#include "cursor.h"
#include "dead.h"
#include "debug.h"
#include "diablo.h"
#include "doom.h"
#include "drlg_l1.h"
#include "drlg_l2.h"
#include "drlg_l3.h"
#include "drlg_l4.h"
#include "dthread.h"
#include "dx.h"
#include "effects.h"
#include "encrypt.h"
#include "engine.h"
#include "error.h"
#include "fault.h"
#include "gamemenu.h"
#include "gendung.h"
#include "gmenu.h"
#include "help.h"
#include "init.h"
#include "interfac.h"
#include "inv.h"
#include "items.h"
#include "lighting.h"
#include "loadsave.h"
#include "logging.h"
#include "mainmenu.h"
#include "minitext.h"
#include "missiles.h"
#include "monster.h"
#include "movie.h"
#include "mpqapi.h"
#include "msg.h"
#include "msgcmd.h"
#include "multi.h"
#include "nthread.h"
#include "objects.h"
#include "pack.h"
#include "palette.h"
#include "path.h"
#include "pfile.h"
#include "player.h"
#include "plrmsg.h"
#include "portal.h"
#include "quests.h"
#include "restrict.h"
#include "scrollrt.h"
#include "setmaps.h"
#include "sha.h"
#include "sound.h"
#include "spells.h"
#include "stores.h"
#include "sync.h"
#include "textdat.h" // check file name
#include "themes.h"
#include "tmsg.h"
#include "town.h"
#include "towners.h"
#include "track.h"
#include "trigs.h"
#include "wave.h"
#include "render.h" // linked last, likely .s/.asm

#endif
