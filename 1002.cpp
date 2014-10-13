/*  This Code is Submitted by wywcgs for Problem 1002 on 2005-03-04 at 18:23:49 */ 
#include <stdio.h>

int main(){
    long long a = 0, b = 0, c = 0;

    while(scanf("%lld %lld %lld", &a, &b, &c) == 3){
        printf("%lld\n", a+b+c);
    }

    return 0;
}