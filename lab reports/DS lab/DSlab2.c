// WAP to print truth table of conjunction and disjunction using T and F
#include <stdio.h>

void printConjunction(void)
{
	char values[] = {'F', 'T'};

	printf("Conjunction (A and B)\n");
	printf("A B | A and B\n");
	printf("--------------\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			char a = values[i];
			char b = values[j];
			char result = (a == 'T' && b == 'T') ? 'T' : 'F';
			printf("%c %c |    %c\n", a, b, result);
		}
	}
}

void printDisjunction(void)
{
	char values[] = {'F', 'T'};

	printf("\nDisjunction (A or B)\n");
	printf("A B | A or B\n");
	printf("-------------\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			char a = values[i];
			char b = values[j];
			char result = (a == 'T' || b == 'T') ? 'T' : 'F';
			printf("%c %c |   %c\n", a, b, result);
		}
	}
}

int main(void)
{
	printConjunction();
	printDisjunction();
	return 0;
}
