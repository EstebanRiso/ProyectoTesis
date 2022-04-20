#ifndef KNNELEMENTQUEUE_HPP
#define KNNELEMENTQUEUE_HPP
#include "Rectangle.hpp"





class KNNElementQueue{

    private:
        long pos;
        Rectangle cuadrant;
        int distance;
        int level;
    
    public:

        KNNElementQueue(long pos, Rectangle cuadrant, int distance, int level){
            this->pos=pos;
            this->cuadrant=cuadrant;
            this->distance=distance;
            this->level=level;
        }
       
        int getLevel(){
            return level;
        }

        int long getPos(){
            return pos;
        }

        int getDistance(){
            return distance;
        }

        Rectangle getCuadrant(){
            return cuadrant;
        }

        void toString(){
            return;
        }

        bool empty(){
            if(this)return true;
            else return false;
        }

};


#endif