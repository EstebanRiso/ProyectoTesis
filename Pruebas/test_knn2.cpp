#include "Knn2.hpp"
#include <fstream>
#include <chrono>


bool cmp(pair<int, int> & a, pair<int, int> & b){
	if(a.second != b.second){
		return a.second < b.second;
	}
	return  a.first < b.first;
}



int main(int argc, char * argv[]){
	
	auto start = std::chrono::high_resolution_clock::now();


    if(argc < 2){
		printf("%s <PATH>\n", argv[0]);
		return -1;
	}
	
	/* Carga de puntos */
	
	string completo(argv[1]);
	completo+= ".txt";
	ifstream fe(completo.c_str());
	if(!fe.is_open()){
		printf("Error al abrir el archivo %s.txt\n", argv[1]);
		return -1;
	}
	vector<pair<int,int>> points;
	int x, y;
	int cantNode = 0;
	int cantEdge = 0;
	pair<int,int> p;
	while (!fe.eof()) {
		fe >> x;
		fe >> y;
		if(x > cantNode){
			cantNode = x;
		}
		if(y > cantNode){
			cantNode = y;
		}
		p = make_pair(x+1, y+1);
		points.push_back(p);
	}
	fe.close();
	cantNode++;
	uint pot2 = 2;
	while(pot2 < cantNode){
		pot2 *= 2;
	}
	cantNode = pot2;
	cantEdge = points.size();
	
	/* Transformacion a adlist */
	
	sort(points.begin(), points.end(), cmp);
	
	int * listNumber = new int[cantNode + cantEdge];
	int listIndex = 0;	
	int pointIndex = 0;
	for(int i = 1; i <= cantNode; i++){
		listNumber[listIndex] = -i;	listIndex++;
		if(pointIndex < cantEdge){
			while(points[pointIndex].second == i){
				listNumber[listIndex] = points[pointIndex].first;	listIndex++;
				pointIndex++;
			}
		}
	}
	
	/* Transformacion a ktree */
	
	uint max_level = floor(log(cantNode)/log(K)); 
	if(floor(log(cantNode)/log(K))==(log(cantNode)/log(K))) {
		max_level=max_level-1;
	}
	
	uint nodes_read=0;
	uint *xedges = new uint[cantEdge];
	uint *yedges = new uint[cantEdge];
	uint cedg = 0;
	int k;
	for(int i=0;i<cantNode+cantEdge;i++) {
		k = listNumber[i];
		if(k<0) {
			nodes_read++;
		}
		else {
			k--;
			xedges[cedg]=nodes_read-1;
			yedges[cedg]=k;
			cedg++;
		}
	}
	cout<<"TODAVIA NO HAY ERROR"<<endl;
	
	MREP * rep = compactCreateKTree(xedges, yedges, cantNode,cantEdge,max_level);

	/*
	for(int i=0;i<rep->btl->integers;i++){
		if(vec[i]!=rep->btl->data[i]){
			cout<<"NO SON IGUALES"<<endl;
			cout<<"problema con la posicion "<<i<<endl;
		}

		if((i==rep->btl->integers-1) && vec[i]==rep->btl->data[i]){
			cout<<"SON IGUALES"<<endl;
		}
	}

	cout<<"en btl dato"<<endl;

	for(int i=0;i<rep->btl->integers;i++){
		if(rep->btl->dato[i]!=rep->btl->data[i]){
			cout<<"NO SON IGUALES"<<endl;
			cout<<"problema con la posicion "<<i<<endl;
		}

		if((i==rep->btl->integers-1) && rep->btl->dato[i]==rep->btl->data[i]){
			cout<<"SON IGUALES"<<endl;
		}
	}*/


    K2Tree k2=K2Tree(rep);

    KNN knn=KNN(&k2);
    
    try{
        priority_queue<KNNElementQueue,vector<KNNElementQueue>,MAXHEAP> resultado=knn.findNNQ(4,Point(18,8));
        cout<<"RESULTADO FINAL:"<<endl;

        priority_queue<KNNElementQueue,vector<KNNElementQueue>,MAXHEAP> resultado2=resultado;

        while(!resultado2.empty()){
            KNNElementQueue a =resultado2.top();
            cout<<a.getDistance()<<" ";
            resultado2.pop();
        }
        cout<<endl;
        cout<<endl;
	/*
        while(!resultado.empty()){
            KNNElementQueue a =resultado.top();
                cout <<"X:"<<a.getCuadrant().getS().getX()<< " ";
                cout <<"Y:"<<a.getCuadrant().getS().getY()<< " ";
                cout <<"X:"<<a.getCuadrant().getT().getX()<< " ";
                cout <<"Y:"<<a.getCuadrant().getT().getY()<< " "<<endl;
                resultado.pop();
    	}
		cout<<"cantidad integers"<<k2.getBitArrayRS()->integers<<endl;
	*/


		

    }
    catch(error_code e){
        cerr<< e.message() << endl;
    }

    
	auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
	cout<<"fin del programa"<<endl;   


 return 0;
}

