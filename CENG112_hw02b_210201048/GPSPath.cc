#include "GPSPath.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


   bool  GPSPath::add_point(){
       
       GPSCoord  coord;
        if (coord.get_from_user()) {
                m_points.push_back(coord);
                return true;
        } else {
                return false;
        }
        
}
 
  double GPSPath::total_distance(){
          double R=6371.0;
          double k;
          GPSCoord coord;
          double distance;
          for(int i=0;i<(m_points.size()-1);i++){
          double long_radi=coord.longt_radian(m_points[i].longtitude);
          double latt_radi=coord.latt_radian(m_points[i].lattitude);
          double longt_const_rad=coord.longt_radian(m_points[i+1].longtitude);
          double latt_const_rad=coord.latt_radian(m_points[i+1].lattitude);
          double difflong_rad=coord.longt_radian((m_points[i].longtitude) - (m_points[i+1].longtitude) );
          double difflatt_rad=coord.latt_radian( (m_points[i].lattitude) - (m_points[i+1].lattitude) );
          double a=  pow(sin(difflatt_rad/2),2) + cos(latt_const_rad) * cos(latt_radi) * pow(sin(difflong_rad/2),2) ;     
          k =2 * atan2(sqrt(a),sqrt(1-a));
          k= R*k;
          distance=distance+k;
      }
       cout << distance<< endl;
      return distance;
}
  void GPSPath::print(){
          
           for(size_t i=0;i<m_points.size();++i){
              cout << "(<"<< m_points[i].lattitude <<","<<m_points[i].longtitude<<">)--";
  }
}

