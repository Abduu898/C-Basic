#include <stdio.h>

typedef struct {
    int heures;
    int minutes;
    int secondes;
} Heure;

int heureEnSecondes(Heure h) {
    return h.heures * 3600 + h.minutes * 60 + h.secondes;
}

Heure secondesEnHeure(int totalSecondes) {
    Heure h;
    h.heures = totalSecondes / 3600;
    totalSecondes %= 3600;
    h.minutes = totalSecondes / 60;
    h.secondes = totalSecondes % 60;
    return h;
}

int main() {
    Heure h1, h2;
    int total;

    scanf("%d %d %d", &h1.heures, &h1.minutes, &h1.secondes);
    total = heureEnSecondes(h1);
    printf("%d\n", total);

    h2 = secondesEnHeure(total);
    printf("%02d:%02d:%02d\n", h2.heures, h2.minutes, h2.secondes);

    return 0;
}
