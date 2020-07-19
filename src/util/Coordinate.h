//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#ifndef SIMUL_WORLD_COORDINATE_H
#define SIMUL_WORLD_COORDINATE_H

#include <cmath>
#include <iostream>

class Coordinate {
public:
    int x;
    int y;
    int z;

    static const Coordinate NONE;

    // Constructors
    explicit Coordinate (int x_in = 0, int y_in = 0, int z_in = 0);
    Coordinate (const Coordinate &right);

    // Operator overloading for coordinates
    Coordinate operator+(const Coordinate &right);

    Coordinate operator-(const Coordinate &right);

    bool operator==(const Coordinate &right);

    double distanceFrom(const Coordinate &right);

    friend std::ostream &operator<<(std::ostream &Str, const Coordinate &coord);

    // Sort by lowest z value, then lowest y value, then lowest x value.
    bool operator<(const Coordinate &right);

    Coordinate moveTowardsCoordinate(const Coordinate &coord);

    static Coordinate wander(const Coordinate &coord);
};


#endif //SIMUL_WORLD_COORDINATE_H
