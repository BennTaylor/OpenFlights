#pragma once

#define _USE_MATH_DEFINES

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Airport {
public:
    // constructor
    Airport(int id, double lat, double lon, string iata, string city, string country);

    // getters
    int id();
    double latitude();
    double longitude();
    string IATA();
    string city();
    string country();

    // distance between this airport and airport 'a' (Haversine formula)
    double getDistance(Airport b);

    void print();
private:
    int airport_id_;
    double lat_;
    double lon_;
    string iata_;
    string city_;
    string country_;
};