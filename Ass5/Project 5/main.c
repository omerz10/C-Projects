/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex5.c
******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "mission1.h"
#include "mission2.h"
#include "mission3.h"
#include "mission4.h"
#include "mission5.h"
#include "mission6.h"


int main()
{
	int task;
	do
	{
		printf("Please enter your input:\n");
		scanf("%d", &task);
		switch (task)
		{
			case 1:
			{
				Mission1();
				break;
			}
			case(2):
			{
				Mission2();
				break;
			}
			case(3):
			{
				Mission3();
				break;
			}
				
			case(4):
			{
				Mission4();
				break;
			}
				
			case(5):
			{
				Mission5();
				break;
			}
			case(6):
			{
				Mission6();
				break;
			}
				
			// end the program
			default:  
			{
				break;
			}	
		}
		// '0' ends the program
	} while (task != 0);
}

