#include <stdio.h>

/*DOES NOT WORK FOR NEGATIVE EXPONENTS*/
int exponent(int a, int b) {
	int i;
	int c=1;
	for (i=0; i<b; i++) {
		c = c * a;
	}
	return c;
}

int largest_square(int a) {
	int i;
	int c=1;
	for (i=0; c<=a; i++){
		c = c * 2;
	}
	return c/2;
}

int printb(int a) {
	int i;
	int l = largest_square(a);
	int b = 0;
	for (i=0; l>1;i++) {
		if (a>=l) {
			b++;
			a = a - l;
		}
		l = l / 2;
		b = b * 10;
	}
	if (a==1){
		b++;
	}
	return b;
}
/* we are not astute learners -> we will not use bit shift*/

int test(int x) {
	int i;
	int bababa;
	for (i=0; i < x; i++) {
		bababa = printb(i);
		printf("%d: %d = %b\n", i, bababa, i);
	}
	return 0;
}

int main() {
	test(10);
	return 0;
}
