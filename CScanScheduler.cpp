#include "CScanScheduler.h"
#include <algorithm>
#include <vector>
#include <cstdlib> // std::abs

long long CScanScheduler::schedule(const DiskInput &input) {
    std::vector<int> reqs = input.requests;
    std::sort(reqs.begin(), reqs.end());

    int head = input.initialHead;
    int maxCyl = input.maxCylinders - 1;
    int minCyl = 0;

    std::vector<int> left, right;
    for (int r : reqs) {
        if (r < head) left.push_back(r);
        else          right.push_back(r);
    }

    // Igual, deducimos dirección a partir de previousRequest
    bool movingUp = (input.previousRequest <= head);

    long long total = 0;
    int current = head;

    if (movingUp) {
        // Atiende hacia arriba
        for (int r : right) {
            total += std::llabs((long long)current - r);
            current = r;
        }

        // Moverse hasta el extremo superior
        if (current != maxCyl) {
            total += std::llabs((long long)current - maxCyl);
            current = maxCyl;
        }

        // "Salto" al extremo inferior
        if (current != minCyl) {
            total += std::llabs((long long)current - minCyl);
            current = minCyl;
        }

        // Atiende las peticiones menores que el head original
        for (int r : left) {
            total += std::llabs((long long)current - r);
            current = r;
        }
    } else {
        // Versión simétrica si estuviera bajando (opcional)
        for (auto it = left.rbegin(); it != left.rend(); ++it) {
            int r = *it;
            total += std::llabs((long long)current - r);
            current = r;
        }

        if (current != minCyl) {
            total += std::llabs((long long)current - minCyl);
            current = minCyl;
        }

        if (current != maxCyl) {
            total += std::llabs((long long)current - maxCyl);
            current = maxCyl;
        }

        for (auto it = right.rbegin(); it != right.rend(); ++it) {
            int r = *it;
            total += std::llabs((long long)current - r);
            current = r;
        }
    }

    return total;
}
