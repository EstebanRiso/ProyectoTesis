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

    uint btlLenght(){
        return tl->btl_len;
    }

    int getNodes(){
      return tl->numberOfNodes;
    }

    int getK(){
      return 2;
    }

    int getHeight(){
      return tl->maxLevel;
    }

    bool checklink(uint i, uint j){
      if(compactCheckLinkQuery(tl,i,j)==0){
        return false;
      }
      return true;
    }



};

#endif



