#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	system("chcp 1251 > nul");
	int a, b, c;
	printf("������� �������� ��� 'a, b, c': ");
	scanf("%d%d%d", &a, &b, &c);
	if ((a < 0) || (b < 0) || (c < 0)) {
		printf("������� �������� ��������!\n");
		return 1;
	}
	if (((b > a) && (b < c)) || ((b < a) && (b > c))) {
		printf("�������� %d, ��������� ����� a & c\n", b);
	}
	else
		printf("�������� %d, �� ��������� ����� a & c\n", b);
	
	system("pause");
	return 0;
}
