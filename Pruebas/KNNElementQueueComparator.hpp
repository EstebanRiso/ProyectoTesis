#ifndef KNNELEMENTQUEUECOMPARATOR_HPP
#define KNNELEMENTQUEUECOMPARATOR_HPP
#include "KNNElementQueue.hpp"



//El comparador pero no se como agregarlo al priorityqueue
//CandidatesMaxComparator.hpp lo mismo, nose como agregarlo al priorityqueue

struct MINHEAP{

    bool operator()(KNNElementQueue const& o1 , KNNElementQueue const& o2){

        KNNElementQueue a=o1;
        KNNElementQueue b=o2;

        return a.getDistance() > b.getDistance();
    }
};

#endif