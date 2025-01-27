#include <stdio.h>

#define CHOICE(e, f, g) ((e&f)|((~e)&g))

#define MEDIAN(e, f, g) ((e&f)|(f&g)|(e&g))

#define ROTLEFT(a, n) ((a<<n)|(a>>(32-n)))


int main() {
	int a = 15;
	int b = 51;
	int c = 85;
	printf("%b, %b, %b\n", 15, 51, 85);
	printf("%b = 1010011\n", CHOICE(a, b, c));
	printf("%b = 10111\n", MEDIAN(a, b, c));
	printf("%b = 10111001\n", ROTLEFT(55, 3));
	return 0;
}
