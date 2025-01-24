#include <stdio.h>

int test(int ba) {
	return 2 + ba;
}

int main(int argc, char **argv)
{
	printf("%c %b\n", argv[1][0], argv[1][0]);
	return 0;
}

