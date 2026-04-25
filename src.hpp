


# ifndef _SJTU_CPP_FINAL_SRC_HPP_
# define _SJTU_CPP_FINAL_SRC_HPP_

# include "task.hpp"

namespace sjtu {
    // FCFS method based CPU.
    class CPU_FCFS : public CPU {
    public:
        pair<CPUState, uint> run() override {
            if (tasks.empty()) {
                return make_pair(idle, 0);
            }
            Task &current_task = tasks[0];
            uint id = current_task.task_id;
            current_task.time--;
            if (current_task.time == 0) {
                tasks.erase(tasks.begin());
            }
            return make_pair(busy, id);
        }
    };

    // SRTF method based CPU.
    class CPU_SRTF : public CPU {
    public:
        pair<CPUState, uint> run() override {
            if (tasks.empty()) {
                return make_pair(idle, 0);
            }
            int best_idx = 0;
            for (int i = 1; i < (int)tasks.size(); ++i) {
                if (tasks[i].time < tasks[best_idx].time) {
                    best_idx = i;
                }
            }
            Task &current_task = tasks[best_idx];
            uint id = current_task.task_id;
            current_task.time--;
            if (current_task.time == 0) {
                tasks.erase(tasks.begin() + best_idx);
            }
            return make_pair(busy, id);
        }
    };

    // priority method based CPU.
    class CPU_PRIORITY : public CPU {
    public:
        pair<CPUState, uint> run() override {
            if (tasks.empty()) {
                return make_pair(idle, 0);
            }
            int best_idx = 0;
            for (int i = 1; i < (int)tasks.size(); ++i) {
                if (tasks[i].priority < tasks[best_idx].priority) {
                    best_idx = i;
                }
            }
            Task &current_task = tasks[best_idx];
            uint id = current_task.task_id;
            current_task.time--;
            if (current_task.time == 0) {
                tasks.erase(tasks.begin() + best_idx);
            }
            return make_pair(busy, id);
        }
    };
}

# endif


