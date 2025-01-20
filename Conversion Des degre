#include <stdio.h>

int main() {
    float celsius = 0, fahrenheit = 0, deg;
    char choix;

    printf("Programme pour la conversion des Unites \n");
    printf("C pour C en F, F pour F en C et Q pour quitter\n");

    do {
        
        printf("\nEntrer votre choix (C, F ou Q) : ");
        scanf(" %c", &choix); 

        if (choix == 'C' || choix == 'F') {
            printf("Entrez le degré : ");
            scanf("%f", &deg);
        }

        switch (choix) {
            case 'C':
                fahrenheit = (deg * 1.8) + 32;
                printf("%.2f C = %.2f F\n", deg, fahrenheit);
                break;
            case 'F':
                celsius = (deg - 32) / 1.8;
                printf("%.2f°F = %.2f°C\n", deg, celsius);
                break;
            case 'Q':
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix introuvable, essayez encore.\n");
                break;
        }
    } while (choix != 'Q');

    return 0;
}
