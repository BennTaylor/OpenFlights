#include "edge.h"

Edge::Edge(Airport* d, double w) {
    destination_ = d;
    weight_ = w;
}
Airport* Edge::dest() {
    return destination_;
}
double Edge::weight() {
    return weight_;
}