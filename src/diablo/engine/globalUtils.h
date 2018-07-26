#pragma once

#ifdef __ENGINE_EXPORT
#ifdef __GNUC__
#define ENGINE_API __attribute__((dllexport))
#else
#define ENGINE_API __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
#endif
#else
#ifdef __GNUC__
#define ENGINE_API __attribute__((dllimport))
#else
#define ENGINE_API __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
#endif
#endif
