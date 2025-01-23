#include <stdio.h>
#include <ctype.h>

/* constants */
#define alphabet "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define fast "BDFHJLCPRTXVZNYEIWGAKMUSQO"
#define medium "AJDKSIRUXBLHWTMCQGZNPYFVOE"
#define slow "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
#define reflect "IXUHFEZDAOMTKQJWNSRLCYPBVG"


/* input index of letter and amount to shift, return new shifted index. */
int shift_index(int index, int shift) {
	int new_index = (index + shift) % 26;
	if (new_index < 0) {
		new_index = new_index + 26;
	}
	return new_index;		
}

/* input letter and rotor, return index of letter in rotor. */
int char_index(char letter, char *rotor) {
	int i;
	if (letter < 'A' || letter > 'Z') {
		return letter;
	}
	for ( i=0; i < 26; i++) {
		if (rotor[i] == letter) {
			return i;
		}
	}
}

int encryption_step(int index, char *rotor0, char *rotor1, int shift) {
	index = shift_index(index, shift);
	char letter = rotor0[index];
	index = char_index(letter, rotor1);
	index = shift_index(index, -shift);
	return index;
}

char encrypt(char letter, int i) {
	int index = char_index(letter, alphabet);
	index = encryption_step(index, fast, alphabet, i);
	index = encryption_step(index, medium, alphabet, i/26);
	index = encryption_step(index, slow, alphabet, i/(26*26));
	
	letter = reflect[index];
	index = char_index(letter, alphabet);

	index = encryption_step(index, alphabet, slow, i/(26*26));
	index = encryption_step(index, alphabet, medium, i/26);
	index = encryption_step(index, alphabet, fast, i);

	letter = alphabet[index];
	return letter;
}

char *encrypt_string(char *str) {
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		char temp = encrypt(str[i], i+1);
		/*printf("%c\n", temp);
		fflush(stdout);*/
		str[i] = temp;
		/*printf("%c\n", temp);
		fflush(stdout);*/
	}
	return str;
}
int main(int argc, char**argv) {
	printf("%s\n", encrypt_string(argv[1]));
	return 0;
}
