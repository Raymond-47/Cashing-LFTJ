//
// Created by 景祖宽 on 2021/6/13.
//

#ifndef CACHING_LFTJ_CACHE_H
#define CACHING_LFTJ_CACHE_H

#include <iostream>
#include <vector>
#include "VariableAssignment.h"

class Cache{
private:
    std::vector<VariableAssignment> vas;
    VariableAssignment lastChecked;
    std::vector<std::vector<std::vector<int>>> ownedKeys;

public:
    Cache();
    void addAssignment(VariableAssignment ass);
    void removeAssignment(VariableAssignment ass);
    void addOwnedKeyResults(VariableAssignment ass,std::vector<int> keys);
    std::vector<std::vector<int>> returnOwnedKeysPath(int key);
    std::vector<std::vector<int>> returnOwnedKeysCycle(int key1,int key2);

private:
    int getAssKey(VariableAssignment ass);
    int getAssKeyPath(int key);
    int getAssKeyCycle(int key1, int key2);

public:
    bool containsAssignmentPath(int var,int ass);
    bool containsAssignmentCycle(int var1,int ass1,int var2,int ass2);

};

#endif //CACHING_LFTJ_CACHE_H
