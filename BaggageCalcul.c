#include <stdio.h>

void baggage(){
    int size;
    scanf("%d",&size);
    if (size<=23){
printf("0");
    }
    else{
        size=size-23;
        printf("%d",size*12);
    }
}

int main() {
    baggage();

    return 0;
}
