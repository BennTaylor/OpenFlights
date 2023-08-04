#include "airport.h"

using namespace std;

Airport::Airport(int id, double lat, double lon, string iata, string city, string country) {
    airport_id_ = id;
    lat_ = lat;
    lon_ = lon;
    iata_ = iata;
    city_ = city;
    country_ = country;
}
int Airport::id() {
    return airport_id_;
}
double Airport::latitude() {
    return lat_;
}
double Airport::longitude() {
    return lon_;
}
string Airport::IATA() {
    return iata_;
}
string Airport::city() {
    return city_;
}
string Airport::country() {
    return country_;
}

double Airport::getDistance(Airport b) {
    // lats,longs of airports a and b converted to radians for calculation
    double lat_a = lat_ * M_PI / 180.0;
    double lon_a = lon_ * M_PI / 180.0;
    double lat_b = b.lat_ * M_PI / 180.0;
    double lon_b = b.lon_ * M_PI / 180.0;

    // Earth radius (km)
    double E_RAD = 6378.8;

    // Haversine formula 
    return E_RAD*acos( sin(lat_a)*sin(lat_b) + cos(lat_a)*cos(lat_b)*cos(lon_b-lon_a) );
}

void Airport::print() {
    cout << "id:      " << airport_id_ << "\n"
         << "lat:     " << lat_ << "\n"
         << "lon:     " << lon_ << "\n"
         << "IATA:    " << iata_ << "\n"
         << "city:    " << city_ << "\n"
         << "country: " << country_ << endl;
}