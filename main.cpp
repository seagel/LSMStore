#include <iostream>
#include "MemTable.h"

int main() {
    MemTable memTable;
    memTable.set(4,5);
    memTable.set(1,4);
    memTable.log();
    memTable.log(memTable.get(4));
    memTable.deleteK(4);
    memTable.log();
    memTable.log(memTable.get(4));
    return 0;
}
