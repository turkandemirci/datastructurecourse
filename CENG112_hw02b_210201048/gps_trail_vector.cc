#include "GPSPath.h"
#include <iostream>
using namespace std;

int main(){
     GPSPath path;
      while (path.add_point())
                ;
      
     
     
     path.total_distance();
     cout << "\n " << endl;
     path.size();
     path.print();
}
