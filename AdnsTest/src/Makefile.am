include $(top_srcdir)/common.mk

bin_PROGRAMS = adns_test

AM_CPPFLAGS += -I$(top_srcdir)/@ADNS_DIR@/src
AM_LDFLAGS += -L$(top_srcdir)/@ADNS_DIR@/src -ladns
adns_test_SOURCES= adns_test.cpp
