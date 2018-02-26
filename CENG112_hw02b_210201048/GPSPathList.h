#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
class GPSPathList{
      public :
      GPSPathList(){ 
      m_size = 0;
      m_points = 0; }
      int size() const { 
      cout << "size : " << m_size;
      return m_size; 
        }
      double longt_radian(double longtitude);
      double latt_radian(double lattitude);
      void print() ;
      void add_points(const double &lattitude , const double &longtitude);
      double distance_to();
      bool get_from_user();
      private:
      struct GPSCoordNode{
       double lattitude;
       double longtitude;
       GPSCoordNode *next;
      };
      void add_item_sorted();
      int m_size;
      GPSCoordNode *m_points;
      };
