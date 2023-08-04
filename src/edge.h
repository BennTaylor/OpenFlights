#pragma once

#include "airport.h"

class Edge {
public:
    Edge(Airport* d, double w);
    Airport* dest();
    double weight();
private:
    Airport* destination_;
    double weight_;
};