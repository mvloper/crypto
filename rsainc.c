#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint32_t gcd(uint32_t a, uint32_t b) {
	uint32_t c, d;
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

uint32_t sixkp1(uint32_t k) {/*generate prime number*/
	uint32_t candidate = 6 * k + 1;
	for (;!is_prime(candidate); ) {
		candidate += 6;
	}
	return candidate;
}

uint32_t EEA(uint32_t a, uint32_t b) {
	uint32_t old_r = a, r = b,
		 old_s = 1, s = 0,
		 old_t = 0, t = 1;

	uint32_t q, temp;

	for (; r != 0;) {
		q = old_r / r;
		temp = r;
		r = old_r - q * r;
		old_r = temp;
		temp = s;
		s = old_s - q * s;
		old_s = temp;
		temp = t;
		t = old_t - q * t;
		old_t = temp;
	}
	printf("t: %d\n", t);
	return t;
}

uint32_t find_d(uint32_t e, uint32_t tN) {
	uint32_t start = EEA(e, tN);
	for (;start < 0;) {
		start += tN;
	}
	printf("d: %d\n TN: %d\n <0: %d\n", start, tN, start < 0);
	return start;
}

int keygen(uint32_t k, uint32_t j) {
	uint32_t p = sixkp1(k), q = sixkp1(j);
	uint32_t n = p*q;
	uint32_t tN = lcm(p-1, q-1); /* totient of n */
	uint32_t e = 65537;
	uint32_t d = find_d(e, tN); 
	

	FILE *fptr;
	fptr = fopen("./unsafe.bad", "w");
	fprintf(fptr, "-----BEGIN UNSAFE PRIVATE KEY-----\n%x\n%x\n%x\n-----END UNSAFE PRIVATE KEY-----\n", n, e, d);
	fclose(fptr);

	fptr = fopen("./unsafe.pub", "w");
	fprintf(fptr, "-----BEGIN UNSAFE PUBLIC KEY-----\n%x\n%x\n-----END UNSAFE PUBLIC KEY-----\n", n, e);
	return 0;
}


int main() {
	keygen(900, 300);
	return 0;
}
