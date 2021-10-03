#include<iostream>
#include<math.h>
#include<vector>
#include<string>

using namespace std;

struct Vector3D {
    double x, y, z;
    Vector3D(){}
    Vector3D(double inp_x, double inp_y, double inp_z) {
        x = inp_x;
        y = inp_y;
        z = inp_z;
    }
    Vector3D operator + (Vector3D v) {
        return *new Vector3D(x + v.x, y + v.y, z + v.z);
    }
    Vector3D operator - (Vector3D v) {
        return *new Vector3D(x - v.x, y - v.y, z - v.z);
    }
    double operator * (Vector3D v) {
        return x * v.x + y * v.y + z * v.z;
    }
    //! Should be overwritten to match vector cross product
    Vector3D operator ^ (Vector3D v) {
        return *new Vector3D(0, 0, 0);
    }
    Vector3D operator * (double d) {
        return *new Vector3D(x * d, y * d, z * d);
    }
    double length() {
        return sqrt(x * x + y * y + z * z);
    }
    string toString() {
        return "v " + to_string(x) + " " + to_string(y) + " " + to_string(z) + "\n";
    }
};

double dist(Vector3D a, Vector3D b) {
    return (a - b).length();
}