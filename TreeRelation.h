//
// Created by 景祖宽 on 2021/6/12.
//

#ifndef CACHING_LFTJ_TREERELATION_H
#define CACHING_LFTJ_TREERELATION_H

#include <iterator>
#include "TreeNode.h"
#include "RelationIterator.h"



class TreeRelation{
private:
    TreeNode * currentNode; // Current node we are looking at.
    int uid; // Unique identifier for each relation

public:
    /**
     * Sets the UID of the relation.
     * @param uid Unique identifier for this relation. Easy while debugging.
     */
    void setUid(int uid);

    /**
     * Function which converts the data sets into a tree structure.
     * @param relArray Contains a double array containing all the data.
     * @param debug Specifies whether we want to output all information or not.
     * When? At initialization.
     * Modifies? currentNode to be equal to the root node of the tree.
     */
    TreeRelation(std::vector<std::vector<int>> relArray, bool debug);

    /**
    * The RelationIterator which allows us to sort our collections easily.
    */
    RelationIterator * iterator(TreeNode * currentNode,int uid);

    class Iterator:public  RelationIterator{
    private:
        bool atend = false;// Keeping track whether our iterator is at it's end.
        TreeNode * currentNode;
        int uid;
    public:
        Iterator(TreeNode * currentNode,int uid);
        int key();
        bool hasNext();
        int next();
        void seek(int seekKey);
        bool atEnd();
        int compareTo(RelationIterator o);
        void open();
        void up();
    private:
        void binarySearch(TreeNode* parentNode, int minIndex, int searchValue);
    public:
        std::string getCurrentNodeInfo(const TreeNode* currentNode);
        std::string debugString();
        void remove();
    };

};



#endif //CACHING_LFTJ_TREERELATION_H
