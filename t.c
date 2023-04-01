void func( int B[5][10] )  // this func is actually the same as the one above! 
{
         B[0][0] = 5;
}

#include <stdio.h>

int main(void){
    int Ar2D[5][10];
    func(Ar2D);   // same as func( &Ar2D[0] )
    printf("%lu", sizeof(int*));
}