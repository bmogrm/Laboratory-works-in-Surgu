#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Лабораторная № 3:
   Вариант № 8.
   Задано кол-во цифр в номере билета.
   Определить кол-во "счастливых" билетов. */
   
int main () {
	system("chcp 1251 > nul");      /* "Руссификация" интерфейса */
   int n, c, num, first, f1, f2 = 0, sec, s1, s2 = 0,  f;
	
	while (printf("Введите кол-во цифр в номере билета: "),
	fflush(stdin),												/* Проверка ввода */
	scanf("%d", &n) != 1 || n % 2 != 0 || n >= 10 || n < 0)
	printf("Кол-во цифр не может быть нечетным и больше 8-ми!\a\n\n\nПопробуй снова\n");
	
	num = pow(10,n) - 1;
	f = pow(10, n/2);
	for (c = 0; num > 0; num--, f2 = 0, s2 = 0) {
		first = num / f; /* Делим кол-во разрядов на две части */
		sec = num % f;   /* Делим кол-во разрядов на две части */
		while (first > 0){
			f1 = first % 10;
			f2 = f2 + f1;
			first = first / 10;
		}
		while (sec > 0){
			s1 = sec % 10;
			s2 = s2 + s1;
			sec = sec / 10;
		}
		if (f2 == s2) 
		c++;
	}
	printf("Общее кол-во билетов ----> %d билетов\n\n", c);
	system("pause");
	return 0;	
}
