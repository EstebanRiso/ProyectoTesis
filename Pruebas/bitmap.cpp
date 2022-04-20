#include "transformador.hpp"









int main(){


    
    cout<<"PRUEBA DEL BITMAP EN C++"<<endl;


    cout<<"ABRIENDO ARCHIVO MATRIZ ADJ"<<endl;     
    
    char* text="matrizadyacencia";

    cout<<"CARGANDO MATRIZ ADJ"<<endl;

    ALREP* prueba=loadAdyacencyList(text);

    cout<<"LISTA CARGADA:"<<endl<<prueba->listady<<endl;
    
    cout<<"NUMERO ESQUINAS:"<<endl<<prueba->numEdges<<endl;

    cout<<"NUMERO NODOS:"<<endl<<prueba->numNodes<<endl;



return 0;
};