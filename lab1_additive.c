//  lab1 combinatorics  var-1C

#include<stdio.h>
#include<stdlib.h>

void printCharBin (char num) {
    int i = 7;
    char buf[8];
    while( i >= 0) {
        if (num & 1) {
            buf[i] = '1';
        } else {
            buf[i] = '0';
        }
        num >>= 1;
        i--;
    }
    printf("%s\n", buf);
}

int countE(char num) {
    int count = 0;
    char comp = 1;
    comp <<= 7;

    int i = 0;
    while ((num & comp) && i < 8) {
        count++;
        num <<= 1; 
        i++;   
    }

    return count;
}

int countN(char num) {
    int count = 0;
    char comp = 1;
    comp <<= 7;

    int i = 0;
    while ((num & comp) && i < 8) {
        num <<= 1; 
        i++;
    }

    while (!(num & comp) && i < 8) {
        count++;
        num <<= 1; 
        i++;
    }

    return count;
}

int pow2toN (int N) {
    if (N > 30) {
        return -1;
    }
    int num = 1;
    for (int i = 0; i < N; i++) {
        num *= 2;
    }
    return num;
}

char TSL (char sol, int E, int N) {
    int n = 8;
    sol = sol + (pow2toN(n-E)) + (pow2toN(n-N+1) - pow2toN(n-N-E+1)) + pow2toN(n-N-E-1);
    return sol;
}



int main() {
    char sol = 7;
    int oneE = 0, zeroN = 0;
    oneE = countE(sol);
    zeroN = countN(sol);

    printf("#%d\n",1);
    printCharBin(sol);
    int i = 1;
    while((oneE + zeroN) != 8) {
        sol = TSL(sol, oneE, zeroN);
        printf("#%d\n",i+1);
        printCharBin(sol);
        oneE = countE(sol);
        zeroN = countN(sol);
        i++;
    }

    return 0;
}