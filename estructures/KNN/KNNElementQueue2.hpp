#ifndef KNNELEMENTQUEUE2_HPP
#define KNNELEMENTQUEUE2_HPP
#endif
#include "rectangle.hpp"


class KNNElementQueue2{

    private:

    long pos;
    Rectangle cuadrant;
    int distance;
    int level;
    double radio;
    
    public:
    
    KNNElementQueue2(long pos, Rectangle cuadrant, int distance, int level){
        this->pos=pos;
        this->cuadrant=cuadrant;
        this->distance=distance;
        this->level=level;
        this->radio=cuadrant.getT().getY()/2;
    }

    double getRadio(){
        return radio;
    }

    void setRadio(double radio){
        this->radio = radio;
    }

    int getLevel(){
        return level;
    }

    long getPos(){
        return pos;
    }

    Rectangle getCuadrant(){
        return cuadrant;
    }

    int getDistance(){
        return distance;
    }

    void toString(){
        return;
    }

    int compareTo(){

    }


};