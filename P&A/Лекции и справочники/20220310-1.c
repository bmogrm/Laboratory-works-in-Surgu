#include <stdio.h>

typedef struct Person_tag
{
	char name[50];
	int age;
	double height;
} Person;

void input(Person * p)
{
	printf("Input person info (name, age, height): ");
	scanf("%s%d%lf", p->name, &p->age, &p->height);
}

void output(const Person * p)
{
	printf("Name:   %s\nAge:    %d\nHeight: %.3lf\n",
	    p->name, p->age, p->height);
}

int main()
{
	Person x;
	
	output(&x);
	input(&x);
	output(&x);
	
	return 0;
}
