#include <stdio.h>

int main() {
	int a = 1;
	char c = 'a';
	float f = 2.0;
	printf("%d\n", (0, 0));
	printf("%d\n", (!(a == 0), f != 0 && c == 'A'));
	return 0;
}
