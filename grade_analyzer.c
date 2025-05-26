#include <stdio.h>

int main() {
    int note[20];        // Array to store grades
    int n, i, s = 0, m = 1; // n = size, s = sum, m = average

    // Prompt for valid array size
    do {
        printf("Entrer la taille du tableau (entre 0 et 20): ");
        scanf("%d", &n);
    } while ((n > 20) || (n < 0));

    // Input elements & calculate sum
    for (i = 0; i < n; i++) {
        printf("Entrer l'élément %d: ", i);
        scanf("%d", &note[i]);
        s += note[i];
    }

    // Display all elements
    printf("\nListe des notes:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", note[i]);
    }
    printf("\n");

    // Calculate average
    m = s / n;
    printf("La somme est : %d, La moyenne est : %d\n", s, m);

    // Compare each note with average
    for (i = 0; i < n; i++) {
        if (note[i] == m) {
            printf("Note %d est égale à la moyenne\n", i);
        } else if (note[i] > m) {
            printf("Note %d est supérieure à la moyenne\n", i);
        } else {
            printf("Note %d est inférieure à la moyenne\n", i);
        }
    }

    // Count positive and negative notes
    int ns = 0, ni = 0;
    for (i = 0; i < n; i++) {
        if (note[i] < 0) {
            ni++;
        } else {
            ns++;
        }
    }

    printf("\nNombre de notes positives: %d\n", ns);
    printf("Nombre de notes négatives: %d\n", ni);

    // Sort the array in descending order
    int temp, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (note[i] < note[j]) {
                temp = note[i];
                note[i] = note[j];
                note[j] = temp;
            }
        }
    }

    // Display sorted array
    printf("\nNotes triées (ordre décroissant):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", note[i]);
    }
    printf("\n");

    return 0;
}
