#include <k2tree.hpp>
#include <KNNElementQueue.hpp>
#include <KNNElementQueue2.hpp>
#include <queue>

#ifndef KNN_HPP
#define KNN_HPP

class KNN{
    private:

        int k;
        BITRS *TL;
        //BitArrayRS;
        int ALTURA;
        int CANTIDADHIJOS;
        K2Tree K2TREE;
        int cantDistanceCalculation;
        //PriorityQueue?
        priority_queue<KNNElementQueue> pQueue;
        priority_queue<KNNElementQueue> candidates;

        Point traductionPointQ(Point q) {
            return Point(q.getId(), q.getY(),abs(q.getX() - K2TREE.getNodes()) + 1, q.getDistance());
        }


        bool isLeaf(KNNElementQueue tmp){
            return tmp.getLevel() > ALTURA;
        }


        void evaluateCandidates(KNNElementQueue tmp, priority_queue<KNNElementQueue> pQueue, priority_queue<KNNElementQueue> Cand, int k, Point q){
            int accumX=0;
            int accumY=0;
            bool flag = false;
            long posHijo= tmp.getPos();
            Point S=tmp.getCuadrant().getS();
            Point T=tmp.getCuadrant().getT();
            int secuence= getSecuence(tmp);
            Rectangle temp;
            if(tmp.getLevel()== K2TREE.getHeight()){
                accumX = S.getX();
                accumY = T.getY();  
                flag=true;
            }else{
                accumX = S.getX();
                accumY = T.getY() - secuence;
            }
        }

        int getSecuence(KNNElementQueue tmp){
            return (tmp.getCuadrant().getT().getY()- tmp.getCuadrant().getS().getY())/K;
        }

        int minDist( Point p, Rectangle R){
            int R1=0;
            int R2=0;

            if(R.Contains(p)){
                return 0;
            } else{
                if(p.getX() < R.getS().getX()){
                    R1=R.getS().getX();
                } else{
                    if(p.getX() > R.getT().getX()){
                        R1=R.getT().getX();
                    } else{
                        R1= p.getX();
                    }
                }
            }
            if (p.getY() < R.getS().getY()){
                R2=R.getS().getY();
            } else{
                if( p.getY() > R.getT().getY()){
                    R2=R.getT().getY();
                } else{
                    R2= p.getY();
                }
            }

            int value1 = p.getX() - R1;
            int value2 = p.getY() - R2;

            return (int) abs(value1*value1)+ abs(value2*value2);
        }


    public:

        KNN(K2Tree k2){
            this->K2TREE=k2;
            this->TL=k2.getBitArrayRS();
            this->k=k2.getK();
            ALTURA=k2.getHeight();
            CANTIDADHIJOS=K*K;
        }

        priority_queue<KNNElementQueue> findNNQ(int k, Point q){
            q= traductionPointQ(q);
            // almacena el 

            int dist = -1;

            Rectangle quad=Rectangle( Point(1,1) , Point(K2TREE.getNodes(),K2TREE.getNodes()));
            KNNElementQueue e= KNNElementQueue(0,quad,minDist(q,quad),1);

            pQueue.push(e);

            while(!pQueue.empty()){
                KNNElementQueue tmp= pQueue.top();
                pQueue.pop();
                KNNElementQueue obj= candidates.top();
                if(candidates.size()!=0){ //identificar si tiene o no elementos;
                    dist=obj.getDistance();
                }
                if((candidates.size()==k)&&(tmp.getDistance() >=dist)){
                    return candidates;
                }
                if(isLeaf(tmp)){
                    if(candidates.size()<k){
                        candidates.push(tmp);
                    } else{
                        KNNElementQueue aux= candidates.top();
                        if(tmp.getDistance() < aux.getDistance()){
                            candidates.pop();
                            candidates.push(tmp);
                        }
                    }
                } else {
                    evaluateCandidates(tmp,pQueue, candidates, k, q);
                }
            }
            return candidates;
        }




   
        int getCantDistanceCalculations(){
            return cantDistanceCalculation;
        }

        priority_queue<KNNElementQueue> getPqueue(){
            return pQueue;
        }

        priority_queue<KNNElementQueue> getCandidates(){
            return candidates;
        }

};

#endif