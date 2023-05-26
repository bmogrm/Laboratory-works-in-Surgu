#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
	system ("chcp 1251 > nul");
	 
	int kx, kx1, ky, ky1, rx, ry, qx, qy;
	printf("Введите значение координат Короля от 1-8: ");
	scanf("%d%d", &kx, &ky);
	printf("Введите значение координат Ладьи от 1-8: ");
	scanf("%d%d", &rx, &ry);
	printf("Введите значение координат Ферзя от 1-8: ");
	scanf("%d%d", &qx, &qy);
	
	kx1 = kx;
	ky1 = ky;
	
	if ((rx == kx) || (qx == kx) || (ry == ky) || (qy == ky) || abs(qx - kx) == abs(qy - ky)) {
		kx1 = kx + 1;
	}
	else {
		printf("Мат не поставлен!");
		return 0;
	}
	if ((kx1 == 9) || (rx == kx1) || (qx == kx1) || (ry == ky1) || (qy == ky1) || abs(qx - kx1) == abs(qy - ky1)) {
		kx1 = kx - 1;
	}
	else {
		printf("Мат не поставлен!");
		return 0;
	}
	if ((kx1 == 0) || (rx == kx1) || (qx == kx1) || (ry == ky1) || (qy == ky1) || abs(qx - kx1) == abs(qy - ky1)) {
		kx1 = kx + 1;
		ky1 = ky + 1;
	}
	else {
		printf("Мат не поставлен!");
		return 0;
	}
	if ((kx1 == 9) || (ky1 == 9) || (rx == kx1) || (qx == kx1) || (ry == ky1) || (qy == ky1) || abs(qx - kx1) == abs(qy - ky1)) {
		kx1 = kx + 1;
		ky1 = ky - 1;
	}
	else {
		printf("Мат не поставлен!");
		return 0;
	}
	if ((kx1 == 9) || (ky1 == 0) || (rx == kx1) || (qx == kx1) || (ry == ky1) || (qy == ky1) || abs(qx - kx1) == abs(qy - ky1)) {
		ky1 = ky + 1;
	}
	else {
		printf("Мат не поставлен!");
		return 0;
	}
	if ((ky1 == 9) || (rx == kx1) || (qx == kx1) || (ry == ky1) || (qy == ky1) || abs(qx - kx1) == abs(qy - ky1)) {
		ky1 = ky - 1;
	}
	else {
		printf("Мат не поставлен!");
		return 0;
	}
	if ((ky1 == 0) || (rx == kx1) || (qx == kx1) || (ry == ky1) || (qy == ky1) || abs(qx - kx1) == abs(qy - ky1)) {
		kx1 = kx - 1;
		ky1 = ky - 1;
	}
	else {
		printf("Мат не поставлен!");
		return 0;
	}
	if ((kx1 == 0) || (ky1 == 0) || (rx == kx1) || (qx == kx1) || (ry == ky1) || (qy == ky1) || abs(qx - kx1) == abs(qy - ky1)) {
		kx1 = kx - 1;
		ky1 = ky + 1;
	}
	else {
		printf("Мат не поставлен!");
		return 0;
	}
	if ((kx1 == 0) || (ky1 == 9) || (rx == kx1) || (qx == kx1) || (ry == ky1) || (qy == ky1) || abs(qx - kx1) == abs(qy - ky1))
	 {
		kx1 = kx;
		ky1 = ky;
		printf("Мат!\n");
	}
	printf("kx = %d\nky = %d\n", kx1, ky1);
	
	system("pause");
	return 0;
}
