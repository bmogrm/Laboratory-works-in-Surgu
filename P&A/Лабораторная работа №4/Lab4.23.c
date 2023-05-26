#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Лабораторная №4
   Вариант 23:
   Задан размер массива действительных чисел
   и значение его элементов. Заменить недостоверные значения
   результатом линейной интерполяции.
   Недостоверными считать значения, не входящие в интервал [0.5m;1.5m],
   где m - среднееарифметическое значение всех элементов массива. */

int main () {
	system ("chcp 1251 > null");
	int size, i, I, count;
	double num, array[20]={0}, m, c, g;
	while (printf("Введите размер массива: "), fflush(stdin), scanf("%d", &size), size > 20  || size < 0)
		printf("Wrong input!\a\nЗначение массива может быть от 1 до 20\n");	
	printf("Введите значения элементов массива:\n");
	
	for (i = 0; i < size; i++){
		printf("Array[%d] = ", i+1);
		scanf("%lf", &num);
		array[i] = num;
		m = m + num;
	}
	m = m / size; // m - Среднее арифметическое всех элементов массива.
	if (array[0] > (1.5 * m) || array[0] < (0.5 * m)){
		array[0] = m;
		}
	if (array[size - 1] > (1.5 * m) || array[size - 1] < (0.5 * m)){
		array[size - 1] = m;
		}	
	for (i = 1; i < size; i++) {
		I = i;
		if (array[i] > (1.5 * m) || array[i] < (0.5 * m)) {
			while (array[I] > (1.5 * m) || array[I] < (0.5 * m)) {
				I++;
			}
			c = array[I] - array[i - 1]; //Разность между элементом недостоверным и первым достоверным
			g = I - i;			     	 //Кол-во недостоверных чисел
			c = c / (g + 1);       		 //Число шага
			while (i != I) {
					array[I - 1] = array[I] - c;
					I--;
		}
	}
}
	printf("\n\nРезультаты линейной интерполяции:\n");
	for (count = 0; count < size; count++){
		printf("Array[%d] = %.3lg\n", count+1, array[count]);
		}	
	system("pause");
	return 0;
}
