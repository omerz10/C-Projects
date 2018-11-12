/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex4.c
******************************************/

/**************************************************************************************************** 
This program has Main menu that suggests the user to operate 2 of the following options:
1) The calculator- operates different actions on matrices, including sum, multiply, and transpose.
2) The Pig Latin Translator- gets sentences in english and translates the words to pig latin language 
****************************************************************************************************/


#include "translator.h"
#include "calculator.h"

int main()
{
	int result=0;
	char operation = 'c';

	while (result != 3)
	{
		printf("Main menu, choose between the options:\n");
		printf("Matrix Calculator\n");
		printf("PigLatin Translator\n");
		// the function changing big leeters to small letters
		result = Change_Letters();  
		// choice is "calculator"
		if (result == 1)		
		{
			Calculator();
		}
		// choice is "Translator"
		else if (result == 2)	
		{
			Translator();
		}
		// wrong word
		else if (result == 4) 
		{
			printf("This wasn't an option.\n");
		}
	}
}
