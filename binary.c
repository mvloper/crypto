#include <stdio.h>

int main(int argc, char**argv) {
	int i=0;
	for (i=0;i<11;i++){
	       printf("%b\n", '\0' + i);
	}
	return 0;
}
