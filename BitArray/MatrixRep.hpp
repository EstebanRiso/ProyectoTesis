#include "BitArrayRS.hpp"
#ifndef MATRIXREP_HPP
#define MATRIXREP_HPP
#endif


typedef struct MatrixRep{
    BITRS * btl;
    uint btl_len;               //Numero de bits de T:L
    uint bt_len;                //Numero de bits de T
    int maxLevel;           //Nivel maximo del arbol
    uint numberOfNodes;
    ulong numberOfEdges;
    uint * div_level_table;
    uint * info;
    uint * info2[2];
    uint * element;
    uint * basex;
    uint * basey;
    int iniq;
    int finq;
}MREP;
