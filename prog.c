#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	array_of_smpl_ints(int *array)	//find all prime numbers by using Sieve of Eratosthenes
{
	for (long i = 2; i < 100000; i++)
	{
		for (long p = i * i; p < 100000; p +=i)
		{
			if (p > 100000)
				break;
			array[p] = 1;							//all prime numbers must be == 0, others == 1
		}
	}
}

int		is_palindrom(char *buffer)
{
	int len = strlen(buffer);						//find size of string
	int	end = len - 1;								//find last letter of string

	if (len < 3)									//if string to short, it's not a palindrom
		return (0);
	for (len = 0; len <= end; len++)
	{
		if (buffer[len] != buffer[end--])			//if letter from start == letter from end, go next letters
			return (0);								//else it's not a palindrom
	}
	return (1);										//if program came here, we have a palindrom
}

int		main(void)
{
	int		*array;
	int		nmbr;
	int		flag = 0;
	int		count = 0;
	char	buffer[50];

	while(1)
	{
		printf("if you want find palindrome, input the search start number (from 2 to 99999) and press enter\n");
		scanf("%d", &nmbr);
		if (nmbr > 1 && nmbr < 100000)
			break;
	}
	if (!(array = (int *)malloc(sizeof(int) * 100000)))	//take memory for big array of int
		return (-1);									//if no memory - exit
	bzero(array, sizeof(int) * 100000);					//make all elements of array = 0
	array_of_smpl_ints(array);							//mark all non prime numbers in array = 1
	for (int i = nmbr; i < 100000; i++)					//find first prime number
	{
		if (array[i] == 0)								//if array[i] == 0, i is an prime number
		{	
			for (int p = nmbr; p < 100000; p++)			//find second prime number
			{
				if (array[p] == 0)						//if array[p] == 0, p is prime nmbr
				{
					bzero(buffer, sizeof(char) * 50);			//clear buffer
					sprintf(buffer, "%ld", ((long int)p * i));	//multiply i and p, conwert result to letters and write in to buffer
					if (is_palindrom(buffer) == 1)								//if result is palindrom
					{
						printf("%d:	%s	(%d * %d)\n", ++count, buffer, i, p);	//print it
						flag = 1;
					}
				}
			}
		}
	}
	if (flag == 0)
		printf("for %d we don't find any palindrome\ntry input 42\n", nmbr);
	free(array);										//free memory and exit 
	return (0);
}