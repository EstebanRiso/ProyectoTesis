#include "k2tree.hpp"
#include "KNNElementQueue.hpp"
#include <queue>
#include "KNNElementQueueComparator.hpp"
#include "CandidatesMaxComparator.hpp"

#ifndef KNN_HPP
#define KNN_HPP

class KNN{
    private:

        int k;
        BITRS *TL;
        //BitArrayRS;
        int ALTURA;
        int CANTIDADHIJOS;
        K2Tree *K2TREE;
        int cantDistanceCalculation;
        //PriorityQueue?
        priority_queue<KNNElementQueue,vector<KNNElementQueue>,MINHEAP> pQueue;
        priority_queue<KNNElementQueue,vector<KNNElementQueue>,MAXHEAP> candidates;



        Point traductionPointQ(Point q) {
            return  Point(q.getId(), q.getY(),abs(q.getX() - K2TREE->getNodes()) + 1, q.getDistance());
        }

        bool isCandidate(priority_queue<KNNElementQueue,vector<KNNElementQueue>,MAXHEAP> Cand, int k, int minD){
           cout<<"ME ADENTRE EN IS CANDIDATE"<<endl;
           cout<<"el size de cand es:"<<Cand.size()<<endl;

            
           int dist=0;
        
           if(Cand.size()!=0){
              KNNElementQueue objs=Cand.top();   
              if(!objs.empty()){
               dist=objs.getDistance();
              }
           }
           cout<<"ASIGNE EN ANTERIORIDAD UN ELEMENTO"<<endl;
          
           return (Cand.size()< k || minD < dist);

        }

        bool isLeaf(KNNElementQueue tmp){
            return tmp.getLevel() > ALTURA;
        }


        void evaluateCandidates(KNNElementQueue tmp, priority_queue<KNNElementQueue,vector<KNNElementQueue>,MINHEAP> pQueue, priority_queue<KNNElementQueue,vector<KNNElementQueue>,MAXHEAP> Cand, int k, Point q){
            
            cout<<"ESTOY EN EL METODO EVALUATE CANDIDATE"<<endl;
            int accumX=0;
            int accumY=0;
            bool flag = false;
            uint posHijo= tmp.getPos();
            Point S=tmp.getCuadrant().getS();
            Point T=tmp.getCuadrant().getT();
            int secuence= getSecuence(tmp);
            cout<<"esta es la secuence:"<<secuence<<endl;
            Rectangle temp;

            cout<<"VOY A DENTRARME EN UN IF"<<endl;
            if(tmp.getLevel()== K2TREE->getHeight()){

                cout<<"ESTOY EN EL IF"<<endl;
                accumX = S.getX();
                accumY = T.getY();  
                flag=true;
            }else{
                cout<<"ESTOY EN EL ELSE"<<endl;
                accumX = S.getX();

                cout<<S.getX()<<endl;
                cout<<T.getY()<<endl;

                accumY = T.getY() - secuence;

                cout<<accumY<<endl;
            }
            
            cout<<"la cantidad de hijos es:"<<CANTIDADHIJOS<<endl;

            for(int i=1;i<=CANTIDADHIJOS;i++){
                cout<<"ciclo for"<<endl;
                if(accumX >T.getX()){
                    accumY=accumY-secuence-1;
                    accumX=S.getX();
                }
                cout<<"voy a entrar en ese if de bitaccess"<<endl;
                if( bitaccess(TL->data,posHijo) != 0){
                    cout<<"he entrado"<<endl;
                    temp= Rectangle(new Point(accumX,accumY),new Point(accumX+secuence,accumY+secuence));
                    cout<<"voy a entrar en mindist"<<endl;
                    int minD = minDist(q,temp);
                    cout<<"termino el mindist y el resultado es:"<<minD<<endl;
                    if(isCandidate(Cand,k,minD)){
                        cout<<"ESTAMOS EN IS CANDIDATE"<<endl;
                        pQueue.push(getCandidate(temp,posHijo,tmp.getLevel()+1,minD));
                    }
                }
            }
            accumX=accumX+secuence+1;
            posHijo++;
        }

        KNNElementQueue getCandidate(Rectangle tmp, uint posHijo, int level, int minD) {
        return  KNNElementQueue((rank1(TL,posHijo) * (K * K)), &tmp, minD, level);
        }

        int getSecuence(KNNElementQueue tmp){
            return (tmp.getCuadrant().getT().getY()- tmp.getCuadrant().getS().getY())/K;
        }

        int minDist( Point p, Rectangle R){

            cout<<"entré en mindist"<<endl;

            int R1=0;
            int R2=0;
            cout<<"voy a entrar en un if de mindist"<<endl;
            if(R.Contains(p)){
                cout<<"entre en el if de mindist"<<endl;
                return 0;
            } else{
                cout<<"entre en el else de mindist"<<endl;
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

            cout<<"asignar los valores de mindist"<<endl;
            int value1 = p.getX() - R1;
            int value2 = p.getY() - R2;

            return (int) abs(value1*value1)+ abs(value2*value2);
        }


    public:


        KNN(K2Tree *k2){
            this->K2TREE=k2;
            this->TL=k2->getBitArrayRS();
            this->k=k2->getK();
            ALTURA=k2->getHeight();
            CANTIDADHIJOS=K*K;
        }

        ~KNN(){}

        priority_queue<KNNElementQueue,vector<KNNElementQueue>,MAXHEAP> findNNQ(int k, Point q){

            cout<<"ESTOY ADENTRO DEL METODO"<<endl;

            // almacena el 
            int dist = -1;
            uint diss=0;

            Rectangle quad= Rectangle( new Point(1,1) , new Point(K2TREE->getNodes(),K2TREE->getNodes()));
            KNNElementQueue e= KNNElementQueue(diss,&quad,minDist(q,quad),1);

            pQueue.push(e); 

            while(!pQueue.empty()){
                KNNElementQueue tmp= pQueue.top();
                cout<<tmp.getDistance()<<endl;
                pQueue.pop();
                cout<<"a punto de adentrarme en algo"<<endl;

                if(candidates.size()!=0){ //identificar si tiene o no elementos;
                    KNNElementQueue obj= candidates.top();
                    cout<<"estoy en el if"<<endl;
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
                    cout<<"VOY A IR A EVALUATE CANDIDATE"<<endl;
                    evaluateCandidates(tmp,pQueue, candidates, k, q);
                }
            }
            return candidates;
        }




   
        int getCantDistanceCalculations(){
            return cantDistanceCalculation;
        }

        priority_queue<KNNElementQueue,vector<KNNElementQueue>,MINHEAP> getPqueue(){
            return pQueue;
        }

        priority_queue<KNNElementQueue,vector<KNNElementQueue>,MAXHEAP> getCandidates(){
            return candidates;
        }

};

#endif