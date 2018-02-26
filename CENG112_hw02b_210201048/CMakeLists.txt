project(ceng112_hw02b CXX)
add_executable(gps_trail_vector GPSCoord.cc GPSPath.cc gps_trail_vector.cc)
add_executable(gps_trail_list GPSPathList.cc gps_trail_list.cc)
set(CMAKE_BUILD_TYPE Debug)
