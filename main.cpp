#include "v3d.cpp"
#include<cstdio>

using namespace std;

int main() {
    freopen("test.obj", "w", stdout);

    // inner_x - half width of inner frame
    // inner_y - half height of inner frame
    // outer_x - half width of outer frame
    // outer_y - half height of outer frame
    // depth - depth of frame extrudes
    double inner_x = .9, inner_y = .9, 
    outer_x = 1, outer_y = 1, 
    depth = .01;

    // Frame profile
    // point.first - relative coordinate on frame
    // point.second - extruding depth of point
    vector<pair<double, double>> extrudes{{0, 0}, {.3, 1}, {.7, 1}, {1, 0}};

    // Creating vertices
    vector<Vector3D> vertexes;
    for (int i = 0; i < extrudes.size(); i++) {
        // For each corner of frame...
        for (pair<int, int> multip : vector<pair<double, double>>{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}}) {
            vertexes.push_back(Vector3D((inner_x / 2 + extrudes[i].first * (outer_x - inner_x)) * multip.first,
            (inner_y / 2 + extrudes[i].first * (outer_y - inner_y)) * multip.second, extrudes[i].second * depth));
        }
    }

    // Writing everything to file
    for (int i = 0; i < vertexes.size(); i++) {
        cout << (vertexes[i] + Vector3D(0, 0, 0)).toString();
    }
    for (int i = 0; i < extrudes.size() - 1; i++) {
        cout << "f " << i * 4 + 1 << ' ' << i * 4 + 1 + 1 << ' ' << i * 4 + 5 + 1 << ' ' << i * 4 + 4 + 1 << endl;
        cout << "f " << i * 4 + 1 + 1 << ' ' << i * 4 + 2 + 1 << ' ' << i * 4 + 6 + 1 << ' ' << i * 4 + 5 + 1 << endl;
        cout << "f " << i * 4 + 2 + 1 << ' ' << i * 4 + 3 + 1 << ' ' << i * 4 + 7 + 1 << ' ' << i * 4 + 6 + 1 << endl;
        cout << "f " << i * 4 + 3 + 1 << ' ' << i * 4 + 0 + 1 <<  ' ' << i * 4 + 4 + 1 << ' ' << i * 4 + 7 + 1 << endl;
    }
}