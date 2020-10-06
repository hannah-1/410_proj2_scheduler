/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/scheduler.h"

//add a process, either a new one or one that
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p){
	ready_q->push(p);
}

//get next process
PCB Scheduler::getNext(){
	return ready_q->front();
}

//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty(){
	return ready_q->empty();
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p){
	if ((p.remaining_cpu_time == 0) or ((preemptive == true) and (time_slice==0))){
		return true;
	}
	return false;
}






