//
// Created by 景祖宽 on 2021/6/12.
//

#ifndef CACHING_LFTJ_RELATIONITERATOR_H
#define CACHING_LFTJ_RELATIONITERATOR_H

#include <iterator>


class RelationIterator{
public:
    virtual int key() = 0;
    virtual void seek(int seekKey) = 0;
    virtual bool atEnd() = 0;
    virtual void open() = 0;
    virtual void up() = 0;
    virtual std::string debugString() = 0;
};


#endif //CACHING_LFTJ_RELATIONITERATOR_H
