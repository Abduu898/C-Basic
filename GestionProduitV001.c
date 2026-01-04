#include <stdio.h>
#include <string.h>
typedef struct{
char nomproduit[26];
char marque[21];
float prix;
int quantite;
}produit;

void saisir(int nb){
FILE *fp=fopen("invantaire.bin","wb");
if(!fp) {perror("Erreur d'ouverture fichier entreprise "); return  ; }


produit pp;

for(int i=0;i<nb;i++){
    printf("Entrer Nom : marque : prix : quantite || du produit %d \n",i);
    scanf("%s",pp.nomproduit);
    scanf("%s",pp.marque);
    scanf("%f",&pp.prix);
    scanf("%d",&pp.quantite);
    fwrite(&pp,sizeof(produit),1,fp);
}
fclose(fp);}
void afficher_trier(int nb){
    produit pp;
    produit tab[nb];
    FILE*fp=fopen("invantaire.bin","rb");
for(int i=0;i<nb;i++){
    fread(&tab[i], sizeof(produit), 1, fp);
}
for(int i=0;i<nb-1;i++){
    for(int j=i+1;j<nb;j++){
        if(strcmp(tab[i].nomproduit, tab[j].nomproduit) > 0){
            produit tmp = tab[i];
            tab[i]=tab[j];
            tab[j]=tmp;}

            }}
for(int i =0;i<nb;i++){
 printf("Nom : %s marque %s: prix %f: quantite: %d \n",tab[i].nomproduit,tab[i].marque,tab[i].prix,tab[i].quantite);
}
fclose(fp);
}
void chercherParNom(int nb,char wanted[]){
    produit pp;
    int trouver=0;
    FILE*fp=fopen("invantaire.bin","rb");
    while(fread(&pp,sizeof(produit),1,fp)){
    if(strcmp(wanted,pp.nomproduit)==0){
        printf("Nom : %s marque %s: prix %.3f: quantite: %d",pp.nomproduit,pp.marque,pp.prix,pp.quantite);
         trouver=1;
         break;
    }
}if (trouver!=1) printf("Nom non trouver \n"); fclose(fp);}

void modifParNom(int nb,char wanted[]){
    produit pp;
    FILE*fp=fopen("invantaire.bin","rb+");
    while(fread(&pp,sizeof(produit),1,fp))
{
    if(strcmp(wanted,pp.nomproduit)==0){
        printf("Voulait vous modifier \n 1- prix\n 2- quantite\n ");
        int cas;
        scanf("%d",&cas);
        switch (cas) {
    case 1:
        printf("Entrer le prix nouveau :\n ");
        float tempprice;
        scanf("%f",&tempprice);
        pp.prix=tempprice;
        break;
    case 2 :
        printf("Entrer Nouvelle quantite : \n");
        int temquantite;
        scanf("%d",&temquantite);
        pp.quantite=temquantite;
        break;
    default :
        printf("Choix introuvable : \n");
    }
    fseek(fp, -sizeof(produit), SEEK_CUR);
            fwrite(&pp, sizeof(produit), 1, fp);
}

}fclose(fp);}
void valeurTotale(){
produit pp;
float total=0;
    FILE*fp=fopen("invantaire.bin","rb");
    while(fread(&pp,sizeof(produit),1,fp)){
        total += pp.prix * pp.quantite;
    }
printf("La valeur totale de l'inventaire est : %f",total);

fclose(fp);
}
int main(){
printf("Bienvenue \n Entrer le nombre des produits souhaiter :\n");
int nb;
scanf("%d",&nb);
saisir(nb);
afficher_trier(nb);
char wanted[100];
printf("Entrer nom du produit a chercher \n :");
scanf("%s", wanted);
chercherParNom(nb,wanted);
modifParNom(nb,wanted);
printf("\nInventaire après modification:\n");
afficher_trier(nb);
valeurTotale();

return 0;
}


