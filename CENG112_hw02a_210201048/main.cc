#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
class GPSCoord{
    private :
    double longtitude;
    double lattitude;
    public :
    double longt_degree();
    double latt_degree();
    double longt_radian(double longtitude);
    double latt_radian(double lattitude);
    double distance_to(const GPSCoord& coord) ;
    GPSCoord(double longt,double latt){
         longtitude=longt;
         lattitude=latt;
         }  
    
    };
    
   
    double GPSCoord::longt_degree(){
            return longtitude;
    }
    double GPSCoord::latt_degree(){
            return lattitude;
    }
    double GPSCoord::longt_radian(double longtitude){
            return (longtitude*M_PI)/180;
    }
    double GPSCoord::latt_radian(double lattitude){
            return (lattitude*M_PI)/180;
    }
    
    
    double GPSCoord::distance_to(const GPSCoord& coord)  {
          double longt=longt_degree();
          double latt=latt_degree();
          double R=6371.0;
          double long_radi=longt_radian(coord.longtitude);
          double latt_radi=latt_radian(coord.lattitude);
          double longt_const_rad=longt_radian(longt);
          double latt_const_rad=latt_radian(latt);
          double difflong_rad=longt_radian((coord.longtitude) - longt);
          double difflatt_rad=latt_radian( (coord.lattitude) - latt );
          double a=  pow(sin(difflatt_rad/2),2) + cos(latt_const_rad) * cos(latt_radi) * pow(sin(difflong_rad/2),2) ;     
          double c =2 * atan2(sqrt(a),sqrt(1-a));
          double distance= R*c;
          if(distance > 1){
            cout << "İzmir and Ankara :" << distance <<  " km"  << endl;
          }
          else {
               distance =distance*1000;
               cout <<  "library and math buildings : "<< distance << " m " << endl;
              }
          return distance ;
          
    }
    int main(){
         // izmir and ankara
         double izmir_long=27.138758;
         double izmir_latt=38.421357;
         GPSCoord izmir(izmir_long,izmir_latt);
         double ankara_long=32.875334;
         double ankara_latt=39.932529;
         GPSCoord ankara(ankara_long,ankara_latt);
         izmir.distance_to(ankara);
         //library and math
         double library_long=26.639503;
         double library_latt=38.319678;
         GPSCoord library(library_long,library_latt);
         double math_long=26.632261;
         double math_latt=38.322355;
         GPSCoord math(math_long,math_latt);
         library.distance_to(math);
         return 0;
    }
      
