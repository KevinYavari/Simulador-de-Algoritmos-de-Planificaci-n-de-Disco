#include "DiskSimulator.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

DiskInput DiskSimulator::loadRequests(const std::string &filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo de entrada: " + filename);
    }

    DiskInput data;
    int n;

    in >> data.maxCylinders;
    in >> data.initialHead;
    in >> data.previousRequest;
    in >> n;

    data.requests.resize(n);
    for (int i = 0; i < n; ++i) {
        in >> data.requests[i];
    }

    if (!in) {
        throw std::runtime_error("Error leyendo datos de " + filename);
    }

    return data;
}

void DiskSimulator::saveResults(const std::string &filename,
                                long long fcfs,
                                long long scan,
                                long long cscan) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo de salida: " + filename);
    }

    out << "Resultados de planificación de disco\n";
    out << "-----------------------------------\n";
    out << "FCFS  : " << fcfs  << " cilindros de movimiento\n";
    out << "SCAN  : " << scan  << " cilindros de movimiento\n";
    out << "C-SCAN: " << cscan << " cilindros de movimiento\n";

    out.close();
}
