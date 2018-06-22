#pragma once

#if (defined(__cplusplus) && __cplusplus >= 201703L) ||                        \
    (defined(_HAS_CXX17) && _HAS_CXX17 == 1) // fix for issue #464
#define SY_HAS_CPP_17
#define SY_HAS_CPP_14
#elif (defined(__cplusplus) && __cplusplus >= 201402L) ||                      \
    (defined(_HAS_CXX14) && _HAS_CXX14 == 1)
#define SY_HAS_CPP_14
#endif

/**
 * Determination a platform of an operation system
 * Fully supported supported only GNU GCC/G++, partially on Clang/LLVM
 */

#if defined(_WIN32)

#define SY_PLATFORM_NAME "windows" // Windows
#define SY_PLATFORM_WINDOWS
#elif defined(_WIN64)
#define SY_PLATFORM_NAME "windows" // Windows
#define SY_PLATFORM_WINDOWS
#elif defined(__CYGWIN__) && !defined(_WIN32)
#define SY_PLATFORM_NAME                                                       \
  "windows" // Windows (Cygwin POSIX under Microsoft Window)
#define SY_PLATFORM_WINDOWS

#elif defined(__linux__)
#define SY_PLATFORM_NAME                                                       \
  "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#define SY_PLATFORM_LINUX

#elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
#include <sys/param.h>
#if defined(__hpux)
#define SY_PLATFORM_NAME "hp-ux" // HP-UX
#elif defined(_AIX)
#define SY_PLATFORM_NAME "aix" // IBM AIX

#elif defined(__APPLE__) && defined(__MACH__) // Apple OSX and iOS (Darwin)
#include <TargetConditionals.h>
#define SY_PLATFORM_DARWIN

#if TARGET_IPHONE_SIMULATOR == 1
#define SY_PLATFORM_NAME "ios" // Apple iOS
#elif TARGET_OS_IPHONE == 1
#define SY_PLATFORM_NAME "ios" // Apple iOS
#elif TARGET_OS_MAC == 1
#define SY_PLATFORM_NAME "osx" // Apple OSX
#endif

#elif defined(BSD)
#define SY_PLATFORM_NAME "bsd" // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
#define SY_PLATFORM_BSD
#endif
#elif defined(__sun) && defined(__SVR4)
#define SY_PLATFORM_NAME "solaris" // Oracle Solaris, Open Indiana
#define SY_PLATFORM_SOLARIS
#else
//#define SY_PLATFORM_NAME NULL
#endif

#ifndef SY_PLATFORM_NAME
#define SY_PLATFORM_UNIX
#define SY_PLATFORM_NAME NULL
#endif

#if defined(SY_PLATFORM_LINUX) || defined(SY_PLATFORM_DARWIN) ||               \
    defined(SY_PLATFORM_BSD)
#define SY_PLATFORM_UNIX
#endif

#if defined(SY_PLATFORM_DARWIN)
#define SY_DLL_EXTENSION ".dylib"
#elif defined(SY_PLATFORM_WINDOWS)
#define SY_DLL_EXTENSION ".dll"
#else
#define SY_DLL_EXTENSION ".so"
#endif

#ifdef __cplusplus
extern "C" {
#endif

const char *sy_platform_name();

#ifdef __cplusplus
}
#endif