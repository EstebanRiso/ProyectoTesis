#include <iostream>
#include <chrono>

using namespace std;


int main(){

    auto start = std::chrono::high_resolution_clock::now();

    cout<<1+1<<endl;


    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
	cout<<"fin del programa"<<endl;

    return 0;
}