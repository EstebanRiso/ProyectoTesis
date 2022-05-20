#include <fstream>
#include "MatrixRep.hpp"
#include "Knn.hpp"
#include <fstream>
#include <chrono>


bool cmp(pair<int, int> & a, pair<int, int> & b){
	if(a.second != b.second){
		return a.second < b.second;
	}
	return  a.first < b.first;
}



vector<uint> getVector(char* filename){
	
	string fila=filename;
	fila+=".dat";
	uint dato;
	uint integers;
    fstream f;
	vector<uint> vector;

    f.open(fila,ios::in | ios::binary);


    if(f.is_open()){

		f.read(reinterpret_cast<char *>(&integers),sizeof(uint));
		
		for(int i=0;i<integers;i++){
			f.read(reinterpret_cast<char *>(&dato),sizeof(uint));
			vector.push_back(dato);
		}

		cout<<"voy a cerrar el archivo"<<endl;
        f.close();
    }
    else{cout<<"no se pudo abrir"<<endl;}


	for(auto i = vector.begin(); i !=vector.end(); ++i) 
        cout << *i << " ";
	cout<<endl;

	return vector;
}



int main(int argc, char * argv[]){

	MREP * rep = loadRepresentation(argv[1]);

	rep->btl->dato=getVector(argv[1]);


	cout<<"AQUI SE COLOCÓ VECTORSITO ex di"<<endl;

	for(auto i = rep->btl->dato.begin(); i !=rep->btl->dato.end(); ++i) 
        cout << *i << " ";

	cout<<"voy a darle a mrep un vector"<<endl;
	cout<<"sali de la función"<<endl;
   


	cout<<"fin del programa"<<endl;


 return 0;
}