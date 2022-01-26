#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Perform an in-place "rotation" of the characters in ioStr
  
// Where "rotation" means shift the characters left or right and those which drop
// off the end of the string are added to the vacated character positions at the other end
// n: the number of places to rotate
// direction: 0 = rotate left, 1 = rotate right
// e.g. RotateString( "ABCDE", 1, 1 ) -> "EABCD"
// e.g. RotateString( "ABCDE", 2, 1 ) -> "DEABC"
// e.g. RotateString( "ABCDE", 4, 0 ) -> "EABCD"

void RotateString( char * ioStr, int n, int direction )
{
    int length = strlen(ioStr);
      //right
    if(direction == 1){
        for(int i = 0; i < n; i++){
            int j;
            int temp;
            temp = ioStr[length-1];
            for(j = length-2; j >=0; j--){
                //shift to the right
                ioStr[j+1] = ioStr[j];
                //printf("%c", ioStr[j]);
            }
            ioStr[0] = temp;
        }
    }
    //left
    if(direction == 0){
        for(int i = 0; i < n; i++){
            int j;
            int temp;
            temp = ioStr[0];
            for(j = 0; j < length-1; j++){
                //shift to the left
                ioStr[j] = ioStr[j+1];
                //printf("%c", ioStr[j]);
            }
            ioStr[j] = temp;
        }
    }
}

int main (int argc, char * const argv[])
{
    char * str = strdup("Hello World");
    printf( " Initial: %s\n", str );
    RotateString( str, 3, 1 );
    printf( " Rotated: %s\n", str );
    free( str );
    return 0;
}