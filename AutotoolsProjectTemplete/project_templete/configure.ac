# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT(make_instant_seeds, 1.0.0, guoshiwei@sohu-rd.com)
AC_CONFIG_AUX_DIR(_aux)
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_HEADER([package_config.h])

# Checks for system
AC_CANONICAL_HOST

# Checks for programs.
AC_LANG(C++)
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([iostream])

#for large file
CPPFLAGS="$CPPFLAGS -D_FILE_OFFSET_BITS=64 -D SS_DOCID_BITS=128"

#Example for AK_DETECT_LIB2: check ace
# AK_DETECT_LIB2(ace, [/usr/local/src/ACE* /usr/local/ACE* /opt/ACE*],
#             [ace/ACE.h], [ACE], [ACE::init],
#               [optional],
#               [], [ace])

AC_CACHE_SAVE

# Example for AK_CHECK_MODULE_ROOT: check SPIDERKERNEL_ROOT
#AK_CHECK_MODULE_ROOT(SPIDERKERNEL_ROOT, [the root of module spider_kernel], third-party/spider_kernel, [], [Library/Linux])

# finalize
AC_CONFIG_FILES([
        Makefile
])
AC_OUTPUT
