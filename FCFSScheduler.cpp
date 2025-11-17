#include "FCFSScheduler.h"
#include <cstdlib> // std::abs

long long FCFSScheduler::schedule(const DiskInput &input) {
    long long total = 0;
    int current = input.initialHead;

    for (int r : input.requests) {
        total += std::llabs((long long)current - r);
        current = r;
    }

    return total;
}
