#include "GPSCoord.h"
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


class GPSPath{
 public :
   size_t size()  { 
   cout<< "size : " << m_points.size();
   return m_points.size();
          }
   bool add_point();
   double total_distance();
   void print();
   
 private :
     std::vector<GPSCoord> m_points;
};

