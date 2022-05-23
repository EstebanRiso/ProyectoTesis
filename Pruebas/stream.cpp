#include <fstream>
#include "MatrixRep.hpp"
#include "Knn.hpp"
#include <chrono>


bool cmp(pair<int, int> & a, pair<int, int> & b){
	if(a.second != b.second){
		return a.second < b.second;
	}
	return  a.first < b.first;
}




int main(int argc, char * argv[]){

	auto start = std::chrono::high_resolution_clock::now();

	fstream f;
	
	MREP * rep = loadRepresentation(argv[1]);

	uint integers=rep->btl->integers;
	uint size= (rep->btl_len/rep->btl->s+1);


	rep->btl->dato=getDatoVector(argv[1],f,integers);
	rep->btl->ers=getRsVector(argv[1],f,size);
	
	cout<<"viendo el data"<<endl;
	
	for(int i=0;i<rep->btl->integers;i++){
		cout<<rep->btl->dato[i]<<" ";
	}

	cout<<endl<<endl;

	cout<<"viendo el rs"<<endl;
	cout<<size<<endl;


	for(int i=0;i<size;i++){
		cout<<rep->btl->ers[i]<<" ";
	}

    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
	cout<<"fin del programa"<<endl;


 return 0;
}