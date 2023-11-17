/*
 * scheduler.c
 *
 *  Created on: Nov 1, 2023
 *      Author: dinhq
 */

#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void){
    current_index_task = 0;
    for (int i=0; i<SCH_MAX_TASKS; i++){
        SCH_tasks_G[current_index_task].pTask = 0;
        SCH_tasks_G[current_index_task].Delay = 0;
        SCH_tasks_G[current_index_task].Period = 0;
        SCH_tasks_G[current_index_task].RunMe = 0;

        SCH_tasks_G[current_index_task].TaskID = -1;
    }
}

uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t Delay, uint32_t Period){
	Delay = Delay / TICK ;
	Period = Period / TICK ;
    if(current_index_task < SCH_MAX_TASKS){

        SCH_tasks_G[current_index_task].pTask = pFunction;
        SCH_tasks_G[current_index_task].Delay = Delay;
        SCH_tasks_G[current_index_task].Period = Period;
        SCH_tasks_G[current_index_task].RunMe = 0;

        SCH_tasks_G[current_index_task].TaskID = current_index_task;

        current_index_task++;
        return SCH_tasks_G[current_index_task-1].TaskID;
    }
    return -1;
}

void SCH_Update(void){
    for (int i = 0; i < current_index_task; i++){
        if(SCH_tasks_G[i].Delay > 0){
            SCH_tasks_G[i].Delay--;
        }
        else {
            SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
            SCH_tasks_G[i].RunMe += 1;
        }
    }
}

void SCH_Dispatch_Tasks(void){
    for (int i = 0; i < current_index_task; i++){
        if (SCH_tasks_G[i].RunMe > 0){
            SCH_tasks_G[i].RunMe--;
            SCH_tasks_G[i].pTask();
            if (SCH_tasks_G[i].Period == 0){
            	SCH_Delete(i);
            }
        }
    }
}

uint8_t SCH_Delete(uint32_t ID){
	if (SCH_tasks_G[ID].pTask == 0) {
		return -1;
	}

	for (int i = ID; i < current_index_task; i++){
		SCH_tasks_G[i].pTask = SCH_tasks_G[i+1].pTask;
		SCH_tasks_G[i].Delay = SCH_tasks_G[i+1].Delay;
		SCH_tasks_G[i].Period = SCH_tasks_G[i+1].Period;
		SCH_tasks_G[i].RunMe = SCH_tasks_G[i+1].RunMe;
	}

	current_index_task--;
	return current_index_task;
}

uint32_t get_time(void) {
    time_t current_time = time(NULL);
    return (uint32_t)(current_time * 1000); // Convert to milliseconds
}

void timerCallback() {
    uint32_t currentTime = get_time();
    printf("Current Time: %lu\n", currentTime);
}
