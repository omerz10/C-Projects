/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex4.c
******************************************/

#ifndef CALCULATOR_H
#define CALCULATOR_H
#define	MAX_M 16
#include <stdio.h>
#include <string.h>
int Change_Letters();
int Matrix_Multiply(int row, int col, int basic_matri[MAX_M][MAX_M]);
void Calculator();
void Translator();
void Matrix_add(int row, int col, int basic_matrix[MAX_M][MAX_M]);
void Matrix_Sub(int row, int col, int basic_matrix[MAX_M][MAX_M]);
void Matrix_Transpose(int row, int col, int basic_matrix[MAX_M][MAX_M]);
void Matrix_Answer(int row, int col, int final_matrix[MAX_M][MAX_M]);

#endif // !TRANSLATOR_H


#pragma once

