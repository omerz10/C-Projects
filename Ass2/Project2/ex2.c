/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex2.c
******************************************/


/***** This program has 4 different operations (cases) when the user inserts numbers from 1 to 4.
while pressing 0 the program will turn off. *****/

#include <stdio.h>
#include <math.h>

int main()

{
	int task, grade;
	int num1, num2, num3;
	int sum;
	float test1, exercise1, test2, exercise2, final1, final2;
	float average;
	char char1, char2, char3;
	char student1, student2;

	printf("Please enter your input:\n");
	scanf("%d", &task);
		
	if (task >= 1 && task <= 4)		// the user choose a number between 1-4, 0 for exit
	{
		switch (task)
		{
		case 1:		// 1- catalogues the user's grade from A-E
			{	
			printf("Please enter your score:\n");	// bigger number then 100 or negative number will print error
			scanf("%d", &grade);

			if (grade >= 0 && grade <= 100)		//the user enter grade between 1-100
				{
				if (grade >= 90)
					printf("The rank for %d is: A\n", grade);
				else if (grade >= 80)
					printf("The rank for %d is: B\n", grade);
				else if (grade >= 70)
					printf("The rank for %d is: C\n", grade);
				else if (grade >= 60)
					printf("The rank for %d is: D\n", grade);
				else
					printf("The rank for %d is: E\n", grade);
				}
			else
				printf("Error\n");		//the user pressed a grade above 100 or negative number
			}	
			break;		// exit case 1
		
		case 2:		// 2- Gets 3 numbers from the user and prints Max,Min and Averege
			{
			printf("Please enter three numbers:\n");
			scanf("%d %d %d", &num1, &num2, &num3);
						
			// we will chek for the Minimal value
			if (num1 < num2)
				{
				if (num1 < num3)
					printf("The minimal value is: %d\n", num1 );
				else	//num3 < num1
					printf("The minimal value is: %d\n", num3);
				}
			else	// num2 < num1
				{
				if (num2 < num3)
					printf("The minimal value is: %d\n", num2);
				else	// num3 < num2
					printf("The minimal value is: %d\n", num3);
				}
	
			// now we will chek for the Maximal value
			if (num1 > num2)
				{
				if (num1 > num3)
					printf("The maximal value is: %d\n", num1);
				else	//num3 > num1
					printf("The maximal value is: %d\n", num3);
				}
			else	// num2 > num1
				{
				if (num2 > num3)
					printf("The maximal value is: %d\n", num2);
				else	// num3 > num2
					printf("The maximal value is: %d\n", num3);
				}
			
			// now we will calculate the average of the 3 numbers
			sum = num1 + num2 + num3;
			average = (float)((float)sum / 3);
			printf("The average is: %8.2f\n", average);
			}
			break;		// exit case 2

		case 3:		// 3- Gets 3 chars from the user and print the chars in different ways
			{
			
			// &dummy receives space
			printf("Please enter three chars:\n");
			scanf(" %c %c %c", &char1, &char2, &char3);
			printf("%c\n", char1);   //prints char1
			printf("%c\n%c\n%c\n", char1, char2, char3);   // according to the input order
			printf("%c@%c@%c\n", char1, char2, char3); 	  // with the sign @ between the chars
			printf("%c\n", char3);   // prints char3
			printf("%c#%c#%c\n", char3, char2, char1);
			}
			break;		// exit case 3

		case 4:		// 4-prints the grades in tast and exercise, first name's letter and final grade
			{
			printf("Please enter two course details:\n");
			scanf("%f %f %c", &test1, &exercise1, &student1);
			scanf("%f %f %c", &test2, &exercise2, &student2);

			// note: the grades must be between 0-100
			if (test1 >= 0 && test1 <= 100 && exercise1 >= 0 && exercise1 <= 100 &&
				test2 >= 0 && test2 <= 100 && exercise2 >= 0 && exercise2 <= 100)
				{
				final1 = (float)(8 * sqrt(test1) + (exercise1 * 0.1));
				final2 = (float)(8 * sqrt(test2) + (exercise2 * 0.1));
				printf("The final grade of %c is: %8.2f\n", student1, final1);
				printf("The final grade of %c is: %8.2f\n", student2, final2);
				}
			else
				printf("Error\n");				
			}
			break;		//exit case 4
		case 0:
			return 0;
		}
	}	// end off the first if- (choosing the number of the case)

}	// end of the program


