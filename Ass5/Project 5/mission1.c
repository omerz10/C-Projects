/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex5.c
******************************************/

#include "mission1.h"

/**************************************************************************************
* function name: Mission1
* input: /
* output: printing str after sorting
* operation function:
- gets from user: size ,str
- allocates memory for: str
- call SortString function
- print: size, str
* Note: /
* *************************************************************************************/
void Mission1()
{
	char *str;
	char dummy;
	int size;
	printf("Please enter how many chars to allocate:\n");
	scanf("%d", &size);
	str = (char*)malloc((size + 1) * sizeof(char));
	// no available memory
	if (str == NULL)
	{
		printf("Error: Cannot Allocate Memory\n");
	}
	// there is available memory for str
	else
	{
		printf("Allocated %d chars\n", size);
		printf("Please enter string to be sorted:\n");
		// scanf dummy for \n
		scanf("%s%c", str, &dummy);
		// verify correct size of input
		if ((int)strlen(str) >= size)
		{
			printf("Error: Illegal input\n");
		}
		// size of input is correct
		else
		{
			SortString(str, size);
			printf("The string after sorting is: %s\n", str);
		}
	}
	free(str);
}

/**************************************************************************************
* function name: SortString
* input: char* str, int size
* output: return flag
* operation function:
- sort string according to alphabetic order and capital letters
- call Compare_Letters function
* Note: called by Mission1 function
* *************************************************************************************/
int SortString(char* str, int size)
{
	int i, j;
	int flag = 0;
	//check if letters are correct
	if (Check_String(str) != 1)
	{
		//go through str
		for (i = 0; i < (size - 1); i++)
		{
			//for each letter in str
			for (j = 0; j < (size - 1 - i); j++)
			{
				flag = Compare_Letters(str, j, flag);
			}
		}
	}
	return(flag);
}

/**************************************************************************************
* function name: Chack_String
* input: char *str
* output:
- prints: "Error: Illegal input\n"
- return 1
* operation function: verify all letters are in English
* Note: /
* *************************************************************************************/
int Check_String(char *str)
{
	int i;
	for (i = 0; i < (int)strlen(str); i++)
	{
		if (*(str + i) < 'A' || *(str + i) > 'z')
		{
			printf("Error: Illegal input\n");
			return(1);
		}
	}
	return(0);
}

/**************************************************************************************
* function name: Swap_Letters
* input: char *str, int i, int j
* output: /
* operation function: Swap letters in array
* Note: /
* *************************************************************************************/
int Swap_Letters(char *str, int i, int j)
{
	char tmp;
	// indicate for operate swap 
	int flag = 1;
	tmp = *(str + i);
	*(str + i) = *(str + j);
	*(str + j) = tmp;
	return (flag);
}

/**************************************************************************************
* function name: Swap_Letters
* input: char *str, int i, int j
* output: /
* operation function: Swap letters in array
* Note: /
* *************************************************************************************/
int Compare_Letters(char *str, int j, int flag)
{
	// compare between 2 big letters
	if ((*(str + j) >= 'A') && (*(str + j) <= 'Z') &&
		(*(str + j + 1) >= 'A') && (*(str + j + 1) <= 'Z') &&
		*(str + j) > *(str + j + 1))
	{
		flag = Swap_Letters(str, j, j + 1);
	}
	// compare between 2 small letters
	else if ((*(str + j) >= 'a') && (*(str + j) <= 'z') &&
		(*(str + j + 1) >= 'a') && (*(str + j + 1) <= 'z') &&
		*(str + j) > *(str + j + 1))
	{
		flag = Swap_Letters(str, j, j + 1);
	}
	// compare between one small letter & one big letter
	else if ((*(str + j) >= 'A') && (*(str + j) <= 'Z') &&
		(*(str + j + 1) >= 'a') && (*(str + j + 1) <= 'z') &&
		*(str + j) < *(str + j + 1))
	{
		flag = Swap_Letters(str, j, j + 1);
	}
	return(flag);
}
