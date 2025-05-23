#include <stdio.h>
void MinMax(int t[],int n, int max,int min){
int i;
max=t[0];
min=t[0];
for(i=0;i<n;i++){
    if(t[i]>max){
        max=t[i];
    }else if(t[i]<min){
min=t[i];
}}
printf("Le min est %d:\n",min);
printf("le max est :%d\n",max);
}
int main(){
     system("color f0");
int n,i,max=0,min=0;
scanf("%d",&n);
int t[n];
for(i=0;i<n;i++){
    scanf("%d",&t[i]);

}
MinMax(t,n,max,min);
}
