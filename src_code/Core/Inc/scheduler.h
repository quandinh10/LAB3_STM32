/*
 * scheduler.h
 *
 *  Created on: Nov 1, 2023
 *      Author: dinhq
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
    void (*pTask)(void);
    uint32_t    Delay;
    uint32_t    Period;
    uint8_t     RunMe;

    uint32_t    TaskID;
}sTasks;

#define SCH_MAX_TASKS   40
#define TICK 			10

void SCH_Init(void);

//init_task
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t Delay, uint32_t Period);

//timerRun
void SCH_Update(void);

//timerFlag
void SCH_Dispatch_Tasks(void);

uint8_t SCH_Delete(uint32_t ID);

uint32_t get_time(void);
void timerCallback();

#endif /* INC_SCHEDULER_H_ */
