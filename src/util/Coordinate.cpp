//
// Created by Dusterwald, Thomas Karl on 2020-07-17.
//

#include "Coordinate.h"

Coordinate::Coordinate(int x_in, int y_in, int z_in) {
    x = x_in;
    y = y_in;
    z = z_in;
}

Coordinate::Coordinate(const Coordinate &right) {
    x = right.x;
    y = right.y;
    z = right.z;
}

// Operator overloading for coordinates
Coordinate Coordinate::operator+(const Coordinate &right) {
    return Coordinate(x + right.x, y + right.y, z + right.z);
}

Coordinate Coordinate::operator-(const Coordinate &right) {
    return Coordinate(x - right.x, y - right.y, z - right.z);
}

bool Coordinate::operator==(const Coordinate &right) {
    return x == right.x && y == right.y && z == right.z;
}

double Coordinate::distanceFrom(const Coordinate &right) {
    Coordinate diff = *this - right;
    return sqrt(pow(diff.x, 2) + pow(diff.y, 2) + pow(diff.z, 2));
}

std::ostream &operator<<(std::ostream &Str, const Coordinate &coord) {
    Str << '{' << coord.x << ',' << coord.y << ',' << coord.z << '}';
    return Str;
}

bool Coordinate::operator<(const Coordinate &right){
    if(z < right.z)
        return true;
    if(z > right.z)
        return false;

    // zs are equal
    if(y < right.y)
        return true;
    if(y > right.y)
        return false;

    // ys are equal
    if(x < right.x)
        return true;
    return false;
}

Coordinate Coordinate::moveTowardsCoordinate(const Coordinate &coord) {
    Coordinate move = *this - coord;
    // Find greatest negative
    Coordinate out = *this;
    if(abs(move.x) > abs(move.y))
        out.x += (move.x < 0 ? 1 : -1);
    else
        out.y += (move.y < 0 ? 1 : -1);
    return out;
}

Coordinate Coordinate::wander(const Coordinate &coord) {
    // Randomly go 1 up down left or right
    int randNum = rand() % 100;
    Coordinate out;
    if(randNum < 24){
        out = Coordinate(coord.x + 1, coord.y, coord.z);
    }
    else if(randNum < 50){
        out = Coordinate(coord.x - 1, coord.y, coord.z);
    }
    else if(randNum < 75){
        out = Coordinate(coord.x, coord.y + 1, coord.z);
    }
    else {
        out = Coordinate(coord.x, coord.y - 1, coord.z);
    }

    return out;
}

const Coordinate Coordinate::NONE = Coordinate(-1, -1, -1);