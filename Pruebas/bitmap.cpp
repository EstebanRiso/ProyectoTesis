#include "transformador.hpp"





int main(int argc, char * argv[]){
    

    MREP *a=loadRepresentation(argv[1]);


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
    for(uint i=0; i<a->btl_len; i++){
        cde=isBitSet(a->btl, i);
        cout<<cde;
        
    }



    cout<<endl;

     for(uint i=0; i<a->btl_len; i++){
        b=isBitSet(a->btl, i)?1:0;
        cout<<b;
        
    }
       
    
    cout<<endl;

    char string[]="110011111010010111011011100110001000100000100010100001100110000100010001010010101010";
    char string2[]="110011111010010111011011100110001000100000100010100001100110000100010001010010101010";

    if(strcmp(string,string2)==0){cout<<"SON IGUALES :D"<<endl;}
    else{
        cout<<"no son iguales D:"<<endl;
    }

    /*for(int i=0;i<1378;i++){
        cout<<"data"<<i<<":"<<a->btl->data[i]<<endl;
    }*/


    if(bitaccess(a->btl->data,0)!=0){cout<<"A"<<endl;}else{cout<<""<<endl;}
    
    


    uint *valor= &a->btl->data[1];
    cout<<" valor:"<<valor<<endl;
    cout<<" valor:"<<*valor<<endl;

    cout<<" b:"<<a->btl->b<<endl;



return 0;
};