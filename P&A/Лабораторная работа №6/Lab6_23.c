#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void FillArray(double *array,int size, double *m);
void Calculation(double *array,int size, double m);
void PrintArray(double *array,int size);
void check(int *size);

//��������� ��������� ������� ��� ����, ����� ������� ����� ���� ���������� � ����� ������� ����.
/* ������������ �4
   ������� 23:
   ����� ������ ������� �������������� �����
   � �������� ��� ���������. �������� ������������� ��������
   ����������� �������� ������������.
   �������������� ������� ��������, �� �������� � �������� [0.5m;1.5m],
   ��� m - ��������������������� �������� ���� ��������� �������. */
   
int main () {
	system ("chcp 1251 > null");
	int size=0, i, I, count;
	double num, array[20]={0}, m, c, g;
	check(&size);
	FillArray(array,size,&m);
	Calculation(array,size,m);
	PrintArray(array,size);
	system("pause");
	return 0;
}

void check(int *size)
{
	int tempsize;
	while(1)
	{
		if(printf("������� ������ �������: "), 
			fflush(stdin), scanf("%d", &tempsize) !=1 || tempsize > 20  || tempsize <= 0)
		printf("Wrong input!\a\n�������� ������� ����� ���� �� 1 �� 20\n");
		else
		{
			*size=tempsize;
			break;
		}
		
	 } 

}
void FillArray(double *array,int size,double *m)
{
	int i;
	printf("������� �������� ��������� �������:\n");
	for (i = 0; i < size; i++)
	{
		printf("Array[%d] = ", i+1);
		scanf("%lf", &array[i]);
		*m = *m + array[i];
	}
}
void Calculation(double *array,int size,double m)
{
	int i, I;
	double c, g;
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
			c = c / (g + 1);        //����� ����
			while (i != I) {
					array[I - 1] = array[I] - c;
					I--;
		}
	}
}
}
void PrintArray(double *array,int size)
{
	int count;
	printf("\n\n���������� �������� ������������:\n");
	for (count = 0; count < size; count++){
		printf("Array[%d] = %.3lg\n", count+1, array[count]);
		}
	
}
