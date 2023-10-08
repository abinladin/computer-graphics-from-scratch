#include"point3d.h"

struct Point3D create_point3d(double x, double y, double z){
    struct Point3D r = {x, y, z};
    return r;
}

