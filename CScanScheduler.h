#ifndef CSCAN_SCHEDULER_H
#define CSCAN_SCHEDULER_H

#include "DiskScheduler.h"

class CScanScheduler : public DiskScheduler {
public:
    long long schedule(const DiskInput &input) override;
};

#endif
