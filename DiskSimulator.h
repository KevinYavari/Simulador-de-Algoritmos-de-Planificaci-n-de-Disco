#ifndef DISK_SIMULATOR_H
#define DISK_SIMULATOR_H

#include "DiskTypes.h"
#include <string>

class DiskSimulator {
public:
    DiskInput loadRequests(const std::string &filename);
    void saveResults(const std::string &filename,
                     long long fcfs,
                     long long scan,
                     long long cscan);
};

#endif
