include $(top_srcdir)/common.mk

SUBDIRS=basetool
bin_PROGRAMS=pagefake_daemon

AM_CPPFLAGS += -I./basetool

AM_LDFLAGS += -L./basetool -lbasetool \
	      -lACE -lsasn1

pagefake_daemon_SOURCES=main.cpp \
		   PageFakeServer.cpp \
		   PageFakeMessage.cpp

check_PROGRAMS=unit_test

unit_test_SOURCES=unit_test_main.cpp

unit_test_LDFLAGS=-lboost_unit_test_framework \
		$(AM_LDFLAGS)
