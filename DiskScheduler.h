#ifndef DISK_SCHEDULER_H
#define DISK_SCHEDULER_H

#include "DiskTypes.h"

class DiskScheduler {
public:
    virtual ~DiskScheduler() = default;
    virtual long long schedule(const DiskInput &input) = 0;
};

#endif
