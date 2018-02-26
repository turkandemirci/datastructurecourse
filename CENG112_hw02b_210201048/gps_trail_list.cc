#include "GPSPathList.h"
#include <iostream>
using std::cout;
using std::endl;
int main(){
    GPSPathList path;
    while(path.get_from_user())
        ;
    

    path.distance_to();
    path.size();
    cout << "\n " << endl;
    path.print();
}

