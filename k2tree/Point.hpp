#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <math.h>

using namespace std;

class Point{
  private:
    int x;
    int y;
    int id;
    int correlative;
    double distance;

  public:
    Point(int x, int y ){
        this->x = x;
        this->y = y;
    }

    Point(){}

    Point(int id, int x, int y){
        this->x = x;
        this->y = y;
        this->id = id;
    }

    Point(int id, int x, int y, double distance ){
        this->x = x;
        this->y = y;
        this->id = id;
        this->distance = distance;
    }

    int getCorrelative(){
        return correlative;
    }

    void setCorrelative(int correlative){
        this->correlative = correlative;
    }

    int getId(){
        return id;
    }

    void setId(int id){
        this->id = id;
    }

    
    int getX(){
        return x;
    }

    void setX( int x){
        this->x=x;
    }

    int getY(){
        return y;
    }

    void setY(int y){
        this->y = y;
    }

    string toString(){
       return "hola";
    }

    double calculateDistance(Point other){
        // euclidian formula
        double result=sqrt(pow((other.x-this->x), 2) + pow((other.y-this->y),2));
        
        return result;
    }
 
    // fuera de la ecuación hasta el momento: bool equals()

    bool equals(Point &o){
      if(this == &o){
          return true;
      }
      if (o == NULL || )
    }

    int HashCode(){
        int result = x;
        result= 31*result+y;
        return result;
    }    

    double getDistance(){
        return distance;
    }

    void setDistance(double distance){
        this->distance = distance;
    }

};


#endif