/*  This Code is Submitted by wywcgs for Problem 1003 on 2005-03-05 at 20:47:29 */ 
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long N, M, i, j, temp, money = 0;
    int flag = 0;
    long *P = NULL, *A = NULL;
    
    scanf("%ld %ld", &N, &M);
    P = (long*)malloc(M*sizeof(long));
    A = (long*)malloc(M*sizeof(long));
    for(i = 0; i < M; i++){
        scanf("%ld %ld", P+i, A+i);
    }
    for(i = 0; i < M-1; i++){
        flag = 0;
        for(j = 0; j < M-1; j++){
            if(P[j] > P[j+1]){
                temp = P[j];
                P[j] = P[j+1];
                P[j+1] = temp;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
    for(i = 0; N >= A[i]; i++){
        N -= A[i];
        money += A[i] * P[i];
    }
    money += N * P[i];
    printf("%ld\n", money);
    free(P);
    free(A);
    
    return 0;
}