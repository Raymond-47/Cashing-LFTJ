//
// Created by 景祖宽 on 2021/6/12.
//

#ifndef CACHING_LFTJ_TREENODE_H
#define CACHING_LFTJ_TREENODE_H

#include <vector>

class TreeNode{
private:
    TreeNode* parent = nullptr;
    std::vector<TreeNode*> children;
    int key; // Containing the note's key value.
    int childNumber = 0; // Containing how much children were born before him(with the same parent).
    int depth; // The current depth we are at.

public:

    /**
     * Constructor for the TreeNode, sets the parameters and initializes the children array.
     * @param key The key value of the node.
     * @param depth The depth at which this node is inserted.
     * @param childNumber The amount of siblings that were born before this node.
     */
    TreeNode(int key, int depth, int childNumber);

    /**
     * We add a child to the current node.
     * @param childKey The key value of the child.
     * @param childDepth The depth at which this child is inserted.
     * @param childNumber The amount of siblings that were born before this child.
     * @return TreeNode of this child.
     */
    TreeNode* addChild(int childKey, int childDepth, int childNumber);

    /**
     * @return parent of this node.
     */
    TreeNode* up();

    /**
     * @return the first child of this node.
     */
    TreeNode* down();

    /**
     * @return whether we can still continue to call next.
     */
    bool hasNext();

    /**
    * @return the sibling born after this node.
    */
    TreeNode* next();

    /**
     * @return key value of this node.
     */
    int getKey();

    /**
     * @return depth of this node.
     */
    int getDepth();

    /**
     * @return the amount of children this node has.
     */
    int getAmountOfChildren();

    /**
     * @return the amount of siblings that were born before this child.
     */
    int getBornIndexOfThisChild();

    /**
     * Gets the child at a specific index.
     * @param numberOfChild the index of the currentChild.
     * @return TreeNode of the child at the given index.
     */
    TreeNode* getChild(int numberOfChild);

    /**
     * Gets the parent at a specific index.
     * @return TreeNode of the parent.
     */
    TreeNode* getParent();

private:
    /**
     * Sets the child number.
     * @param childNumber How much siblings were born before this node.
     */
    void setChildNumber(int childNumber);

    /**
     * Sets the depth of this note.
     * @param depth of this note.
     */
    void setDepth(int depth);

    /**
     * Sets the key of this note.
     * @param key value of this note.
     */
    void setKey(int key);

    /**
     * Sets the parent of this note.
     * @param parent TreeNote of the parent.
     */
    void setParent(TreeNode* parent);

};

#endif //CACHING_LFTJ_TREENODE_H
