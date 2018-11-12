#ifndef MISSION6_H
#define MISSION6_H



#include <stdio.h>
#include <stdlib.h>
/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex5.c
******************************************/


#include <string.h>
#include <malloc.h>

struct number
{
	int x;
	struct number *nxt_number;
};
typedef struct number number_t;

void Mission6();
void Add_Item(number_t** head);
void Eject_Item(number_t** head);
void Print_Queue(number_t** head);
void Max_Value(number_t** head);
void Min_Value(number_t** head);
void Find_index(number_t** head);
void Clean_Queue(number_t** head);

#endif // !TRANSLATOR_H


#pragma once