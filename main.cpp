#include <iostream>
#include <fstream>
#include "haversine.h"

int main() {
    // Sagrada Familia
    double latA = 41.4036;
    double lonA = 2.1744;

    // Parque Güell
    double latB = 41.4145; 
    double lonB = 2.1527;

    // La Pedrera
    double latC = 41.3954;
    double lonC = 2.1619;

    double distanciaAB = calcularDistancia(latA, lonA, latB, lonB);
    double distanciaAC = calcularDistancia(latA, lonA, latC, lonC);
    double distanciaBC = calcularDistancia(latB, lonB, latC, lonC);

    double distanciaMinima;
    std::string distanciaMasCorta;

    if (distanciaAB < distanciaAC && distanciaAB < distanciaBC) {
        distanciaMinima = distanciaAB;
        distanciaMasCorta = "AB";
    } else if (distanciaAC < distanciaAB && distanciaAC < distanciaBC) {
        distanciaMinima = distanciaAC;
        distanciaMasCorta = "AC";
    } else {
        distanciaMinima = distanciaBC;
        distanciaMasCorta = "BC";
    }

    std::ofstream archivoSalida("salida.txt");

    if (archivoSalida) {
        archivoSalida << "La distancia entre Sagrada Familia y Parque Güell (AB) es: "
                      << distanciaAB << " km." << std::endl;
        archivoSalida << "La distancia entre Sagrada Familia y La Pedrera (AC) es: "
                      << distanciaAC << " km." << std::endl;
        archivoSalida << "La distancia entre Parque Güell y La Pedrera (BC) es: "
                      << distanciaBC << " km." << std::endl;
        archivoSalida << "La distancia más corta es entre los puntos: " << distanciaMasCorta
                      << " con una distancia de " << distanciaMinima << " km." << std::endl;
        
        archivoSalida.close();
    } else {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
    }

    return 0;
}
