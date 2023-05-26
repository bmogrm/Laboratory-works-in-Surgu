#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	system("chcp 1251 > nul");
	int a, b, c;
	printf("Введите значения для 'a, b, c': ");
	scanf("%d%d%d", &a, &b, &c);
	if ((a < 0) || (b < 0) || (c < 0)) {
		printf("Введено неверное значение!\n");
		return 1;
	}
	if (((b > a) && (b < c)) || ((b < a) && (b > c))) {
		printf("Значение %d, находится между a & c\n", b);
	}
	else
		printf("Значение %d, не находится между a & c\n", b);
	
	system("pause");
	return 0;
}
