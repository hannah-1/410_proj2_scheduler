/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"
#include "../includes/PCB.h"
#include <vector>
#include <iostream>

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo(){
	for (int lines = 0; lines < vec->size(); lines++){
		std::cout << "Process " << lines
				<< " Required CPU time:"<< vec->at(lines).required_cpu_time
				<<" arrived:" << vec->at(lines).arrival_time
				<<" started:" << vec->at(lines).start_time
				<< " finished:" << vec->at(lines).finish_time
				<< "/n";
		}
	}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time(){
	return av_response_time;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time(){
	return av_turnaround_time;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time(){
	calcStats();
	return av_wait_time;
}

void Stats::calcStats(){
	av_wait_time = 0.0;
	av_turnaround_time = 0.0;
	av_response_time = 0.0;

	for (int lines = 0; lines < vec->size(); lines++){
		av_wait_time += vec->at(lines).finish_time - vec->at(lines).arrival_time - vec->at(lines).required_cpu_time;
		av_turnaround_time += vec->at(lines).finish_time - vec->at(lines).arrival_time;
		av_response_time += vec->at(lines).start_time - vec->at(lines).arrival_time;
	}

	av_wait_time = av_wait_time/vec->size();
	av_turnaround_time = av_turnaround_time /vec->size();
	av_response_time = av_response_time/vec->size();
}
