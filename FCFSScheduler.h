#ifndef FCFS_SCHEDULER_H
#define FCFS_SCHEDULER_H

#include "DiskScheduler.h"

class FCFSScheduler : public DiskScheduler {
public:
    long long schedule(const DiskInput &input) override;
};

#endif
