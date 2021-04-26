#include <stdio.h>

int main() {
	int a = 1, i = a + 1;
	do
	{
		a++;
	} while(!~i++ > 3);
	printf("%d\n", a);
	return 0;
}
