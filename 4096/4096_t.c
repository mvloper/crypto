/* 4096_t.c */

/*
gcc 4096_t.c --std=c89 -Wall -Wextra -Werror -Wpedantic
*/

#include "4096_t.h"

uint64_t bigsub(uint64_t *min, uint64_t *sub, uint64_t *dif) {
      size_t i;
      uint64_t carry = 0, tmp;
      for (i = 0; i < S; i++) {
          tmp = min[i] - sub[i] - carry;
          carry = min[i] < sub[i];
          dif[i] = tmp;
    }
    return carry;
}

uint64_t bigadd(){
	return 0;
}

int main() {
    uint64_t min[S], sub[S], dif[S];
    size_t i;
    memset(min, 0, BYTES);
    memset(sub, 0, BYTES);
    for (i = 0; i < S; i++) {
        min[i] = i * 3;
        sub[i] = i * 2;
    }
    bigsub(min, sub, dif);
    for (i = 0; i < S; i++) {
        printf("dif[%02lx] = %02lx\n", i, dif[i]);
    }
    return 0;
}
