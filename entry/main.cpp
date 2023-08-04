#include "airports_graph.h"

#include <string>
#include <iostream>

using namespace std;

int main() {
    /* primary functionality/demonstration here */
    cout << "\nyou so icy i'm a glacier boy\n" << endl;

    string portsfname = "../src/airports.dat";
    string routesfname = "../src/routes.dat";
    AirportsGraph g = AirportsGraph(portsfname, routesfname);

    g.printKeys(3);

    Airport* a = g.getMap().begin()->first;
    g.printEdges(a, 10);

    // AirportsGraph g = AirportsGraph();
    // string l = "641,\"Harstad/Narvik Airport, Evenes\",\"Harstad/Narvik\",\"Norway\",\"EVE\",\"ENEV\",68.491302490234,16.678100585938,84,1,\"E\",\"Europe/Oslo\",\"airport\",\"OurAirports\"";
    
    // vector<string> entries = g.lineToVector(l);
    // for (string s : entries) {
    //     cout << s << endl;
    // }

    return 0;
}