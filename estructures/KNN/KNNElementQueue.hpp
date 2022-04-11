#ifndef KNNELEMENTQUEUE_HPP
#define KNNELEMENTQUEUE_HPP






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

        void toString(){
            return;
        }

};


#endif