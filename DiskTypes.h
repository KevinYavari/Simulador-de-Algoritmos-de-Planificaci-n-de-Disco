#ifndef DISK_TYPES_H
#define DISK_TYPES_H

#include <vector>

struct DiskInput {
    int maxCylinders;          // número total de cilindros (ej. 5000)
    int initialHead;           // posición inicial del cabezal
    int previousRequest;       // petición previa (para deducir dirección en SCAN)
    std::vector<int> requests; // lista de peticiones
};

#endif
