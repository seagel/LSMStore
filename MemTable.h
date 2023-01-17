//
// Created by Somesh Mehta on 1/10/23.
//
#ifndef LSMSTORE_MEMTABLE_H
#define LSMSTORE_MEMTABLE_H

#include <set>

class MemTableEntry {
public :
    int key;
    int value;
    long timestamp;
    bool isDeleted;

    MemTableEntry() {

    }

    MemTableEntry(int key) {
        this->key = key;
        this->isDeleted = false;
    }

    std::string toString() const;

    friend bool operator<(const MemTableEntry &A, const MemTableEntry &B);
};

class MemTable {
public :
    std::set<MemTableEntry> entries;

    MemTable() {
        entries = std::set<MemTableEntry>();
    }

    uint32_t size();

    std::set<MemTableEntry>::iterator get(int key);

    bool set(int key, int value);

    bool deleteK(int key);

    void log();

    void log(std::set<MemTableEntry>::iterator it);
};


#endif //LSMSTORE_MEMTABLE_H
