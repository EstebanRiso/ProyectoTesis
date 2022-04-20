#include "KNNElementQueue.hpp"




int compareKNNEQ1(KNNElementQueue o1, KNNElementQueue o2){
    if (o1.getDistance() > o2.getDistance()){
            return -1;
    }
    if (o1.getDistance() < o2.getDistance()){
         return 1;
    }

    return 0;
}
