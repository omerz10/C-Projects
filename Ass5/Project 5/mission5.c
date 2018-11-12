/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex5.c
******************************************/

#include "mission5.h"
/**************************************************************************************
* function name: Mission5
* input: /
* output: prints request sentence from user
* operation function:
- allocates memory and define several strings
- call Get_EachChar function, Print_FinalStr function
* Note: /
* *************************************************************************************/
void Mission5()
{
	int counter = 0, maxLength = 0, flag = 0, length = 1;
	char dummy;
	char *newName, *finalStr, *s, *temp;
	char *quit = "QUIT";
	// allocate memory for strings
	finalStr = (char*)malloc(length * sizeof(char));
	temp = (char*)malloc(length * sizeof(char));
	newName = (char*)malloc(length * sizeof(char));
	s = (char*)malloc(2 * sizeof(char));
	// create empty stings
	*finalStr = '\0';
	*newName = '\0';
	*temp = '\0';
	*s = ' ';
	// verify there is no trash in string
	*(s + 1) = '\0';
	printf("Please enter list of names:\n");
	scanf("%c", &dummy);

	length = Get_EachChar(&newName, length);
	while (strcmp(newName, quit) != 0)
	{
		counter++;
		// save the maximum length (use it in the realloc)
		if (length > maxLength)
		{
			maxLength = length;
		}

		// if it is the first word
		if (counter == 1)
		{
			strcat(newName, s);
			strcat(temp, newName);
		}
		// second name and beyond
		else
		{
			// gets word from finalStr
			flag = Sort_word(&temp, &finalStr, &newName, counter, maxLength);

		}
		// newName bigger than all words in finalStr
		if (flag == 0 && counter != 1)
		{
			strcat(newName, s);
			strcat(temp, newName);
		}
		finalStr = (char*)realloc(finalStr, (strlen(temp))*counter *
			sizeof(char));
		strcpy(finalStr, temp);
		// initilize the parameters before next name 
		*newName = '\0';
		flag = 0;
		length = 1;
		// scaning the next new word
		length = Get_EachChar(&newName, length);
	}
	Print_FinalStr(finalStr, s, counter, maxLength);
	free(temp);
	free(finalStr);
	free(newName);
	free(s);

}

/**************************************************************************************
* function name: Sort_word
* input: char **temp, char ** finalStr, char** newName, int counter, int maxLength
* output: return flag
* operation function: sort word's position according alphabetic order
* Note: called by Mission5 function
* *************************************************************************************/
int Sort_word(char **temp, char ** finalStr, char** newName, int counter,
	int maxLength) {
	int flag = 0;
	char *word = (char*)malloc(2 * sizeof(char));
	word = (char*)realloc(word, maxLength * sizeof(char));
	*word = '\0';
	*temp = (char*)realloc(*temp, (maxLength + 1)*counter *
		sizeof(char));
	char* s = (char*)malloc(2 * sizeof(char));
	*s = ' ';
	*(s + 1) = '\0';
	word = strtok(*finalStr, s);
	**temp = '\0';
	// add word to correct place in finalStr
	while (word != NULL)
	{
		// newName lower than word
		if ((strcmp((*newName), (word)) < 0) && (flag == 0))
		{
			strcat(*newName, s);
			strcat(*temp, *newName);
			strcat(*temp, word);
			strcat(*temp, s);
			flag = 1;
		}
		// the name is already exist
		else if ((strcmp((*newName), (word)) == 0) && (flag == 0))
		{
			strcat(*temp, word);
			strcat(*temp, s);
			flag = 1;
		}
		// newName of the newName bigger than word
		else
		{
			strcat(*temp, word);
			strcat(*temp, s);
		}
		word = strtok(NULL, s);
	}
	free(word);
	free(s);
	return(flag);
}

/**************************************************************************************
* function name: Get_EachChar
* input: char *newName, char *singleCh, int length
* output: /
* operation function: gets each char from input and assign in newName
* Note: called by Mission5 function
* *************************************************************************************/
int Get_EachChar(char **newName, int length)
{
	char *singleCh = (char*)malloc(2 * sizeof(char));
	*singleCh = getchar();
	*(singleCh + 1) = '\0';
	while (strcmp(singleCh, "\n") != 0)
	{
		*newName = (char*)realloc(*newName, (++length) * sizeof(char));
		// define newName
		strcat(*newName, singleCh);
		*singleCh = getchar();
	}
	free(singleCh);
	return (length);
}

/**************************************************************************************
* function name: Print_FinalStr
* input: char *finalStr, char *s, char *word, int counter
* output: prints the number of names in strMid and prints each name
* operation function: run through finalStr and prints all names
* Note: called by Mission5 function
* *************************************************************************************/
void Print_FinalStr(char *finalStr, char *s, int counter, int maxLength)
{
	char *word = (char*)malloc(2 * sizeof(char));
	word = (char*)realloc(word, maxLength * sizeof(char));
	printf("There are %d names:\n", counter);
	// get the first word
	word = strtok(finalStr, s);

	// run through other words
	while (word != NULL)
	{
		printf("%s\n", word);
		word = strtok(NULL, s);
	}
	free(word);
}

