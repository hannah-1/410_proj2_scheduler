/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */
#include "../includes/scheduler_SRTF.h"
#include <vector>
#include <algorithm>

//override base class behaviour if necessary, otherwise call it
bool  Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

bool greater_than_sort(PCB first, PCB second){
	return (first.remaining_cpu_time < second.remaining_cpu_time);
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort(){
	preemptive = true;
	std::vector<PCB> vec;
	while (!ready_q->empty()){
		vec.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(vec.begin(), vec.end(), greater_than_sort);

	for(unsigned int i=0; i<vec.size();i++){
		ready_q->push(vec.at(i));
	}

}
