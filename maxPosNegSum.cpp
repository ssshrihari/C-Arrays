
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	int i, key, j;
	if (length <= 0)
		return 0;
	for (i = 1; i < length; i++)
	{
		key = input[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && input[j] > key)
		{
			input[j + 1] = input[j];
			j = j - 1;
		}
		input[j + 1] = key;
	}
	if (input[0] >= 0)
		return 0;
	if (input[length - 1] < 0)
		return 0;
	int x, y;
	x = input[length - 1];
	for (i = 0; i<length; i++)
	{
		if (input[i]<0 && input[i + 1] >= 0)
			y = input[i];
	}
	return x + y;
}