/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex5.c
******************************************/

#include "mission4.h"

/**************************************************************************************
* function name: Mission4
* input: /
* output: prints request sentences for different inputs
* operation function:
- gets from user: sizeStr, str, n
- allocates memory for: str, strMid
- call ReverseNumWords function
* Note: /
* *************************************************************************************/
void Mission4()
{
	char *str, *strMid;
	char dummy;
	int n, sizeStr;
	printf("Please enter how many chars to allocate:\n");
	scanf("%d", &sizeStr);
	str = (char*)malloc((sizeStr + 1) * sizeof(char));
	strMid = (char*)malloc((sizeStr + 1) * sizeof(char));
	// no available memory
	if (str == NULL || strMid == NULL)
	{
		printf("Error: Cannot Allocate Memory\n");
	}
	// there is available memory for str
	else
	{
		printf("Allocated %d chars\n", sizeStr);
		printf("Please enter your string:\n");
		// dummy for \n
		scanf("%c", &dummy);
		fgets(str, sizeStr + 1, stdin);
		*(str + strlen(str) - 1) = '\0';
		printf("Please enter how many words to reverse:\n");
		scanf("%d", &n);
		// verify correct size of input
		ReverseNumWords(str, strMid, n, sizeStr);
	}
	free(str);
	free(strMid);
}

/**************************************************************************************
* function name: ReverseNumWords
* input: char *str, char *strMid, int n, int sizeStr
* output: print string after reverse
* operation function: reverse words in string until the "n" word position
* Note: called by Mission4 function
* *************************************************************************************/
void ReverseNumWords(char *str, char *strMid, int n, int sizeStr)
{
	int flag = 0;
	char *s, *temp;
	char *word = NULL;
	s = (char*)malloc(2 * sizeof(char));
	temp = (char*)malloc((sizeStr + 1) * sizeof(char));
	// no available memory
	if ( temp == NULL || s == NULL)
	{
		printf("Error: Cannot Allocate Memory\n");
		return;
	}
	// there is available memory for str
	else
	{
		*s = ' ';
		*(s + 1) = '\0';
		*strMid = '\0';
		// get first word from str
		word = strtok(str, s);
		// run through all words in str
		while (word != NULL)
		{
			strcpy(temp, word);
			// flag is number of word in str
			flag++;
			// until word in "n" position
			if (flag <= n)
			{
				// add space
				strcat(temp, s);
				strcat(temp, strMid);
				strcpy(strMid, temp);
			}
			// from word in "n" position to end of str
			else
			{
				// no space after the "n" word position
				if (flag != n + 1)
				{
					strcat(strMid, s);
				}
				strcat(strMid, temp);
			}
			word = strtok(NULL, s);
		}
		// n is bigger than flag
		if (n > flag)
		{
			printf("Error: Illegal input\n");
			free(s);
			free(temp);
			return;
		}
		// n is smaller than flag 
		else
		{
			printf("The string after reverse is: %s\n", strMid);
		}
		free(s);
		free(temp);
	}
}
