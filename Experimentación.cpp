#include "Knn.hpp"

using namespace std;

  
/*
  #include <math.h> // para las funciones de square root (raiz cuadrada) y pow (elevado)
#include <vector>
#include "k2tree.hpp"
#include "KNNElementQueue.hpp"



class punto{     
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

    radio=sqrt( distanciax + distanciay );
    return radio;
} 




void KNN(punto busqueda, K2tree arbol){    
    
    arbol.metodo_de_prueba();
}





// Metodo de la distancia euclidiana




*/
  
  
  
                        /* Aqui estara el programa llamado experimentación cpp, el cual su rol sera a traves de una serie de comandos a traves 
                           de los argumentos que se traspasen aqui */
int main(){
  
  
  int x1=1;
  int x2=4;

  int y1=1;
  int y2=5;
 
  int respuesta;
  
  respuesta=formula_euclidiana(x1,x2,y1,y2);

  K2tree a;

  a.metodo_de_prueba();

  std::cout<<"EL RESULTADO EUCLIADIANO ES "<< respuesta <<"\n";

  return 0;
}








