/*
 * GccApplication1.c
 *
 * Created: 9/25/2019 9:09:41 AM
 * Author : bpaiva1
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
uint8_t taskData;
uint8_t stateMemory;
uint8_t CurrentTask=0;
uint8_t Priority[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
uint8_t Deadlock=0;
uint8_t DeadlockLast=0;
uint8_t DeadlockCount=0;

extern func();
extern KillSwitch();

Task list = (Task*)malloc(16*sizeof(Task));

int main(void)
{
	MemoryAllocation();
	TCNT1= -62500; //TICKS
	TCCR1A=(0b00<<COM1A0)|(0b00<<COM1B0)|(0b00WGM10); //Timer 1, Normal Mode
	TCCR1B=(0b00<<WGM12)|(0b100<<CS10);
	TIMSK1=(0b0<<TOIE0);
	sei(); //Enables interrupts
    while(1)
    {
        runTask();
    }
}
ISR(TIMER1_OVF_vect)
{
    TCNT1 = -62500;
    if (Deadlock == 1)
    {
        extern KillSwitch();
        KillSwitch();
        return;
    }
	extern func();
	func();//pushs and pops registers and calls nextTask()
	
}

/*
Operating System Functions for Task 
-OS_Kill
-OS_Sleep
-OS_Yield
-

*/ 
void MemoryAllocation()
{
	taskData = (int*)malloc(250*sizeof(int)); //1kb
	stateMemory = (int*)malloc(250*sizeof(int)); //1kb
}
typedef struct
{
	uint8_t state = 0; // 0 = ready, 1 = run, 2 = sleep, 3 = blocked
	uint8_t priority = 0; // 0 = atomic, 1 = high, 2 = med, 3 = low
}
void Nexttask()
{
	list[CurrentTask].state = 0;//sets state to ready
	uint8_t temp = CurrentTask;
	uint8_t temp1=0;
	uint8_t i=15;
	for(i=15; i>=0 ;i++)//sorts priority queue
	{
		temp1= Priority[i];
		Priority[i] = temp;
		temp = temp1;
	}
    if(Priority[0] == DeadlockLast)
    {
        DeadlockCount++;
        if(DeadlockCount > 20)
        {
            CurrentTask= Priority[1]
            Deadlock=1;
            DeadlockCount=0;
            return;
        }
    }
    else
    {
        DeadlockCount = 0;
    }
    DeadlockLast = Priority[0];
	temp = CurrentTask;
	do{
		if(list[Priority[i]].state==0)
		{
			CurrentTask= Priority[i];
		}
        else
            i++;
	}while(CurrentTask==temp);
    
	list[CurrentTask].state = 1;//moves program to run state
}

struct TCB{
	uint16_t taskID;
	uint16_t taskPriority; 
	uint16_t taskState;
    uint8_t Semaphore;
	void* taskDataPtr; 
	void killTask(); 
	void suspendTask(); 
	void runTask();
	};
	typedef struct TCB TCBType;
	typedef TCBType *TCBPtr;
	
TCBType tasks[16];	//List of tasks 0-16 while active 
 

tasks[0].taskID = 0;
tasks[1].taskID = 1;
tasks[2].taskID = 2;
tasks[3].taskID = 3;
tasks[4].taskID = 4;
tasks[5].taskID = 5;
tasks[6].taskID = 6;
tasks[7].taskID = 7;
tasks[8].taskID = 8;
tasks[9].taskID = 9;
tasks[10].taskID = 10;
tasks[11].taskID = 11;
tasks[12].taskID = 12;
tasks[13].taskID = 13;
tasks[14].taskID = 14;
tasks[15].taskID = 15;

void killTask()
{
    list[CurrentTask].state = 3;//gets overwritten quickly-working on solution
    Deadlock = 0;
    extern KillSwitch();
    KillSwitch();
    //new assmbely function to delete registers.
    
}
void suspendTask()
{
	list[CurrentTask].state = 2;//sets state to sleep
    uint8_t temp = CurrentTask;
    uint8_t temp1=0;
    uint8_t i=15;
    for(i=15; i>=0 ;i++)//pushs forward queue
    {
        temp1= Priority[i];
        Priority[i] = temp;
        temp = temp1;
    }
    temp = CurrentTask;
    do{
        if(list[Priority[i]].state==0)
        {
            CurrentTask= Priority[i];
        }
        else
            i++;
    }while(CurrentTask==temp);
    list[CurrentTask].state = 1;//moves program to run state
}
/*void sem_wait(S)
{
    while (S<=0);
    S--;
}

void sem_signal()
{
    S++;
}*/

/*
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int* array;
    };

struct semaphore{enum value(0,1);  // Process synchronization example from geeksforgeeks.org
    //q contains all TCBs
    Queue<task> q; }
    P(semaphore s)
    {
        if (s.value == 1)
        {
            s.value = 0;
        }
    }
    V(semaphore s)
    {
        if (s.q == NULL) //if s.q is empty
        {
            s.value = 1;
        }
        else
        {
            q.pop(); //select a process from the waiting queue
            wakeup();
        }
    }
*/

void runTask()
{
	switch(CurrentTask)
    {
        case 0:
            task0();
            break;
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        case 6:
            task6();
            break;
        case 7:
            task7();
            break;
        case 8:
            task8();
            break;
        case 9:
            task9();
            break;
        case 10:
            task10();
            break;
        case 11:
            task11();
            break;
        case 12:
            task12();
            break;
        case 13:
            task13();
            break;
        case 14:
            task14();
            break;
        case 15:
            task15();
            break;
        case 16:
            task16();
            break;
    }
    TCNT1=0 //if program ends triger ISR
}
void task0(){
        
}
void task1(){
        
}
void task2(){
        
}
void task3(){
        
}
void task4(){
        
}
void task5(){
        
}
void task6(){
        
}
void task7(){
        
}
void task8(){
        
}
void task9(){
        
}
void task10(){
    
}
void task11(){
        
}
void task12(){
        
}
void task13(){
        
}
void task14(){
    
}
void task15(){
        
}
void task16(){
        
}
