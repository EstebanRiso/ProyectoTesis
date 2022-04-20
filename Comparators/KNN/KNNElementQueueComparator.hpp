#include "KNNElementQueue.hpp"



//El comparador pero no se como agregarlo al priorityqueue
//CandidatesMaxComparator.hpp lo mismo, nose como agregarlo al priorityqueue


int compareKNNEQ2(KNNElementQueue o1 , KNNElementQueue o2){
    return o1.getDistance() - o2.getDistance();
