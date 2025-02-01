#include <stdio.h>
#include <string.h>

int main(){
int i=0;
char code1[20]="Bonjour";
char code2[20]="Topsecret25";
char x[20];
printf("Saisir Le code \n");
scanf("%s",&x);
if ((strcmp(x,"Bonjour")==0)){
printf(" Succes ");
}else{
while( (i<3) && (strcmp(x,code1)!=0)){
    printf("Code incorrecte \n");
    printf("Ressayer \n");
    scanf("%s",&x);
    i++;}}
if (i>=3){
printf("Quelle est votre code precedent :\n");
scanf("%s",&x);
if ((strcmp(x,code2)==0)){
    printf("Succes");
}else {
printf("Acces refuse");
}}

}
