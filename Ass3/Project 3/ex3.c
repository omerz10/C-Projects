	/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex3.c
******************************************/


/***** This program takes a number between 0-5 from the user and operates different tasks for each number.
	   the number 0 will end the program *****/

#include <stdio.h>
#include <math.h>

void Multiply_1();
void Dividers_1();
void Check_Key(int div1, int div2, int n, char key);
void Or_dividers(int div1, int div2, int n);
void And_Dividers(int div1, int div2, int n);
void Fibonachi_input();
void Fibonachi_positive(int n);
void Fibonachi_Not1(int n);
void Smallest_Numbers();
int Positive_numbers();
void Find_Two_Mins(int num1, int num2);
void Sum_Of_Digits();
int Substract_Digit(unsigned long number, int sum);

int main()
{

	int mission;


	do		// start of the loop "while"- the number has to be between 1-5
	{
		printf("Please select the assignment:\n");
		scanf("%d", &mission);

		switch (mission)
		{

		case(1):
		{
			Multiply_1();
		}
			break;		// end of case(1)

		case(2):
		{
			Dividers_1();
		}
			break;		// end of case(2)

		case(3):
		{
			Fibonachi_input();
		}
			break;		// end of case(3)

		case(4):
		{
			Smallest_Numbers();
		}
			break;		// end of case(4)

		case(5):
		{
			Sum_Of_Digits();
		}
		break;		// end of case(5)

		case(0):
			break;		// end of case(0)

		default:
			printf("NO SUCH ASSIGNMENT!\n");
		}
	} while (mission!=0);	// end of while loop

	return(0);
}

/**************************************************************************************
* function name: Multiply_1
* input: 2 numbers
* output: results of multiplication
* operation function: the function creates matrix pattern for multiplication of 2 numbers
* Note: the order of entering the numbers is unimportant
* *************************************************************************************/
void Multiply_1()
{
	int i, j, row;
	int num1, num2, temp;

	printf("Please enter two numbers for the multiplication table:\n");
	scanf("%d %d", &num1, &num2);

	if (num1 > num2)
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	for (i = num1; i <= num2; i++)	// moving line
	{

		for (j = num1; j <= num2; j++)		//printing row results
		{
			row = i * j;
			printf("%-4d", row);
		}
		printf("\n");		// next line. end of second "for" loop
		
	}		// end of first "for" loop

}

/**************************************************************************************
* function name: Dividers_1
* input: gets numbers and the char "key" for choosing operation
* output: prints instructions to the user
* operation function: operating the function Check_Key(div1, div2, n, key);
* Note: function gets numbers and letters 
* *************************************************************************************/
void Dividers_1()
{
	int div1, div2, n;
	char key;
	
	printf("Please enter n:\n");
	scanf("%d",&n);
	printf("Please enter two dividers:\n");
	scanf("%d %d",&div1,&div2);
	printf("Please enter the key:\n");
	scanf(" %c",&key);

	Check_Key(div1, div2, n, key);		
		
}

/**************************************************************************************
* function name: Chek_key
* input: gets small or big letter from the user
* output: operating other functions or prints error
* operation function: the function Or_Dividers and And_dividers
* Note: wrong key prints error
* *************************************************************************************/
void Check_Key(int div1, int div2, int n, char key)
{
	
	if ((key == 'o') || (key == 'O'))		//prints the diveders of div1 or! div2 
	{
		Or_dividers(div1, div2, n);
	}
	else if ((key == 'A') || (key == 'a'))	//prints the diveders of div1 and! div2 
	{
		And_Dividers(div1, div2, n);
	}
	else
		printf("ERROR IN KEY\n");
}

/**************************************************************************************
* function name: Or_dividers
* input: the initial numbers' from function Dividers_1
* output: dividers of "n" in "or" condition
* operation function: prints the numbers
* Note: the function check for reminders of division
* *************************************************************************************/
void Or_dividers(int div1, int div2, int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		if ((i % div1 == 0) || (i % div2 == 0))
			printf("%d ", i);
	}
	printf("\n");
}

/**************************************************************************************
* function name: And_dividers
* input: the initial numbers' from function Dividers_1
* output: dividers of "n" in "And" condition
* operation function: prints the numbers
* Note: the function check for riminders of division
* *************************************************************************************/
void And_Dividers(int div1, int div2, int n)
{

	int i;
	for (i = 1; i <= n; i++)
	{
		if ((i % div1 == 0) && (i % div2 == 0))
			printf("%d ", i);
	}
	printf("\n");
}

/**************************************************************************************
* function name: Fibonachi_input
* input: gets number from the user
* output: print instructions for the user
* operation function: operating the function Fibonachi_positive(n)
* Note: do not get numbers beneath 1 - error
* *************************************************************************************/
void Fibonachi_input()
{
	int n;
	printf("Please enter n:\n");
	scanf("%d", &n);

	if (n < 1)
		printf("INPUT ERROR\n");
	else
		Fibonachi_positive(n);
}

/**************************************************************************************
* function name: Fibonachi_positive
* input: "n" from the function Fibonaci_input()
* output: prints var 1
* operation function: checks if "n" bigger then 1
* Note: operating the function Fibonaci_not1
* *************************************************************************************/
void Fibonachi_positive(int n)
{
	int var1;

	if (n > 1)
	{
		Fibonachi_Not1(n);
	}
	else
	{
		var1 = 1;
		printf("%d", var1);
	}
	printf("\n");
}

/**************************************************************************************
* function name: Fibonachi_Not1
* input: i, var1, var2, var3
* output: prints var 1, var2, var3
* operation function: sum the 2 variables and print var3
* Note: i < n-1 (not n)
* *************************************************************************************/
void Fibonachi_Not1(int n)
{
	int i, var1, var2, var3;
	var1 = 1;
	var2 = 1;
	printf("%d %d ", var1, var2);
	for (i = 1; i < n - 1; i++)
	{
		var3 = var2 + var1;
		printf("%d ", var3);
		var1 = var2;
		var2 = var3;
	}
}

/**************************************************************************************
* function name: Smallest_numbers
* input: serial of integers
* output: no output
* operation function: compare between inserted number to 2 minimum numbers
* Note: num1 is the first minimum
* *************************************************************************************/
void Smallest_Numbers()
{
	int num1, num2, temp;
	printf("Please enter your sequence:\n");
	num1 = Positive_numbers();
	do
	{
		num2 = Positive_numbers();
	} while (num1 == num2);		// the numbers must have to be different
	if (num2 == -1)  // in case of x,x, -1 (two first same numbers)
	{
		num2 = num1;
		printf("%d %d\n", num1, num2);
		return;
	}
	if (num1 > num2)		// num1 hold the minimum number and num2 the second minimum
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	Find_Two_Mins( num1, num2);
}

/**************************************************************************************
* function name: Find_Two_Mins
* input: new, num1, num2
* output: 2 minimum positive numbers
* operation function: check for minimum valua of the 3 inputs
* Note: -1 end the function
* *************************************************************************************/
void Find_Two_Mins(int num1, int num2)
{
	int new;
	scanf("%d", &new);
	while (new != -1)		// -1 end the function
	{
		if (new > 0)	// comparing positive numbers
		{
			if (new < num1)
			{
				num2 = num1;
				num1 = new;
			}
			else if ((new < num2) && (new != num1))
			{
				num2 = new;
			}
		}
		scanf("%d", &new);
	}
	printf("%d %d\n", num1, num2);
}

/**************************************************************************************
* function name: Positive_numbers
* input: no input
* output: return positive numbers
* operation function:checks if the nubers are positive
* Note: /
* *************************************************************************************/
int Positive_numbers()
{
	int temp;
	do
	{
		scanf("%d", &temp);
	} while (temp <= 0 && temp != -1);
	return(temp);
}

/**************************************************************************************
* function name: Sum_Of_Digits
* input: no input
* output: print the sum of a number's digits
* operation function:sum digits of a number
* Note: /
* *************************************************************************************/
void Sum_Of_Digits()
{
	unsigned long number;
	int sum = 0;
	printf("Please enter your number:\n");
	scanf("%d",&number);
	do 
	{
		sum = Substract_Digit(number, sum);
		number /= 10;
	} while (number > 9);	
	sum += (number % 10);
	printf("%d\n", sum);
}

/**************************************************************************************
* function name: Substract_Digit
* input: the partial number and the current sum
* output: the new sum (with the next digit)
* operation function:add the next digit to sum
* Note: /
* *************************************************************************************/
int Substract_Digit(unsigned long number, int sum)
{
	int digit;
	digit = (int)(number % 10);
	sum += digit;
	return sum;
}