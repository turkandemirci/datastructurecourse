#include "GPSPathList.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
    double GPSPathList::longt_radian(double longtitude)
    {
            return (longtitude*M_PI)/180;
    }
    double GPSPathList::latt_radian(double lattitude)
    {
            return (lattitude*M_PI)/180;
    }
    void GPSPathList::print()
    {
       GPSCoordNode *node=m_points;
       while(node !=0)
       {
       cout << "(<"<< node->lattitude <<","<<node->longtitude<<">)--";
       node=node->next;
       }
      
    }
    void GPSPathList::add_points(const double &lattitude,const double &longtitude)
    {
       GPSCoordNode *new_point=new GPSCoordNode;
       new_point->lattitude=lattitude;
       new_point->longtitude=longtitude;
       if(m_points==0)
       {
       m_points=new_point;
       m_points->next=0;
     
       }else{
       GPSCoordNode *iter=m_points;
       while(iter->next != 0)
       iter=iter->next;
       iter->next=new_point;
       iter=new_point;
       iter->next=0;
       }
       m_size++;
    }
    bool GPSPathList::get_from_user()
    {
       double lattitude;
       cout << "Enter lattitude (\"0.0\" to quit): "<< endl;
       cout << "enter lattitude : ";
       cin >> lattitude;
       if (lattitude==0.0)
        return false;

       double longtitude;
       cout << "Enter longtitude: ";
       cin >> longtitude;

       add_points(lattitude, longtitude);
       return true;
    }
    double GPSPathList::distance_to()
    {
       double R=6371.0;
       double k;
       GPSCoordNode *prev=m_points;
       GPSCoordNode *pos=m_points->next;
       double distance;
       while(prev != 0 && pos !=0){
       double long_radi=longt_radian(prev->longtitude);
       double latt_radi=latt_radian(prev->lattitude);
       double longt_const_rad=longt_radian(pos->longtitude);
       double latt_const_rad=latt_radian(pos->lattitude);
       double difflong_rad=longt_radian((prev->longtitude) - (pos->longtitude) );
       double difflatt_rad=latt_radian( (prev->lattitude) - (pos->lattitude) );
       double a=  pow(sin(difflatt_rad/2),2) + cos(latt_const_rad) * cos(latt_radi) * pow(sin(difflong_rad/2),2) ;     
       k =2 * atan2(sqrt(a),sqrt(1-a));
       k= R*k;
       distance=distance+k;
       prev=prev->next;
       pos=pos->next;
        }
          cout << distance<< endl;
          return distance;
    }
     
    
     
     
