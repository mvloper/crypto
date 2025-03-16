#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint32_t gcd(uint32_t a, uint32_t b) {
	int c, d;
	for (; b>0;) {
		c = b;
		d = a % b;
		a = c;
		b = d;
	}
	return a;
}

uint32_t lcm(uint32_t a, uint32_t b) {
    return (a * b) / gcd(a, b);
}

int is_prime(uint32_t n) {
	if (n <= 1) {return 0;}
	if (n <= 3) {return 1;}
	size_t i;
	for (i=2; i*i <= n; i++) {
		if (n % i == 0) {return 0;}
	}
	return 1;
}

uint32_t sixkp1(int k) {/*generate prime number*/
	uint32_t candidate = 6 * k + 1;
	for (;!is_prime(candidate); ) {
		candidate += 6;
	}
	return candidate;
}

int keygen(uint32_t k, uint32_t j) {
	uint_t p = sixkp1(k), q = sixkp1(j);
	uint32_t n = p*q;
	uint32_t tN = lcm(p-1, q-1); /* totient of n */
	uint32_t e = 65537; 

	FILE *fptr;
	fptr = fopen("./unsafe.bad", "w");
	fprintf(fptr, "-----BEGIN UNSAFE PRIVATE KEY-----\n%x\n%x\n%x\n-----END UNSAFE PRIVATE KEY-----\n", tN, e, n);
	fclose(fptr);

	fptr = fopen("./unsafe.pub", "w");
	fprintf(fptr, "-----BEGIN UNSAFE PUBLIC KEY-----\n%x\n%x\n-----END UNSAFE PUBLIC KEY-----\n", tN, e);
	return 0;
}


int main() {
	keygen(3, 4);
	return 0;
}
