#pragma once

#include <vector>
#include <map>
#include <utility>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

#include "airport.h"
#include "edge.h"

using namespace std;

class AirportsGraph {
public:
    /*
     * Empty constructor (for testing).
     */
    AirportsGraph();

    /*
     * Constructor. Takes in two file paths, one to the airports data and one to routes data and
     * parses csv files to initialize adjacency list.
     */
    AirportsGraph(string& airports_file, string& routes_file);

    /*
     * Prints 'max' first keys (or all keys if max >= size) in map and number of airports in map.
     */
    void printKeys(int max);

    void printEdges(Airport* a, int max);

    map<Airport*, vector<Edge>> getMap();
private:
    /**
     * Constructor helper that initializes keys of the map.
     * Parses airports.dat csv file of every airport's information, initializing Airport objects and 
     * adding them into graph.
     * Initially maps every Airport to empty vector.
     */
    void loadAirports(string& airports_file);

    /**
     * Constructor helper that initializes actual graph structure.
     * parses routes.dat csv file of every airplane route, adding to adjacency lists of our Airport keys.
     * Utilizes getDistance(Airport b) function provided in Airport class to assign weight to the given connection.
     */
    void loadRoutes(string& routes_file);

    /*
     * Helper function for parsing csv files.
     * takes in a string and converts it to a vector of entries in that line (comma delimited).
     * Also trims entries in quotations.
     * i.e. "1,2,"3","4",5"  -->  [1,2,3,4,5]
     */
    vector<string> lineToVector(string& l);

    map<string, Airport*> iata_to_ptr_;
    /**
     * Map from airport pointers to vector of adjacent airports.
     * adjacent airports stored as pairs: airport ptr, connection weight.
     */
    map<Airport*, vector<Edge>> adj_lists_;
    int num_routes_ = 0;
};