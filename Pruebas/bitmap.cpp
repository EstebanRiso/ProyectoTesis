#include "transformador.hpp"
#include <unistd.h>

bool cmp(pair<int, int> & a, pair<int, int> & b){
	if(a.second != b.second){
		return a.second < b.second;
	}
	return  a.first < b.first;
}


void bitmap(MREP *a){
     cout<<"\n"<<endl;
    cout<<"\n"<<endl;

    cout<<"MATRIZ REPRESENTATIVA"<<endl;
    cout<< "btl:"<< a->btl << endl;
    cout<< "basex:"<<a->basex<<endl;
    cout<< "basey:"<<a->basey<<endl;
    cout<< "btl_len:"<<a->btl_len<<endl;
    cout<< "bt_len:"<<a->bt_len<<endl;
    cout<< "numbrerOfNodes:"<<a->numberOfNodes<<endl;
    cout<< "numberOfEdges:"<<a->numberOfEdges<<endl;
    cout<< "element:"<<a->element<<endl;
    cout<< "info:"<<a->info<<endl;
    cout<< "info2:"<<a->info2<<endl;
    cout<< "maxLevel:"<<a->maxLevel<<endl;
    cout<< "div_level_table:"<<a->div_level_table<<endl;
    cout<< "iniq:"<<a->iniq<<endl;
    cout<< "finiq:"<<a->finq<<endl;

    cout<<"\n"<<endl;
    cout<<"\n"<<endl;

    cout<<" BTL"<<endl;
    cout<<" owner:"<<a->btl->owner<<endl;
    cout<<" integers:"<<a->btl->integers<<endl;
    cout<<" factor:"<<a->btl->factor<<endl;
    cout<<" n:"<<a->btl->n<<endl;
    cout<<" s:"<<a->btl->s<<endl;
    cout<<" data:"<<a->btl->data<<endl;


    cout<<"BITMAP"<<endl;
    char* arreglo;
    uint b;
    uint cde;
    /*for(uint i=0; i<a->btl_len; i++){
        cde=isBitSet(a->btl, i);
        cout<<cde;
        
    }*/



    int contador=0;
    uint contador2=0;


    cout<<endl;
    cout<<endl;

    for(uint i=0; i<a->btl_len; i++){
        b=isBitSet(a->btl, i)?1:0;
        cout<<b;
    }

    cout<<endl;
    
    cout<<"tamano del bitmap tl:"<<a->btl_len<<endl;
    cout<<"alcanze a cortar en:"<<contador2<<endl;
    cout<<"tamaño bitmap t "<<a->bt_len<<endl;
    cout<<"detiene de contar en 46"<<endl;
    

    
    cout<<endl;
    string prueba="100011111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111011111111111111111111111111111111111111111111111111111101111111111111111111111111111111111111111111101111111111111110111111111111111111100001011100011111110111011110111111100111111101011111011111001100011111001101011011011001111111001010100101011111110011111000100011101110101011011111111100111111111111111011011011101101101111110001111011011010110110100111010001010010010101110110101110011110101111010101111111010100111110011101100111111111001010101011000111110101110110100111111011111100110110111010111011111011011110101111101100011000101111111011111101001110101010110010110110111101001101101001101011011010010101011111010001101100101111110110111110010001111110000110101100111110011000111100101011010101111111111111011100101111110000";
    cout<<"tamano antes de tirar puros ceros en test-1.kt:"<<prueba.size()<<endl;
    /*if(strcmp(string,string2)==0){cout<<"SON IGUALES :D"<<endl;}
    else{
        cout<<"no son iguales D:"<<endl;
    }*/

    /*for(int i=0;i<1378;i++){
        cout<<"data"<<i<<":"<<a->btl->data[i]<<endl;
    }*/


    if(bitaccess(a->btl->data,0)!=0){cout<<"A"<<endl;}else{cout<<""<<endl;}
    
    


    uint *valor= &a->btl->data[1];
    cout<<" valor:"<<valor<<endl;
    cout<<" valor:"<<*valor<<endl;

    cout<<" b:"<<a->btl->b<<endl;

}


int main(int argc, char * argv[]){
  /*
    if(argc < 2){
		printf("%s <PATH>\n", argv[0]);
		return -1;
	}
	
	/* Carga de puntos */
  /*
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
	/*
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
	/*
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
	*/
	MREP * rep = loadRepresentation(argv[1]);
	
    bitmap(rep);
   


return 0;
};


