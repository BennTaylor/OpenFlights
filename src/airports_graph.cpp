#include "airports_graph.h"

using namespace std;

AirportsGraph::AirportsGraph() {}

AirportsGraph::AirportsGraph(string& airports_file, string& routes_file) {
    adj_lists_ = map<Airport*, vector<Edge>>();
    // initialize our airports (so we have something to refer to before building edges)
    loadAirports(airports_file);
    // initialize adjacencies
    loadRoutes(routes_file);
}

void AirportsGraph::loadAirports(string& airports_file) {
    fstream airports(airports_file.c_str(), ios::in);
    string line;

    if (airports.is_open()) {
    while (getline(airports, line)) {
        vector<string> entries = lineToVector(line);
        // bad entry
        if (entries.size() != 14) {
            cout << "bad entry at line " << entries[0] << endl;
            continue;
        }
        // airport attributes are these
        int id = stoi(entries[0]);
        double lat = stod(entries[6]);
        double lon = stod(entries[7]);
        string iata = entries[4];
        string city = entries[2];
        string country = entries[3];

        // toss entries with null iata's
        if (iata.compare("\\N") == 0) {
            // cout << "no IATA at entry " << id << endl;
            continue;
        }

        // new airport with those attributes
        Airport* a = new Airport(id, lat, lon, iata, city, country);

        // add the airport as a key in map
        adj_lists_[a] = vector<Edge>();
        iata_to_ptr_[iata] = a;
    }
    } else {
    cout << "file not opened." << endl;
    }
}

void AirportsGraph::loadRoutes(string& routes_file) {
    fstream routes(routes_file.c_str(), ios::in);
    string line;
    int i = 0;

    if (routes.is_open()) {
    while (getline(routes, line)) {
        i++;
        vector<string> entries = lineToVector(line);

        // edge data
        // skip indirect flights
        if (stoi(entries[entries.size() - 2]) != 0) {
            continue;
        }
        string src_iata = entries[2];
        string dest_iata = entries[4];
        if (src_iata.compare(dest_iata) == 0) {
            cout << "airport routed to self for whatever fuckin reason. line: " << i << endl;
        }
        // skip route entries referring to airports not in our map
        if (iata_to_ptr_.find(src_iata) == iata_to_ptr_.end() || iata_to_ptr_.find(dest_iata) == iata_to_ptr_.end()) {
            // cout << "bad route at line " << i << endl;
            continue;
        }
        Airport* src = iata_to_ptr_[src_iata];
        Airport* dest = iata_to_ptr_[dest_iata];

        // check if route already exists
        bool redundant = false;
        for (Edge e : adj_lists_[src]) {
            if (e.dest()->IATA().compare(dest_iata) == 0) {
                redundant = true;
                break;
            }
        }
        if (redundant) {
            continue;
        }
        // edge weight given by (haversine) distance between airports
        double weight = src->getDistance(*dest);

        // make our edge
        Edge e = Edge(dest, weight);
        adj_lists_[src].push_back(e);
        num_routes_++;
    }
    } else {
    cout << "file not opened." << endl;
    }
}

 map<Airport*, vector<Edge>> AirportsGraph::getMap() {
    return adj_lists_;
 }

vector<string> AirportsGraph::lineToVector(string& l) {
    // vector of entries for this line to be returned
    vector<string> v;
    // current character in l
    char c;
    // entry we're 'building'
    string entry = "";
    // flag used for bug when a comma is in the name of an entry; i.e. "Chicago, USA"
    bool quot_open = false;

    // loop over characters in the line
    // if we reach a comma, add the entry to vector and reset entry (when quotations not open)
    // o.w. add current char to entry when it is not a "
    // toggle quotation flag when we see a "
    for (unsigned i = 0; i < l.size(); i++) {
        c = l[i];
        if (c == ',') {
            if (quot_open) {
                continue;
            }
            v.push_back(entry);
            entry = "";
        } else if (c != '"') {
            entry += c;
        } else {
            quot_open = !quot_open;
        }
    }
    // add the last entry (leftover from loop structure)
    if (entry.compare("") != 0) {
        v.push_back(entry);
    }

    return v;
}

void AirportsGraph::printKeys(int max) {
    int size = adj_lists_.size();
    cout << "Airports in graph: "<< size << "\n" << endl;
    cout << "Routes in graph: "<< num_routes_ << "\n" << endl;

    int i = 0;
    for (auto it = adj_lists_.begin(); it != adj_lists_.end(); it++) {
        it->first->print();
        cout << endl;
        i++;
        if (i >= max) {
            cout << "..." << "(" << size-max << " more airports)" << "...\n" << endl;
            return;
        }
    }
    cout << "\nAll airports listed.\n" << endl;
}

void AirportsGraph::printEdges(Airport* a, int max) {
    int i = 0;
    vector<Edge> edges = adj_lists_[a];

    cout << "Routes from " << a->IATA() << ":\n" << endl;

    for (Edge e : edges) {
        i++;
        cout << a->IATA() << " -> " << e.dest()->IATA() << ", " << e.weight() << "km" << endl;

        if (i >= max) {
            cout << "..." << "(" << edges.size()-max << " more edges)" << "...\n" << endl;
            return;
        }
    }

    cout << "\nAll routes listed.\n" << endl;

}

