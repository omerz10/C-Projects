/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex4.c
******************************************/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#define MAX_LINE 55
#define MAX_WORD 15
#include <stdio.h>
#include <string.h>
void Small_Letters(char pig_latin[MAX_WORD]);
void Vowel_Middle(int i, char until_vowel[MAX_WORD], char pig_latin[MAX_WORD]);
void Vowel_First(char until_vowel[MAX_WORD], char pig_latin[MAX_WORD]);
void Word_Kinds(int counter, int i, char until_vowel[MAX_WORD], char pig_latin[MAX_WORD]);

#endif // !TRANSLATOR_H


#pragma once


