#include "GPSCoord.h"
#include <iostream>
#include <cmath>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;

    double GPSCoord::get_latt()
    {
          
           return lattitude;
    }
    double GPSCoord::get_longt(){
           
            return longtitude;
    }
    double GPSCoord::longt_radian(double longtitude)
    {
            return (longtitude*M_PI)/180;
    }
    double GPSCoord::latt_radian(double lattitude)
    {
            return (lattitude*M_PI)/180;
    }
    bool GPSCoord::get_from_user(){
    cout << "Enter lattitude (\"0.0\" to quit): "<<  endl;
    cout << "Enter lattitude :" ;
        cin >> lattitude;
        if (lattitude == 0.0)
                return false;
        cout << "Enter longtitude : ";
        cin >> longtitude;
        return true;
    }
    
    
    
