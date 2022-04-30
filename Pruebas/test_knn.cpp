#include "Knn.hpp"




int main(int argc, char * argv[]){

    MREP *a=loadRepresentation(argv[1]);

    cout<<"VAMOS A VER EL RESULTADO"<<endl;

    K2Tree k2=K2Tree(a);

    cout<<"VAMOS A VER EL RESULTADO"<<endl;

    KNN knn=KNN(&k2);

    cout<<"VAMOS A VER EL RESULTADO"<<endl;

    priority_queue<KNNElementQueue,vector<KNNElementQueue>,MAXHEAP> resultado=knn.findNNQ(1,Point(1,1));
    
    cout<<"VAMOS A VER EL RESULTADO FINAL"<<endl;
    cout<<"resultado:"<<resultado.size()<<endl;

    while(!resultado.empty()){
        cout<<"ESTOY EN EL CICLO WHILE"<<endl;
        KNNElementQueue a =resultado.top();
            
            cout <<a.getDistance()<< " ";
            resultado.pop();
    }
    


 return 0;
}

