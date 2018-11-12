/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex5.c
******************************************/

#ifndef MISSION5_H
#define MISSION5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void Mission5();
void Print_FinalStr(char *finalStr, char *s, int counter, int maxLength);
int Get_EachChar(char **newName, int length);
int Sort_word(char **temp, char ** finalStr, char** newName, int counter,
	int maxLength);

#endif // !TRANSLATOR_H


#pragma once