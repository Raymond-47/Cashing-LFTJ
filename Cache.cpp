//
// Created by 景祖宽 on 2021/6/13.
//

#include "Cache.h"


Cache::Cache() {
    this->vas = std::vector<VariableAssignment>();
    this->ownedKeys = std::vector<std::vector<std::vector<int>>>();
    this->lastChecked = VariableAssignment();
}

void Cache::addAssignment(VariableAssignment ass) {
    this->vas.push_back(ass);
    std::vector<std::vector<int>> emptyArrayList = std::vector<std::vector<int>>();
    this->ownedKeys.push_back(emptyArrayList);
}

void Cache::removeAssignment(VariableAssignment ass) {
    this->ownedKeys.emplace(this->ownedKeys.begin()+getAssKey(ass));
}

void Cache::addOwnedKeyResults(VariableAssignment ass, std::vector<int> keys) {
    this->ownedKeys.at(getAssKey(ass)).push_back(keys);
}

std::vector<std::vector<int>> Cache::returnOwnedKeysPath(int key) {
    return this->ownedKeys.at(getAssKeyPath(key));
}

std::vector<std::vector<int>> Cache::returnOwnedKeysCycle(int key1, int key2) {
    return ownedKeys.at((getAssKeyCycle(key1,key2)));
}

int Cache::getAssKey(VariableAssignment ass) {
    int result = 0;
    for(VariableAssignment vasItem: vas){
        if(ass==vasItem){
            return result;
        }
        result++;
    }
    std::cout<<"Could not find VariableAssignment in current bag."<<std::endl;
    return -1;
}

int Cache::getAssKeyPath(int key) {
    int result = 0;
    for(int i =0;i<vas.size();i++){
        if(vas.at(i).assignment1 == key){
            return result;
        }
        result++;
    }
    std::cout<<"Could not find VariableAssignment in current bag."<<std::endl;
    return -1;
}

int Cache::getAssKeyCycle(int key1, int key2) {
    int result = 0;
    for(int i = 0; i < vas.size(); i++){
        if(vas.at(i).assignment1 == key1 && vas.at(i).assignment2 == key2){
            return result;
        }
        result++;
    }
    std::cout<<"Could not find VariableAssignment in current bag."<<std::endl;
    return -1;
}

bool Cache::containsAssignmentPath(int var, int ass) {
    for(VariableAssignment va : vas) {
        if (va.variable1 == var && va.assignment1 == ass) {
            lastChecked = va;
            return true;
        }
    }
    return false;
}

bool Cache::containsAssignmentCycle(int var1, int ass1, int var2, int ass2) {
    for(VariableAssignment va : vas) {
        if (va.variable1 == var1 && va.assignment1 == ass1 && va.variable2 == var2 && va.assignment2 == ass2) {
            lastChecked = va;
            return true;
        }
    }
    return false;
}