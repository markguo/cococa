# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT(AdnsTest, 1.0.0, guoshiwei@sohu-rd.com)
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

AC_CONFIG_SUBDIRS([third-party/adns-1.2])

AC_SUBST(ADNS_DIR, [third-party/adns-1.2])

# finalize
AC_CONFIG_FILES([
	Makefile
	src/Makefile
])
AC_OUTPUT
