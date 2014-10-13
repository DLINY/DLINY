/*  This Code is Submitted by wywcgs for Problem 1006 on 2005-03-05 at 15:30:14 */ 
#include <stdio.h>

int main()
{
    int s, p;
    
    while(scanf("%d %d", &s, &p) == 2){
        if((s == 0) && (p == 0)){
            return 0;
        }else if((s == 0) && (p != 0)){
            printf("0\n");
        }else if(s*(p+1) % 60 == 0){
            printf("1\n");
        }else if(s*(p+1)*(p+1) % 60 == 0){
            printf("2\n");
        }else{
            printf("Impossible\n");
        }
    }
    
    return 0;
}