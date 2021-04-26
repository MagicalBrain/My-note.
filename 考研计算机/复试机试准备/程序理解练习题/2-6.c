#include <stdio.h>

int main() {
	int x = 0x02ff, y = 0x0ff0;
	printf("%d\n", (x & y) >> 4 | 0x005f);
	return 0;
}
