
/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex4.c
******************************************/

# include "translator.h"

/**************************************************************************************
* function name: Translator
* input: \
* output: prints sentence in Pig_latin language
* operation function:
1) gets sentence from the user
2) turn it to Pig_latin language
3) prints the new sentence
* Note: the sentence is printed in small letters only
* *************************************************************************************/
void Translator()
{
	int i, counter;
	char *word;
	char pig_latin[MAX_WORD];
	char until_vowel[MAX_WORD];
	char line[MAX_LINE];
	char dummy, choice;
	do
	{
		printf("Please enter a sentence in English:\n");
		scanf("%c", &dummy);
		fgets(line, MAX_LINE, stdin);
		const char s[2] = " ";
		//gets the first token
		word = strtok(line, s);
		// walking through the sentence
		while (word != NULL)				
		{
		// initializing until_vowel
			until_vowel[1] = '\0';	
		// copy the chosen word to other array
			strcpy(pig_latin, word);	
		// in case this is the final word in line
			if (pig_latin[strlen(pig_latin) - 1] == '\n') 
			{
				pig_latin[strlen(pig_latin) - 1] = '\0';
			}
		// changing the word to small letter
			Small_Letters(pig_latin);     				
			i = 0;
		// saving the first letter for all cases
			until_vowel[i] = pig_latin[i];	
		// first letter is a vowel
			if ((pig_latin[0] == 'a') ||
				(pig_latin[0] == 'e') ||
				(pig_latin[0] == 'i') ||
				(pig_latin[0] == 'o') ||
				(pig_latin[0] == 'u'))		
			{
				Vowel_First(until_vowel, pig_latin);
			}
			// first letter is not a vowel
			else					       
			{
			//run through pig_latin letters
				for (i = 1; i < ((int)strlen(pig_latin)); i++)
				{
					counter = 0;
				// the first letter is a vowel
					if ((pig_latin[i] != 'a') &&
						(pig_latin[i] != 'e') &&
						(pig_latin[i] != 'i') &&
						(pig_latin[i] != 'o') &&
						(pig_latin[i] != 'u') &&
						(pig_latin[i] != 'y'))    
					{
						until_vowel[i] = pig_latin[i];
					}
				// in case there is vowel in the word
					else				          
					{
						counter++;
						break;
					}
				}
				Word_Kinds(counter, i, until_vowel, pig_latin);
			}
			until_vowel[i] = '\0';
			word = strtok(NULL, s);
		// end of while (word != NULL)
		}		
		printf("\nDo you want to translate another sentence?(y/n)\n");
		scanf(" %c", &choice);
	} while ((choice == 'y') || (choice == 'Y'));
}

/**************************************************************************************
* function name: Small_Letters
* input: pig_latin[MAX_WORD]
* output: \
* operation function: turn big words to small words
* Note: just letters in english from A-Z
* *************************************************************************************/
void Small_Letters(char pig_latin[MAX_WORD])
{
	int i;

	for (i = 0; i < (int)strlen(pig_latin); i++)
	{
		if (pig_latin[i] >= 'A' && pig_latin[i] <= 'Z')
		{
		// changing to small letters
			pig_latin[i] += ('a' - 'A');		
		}
	}
}

/**************************************************************************************
* function name: Vowel_first
* input: char until_vowel[MAX_WORD], char pig_latin[MAX_WORD]
* output: prints pig_latin
* operation function:
1) save char in other array
2) prints pig_latin
* Note:
* *************************************************************************************/
void Vowel_First(char until_vowel[MAX_WORD], char pig_latin[MAX_WORD])
{
	strcat(pig_latin, "way");
	printf("%s ", pig_latin);
}

/**************************************************************************************
* function name: Word_Kinds
* input: int counter, int i, char until_vowel[MAX_WORD], char pig_latin[MAX_WORD]
* output: prints pig_latin
* operation function:
1) prints pig_latin
2) call to Vowel_middle
* Note: \
* *************************************************************************************/
void Word_Kinds(int counter, int i, char until_vowel[MAX_WORD], char pig_latin[MAX_WORD])
{
// no vowels in the word
	if ((counter == 0) && (pig_latin[0] == 'y'))	
	{
		strcat(pig_latin, "ay");
		printf("%s ", pig_latin);
	}
// vowl is in the middle of the word
	else											
	{
		Vowel_Middle(i, until_vowel, pig_latin);
	}
}

/**************************************************************************************
* function name: Vowel_middle
* input: int i, char until_vowel[MAX_WORD], char pig_latin[MAX_WORD]
* output: prints final_latin
* operation function:
1) puts letters in _final_latin
2) add letters from until_vowel to final_latin array
3) prints final_latin
* Note: strcat adding single letters to an array
* *************************************************************************************/
void Vowel_Middle(int i, char until_vowel[MAX_WORD], char pig_latin[MAX_WORD])
{
	int j, k;
	char final_latin[MAX_WORD];
//run through pig_latin letters
	for (j = i, k = 0; j < ((int)strlen(pig_latin)); j++, k++)
	{
		final_latin[k] = pig_latin[j];
	}
	final_latin[k] = '\0';
	until_vowel[i] = '\0';
	strcat(final_latin, until_vowel);
	printf("%say ", final_latin);
}
