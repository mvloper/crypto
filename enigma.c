#include <stdio.h>

// constants
#define alphabet "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define fast "BDFHJLCPRTXVZNYEIWGAKMUSQO"
#define medium "AJDKSIRUXBLHWTMCQGZNPYFVOE"
#define slow "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
#define reflect "IXUHFEZDAOMTKQJWNSRLCYPBVG"

#define NC 26 // number of characters

// input index of letter and amount to shift, return new shifted index.
int shift_index(int index, int shift) {
	int new_index = (index + shift) % NC;
	if (new_index < 0) {
		new_index = new_index + 26;
	}
	return new_index;		
}

// input letter and rotor, return index of letter in rotor.
int char_index(char letter, char *rotor) {
	int i;
	for ( i=0; i < 26; i++) {
		if (rotor[i] == letter) {
			return i;
		}
	}
}

// returns length of string
int len(char *str) {
	int i = 0;
	for ( ; str[i] ; ) {
		i++;
	}
	// printf("%d\n", i);
	return i;
}

int main() {
	char *str = "HELLO WORLD";
	int length = len(str);
	printf("%s [length %d]\n", str, length);
	printf("index of o: %d\n", char_index('O', str));
	printf("20 + 10: %d\n", shift_index(20, 10));
	printf("5 - 6: %d\n", shift_index(5, -6));
	return 0;
}
