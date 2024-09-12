#include <iostream>
#include <fstream>
#include "haversine.h"

int main() {
    // Coordenadas de los puntos de interés
    double latA = 41.4036; // Sagrada Familia
    double lonA = 2.1744;

    double latB = 41.4145; // Parque Güell
    double lonB = 2.1527;

    double latC = 41.3954; // La Pedrera
    double lonC = 2.1619;

    // Calcular distancias
    double distanciaAB = calcularDistancia(latA, lonA, latB, lonB);
    double distanciaAC = calcularDistancia(latA, lonA, latC, lonC);
    double distanciaBC = calcularDistancia(latB, lonB, latC, lonC);

    // Determinar la distancia más corta
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

    // Abrir el archivo para escritura
    std::ofstream archivoSalida("salida.txt");

    if (archivoSalida) {  // Verifica si el archivo se abrió correctamente
        archivoSalida << "La distancia entre Sagrada Familia y Parque Güell (AB) es: "
                      << distanciaAB << " km." << std::endl;
        archivoSalida << "La distancia entre Sagrada Familia y La Pedrera (AC) es: "
                      << distanciaAC << " km." << std::endl;
        archivoSalida << "La distancia entre Parque Güell y La Pedrera (BC) es: "
                      << distanciaBC << " km." << std::endl;
        archivoSalida << "La distancia más corta es entre los puntos: " << distanciaMasCorta
                      << " con una distancia de " << distanciaMinima << " km." << std::endl;
        
        archivoSalida.close(); // Cerrar el archivo
    } else {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
    }

    return 0;
}
