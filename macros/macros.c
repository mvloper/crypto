#include <stdio.h>

#define CHOICE(e, f, g) ((e&f)|((~e)&g))

#define MEDIAN(e, f, g) ((e&f)|(f&g)|(e&g))

#define ROTLEFT(a, n) ((a<<n)|(a>>(32-n)))

#define ROTATE(a, n) ((a>>n)|(a<<(32-n)))


int main() {
	return 0;
}
