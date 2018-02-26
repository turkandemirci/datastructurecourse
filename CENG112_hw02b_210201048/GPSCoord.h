
#include <cmath>
#include <math.h>

class GPSCoord{
    public :
    double longtitude;
    double lattitude;
    
    double get_longt();
    double get_latt();
    double longt_radian(double longtitude);
    double latt_radian(double lattitude);
    bool get_from_user();
    
    GPSCoord(){}
    
   
    };
    
