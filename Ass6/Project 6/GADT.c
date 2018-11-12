/******************************************
* Student name: Omer Zucker
* Student: 200876548
* Course Exercise Group: 01
* Exercise name: ex6
******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "GADT.h"

/*******************************************
node_t is struct for nodes in linked list.
the struct comprise of value, next node
and different functios called from main.c
*******************************************/
typedef struct
{
	ELM val;
	struct node* nxt_node;
	// for each node call functions
	ELM(*create_elm)();
	void(*cpy_elm)(ELM, ELM);
	int(*cmp_elm)(ELM, ELM);
	void(*free_elm)(ELM);
	void(*print_elm)(ELM);
	ELM(*add_elm_to_elm)(ELM, ELM);
} node_t;

/******************************************************************************
*Function name: SLCreate
*The input: ELM head_val, ELM(*create_elm)(), void(*cpy_elm)(ELM, ELM),
			int(*cmp_elm)(ELM, ELM), void(*free_elm)(ELM),
			void(*print_elm)(ELM), ELM(*add_elm_to_elm)(ELM, ELM)
*The output: HEAD
*The function operation: create head node of linked list.
gets from main.c inserted value by user as well as specific functions for 
string or point values.
using malloc
******************************************************************************/
HEAD SLCreate(ELM head_val, ELM(*create_elm)(), void(*cpy_elm)(ELM, ELM),
	int(*cmp_elm)(ELM, ELM), void(*free_elm)(ELM),
	void(*print_elm)(ELM), ELM(*add_elm_to_elm)(ELM, ELM))
{
	// creating new node
	node_t *head = (node_t*)malloc(sizeof(node_t));
	// there is no available memory
	if (head == NULL)
	{
		return(NULL);
	}
	// there is available memory
	else
	{
		head->val = (ELM)create_elm();
		cpy_elm(head->val, head_val);
		head->nxt_node = NULL;
		head->create_elm = create_elm;
		head->cpy_elm = cpy_elm;
		head->cmp_elm = cmp_elm;
		head->free_elm = free_elm;
		head->print_elm = print_elm;
		head->add_elm_to_elm = add_elm_to_elm;
	}
	return(HEAD)(head);
}

/******************************************************************************
*Function name: SLDestroy
*The input: HEAD head
*The output: no output
*The function operation: deletes all values and nodes in list, by using the 
relevant free function from main.c
******************************************************************************/
void SLDestroy(HEAD head)
{
	node_t *currentNode, *prevNode;
	currentNode = (*((node_t**)head));
	node_t *tempNode = (node_t*)malloc(sizeof(node_t));
	tempNode->free_elm = (*((node_t**)head))->free_elm;
	// run through list until last node
	while (currentNode != NULL)
	{
		prevNode = currentNode;
		currentNode = (void*)currentNode->nxt_node;
		tempNode->free_elm(prevNode->val);
		free(prevNode);
	}
	free(tempNode);
}

/******************************************************************************
*Function name: SLAddListElement
*The input: HEAD* head, ELM node
*The output: RESULT (typedef enum)
*The function operation: creates new node and add it to correct place in list,
by using the relevant functions from main.c
******************************************************************************/
RESULT SLAddListElement(HEAD* head, ELM node)
{
	int flag, counter = 0;
	node_t *currentNode, *prevNode;
	currentNode = (*((node_t**)head));
	prevNode = currentNode;
	// create new node
	node_t *newNode = (node_t*)malloc(sizeof(node_t));
	newNode->val = (ELM)((*((node_t**)head))->create_elm());
	((*((node_t**)head))->cpy_elm)(newNode->val, node);
	// there is not available memory
	if (newNode == NULL)
	{
		return(outOfMem);
	}
	// run through list
	while (currentNode != NULL)
	{
		counter++;
		flag = (*((node_t**)head))->cmp_elm(currentNode->val, node);
		//  current->val > node
		if (flag == 1)
		{
			// newNode smaller than head
			if (counter == 1)
			{
				newNode->nxt_node = currentNode->nxt_node;
				(*((node_t**)head))->nxt_node = (void*)newNode;
				(*((node_t**)head))->cpy_elm(newNode->val, currentNode->val);
				(*((node_t**)head))->cpy_elm((*((node_t**)head))->val, node);
				return(success);
			}
			// end loop when finding correct place to add
			break;
		}
		// continue to next node
		else
		{
			prevNode = currentNode;
			currentNode = (void*)currentNode->nxt_node;
		}
	}
	//add newNode to correct place in list
	newNode->nxt_node = (void*)currentNode;
	prevNode->nxt_node = (void*)newNode;
	return(success);
}

/******************************************************************************
*Function name: SLRemoveElement
*The input: HEAD* head, ELM node
*The output: RESULT (typedef enum)
*The function operation: deletes specifec node that was choosen by user
in main.c.
******************************************************************************/
RESULT SLRemoveElement(HEAD* head, ELM node)
{
	int flag;
	node_t *currentNode, *prevNode;
	currentNode = (*((node_t**)head));
	prevNode = currentNode;
	//run through all nodes in list
	while (currentNode != NULL)
	{
		// compare between node to each val in list
		flag = (*((node_t**)head))->cmp_elm(currentNode->val, node);
		// head is the one to remove
		if ((flag == 0) && (currentNode == *head))
		{
			//head is not the only node in list
			if (currentNode->nxt_node != NULL)
			{
				currentNode = (void*)currentNode->nxt_node;
				(*((node_t**)head))->nxt_node = currentNode->nxt_node;
				(*((node_t**)head))->cpy_elm((*((node_t**)head))->val,
					currentNode->val);
			}
			(*((node_t**)head))->free_elm(currentNode->val);
			free(currentNode);
			return(success);
		}
		// the one to remove is not head
		else if (flag == 0)
		{
			prevNode->nxt_node = currentNode->nxt_node;
			(*((node_t**)head))->free_elm(currentNode->val);
			free(currentNode);
			return(success);
		}
		// continue to next node
		else
		{
			prevNode = currentNode;
			currentNode = (void*)currentNode->nxt_node;
		}
	}
	// node is not in the list
	return(badArgs);
}

/******************************************************************************
*Function name: SLFindElement
*The input: HEAD head, ELM node
*The output: ELM
*The function operation: run through all nodes in list until reaching the 
chosen node that has been inserted by user in main.c
******************************************************************************/
ELM SLFindElement(HEAD head, ELM node)
{
	int flag;
	node_t *currentNode;
	currentNode = (*((node_t**)head));
	while (currentNode != NULL)
	{
		flag = (*((node_t**)head))->cmp_elm(currentNode->val, node);
		// node == (currentNode->val)
		if (flag == 0)
		{
			// end loop when finding correct place to add
			return(currentNode);
		}
		// continue to next node
		else
		{
			currentNode = (void*)currentNode->nxt_node;
		}
	}
	// Element is not in list
	return(currentNode);
}

/******************************************************************************
*Function name: SLAddToElement
*The input: HEAD* head, ELM toEl, ELM addEl
*The output: no output
*The function operation: run through all nodes in list until reaching the
chosen node that has been inserted by user in main.c.
if the node found in list- it add the second element that also inserted by user,
if not- go out from function
******************************************************************************/
void SLAddToElement(HEAD* head, ELM toEl, ELM addEl)
{
	int flag;
	node_t *currentNode;
	currentNode = SLFindElement(head, toEl);
	// toEl not found in list
	if (currentNode != NULL)
	{
		// create val for addNode
		node_t *addNode = (node_t*)malloc(sizeof(node_t));
		addNode->val = (ELM)((*((node_t**)head))->create_elm());
		(*((node_t**)head))->cpy_elm(addNode->val, toEl);

		// add "addEl" to "toEl" 
		(*((node_t**)head))->add_elm_to_elm(addNode->val, addEl);

		// add the new val to correct place in list
		SLAddListElement(head, addNode->val);

		// remove toEl from list
		SLRemoveElement(head, toEl);
		(*((node_t**)head))->free_elm(addNode->val);
		free(addNode);
	}
}

/******************************************************************************
*Function name: SLPrintList
*The input: HEAD head
*The output: no output
*The function operation: prints the value of each node in list
******************************************************************************/
void SLPrintList(HEAD head)
{
	int i, counter = 0;
	node_t *currentNode;
	currentNode = (*((node_t**)head));
	while (currentNode != NULL)
	{
		i = 0;
		while (i != counter)
		{
			printf("\t");
			i++;
		}
		(*((node_t**)head))->print_elm(currentNode->val);
		currentNode = (void*)currentNode->nxt_node;
		counter++;
	}
}