#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ������������ ������ �45
   ������ ���������� ���� ��������������� ����� ��������,
   ����������� �� ��������� ������������ ���� ��������� �� 
   ����������� ������������ ����. ����� ���������� ��������� �����. */
   
int main () {
	system ("chcp 1251 > nul");
	
	double x1, y1, x2, y2, x3, y3, x4, y4, xc, yc, xr, yr;
	printf("������� �������� ��������� x1, y1: ");
	scanf("%lf%lf", &x1, &y1);
	printf("������� �������� ��������� x2, y2: ");
	scanf("%lf%lf", &x2, &y2);
	xc = (x1 + x2) / 2;
	yc = (y1 + y2) / 2;
	xr = xc - x1;
	yr = yc - y1;
	x3 = xc - yr;
	y3 = yc + xr;
	x4 = xc + yr;
	y4 = yc - xr;
	printf("�������� ���������:\nA = (%.2lf;%.2lf)\nB = (%.2lf;%.2lf)\nC = (%.2lf;%.2lf)\nD = (%.2lf;%.2lf)\n\n", x1, y1, x2, y2, x3, y3, x4, y4);
	printf("\t������� ����������:\n� = (%.2lf;%.2lf)\nD = (%.2lf;%.2lf)\n", x3, y3, x4, y4);
	
	system("pause");
	return 0;
}
