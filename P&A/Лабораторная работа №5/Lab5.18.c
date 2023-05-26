#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 15
/* ������������ ������ �5
   ������� 18.
   ������ ���������� ����� � �������� �������������� 
   ������� � ������� ��� ��������� (0 ��� 1).
   ��������� ���������� �� ���������� ���� ����� ���������������,
   �������������� ���������� ����������. */

int main () {
	system("chcp 1251 > nul");
	
	int s1, s2;
	while (printf("������� ������ ���������� �������: "), fflush(stdin), scanf("%d%d", &s1, &s2), s1 > 15  || s1 < 1 || s2 > 15 || s2 < 1)
		printf("Wrong input!\a\n�������� ���������� ������� ����� ���� �� 1 �� 15\n");	
	
	printf("������� �������� ��������� �������:\n");
	int a, b, A, B, array[N][N] = {0}, n, flag = 1;
	for (a = 0; a < s1; a++) {
		for (b = 0; b < s2; b++) {
			printf ("Array[%d][%d] = ", a+1, b+1);
		while (fflush(stdin), scanf("%d", &n), n > 1 || n < 0)
			printf("Wrong input!\a\n�������� ��������� �������: 1 ��� 0\n");
			array[a][b] = n;
		}
	}
	
	int size_width = 0, size_height = 0, count = 0, total_count = 0, c, d;
	for (a = 0; a < s1; a++) {
		for (b = 0; b < s2; b++) 
		if ((array[a][b] == 1) && (b == 0 || array[a][b-1] == 0) && (a == 0 || array[a-1][b] == 0) && (array[a-1][b-1] == 0 || (a == 0 || b == 0))) {
			
			// ����� ������ ��������������
			for (A = a, B = b; array[A][B] == 1 && B+1 <= s2; size_height++) {
				B++;
			}
			
			// ����� ������ ��������������
			for (A = a, B = b; array[A][B] == 1 && A+1 <= s1; size_width++){
				A++;
			}
			
			// �������� �� �� �������� �� ������������ 1-��
			for(A = a, B = b; A <= a + size_width - 1; A++, B = b) {
				while(B <= b + size_height - 1)
					if (array[A][B] == 1) {
						count++;
						B++;
					}
					else B++;
			}
			
			// �������� �� ������������ ������ �� �����������.
			for(c = a; c < a+size_width; c ++){  
				if (b == 0){
					if (array[c][b + size_height] != 0){
						flag = 0;
						break;
					}
				}
				if (b > 0){
					if (array[c][b-1] != 0 || array[c][b + size_height] != 0){
						flag = 0;
						break;
					}
				}
				if (b+1 == s2){
					if (array[c][b-1] != 0){
						flag = 0;
						break;
					}
				}
			}
			
			// �������� �� ������������ ������ �� ���������.
			for(d = b; d < b+size_height; d ++){ 
				if (a == 0){
					if (array[a + size_width][d] != 0){
						flag = 0;
						break;
					}
				}
				if (a > 0){
					if(array[a + size_width][d] != 0 || array[a-1][d] != 0){
						flag = 0;
						break;
					}
				}
				if (a+1 == s1){
					if (array[a-1][d] != 0){
						flag = 0;
						break;
					}
				}
			}
			
			// �������� �� ������������� ������ �� ���������
			if(a + size_width != s1 || b + size_height != s2 || a != 0 || b != 0){
				if(a != 0 && b != 0){
					if(array[a-1][b-1] != 0){
						flag = 0;
					}
				}
				if(a != 0 && b + size_height != s2){
					if(array[a-1][b+size_height] != 0){
						flag = 0;
					}
				}
				if(a + size_width != s1 && b != 0){
					if(array[a+size_width][b-1] != 0){
						flag = 0;
					}
				}
				if(a + size_width != s1 && b + size_height != s2){
					if(array[a+size_width][b+size_height] != 0){
						flag = 0;
					}
				}
			}

			
			if((size_width * size_height) == count && size_height > 0 && size_width > 0) {
				if(flag == 1)
					total_count++;
				}
			
			size_width = 0;
			size_height = 0;
			count = 0;
			flag = 1;
		}
	}
	
	for (a = 0; a < s1; a++, printf("\n\n")) { // ����� �������.
		for (b = 0; b < s2; b++) {
			printf("%d\t", array[a][b]);
		}
	}
	
	printf("����� ���-�� ���������������: %d\n\n", total_count);
	system("pause");
	return 0;
}
