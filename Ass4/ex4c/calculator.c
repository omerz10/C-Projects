/******************************************
Student Name: Omer Zucker
Student ID: 200876548
Group Exercise Course: ого"з 01
name Exercise: ex4.c
******************************************/

# include "calculator.h"

/**************************************************************************************
* function name: Change_Letters
* input: choice
* output: my_word
* operation function: Changing big words to small words
* Note: \
* *************************************************************************************/
int Change_Letters()
{
	int i;
	char my_word[20];
	scanf("%s", &my_word);	
	// string input
	for (i = 0; my_word[i] != '\0'; i++)
	{
		if (my_word[i] >= 'A' && my_word[i] <= 'Z')
		{
			my_word[i] += ('a' - 'A');
		}
	}
	if (strcmp(my_word, "calculator") == 0)
	{
		return(1);
	}
	else if (strcmp(my_word, "translator") == 0)
	{
		return(2);
	}
	else if (strcmp(my_word, "quit") == 0)
	{
		return(3);
	}
	// wrong word
	else	
	{
		return(4);
	}
}

/**************************************************************************************
* function name: Calculator
* input: \
* output: prints results of sum/substract/multiply/transpose between matrices
* operation function: operates different functions of +,-,*,t according to
the requested operation that is entering by the user.
* Note: the function includes sub-functions
* *************************************************************************************/
void Calculator()
{
	int basic_matrix[MAX_M][MAX_M];
	int row, col, i, j, temp;
	char operation = 'c';

	printf("Welcome to the Matrix calculator\n");
	while (operation == 'c')
	{
		// scaning the row and the col until the input is different then <= 0
		do
		{
			printf("Please enter first matrix dimensions (row col):\n");
			scanf("%d %d", &row, &col);
		// basic matrix dimensions
			if (row <= 0 || col <= 0)
			{
				printf("Error\n");
			}
		// matrix dimensions must have to be more then zero
		} while (row <= 0 || col <= 0); 

		printf("Please enter matrix elements(%dX%d):\n", row, col);
		// sets the elements to the basic matrix
		for (i = 0; i < row; i++)	
		{
			for (j = 0; j < col; j++)
			{
				scanf("%d", &basic_matrix[i][j]);
			}
		}
		// run first time and then checking for clear or quit operations
		do 
		{
			printf("Please enter operation: (+, -, *, t, c, q):\n");
			scanf(" %c", &operation);
			switch (operation)
			{
			case('+'):
			{
			// call the function Matrix_add
				Matrix_add(row, col, basic_matrix);	
				break;
			}
			case('-'):
			{
			// call the function Matrix_Sub
				Matrix_Sub(row, col, basic_matrix);	
				break;
			}
			case('*'):
			{
			// call the function Matrix_Multiply
				col = Matrix_Multiply(row, col, basic_matrix);	
				break;
			}
			case('t'):
			{
			// call the function Matrix_Transpose
				Matrix_Transpose(row, col, basic_matrix);	
				temp = row;
				row = col;
				col = temp;
				break;
			}
			case('c'):
			{
			//clear the matrices and start from demensions line input
				break;		
			}
			case('q'):
			{
			// quit from calculator and go to Main menu
				break;		
			}
			default:
			{
				printf("This opration doesn't exist\n");
				break;
			}
			// end of switch
			}		
		} while ((operation != 'q') && (operation != 'c'));
	}
}

/**************************************************************************************
* function name: Matrix_add
* input: row, col, basic_matrix
* output: final_matrix
* operation function: sum 2 matrices and call to Matrix_answer
* Note: the finction doesn't print Final_matrix
* *************************************************************************************/
void Matrix_add(int row, int col, int basic_matrix[MAX_M][MAX_M])
{
	int second_matrix[MAX_M][MAX_M];
	int i, j;

	printf("Please enter matrix elements(%dX%d):\n", row, col);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			// sets the elements to the basic matrix
			scanf("%d", &second_matrix[i][j]);		
			//calculate and put the elements in final_matrix
			basic_matrix[i][j] += second_matrix[i][j];		
		}
	}
	Matrix_Answer(row, col, basic_matrix);

}

/**************************************************************************************
* function name: Matrix_add
* input: row, col, basic_matrix
* output: final_matrix
* operation function: substract 2 matrices and call to Matrix_answer
* Note: the finction doesn't print Final_matrix
* *************************************************************************************/
void Matrix_Sub(int row, int col, int basic_matrix[MAX_M][MAX_M])
{
	int second_matrix[MAX_M][MAX_M];
	int i, j;

	printf("Please enter matrix elements(%dX%d)\n", row, col);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			// sets the elements to the basic matrix
			scanf("%d", &second_matrix[i][j]);
			//calculate and put the elements in final_matrix
			basic_matrix[i][j] -= second_matrix[i][j];		
		}
	}
	Matrix_Answer(row, col, basic_matrix);
}

/**************************************************************************************
* function name: Matrix_Multiply
* input: row, col, basic_matrix
* output: final_matrix
* operation function: gets elements to second_ matrix, multiply 2 matrices and call to Matrix_answer
* Note: the finction doesn't print Final_matrix
* *************************************************************************************/
int Matrix_Multiply(int row, int col, int basic_matrix[MAX_M][MAX_M])
{
	int second_matrix[MAX_M][MAX_M];
	int final_matrix[MAX_M][MAX_M];
	int i, j, m, n, k, col2;

	printf("Please enter column dimension of second matrix:\n");
	scanf("%d", &col2);
	printf("Please enter matrix elements(%dX%d)\n", col, col2);
	// gets elements to second_matrix
	for (i = 0; i < col; i++)	
	{
		for (j = 0; j < col2; j++)
		{
			scanf("%d", &second_matrix[i][j]);
		}
	}
	// calculates multipication between basic_matrix and second_matrix
	for (m = 0; m < row; m++)	
	{
		for (n = 0; n < col2; n++)
		{
			// initializing final_matrix elements
			final_matrix[m][n] = 0; 
			for (k = 0; k < col; k++)
			{
				final_matrix[m][n] += ((basic_matrix[m][k]) * (second_matrix[k][n]));
			}
		}
	}
	// copy the elements to basic_matrix
	for (i = 0; i < row; i++)	
	{
		for (j = 0; j < col2; j++)
		{
			basic_matrix[i][j] = final_matrix[i][j];
		}
	}

	Matrix_Answer(row, col2, basic_matrix);
	return col2;
}

/**************************************************************************************
* function name: Matrix_transpose
* input: row, col, basic_matrix
* output: final_matrix
* operation function: transpose to th basic_matrix and prints the final matrix
* Note: /
* *************************************************************************************/
void Matrix_Transpose(int row, int col, int basic_matrix[MAX_M][MAX_M])
{
	int i, j;
	int final_matrix[MAX_M][MAX_M];
	//switch between row and column
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			final_matrix[j][i] = basic_matrix[i][j];
		}
	}
	//switch between row and column
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			basic_matrix[i][j] = final_matrix[i][j];
		}
	}
	Matrix_Answer(col, row, basic_matrix);
}

/**************************************************************************************
* function name: Matrix_answer
* input: row, col, final_matrix
* output: prints the final_matrix
* operation function: gets the final matrix and prints it
* Note: \
* *************************************************************************************/
void Matrix_Answer(int row, int col, int final_matrix[MAX_M][MAX_M])
{
	int i, j;
	printf("The answer is:\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%4d", final_matrix[i][j]);
		}
		printf("\n");
	}
}



