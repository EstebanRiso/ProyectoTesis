#include "KNNElementQueue.hpp"





class KNNElementQueueComparator{

    public:
    int compare(KNNElementQueue o1 , KNNElementQueue o2){
        return o1.getDistance() - o2.getDistance();
    }
};