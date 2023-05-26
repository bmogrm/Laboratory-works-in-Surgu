#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	system("chcp 1251 > nul");
	
	double x, y, z;
	
	printf("Введите значение x и значение y: ");
	scanf("%lg%lg", &x, &y);
	z = (sin(x) * sin(x) + cos(y) * cos(y)) / exp(x+1);
	printf("Ответ: %lg\n", z);
	system("pause");
	return 0;
}
