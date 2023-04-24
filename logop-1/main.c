#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double a=-3.0;
    double b=-7.0;
    double c=-12.0;
    if(a>0 && b>0 && c>0) {
        printf("Trzy dodatnie!\n");
    }
    else if((a>0 && b>0 && c<= 0) || (a<=0 && b>0 && c>0) || (a>0 && b<=0 && c>0)){
        printf("Dwie dodatnie!\n");
    }
    else{
        printf("Nic :(\n");
    }
    return EXIT_SUCCESS;
}
