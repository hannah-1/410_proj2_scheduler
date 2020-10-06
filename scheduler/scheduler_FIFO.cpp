/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 *
 * 	Student Author: Hannah Allen
 * 	Due date: 10/6/2020
 *
 * 	Version: 1
 */


#include "../includes/scheduler_FIFO.h"

//override base class behaviour if necessary, otherwise call it
bool  Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);
}

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort(){
	preemptive = false;
}
