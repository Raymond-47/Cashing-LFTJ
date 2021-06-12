//
// Created by 景祖宽 on 2021/6/12.
//

#include "TreeNode.h"

TreeNode::TreeNode(int key, int depth, int childNumber){
    this->setKey(key);
    this->setDepth(depth);
    this->setChildNumber(childNumber);
    this->children = std::vector<TreeNode*>();
}

TreeNode * TreeNode::addChild(int childKey, int childDepth, int childNumber) {
    auto child = new TreeNode(childKey,childDepth,childNumber);
    child->setParent(this);
    this->children.push_back(child);
    return child;
}

TreeNode* TreeNode::up() {
    return this->parent;
}

TreeNode* TreeNode::down() {
    return this->children.at(0);
}

bool TreeNode::hasNext() {
    return this->parent->children.size() - 1 != this->childNumber;
}

TreeNode* TreeNode::next(){
    return this->parent->getChild(childNumber+1);
}

int TreeNode::getKey() {
    return this->key;
}

int TreeNode::getDepth() {
    return this->depth;
}

int TreeNode::getAmountOfChildren() {
    return children.size();
}

int TreeNode::getBornIndexOfThisChild() {
    return childNumber;
}

TreeNode* TreeNode::getChild(int numberOfChild) {
    return this->children.at(numberOfChild);
}

TreeNode* TreeNode::getParent() {
    return this->parent;
}

void TreeNode::setChildNumber(int childNumber) {
    this->childNumber = childNumber;
}

void TreeNode::setDepth(int depth) {
    this->depth = depth;
}

void TreeNode::setKey(int key) {
    this->key = key;
}

void TreeNode::setParent(TreeNode* parent) {
    this->parent = parent;
}