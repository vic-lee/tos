#pragma once

#include <vector>

#include "process.h"
#include "scheduler.h"

namespace scheduler
{
class ProcessManager
{
    typedef std::pair<pid_t, process_t> PCB_t;

public:
    ProcessManager();
    pid_t load();
    pid_t find(pid_t pid);
    size_t active_process_count() const;

private:
    static const unsigned int MAX_ACTIVE_PROCESS_COUNT_;
    static unsigned int pidctr_;
    std::map<pid_t, process_t> processtable_;
    Scheduler sch_;
};
} // namespace scheduler