#pragma once

#if defined(SOMELIBC_STATIC)         // Using static.
#  define SOMELIBC_SYMEXPORT
#elif defined(SOMELIBC_STATIC_BUILD) // Building static.
#  define SOMELIBC_SYMEXPORT
#elif defined(SOMELIBC_SHARED)       // Using shared.
#  ifdef _WIN32
#    define SOMELIBC_SYMEXPORT __declspec(dllimport)
#  else
#    define SOMELIBC_SYMEXPORT
#  endif
#elif defined(SOMELIBC_SHARED_BUILD) // Building shared.
#  ifdef _WIN32
#    define SOMELIBC_SYMEXPORT __declspec(dllexport)
#  else
#    define SOMELIBC_SYMEXPORT
#  endif
#else
// If none of the above macros are defined, then we assume we are being used
// by some third-party build system that cannot/doesn't signal the library
// type. Note that this fallback works for both static and shared but in case
// of shared will be sub-optimal compared to having dllimport.
//
#  define SOMELIBC_SYMEXPORT         // Using static or shared.
#endif
