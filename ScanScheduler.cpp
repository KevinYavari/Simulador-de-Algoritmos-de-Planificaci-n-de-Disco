#include "ScanScheduler.h"
#include <algorithm>
#include <vector>
#include <cstdlib> // std::abs

long long ScanScheduler::schedule(const DiskInput &input) {
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

    // Deducir dirección a partir de previousRequest:
    // Si previous < head, venía subiendo (hacia cilindros más grandes).
    bool movingUp = (input.previousRequest <= head);

    long long total = 0;
    int current = head;

    if (movingUp) {
        // Primero hacia arriba
        for (int r : right) {
            total += std::llabs((long long)current - r);
            current = r;
        }
        // Luego hacia abajo
        for (auto it = left.rbegin(); it != left.rend(); ++it) {
            int r = *it;
            total += std::llabs((long long)current - r);
            current = r;
        }
    } else {
        // Primero hacia abajo
        for (auto it = left.rbegin(); it != left.rend(); ++it) {
            int r = *it;
            total += std::llabs((long long)current - r);
            current = r;
        }
        // Luego hacia arriba
        for (int r : right) {
            total += std::llabs((long long)current - r);
            current = r;
        }
    }

    return total;
}
