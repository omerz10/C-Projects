/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex5.c
******************************************/


#include "mission2.h"

/**************************************************************************************
* function name: Mission2
* input: /
* output: printing size1, size2, str, sub
* operation function:
- gets from user: size1, size2 ,str, sub
- allocates memory for: str, sub
- call Check_TwoStrings
- print: size1, size2, str, sub, flag
* Note: /
* *************************************************************************************/
void Mission2()
{
	int size1, size2, flag = 0;
	char *str, *sub, dummy;
	printf("Please enter how many chars to allocate to the two strings:\n");
	scanf("%d %d", &size1, &size2);
	str = (char*)malloc(size1 * sizeof(char));
	sub = (char*)malloc(size2 * sizeof(char));
	// no available memory
	if ((str == NULL) || (sub == NULL))
	{
		printf("Error: Cannot Allocate Memory\n");
	}
	// there is available memory for str1, str2
	else
	{
	
		printf("Allocated %d chars and %d chars\n", size1, size2);
		printf("Please enter two arrays of chars:\n");
		// scanf dummy for \n
		scanf("%s%s%c", str, sub, &dummy);
		flag = Check_TwoStrings(size1, size2, flag, str, sub);
		// there is concentration
		if (flag > 0)
		{
			printf("%s is a concatenation of %s %d times\n", str, sub, flag);
		}
	}
	free(str);
	free(sub);
}

/**************************************************************************************
* function name: Check_TwoStrings
* input: int size1, int size2, int flag, char *str, char *sub
* output: prints if there is error
* operation function:
- checks if there is error in input
- call SubGenerator
* Note: called by Mission2 function
* *************************************************************************************/
int Check_TwoStrings(int size1, int size2, int flag, char *str, char *sub)
{
	// str or sub are bigger than allocated sizes
	if (((int)strlen(str) >= size1) || ((int)strlen(sub) >= size2))
	{
		printf("Error: Illegal input\n");
	}
	// size of sub bigger than str
	else if (strlen(sub) > strlen(str))
	{
		printf("No concatenation found\n");
	}
	// correct input
	else
	{
		flag = SubGenerator(str, sub, flag);
		return(flag);
	}
	return(flag);
}

/**************************************************************************************
* function name: SubGenerator
* input: char *str, char *sub, int flag
* output: print concentration's differnet conditions
* operation function: checks concentration between str and sub
* Note: called by  Check_TwoStrings function
* *************************************************************************************/
int SubGenerator(char *str, char *sub, int flag)
{
	int i;

	for (i = 0; i < (int)strlen(str); i += (strlen(sub)))
	{
		// sub is in str
		if (strncmp(str + i, sub, strlen(sub)) == 0)
		{
			flag++;
		}
		// sub is not in str completely
		else
		{
			printf("No concatenation found\n");
			flag = 0;
			return(flag);
		}
	}
	return(flag);
}
