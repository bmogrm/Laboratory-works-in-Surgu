#include <stdio.h>
#include <stdlib.h>

int main(void) {
	system("chcp 1251 > nul");
	int n;
	while (printf("Enter value:"), fflush(stdin), scanf("%d", &n) == 5 || n % 2 != 0)
		printf("Wrong input!\a\nTry again\n");
	
	printf("Value = %d\n\n", n);
	
	system("pause");
	return 0;
}
