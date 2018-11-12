/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex5.c
******************************************/

#include "mission6.h"

/****************************************************************************
* function name: Mission6
* input: /
* output: prints request sentence from user and choice
* operation function:
- allocates memory and define several strings
- call Get_EachChar function, Print_FinalStr function
- each case calls different function
* Note: /
* *************************************************************************/
void Mission6()
{
	int flag, choice = 8;
	number_t *head = NULL;
	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
		{
			Add_Item(&head);
			break;
		}
		case 2:
		{
			Eject_Item(&head);
			break;
		}
		case 3:
		{
			Print_Queue(&head);
			break;
		}
		case 4:
		{
			Max_Value(&head);
			break;
		}
		case 5:
		{
			Min_Value(&head);
			break;
		}
		case 6:
		{
			Find_index(&head);
			break;
		}
		case 7:
		{
			Clean_Queue(&head);
			break;
		}
		case 8:
		{
			printf("Please select your choice:\n");
			printf("0.Exit\n1.Add item to the queue\n");
			printf("2.Remove item from the queue\n3.Print queue\n");
			printf("4.Print the maximum item in the queue\n");
			printf("5.Print the minimum item in the queue\n");
			printf("6.Print index of given item\n7.Clear queue\n");
			printf("8.Print the menu\n");
			flag = 0;
			break;
		}
		}
		// 0 ends the program
		if (flag != 0)
		{
			printf("Please select your next choice ");
			printf("(select 8 for complete menu)\n");
		}
		flag = 1;
		scanf("%d", &choice);
	}
}

/****************************************************************************
* function name: Add_Item
* input: int** head
* output: print item add by user
* operation function:
- add item and save it in list in FIFO order
- print added item
* Note: /
* ****************************************************************************/
void Add_Item(number_t** head)
{
	int var;
	char dummy;
	number_t *temp;
	temp = *head;
	// create new item
	number_t* newItem = (number_t*)malloc(sizeof(number_t));
	// there is not available memory
	if (newItem == NULL)
	{
		printf("Error: Cannot allocate Memory\n");
	}
	// there is available memory
	else
	{
		printf("Enter item value to add\n");
		scanf("%c%d", &dummy, &var);
		newItem->x = var;
		// queue is empty
		if (*head == NULL)
		{
			*head = newItem;
			newItem->nxt_number = NULL;
		}
		// queue is not empty
		else
		{
			while ((temp->nxt_number) != NULL)
			{
				temp = temp->nxt_number;
			}
			newItem->nxt_number = NULL;
			temp->nxt_number = newItem;
		}
	}
	printf("Item %d added\n", newItem->x);
}

/******************************************************************************
* function name: Eject_Item
* input: int** head
* output: print ejected item by user
* operation function:
- eject item and in FIFO order and clear it from list
- eject added item
* Note: /
* ****************************************************************************/
void Eject_Item(number_t** head)
{
	number_t *temp;
	temp = NULL;
	// queue is empty
	if (*head == NULL)
	{
		printf("Error: Queue is empty!\n");
	}
	else
	{
		temp = *head;
		*head = (*head)->nxt_number;
		printf("Item %d was removed\n", temp->x);
	}
	free(temp);
}

/*****************************************************************************
* function name: Print_Queue
* input: int** head
* output: print all queue items
* operation function: run through list and prind each item
* Note: /
* ****************************************************************************/
void Print_Queue(number_t** head)
{
	int flag = 0;
	number_t *temp;
	temp = *head;
	// queue is empty
	if (*head == NULL)
	{
		printf("Error: Queue is empty!\n");
	}
	// queue is not empty
	else
	{
		printf("Queue items are: ");
		// run through queue until first input var
		while ((temp->nxt_number) != NULL)
		{
			// first item
			if (flag == 0)
			{
				printf("%d", temp->x);
			}
			// second item and beyond
			else
			{
				printf(" %d", temp->x);
			}
			flag++;
			temp = temp->nxt_number;
		}
		// last item
		printf(" %d\n", temp->x);
	}
}

/*****************************************************************************
* function name: Max_Value
* input: int** head
* output: prints maximum value
* operation function: run through list and print maximum value in item
* Note: /
* ***************************************************************************/
void Max_Value(number_t** head)
{
	int flag = 0, max = 0;
	number_t *temp;
	temp = *head;
	// queue is empty
	if (*head == NULL)
	{
		printf("Error: Queue is empty!\n");
	}
	// queue is not empty
	else
	{
		// max is the first item.x in queue
		max = (*head)->x;
		// run through queue until first input var
		while ((temp->nxt_number) != NULL)
		{
			// change max
			if ((temp->x) > max)
			{
				max = temp->x;
			}
			temp = temp->nxt_number;
		}
		// change max for last item
		if ((temp->x) > max)
		{
			max = temp->x;
		}
		// last item
		printf("Maximum item in queue is %d\n", max);
	}
}

/******************************************************************************
* function name: Min_Value
* input: int** head
* output: prints minimum value
* operation function: run through list and print minimum value in item
* Note: /
* ****************************************************************************/
void Min_Value(number_t** head)
{
	int flag = 0, min = 0;
	number_t *temp;
	temp = *head;
	// queue is empty
	if (*head == NULL)
	{
		printf("Error: Queue is empty!\n");
	}
	// queue is not empty
	else
	{
		// max is the first item.x in queue
		min = (*head)->x;
		// run through queue until first input var
		while ((temp->nxt_number) != NULL)
		{
			// change max
			if ((temp->x) < min)
			{
				min = temp->x;
			}
			temp = temp->nxt_number;
		}
		// change max for last item
		if ((temp->x) < min)
		{
			min = temp->x;
		}
		// last item
		printf("Minimum item in queue is %d\n", min);
	}
}

/******************************************************************************
* function name: find_index
* input: int** head
* output: prints index of requested item
* operation function: run through list and pprint
* Note: /
* ****************************************************************************/
void Find_index(number_t** head)
{
	char dummy;
	int flag = 0, min = 0, var = 0, counter = 1;
	number_t *temp;
	temp = *head;
	// queue is empty
	if (*head == NULL)
	{
		printf("Error: Queue is empty!\n");
		return;
	}
	// queue is not empty
	else
	{
		printf("Please enter the item you would like to know its index\n");
		// dummy for \n
		scanf("%c%d", &dummy, &var);
		// run through queue until first input var
		while ((temp->nxt_number) != NULL)
		{
			// change max
			if ((temp->x) == var)
			{
				printf("Item %d index is %d\n", var, counter);
				flag = 1;
			}
			counter++;
			temp = temp->nxt_number;
		}
			// if it is the last number
			if ((temp->x) == var)
			{
				printf("Item %d index is %d\n", var, counter);
				flag = 1;
			}
			// the item is not exist
			else if(flag == 0)
			{
				printf("Error: no such item!\n");
			}
		}

	}


/******************************************************************************
* function name: Clean_Queue
* input: int** head
* output: print after the list were cleaned from items
* operation function: run through list and clean the items
* Note: /
* ****************************************************************************/
void Clean_Queue(number_t** head)
{
	int flag = 0;
	number_t *temp;
	temp = *head;
	// queue is empty
	if (*head == NULL)
	{
		printf("Error: Queue is empty!\n");
	}
	// queue is not empty
	else
	{
		// run through queue until first input var
		while ((*head) != NULL)
		{
			temp = *head;
			*head = (*head)->nxt_number;
			free(temp);
		}
		printf("Queue is clear\n");
	}
}


