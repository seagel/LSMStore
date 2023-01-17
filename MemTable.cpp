//
// Created by Somesh Mehta on 1/10/23.
//

#include "MemTable.h"
#include <iostream>

//bool MemTableEntry::operator==(const MemTableEntry &A, const MemTableEntry &B) {
//    return A.key == B.key;
//}

// get size of the whole table
u_int32_t MemTable::size() {
    return entries.size() * (sizeof(int) * 2 + sizeof(long) + sizeof(bool));
}

std::set<MemTableEntry>::iterator MemTable::get(int key) {
    MemTableEntry entry;
    entry.key = key;
    return entries.find(entry);
}

bool MemTable::set(int key, int value) {
    MemTableEntry entry;
    entry.key = key;
    entry.timestamp = std::time(nullptr);
    entry.value = value;
    entry.isDeleted = false;
    entries.insert(entry);
}

bool MemTable::deleteK(int key) {
    auto it = get(key);
    MemTableEntry copy;
    copy.key = it->key;
    copy.value = it->value;
    copy.timestamp = std::time(nullptr);
    copy.isDeleted = true;
    entries.erase(it);
    entries.insert(copy);
    return true;
}

void MemTable::log() {
    for (auto entry: entries) {
        !entry.isDeleted && std::cout << entry.toString() << std::endl;
    }
}

void MemTable::log(std::set<MemTableEntry>::iterator it) {
    if (it == entries.end()) {
        std::cout << "Key doesn't exist" << std::endl;
    }
    std::string result;
    result = it->isDeleted ? (std::to_string(it->key) + " key is deleted") :
             (std::to_string(it->key) + ": " +
              std::to_string(it->value)
              + " TimeStamp- " +
              std::to_string(it->timestamp));
    std::cout << result << std::endl;
}


bool operator<(const MemTableEntry &A, const MemTableEntry &B) {
    return A.key < B.key;
}

std::string MemTableEntry::toString() const {
    std::string result = this->isDeleted ? (std::to_string(this->key) + " key is deleted") : (
            std::to_string(this->key) + ": " +
            std::to_string(this->value)
            + " TimeStamp- " +
            std::to_string(this->timestamp));
    return result;
}
