#include <k2tree.hpp>
#include <KNNElementQueue.hpp>
#include <KNNElementQueue2.hpp>
#include <queue>

class KNN{
    private:
    int K;
    BITRS *TL;
    //BitArrayRS;
    int ALTURA;
    int CANTIDADHIJOS;
    K2Tree K2TREE;
    int cantDistanceCalculation;
    //PriorityQueue?
    priority_queue<KNNElementQueue> pQueue;
    priority_queue<KNNElementQueue> candidates;

    public:
    KNN(K2Tree k2){
        this->K2TREE=k2;
        this->TL=k2.getBitArrayRS();
        ALTURA;
        
    }

    priority_queue<KNNElementQueue> findNNQ{
        
    }


};