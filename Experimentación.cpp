#include "Knn.hpp"

using namespace std;

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








