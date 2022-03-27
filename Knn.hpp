#include <math.h> // para las funciones de square root (raiz cuadrada) y pow (elevado)
#include <vector>
#include "k2tree.hpp"



class punto{        /* la clase de los puntos es para identificar los puntos, este objeto se unira en un array de la clase de Vector
                       cuyo proposito será mantener registro de los puntos cercanos y tambien del punto el cual queremos analizar en el k2tree*/
public:

    float x;
    float y;

    punto(float x, float y){        // el constructor del punto, se puede hacer con struct.
        this->x=x;
        this->y=y;
    }
    
};


int formula_euclidiana(int x1, int x2, int y1 ,int y2){  // aplica la formula de euclides
    
    int radio;
    
    int distanciax= pow((x2-x1),2);
    int distanciay= pow((y2-y1),2);

    cout<<distanciax<<"\n";
    cout<<distanciay<<"\n";

    radio=sqrt( distanciax + distanciay ); /*al restar x2-x1 y y2-y1 se obtienen las distancias del eje de las abcisas y las ordenadas respectivamente del plano 
                                        por lo tanto lo siquiente para lo formula euclidiana es hacer pitagoras, obteniendo asi el radio que será usado para identificar 
                                        si tocan o no a la minima distancia entre los mas cercanos*/
    return radio;
} 




void KNN(punto busqueda, K2tree arbol){    
    
    arbol.metodo_de_prueba();
}





// Metodo de la distancia euclidiana







