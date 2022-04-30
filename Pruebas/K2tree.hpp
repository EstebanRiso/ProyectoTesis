#include <iostream>
#include <vector>
#include "matrixrep.hpp"

#ifndef K2TREE_HPP
#define K2TREE_HPP

using namespace std;

class K2Tree{

    private:

    MREP* tl;

    public:
    K2Tree();
    ~K2Tree(){};

    K2Tree(MREP *a){
      tl=a;
    }


    BITRS* getBitArrayRS(){
        return tl->btl;
    }

    int getNodes(){
      return 1;
    }

    int getK(){
      return 2;
    }

    int getHeight(){
      return tl->maxLevel;
    }
};

#endif



