#include <stdio.h>
#include <stdlib.h>

int main(){
    char* s = (char*)malloc(256);
    scanf("%s", s);
    printf("Hello, %s!\n", s);
}
