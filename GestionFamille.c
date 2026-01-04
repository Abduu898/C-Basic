#include <stdio.h>
#include <string.h>

typedef struct {
    char cin[20];
    char nom[50];
    char prenom[50];
} Membre;

int main() {
    FILE *fp;
    Membre m;
    char ligne[200];

    printf("=== EXERCICE 4 COMPLET ===\n\n");

    // 1. Créer fichiers famille
    printf("--- 1. Creation fichiers famille ---\n");

    // Famille 1
    fp = fopen("famille1.txt", "w");
    printf("Famille 1 - Nombre de membres: ");
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Membre %d (CIN Nom Prenom): ", i+1);
        scanf("%s %s %s", m.cin, m.nom, m.prenom);
        fprintf(fp, "%s %s %s\n", m.cin, m.nom, m.prenom);
    }
    fclose(fp);

    // Famille 2
    fp = fopen("famille2.txt", "w");
    printf("\nFamille 2 - Nombre de membres: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Membre %d (CIN Nom Prenom): ", i+1);
        scanf("%s %s %s", m.cin, m.nom, m.prenom);
        fprintf(fp, "%s %s %s\n", m.cin, m.nom, m.prenom);
    }
    fclose(fp);

    // 2. Ajouter membre famille 2
    printf("\n--- 2. Ajout membre famille 2 ---\n");
    fp = fopen("famille2.txt", "a");
    printf("Nouveau membre (CIN Nom Prenom): ");
    scanf("%s %s %s", m.cin, m.nom, m.prenom);
    fprintf(fp, "%s %s %s\n", m.cin, m.nom, m.prenom);
    fclose(fp);

    // 3. Créer fichier résultat
    printf("\n--- 3. Creation fichier resultat ---\n");
    FILE *resultat = fopen("resultat.txt", "w");

    // Copier famille1
    fp = fopen("famille1.txt", "r");
    while(fgets(ligne, 200, fp)) {
        fputs(ligne, resultat);
    }
    fclose(fp);

    // Copier famille2
    fp = fopen("famille2.txt", "r");
    while(fgets(ligne, 200, fp)) {
        fputs(ligne, resultat);
    }
    fclose(fp);
    fclose(resultat);

    printf("Fichier resultat.txt cree.\n");

    printf("\n--- 4. Suppression des 'Paul' ---\n");

    FILE *temp = fopen("temp.txt", "w");
    resultat = fopen("resultat.txt", "r");

    int supprimes = 0;
    char cin[20], nom[50], prenom[50];

    while(fscanf(resultat, "%s %s %s", cin, nom, prenom) == 3) {
        if(strcmp(prenom, "Paul") == 0) {
            printf("Supprime: Paul %s\n", nom);
            supprimes++;
        } else {
            fprintf(temp, "%s %s %s\n", cin, nom, prenom);
        }
    }

    fclose(resultat);
    fclose(temp);

    // Remplacer ancien par nouveau
    remove("resultat.txt");
    rename("temp.txt", "resultat.txt");

    printf("%d personnes nommees Paul supprimees.\n", supprimes);

    return 0;
}
