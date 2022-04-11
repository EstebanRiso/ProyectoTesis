#include <iostream>
#include <vector>
#include "matrixrep.hpp"

using namespace std;

class K2Tree{

    private:

    MREP* tl;

    public:
    K2Tree();

    K2Tree(MREP *a){
      tl=a;
    }


    BITRS* getBitArrayRS(){
        return tl->btl;
    }

};





