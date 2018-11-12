/******************************************
* Student name: Omer Zucker
* Student: 200876548
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GADT.h"

/*******************************************
struct for the point.
*******************************************/
typedef struct
{
	int x, y;
} point;

// functions declaration
HEAD create_str();
HEAD create_point();
void cpy_point(point *p1, point *p2);
void cpy_str(char* str1, char* str2);
int cmp_point(point* p1, point* p2);
int cmp_str(char* str1, char* str2);
void free_point(point* p);
void free_str(char* str);
void print_point(point* p);
void print_str(char* str);
ELM add_point_to_point(point* p1, point* p2);
ELM add_str_to_str(char* str1, char* str2);
ELM InputType(int choice);

/*****************************************************************************
*Function name: main												         
*The input: no input					                                     
*The output: no output 						                                 
*The function operation: the user for linked list of strings or points, and
then choose each operation using switch case.
in every case we use "if" to divide between string(num==0) to point(num==1)	 
*****************************************************************************/
int main()
{
	int choice, counter = 0;
	int add_result, remove_result;
	char dummy, listKey;
	HEAD head_val, head;
	ELM node, find_result, toEl, addEl;
	// dummy for \n
	scanf("%d%c", &choice, &dummy);
	switch (choice)
	{
		// creates head in linked list of strings
		case 0:
		{
			head_val = InputType(choice);
			// call the generic function SLCreate from GADT.c 
			head = SLCreate(head_val, (ELM)create_str, (ELM)cpy_str, 
				(ELM)cmp_str, (ELM)free_str, (ELM)print_str, 
				(ELM)add_str_to_str);
			free(head_val);
			//one element added to list
			counter++;
			break;
		}
		// creates head in linked list of points
		case 1:
		{
			head_val = InputType(choice);
			// call the generic function SLCreate from GADT.c 
			head = SLCreate(head_val, (ELM)create_point, (ELM)cpy_point,
				(ELM)cmp_point, (ELM)free_point, (ELM)print_point,
				(ELM)add_point_to_point);
			free(head_val);
			//one element added to list
			counter++;
			break;
		}
		default:
		{
			break;
		}
	}
	do
	{
		// dummy for \n
		scanf("%c%c", &listKey, &dummy);
		// each case operates different action in linked list
		switch (listKey)
		{
			// adding new node to list
			case('a'):
			{
				// gets string or point from user
				node = InputType(choice);
				add_result = SLAddListElement(&head, node);
				free(node);
				// one element added to list
				if (add_result == success)
				{
					counter++;
				}
				break;
			}
			// find specific node in list
			case('s'):
			{	
				// gets string or point from user
				node = InputType(choice);
				find_result = SLFindElement(&head, node);
				free(node);
				// node found in list
				if (find_result != NULL)
				{
					printf("TRUE\n");
				}
				// node was not found in list
				else
				{
					printf("FALSE\n");
				}
				break;
			}
			// remove specific node in list
			case('d'):
			{
				// gets string or point from user
				node = InputType(choice);
				remove_result =  SLRemoveElement(&head, node);
				free(node);
				// node found in list
				if (remove_result == success)
				{
					counter--;
					// list is empty
					if (counter == 0)
					{
						// ends the program
						listKey = 'e';
					}
				}
				// node was not found in list
				else
				{
					printf("FALSE\n");
				}
				break;
			}
			// prints values of all nodes in list
			case('p'):
			{
				SLPrintList(&head);
				break;
			}
			// prints length of list
			case('l'):
			{
				printf("%d\n", counter);
				break;
			}
			// add element to element
			case('t'):
			{
				// gets the elemnt we add to
				toEl = InputType(choice);
				// gets the added element
				addEl = InputType(choice);
				SLAddToElement(&head, toEl, addEl);
				free(toEl);
				free(addEl);
				break;
			}
			// deletes values of all nodes in list
			case('e'):
			{
				SLDestroy(&head);
				break;
			}
			default:
			{
				break;
			}
		}
	// enter 'e' ends the program
	} while (listKey != 'e');
}

/******************************************************************************
*Function name: InputType									            
*The input: int choice				                                        
*The output: ELM												                
*The function operation: gets from the user string value or point values
using malloc																	
******************************************************************************/
ELM InputType(int choice)
{
	char dummy;
	switch (choice)
	{
		// gets string
		case 0:
		{
			char* str = (char*)malloc(16 * sizeof(char));
			if (str == NULL)
			{
				return(NULL);
			}
			// dummy for \n
			scanf("%s%c", str, &dummy);
			return(str);
		}
		// gets point
		case 1:
		{
			point* point_val = (point*)malloc(1 * sizeof(point));
			if (point_val == NULL)
			{
				return(NULL);
			}
			// input in pattern: (x,y)
			scanf(" (%d,%d)%c", &(point_val->x), &(point_val->y), &dummy);
			return(point_val);
		}
		default:
		{
			return(NULL);
		}
	}
}

/******************************************************************************
*Function name: create_point									            
*The input: no input					                                        
*The output: ELM												                
*The function operation: allocates memory for the point
using malloc																	
******************************************************************************/
HEAD create_point()
{
	point* newPoint = (point*)malloc(1 * sizeof(point));
	return(HEAD)(newPoint);
}

/******************************************************************************
*Function name: create_str										            
*The input: no input					                                        
*The output: ELM												                
*The function operation: allocates memory for the string
using malloc																	
******************************************************************************/
HEAD create_str()
{
	char* str = (char*)malloc(15 * sizeof(char));
	return(HEAD)(str);
}

/******************************************************************************
*Function name: cpy_point
*The input: point *p1 , point *p2
*The output: no output
*The function operation: insert the value to the memory allocated
******************************************************************************/
void cpy_point(point *p1 , point *p2)
{
	p1->x = p2->x;
	p1->y = p2->y;
}

/******************************************************************************
*Function name: cpy_str										            
*The input: char* str1, char* str2			                                        
*The output: no output											                
*The function operation: insert the value to the memory allocated																		
******************************************************************************/
void cpy_str(char* str1, char* str2)
{
	strcpy(str1, str2);
}

/******************************************************************************
*Function name: cmp_point
*The input: point* p1, point* p2
*The output: int
*The function operation: compare between the exist node to the new node using
strcmp function
******************************************************************************/
int cmp_point(point* p1, point* p2)
{
	int total_p1 = abs(p1->x) + abs(p1->y);
	int total_p2 = abs(p2->x) + abs(p2->y);
	if (total_p1 > total_p2)
	{
		return(1);
	}
	else if (total_p1 == total_p2)
	{
		return(0);
	}
	// total_p1 < total_p2
	else
	{
		return(-1);
	}
}

/******************************************************************************
*Function name: cmp_str											            
*The input: char* str1, char* str2			                                        
*The output: int												                
*The function operation: compare between the exist node to the new node using
strcmp function												
******************************************************************************/
int cmp_str(char* str1, char* str2)
{
	int result;
	result = strcmp(str1, str2);
	return(result);
}

/******************************************************************************
*Function name: free_point
*The input: char* point
*The output: no output
*The function operation: free memory
******************************************************************************/
void free_point(point* p)
{
	free(p);
}

/******************************************************************************
*Function name: free_str										            
*The input: char* str						                                        
*The output: no output											                
*The function operation: free memory							
******************************************************************************/
void free_str(char* str)
{
	free(str);
}

/******************************************************************************
*Function name: print_point
*The input: char* point
*The output: no output
*The function operation: prints the point value
******************************************************************************/
void print_point(point* p)
{
	printf("%.3d|%.3d\n", p->x, p->y);
}

/******************************************************************************
*Function name: print_str										            
*The input: char* str					                                        
*The output: no output											                
*The function operation: prints the string value				
******************************************************************************/
void print_str(char* str)
{
	printf("%s\n", str);
}

/******************************************************************************
*Function name: add_point_to_point
*The input: point* p1, point* p2
*The output: ELM
*The function operation: adding 2 values by using the saved function 'strcat'
******************************************************************************/
ELM add_point_to_point(point* p1, point* p2)
{
	p1->x = (p1->x) + (p2->x);
	p1->y = (p1->y) + (p2->y);
	return(ELM)(p1);
}

/******************************************************************************
*Function name: add_str_to_str								            
*The input: char* str1, char* str2	                                        
*The output: ELM												                
*The function operation: adding 2 values by using the saved function 'strcat'												
******************************************************************************/
ELM add_str_to_str(char* str1, char* str2)
{
	strcat(str1, str2);
	return(ELM)(str1);
}

