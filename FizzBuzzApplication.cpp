// FizzBuzzApplication.cpp : Defines the entry point for the console application.
// Jason Meyer 10/31/16 Gholam Ali Shaykhian
// This program takes a list of numbers seperated by commas and checks if they are divisible by either 3, 5, both, or neither and gives a response to the user accordingly 

#include "stdafx.h"
#include "iostream"
#include "sstream"

int fizzBuzz(int row, int column) //prototype int FizzBuzz(int, int) the function takes the row number input as the first parameter and the column input as second parameter
{
	const int fizz = 3; //constant value to test if input is divisible by 3
	const int buzz = 5; //constant value to test if input is divisible by 5
	if (column % fizz == 0 && column % buzz == 0) //checking if number is divisible by both 3 and 5
	{
		std::cout << "Number: " << column << "-FizzBuzz\n" << "Congratulations you have guessed FizzBuzz on attempt " << row << "!\n"; //output message
		return 1;
	}
	else if (column % fizz == 0) //checking if number is divisible by 3
	{
		std::cout << "Number: " << column << "-Fizz\n" << "Please try again you haven't got FizzBuzz!\n"; //output message
		return 0;
	}
	else if (column % buzz == 0) //checking if number is divisible by 5
	{
		std::cout << "Number: " << column << "-Buzz\n" << "Please try again you haven't got FizzBuzz!\n"; //output message
		return 0;
	}
	else
	{
		std::cout << "Number: " << column << "\n"
			<< "Please enter another integer or list of integers you haven't got FizzBuzz!\n"; //if number isn't divisible by 3 or 5 output message
		return 0;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int numbersCounter = 0; //variable to count ammount of numbers inputed to the program
	int previousAttemptCounter = 0; //variable to count the users attempts at inputing numbers
	int row; //fizzbuzz argument variable
	int reset; //variable to hold fizbuzz return value used to reset the program once fizzbuzz is guessed
	char response = 'N'; //set initial value for while loop conditional statement
	while (response == 'N') //Does the user want to continue to run this program
	{
		int numbers[10];
		char numberList[100]; //allocate a variable to hold users input
		char* point; //instantiate a pointer
		std::cout << "If you would like to play FizzBuzz please enter a integer or a list of integers no more then 10 of them seperated by a comma to play FizzBuzz and press enter." << std::endl; //output message to promt for input for numberList
		std::cin >> numberList; //input data
		point = strtok(numberList, ","); //setting pointer to strtok with a delimiter being (,)
		while (point != NULL) //make sure point isn't null and perform a sequence of calls to this strtok to split str into tokens
		{
			std::stringstream str;
			str << point;
			int number;
			str >> number; //casting type char to type int using stringstream
			numbers[numbersCounter] = number; //setting a value for numbers array with number value
			point = strtok(NULL, ","); //continue loop
			++numbersCounter; //incrementing numbersCounter
		}
		row = numbersCounter + previousAttemptCounter; //setting row value
		for (int i = 0; i < numbersCounter; i++) //iterating through numbers array
		{
			reset = fizzBuzz(row, numbers[i]); //passing row argument and value from numbers array to fizzBuzz function then setting reset value from fizzBuzz return value
		}
		for (int i = 0; i < numbersCounter; i++) //iterating through numbers array
		{
			numbers[i] = NULL; // setting index values to null to prepair the array for the net set of input
		}
		std::cout << "Are you finished playing FizzBuzz type Y for yes or N for no.\n"; //output message to promt the user whether they would like to continue to use the program or end it
		std::cin >> response; //response input
		if (reset == 1) //checking if fizzBuzz returns a 1 value indicating that a fizzBuzz integer was entered
		{
			previousAttemptCounter = 0; //setting value to 0 so user can continue to play if they would like to
		}
		else
		{
			previousAttemptCounter = previousAttemptCounter + numbersCounter; //If fizzBuzz returns a value other then 1 increase the value of previousAteemptCounter to include the ammount of numbers entered this iteration
		}
		numbersCounter = 0; //set numbersCounter value to 0
	}
	return 0;
}

