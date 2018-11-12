/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex5.c
******************************************/

#include "mission3.h"

/**************************************************************************************
* function name: Mission3
* input: /
* output: printing (str+n), strlen(str+n)
* operation function:
- gets from user: size, str
- allocates memory for: str
- call ShortestStr function
- print: (str+n), strlen(str+n)
* Note: /
* *************************************************************************************/
void Mission3()
{
	char *str;
	char dummy;
	int size, n;
	printf("Please enter how many chars to allocate:\n");
	scanf("%d", &size);
	str = (char*)malloc(size * sizeof(char));
	// no available memory
	if (str == NULL)
	{
		printf("Error: Cannot Allocate Memory\n");
	}
	// there is available memory for str
	else
	{
		printf("Allocated %d chars\n", size);
		printf("Please enter your string:\n");
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
			n = ShortestStr(str);
			printf("The shortest prefix building the string is: ");
			printf("%s of length %d\n", (str + n), strlen(str + n));
		}
	}
	free(str);
}

/**************************************************************************************
* function name: ShortestStr
* input: char *str
* output: return strlen(str+i), i
* operation function: checks the smallest protasis
* Note: called by Mission3 function
* *************************************************************************************/
int ShortestStr(char *str)
{
	int i;
	for (i = 1; i < (int)strlen(str); i++)
	{
		// smallest protasis is a part of the string
		if (strncmp(str, (str + i), (int)strlen(str + i)) == 0)
		{
			return(strlen(str + i));
		}
	}
	// smallest protasis is the whole string
	i = 0;
	return(i);
}
