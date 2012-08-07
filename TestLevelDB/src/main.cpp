/**
 *    \file   main.cpp
 *    \brief  Test leveldb
 *    \date   2012Äê08ÔÂ07ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <assert.h>
#include <string>
#include <iostream>
#include "leveldb/db.h"
#include "leveldb/write_batch.h"

using namespace std;

void write(leveldb::DB *db)
{
    std::string key("Test key 1");
    std::string value("Value 1");
    leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);
    assert(s.ok());
}
void read_and_write(leveldb::DB *db)
{
    std::string key1("Test key 1");
    std::string key2("Test key 2");

    std::string value("Test read and write");
    leveldb::Status s = db->Get(leveldb::ReadOptions(), key1, &value);
    if (s.ok()) s = db->Put(leveldb::WriteOptions(), key2, value);
    if (s.ok()) s = db->Delete(leveldb::WriteOptions(), key1);
}

void batch_update(leveldb::DB *db)
{
    std::string key1("Test key 1");
    std::string key2("Test key 2");

    std::string value;
    leveldb::Status s = db->Get(leveldb::ReadOptions(), key1, &value);
    if (s.ok()) {
        leveldb::WriteBatch batch;
        //        batch.Delete(key1);
        batch.Put(key2, value);
        s = db->Write(leveldb::WriteOptions(), &batch);
    }

}

void iter(leveldb::DB *db)
{
    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next()) {
        cout << it->key().ToString() << ": "  << it->value().ToString() << endl;
    }
    assert(it->status().ok());  //x Check for any errors found during the scan

}
int main(int argc, char **argv)
{

    leveldb::DB* db = NULL;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "./__testdb", &db);
    assert(status.ok());

    write(db);
    read_and_write(db);
    batch_update(db);
    iter(db);
    delete db;
    return 0;
}
