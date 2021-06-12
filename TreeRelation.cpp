//
// Created by 景祖宽 on 2021/6/12.
//

#include "TreeRelation.h"
#include <iostream>
#include <sstream>
#include <string>
#include <exception>

void TreeRelation::setUid(int uid) {
    this->uid = uid;
}

TreeRelation::TreeRelation(std::vector<std::vector<int>> relArray, bool debug) {
    if(debug){
        std::cout<<"------------------------ LOADING IN DATA ------------------------"<<std::endl;
        std::cout<<"Add root =[-1]"<<std::endl;
    }
    TreeNode * rootNode = new TreeNode(-1,-1,0);
    int j = relArray[0][0];
    if(debug){std::cout << "Add parent =[" << relArray[0][0] << "]" << std::endl;}
    this->currentNode = rootNode->addChild(relArray[0][0],0,0);
    int parentCounter = 1;
    int childCounter = 0;

    for(auto aRelArray: relArray){
        if(j == aRelArray[0]){
            if(debug){
                std::cout << "Add child [" << this->currentNode->getKey() << "][" << aRelArray[1] <<"]" << std::endl;
            }
            this->currentNode->addChild(aRelArray[1],1,childCounter);
            this->currentNode->addChild(aRelArray[1],1,childCounter);
            childCounter++;
        }else{
            if(debug){
                std::cout << "Add parent =[ " << aRelArray[0] <<" ]" << std::endl;
            }
            this->currentNode = rootNode->addChild(aRelArray[0],0,parentCounter);
            parentCounter++;
            j = aRelArray[0];
            if(debug){
                std::cout<<"Add child ["<<this->currentNode->getKey()<<"]["<<aRelArray[1]<<"]"<<std::endl;
            }
            childCounter = 0;
            this->currentNode->addChild(aRelArray[1],1,childCounter);
            childCounter++;
        }
    }
}

RelationIterator * TreeRelation::iterator(TreeNode * currentNode,int uid) {
    RelationIterator * relIt = new Iterator(currentNode,uid);
    return relIt;
}

TreeRelation::Iterator::Iterator(TreeNode *currentNode, int uid) {
    this->currentNode = currentNode;
    this->uid = uid;
}

int TreeRelation::Iterator::key() {
    return this->currentNode->getKey();
}

bool TreeRelation::Iterator::hasNext() {
    return this->currentNode->hasNext();
}

int TreeRelation::Iterator::next() {
    if(this->currentNode->getBornIndexOfThisChild() + 1 >= this->currentNode->getParent()->getAmountOfChildren()){
        atend = true;
    }else{
        this->currentNode = currentNode->next();
    }
    return this->currentNode->getKey();
}

void TreeRelation::Iterator::seek(int seekKey) {
    this->binarySearch(this->currentNode->getParent(),this->currentNode->getBornIndexOfThisChild(),seekKey);
}

bool TreeRelation::Iterator::atEnd() {
    return this->atend;
}

int TreeRelation::Iterator::compareTo(RelationIterator o) {
    if(this->key() > o.key()){
        return 1;
    }else if(this->key() == o.key()){
        return 0;
    }else{
        return -1;
    }
}

void TreeRelation::Iterator::open() {
    this->currentNode = currentNode->down();
}

void TreeRelation::Iterator::up() {
    atend = false;
    TreeNode *nextNode = currentNode->up();
    if(nextNode != nullptr){
        this->currentNode = nextNode;
    }else{
        std::cout<<"We called up at a treeNode.. that shouldn't happen...."<<std::endl;
    }
}

void TreeRelation::Iterator::binarySearch(TreeNode *parentNode, int minIndex, int searchValue) {
    int min = minIndex;
    int max = parentNode->getAmountOfChildren();
    while(max > min){
        int middle = (min + max)/2;
        if(parentNode->getChild(middle)->getKey() == searchValue){
            max = middle;
        }
        if(parentNode->getChild(middle)->getKey() < searchValue){
            max = middle + 1;
        }
        if(parentNode->getChild(middle)->getKey() > searchValue){
            max = middle - 1;
        }
    }
    if(min >= parentNode->getAmountOfChildren()){
        atend = true;
        this->currentNode = parentNode->getChild(parentNode->getAmountOfChildren() - 1);
    }else{
        if(parentNode->getChild(min)->getKey() < searchValue){
            this->currentNode = parentNode->getChild(min);
        }
        if(parentNode->getChild(min)->getKey() < searchValue){
            if(min + 1 == parentNode->getAmountOfChildren()){
                atend = true;
                this->currentNode = parentNode->getChild(parentNode->getAmountOfChildren() - 1);
            }else{
                this->currentNode = parentNode->getChild(min + 1);
            }
        }
        if(parentNode->getChild(min)->getKey() > searchValue){
            currentNode = parentNode->getChild(min);
        }
    }
}

std::string TreeRelation::Iterator::getCurrentNodeInfo(const TreeNode *currentNode) {
    std::stringstream ss;
    ss<<"CurrentNode = ["<<this->currentNode->getParent()->getKey()<<"]["<<this->currentNode->getKey()<<"] "<<" Depth = "<< this->currentNode->getDepth()<<" Parent depth = "<<this->currentNode->getParent()->getDepth();
    return ss.str();
}

std::string TreeRelation::Iterator::debugString() {
    if(this->currentNode->getParent() != nullptr){
        std::stringstream ss;
        ss << "uid: " << this->uid << ", key: " << this->key() << ", depth: " << this->currentNode->getDepth() << ", parentKey: " << this->currentNode->getParent()->getKey() << ", amount of children: " << this->currentNode->getAmountOfChildren() << ", get amount of brothers: " << this->currentNode->getParent()->getAmountOfChildren() << ", compared to brothers at index: " << this->currentNode->getBornIndexOfThisChild();
        return ss.str();
    }else{
        std::stringstream ss;
        ss << "uid: " << this->uid << ", key: " << this->key() << ", depth: " << this->currentNode->getDepth() << ", amount of children: " << this->currentNode->getAmountOfChildren() << ", This is the root note...";
        return ss.str();
    }
}

void TreeRelation::Iterator::remove() {
    throw std::domain_error("Not supported yet");
}