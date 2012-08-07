include $(top_srcdir)/common.mk

LDB_CPPFLAGS=-I/home/guoshiwei/development/source_reading/leveldb/include
LDB_LDFLAGS=-L/home/guoshiwei/development/source_reading/leveldb/ -lleveldb -lpthread

bin_PROGRAMS=test_leveldb
test_leveldb_SOURCES=main.cpp
test_leveldb_CPPFLAGS = $(LDB_CPPFLAGS)
test_leveldb_LDFLAGS = $(LDB_LDFLAGS)
