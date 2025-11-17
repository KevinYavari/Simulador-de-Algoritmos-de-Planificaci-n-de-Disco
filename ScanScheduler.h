#ifndef SCAN_SCHEDULER_H
#define SCAN_SCHEDULER_H

#include "DiskScheduler.h"

class ScanScheduler : public DiskScheduler {
public:
    long long schedule(const DiskInput &input) override;
};

#endif
