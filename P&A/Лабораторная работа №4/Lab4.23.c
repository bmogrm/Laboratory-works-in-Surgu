#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ������������ �4
   ������� 23:
   ����� ������ ������� �������������� �����
   � �������� ��� ���������. �������� ������������� ��������
   ����������� �������� ������������.
   �������������� ������� ��������, �� �������� � �������� [0.5m;1.5m],
   ��� m - ��������������������� �������� ���� ��������� �������. */

int main () {
	system ("chcp 1251 > null");
	int size, i, I, count;
	double num, array[20]={0}, m, c, g;
	while (printf("������� ������ �������: "), fflush(stdin), scanf("%d", &size), size > 20  || size < 0)
		printf("Wrong input!\a\n�������� ������� ����� ���� �� 1 �� 20\n");	
	printf("������� �������� ��������� �������:\n");
	
	for (i = 0; i < size; i++){
		printf("Array[%d] = ", i+1);
		scanf("%lf", &num);
		array[i] = num;
		m = m + num;
	}
	m = m / size; // m - ������� �������������� ���� ��������� �������.
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
			c = array[I] - array[i - 1]; //�������� ����� ��������� ������������� � ������ �����������
			g = I - i;			     	 //���-�� ������������� �����
			c = c / (g + 1);       		 //����� ����
			while (i != I) {
					array[I - 1] = array[I] - c;
					I--;
		}
	}
}
	printf("\n\n���������� �������� ������������:\n");
	for (count = 0; count < size; count++){
		printf("Array[%d] = %.3lg\n", count+1, array[count]);
		}	
	system("pause");
	return 0;
}
