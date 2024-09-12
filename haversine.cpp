#include "haversine.h"
#include <cmath>

const double RADIO_TIERRA = 6371.0;

double calcularDistancia(double lat1, double lon1, double lat2, double lon2) {
    lat1 = lat1 * M_PI / 180.0;
    lon1 = lon1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;
    lon2 = lon2 * M_PI / 180.0;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distancia = RADIO_TIERRA * c;

    return distancia;
}
