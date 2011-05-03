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

#check ace
AK_DETECT_LIB2(ace, [/usr/local/src/ACE* /usr/local/ACE* /opt/ACE*],
               [ace/ACE.h], [ACE], [ACE::init],
               [optional],
               [], [ace])

AK_DETECT_LIB2(mysql, [/usr/local/include /usr/include /opt/sogou],
               [mysql/mysql.h], [mysqlclient], [],
               [required],
               [],[])
#check offdb
AK_DETECT_LIB2(offdb, [/usr/local/include /usr/include /opt/sogou],
               [offdb/OffPage.h], [offdb], [],
               [required],
               [],[])

AK_DETECT_LIB2(encoding, [/usr/local/include /usr/include /opt/sogou],
               [Platform/encoding.h], [encoding], [],
               [required],
               [],[])

AK_DETECT_LIB2(ssplatform2, [/usr/include /usr/local/include /opt/sogou],
               [Platform/md5/md5.h],[ssplatform], [], 
               [required],
               [],[])

#check simple ASN.1
#AK_DETECT_LIB2(sasn1, [],
#	[sasn1/simple_asn1.h], [sasn1], [asn1_ber_encode],
#	[optional],
#	[], [])
#

##check db4 
#AK_DETECT_LIB2(db4, [],
#	[db.h], [db-4.4 db-4.3 db-4.2 db], db_create,
#	[optional],
#	[], [])

##check sqlite 
#AK_DETECT_LIB2(sqlite3, [],
#	[sqlite3.h], [sqlite3], sqlite3_exec,
#	[optional],
#	[], [])

AC_CACHE_SAVE

AK_CHECK_MODULE_ROOT(SPIDERKERNEL_ROOT, [the root of module spider_kernel], third-party/spider_kernel, [], [Library/Linux])
AK_CHECK_MODULE_ROOT(WEBSPIDER_ROOT, [the root of module web_spider], third-party/web_spider, [], [Library/Linux])
AK_CHECK_MODULE_ROOT(WEB_SELECTOR_ROOT, [the root of module web_selector], third-party/web_selector, [], [Library/Linux])
AK_CHECK_MODULE_ROOT(WEB_DATAMINE_ROOT, [the root of module web_datamine], third-party/web_datamine, [], [Library/Linux])
AK_CHECK_BUILD_DEPENDENCIES([yes], [$MODULE_ROOT_VALUES])

# finalize
AC_CONFIG_FILES([
	Makefile
	src/Makefile
	src/Common/Makefile
	src/PageSource/Makefile
	src/AntispamPage/Makefile
	src/Application/Makefile
	src/snapshot_reader/Makefile
])
AC_OUTPUT
