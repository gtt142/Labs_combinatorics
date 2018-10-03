//  lab1 combinatorics  var-1C
//  перечисление двоичных наборов решений уранений X1+X2+X3+X4+X5+X6+X7+X8=3
//  по алгоритму транспозиции бинарных сочетаний с левым сдвигом
#include<stdio.h>
#define NUM 8

int sol[NUM] = {0, 0, 0, 0, 0, 1, 1, 1};

void printSolMas(void) {
    for (int i = 0; i < NUM; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

int transpose() {
    int pos = -1;
    for(int i = 1; i < NUM; i++) {
        if(sol[i]==1 && sol[i-1]==0) {
            sol[i]=0;
            sol[i-1]=1;
            pos = i-1;
            break;
        }
    }
    return pos;
}

int shift(int trPos) {
    if (trPos < 1) {
        return -1;
    }
    if(sol[0] != 1) {
        return -1;
    }
    if(sol[trPos-1] == 1) {
        return -1;
    }
    int leftOnesCount = 1;
    int i = 1;
    while(sol[i] == 1 && i < trPos) {
        leftOnesCount++;
        i++;
    }
    for(int j = 0; j < leftOnesCount; j++) {
        sol[j] = 0;
    }
    for(int j = 0; j < leftOnesCount; j++) {
        sol[trPos-j-1] = 1;
    }
}

int main() {
    printf("#%d\n",1);
    printSolMas();
    int trPos, i=1;
    while((trPos = transpose()) != -1) {
        shift(trPos);
        printf("#%d\n",i+1);
        printSolMas();
        i++;
    }
    return 0;
}