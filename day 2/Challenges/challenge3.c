#include <stdio.h>
int main(void)
{
    int heure;
    int minutes;
    int heure_sec;

    printf("Donner l heure");
    scanf("%d", &heure);

    printf("Donner l minutes");
    scanf("%d", &minutes);

    heure_sec = heure * 60 + 15;

    if (heure_sec > 480 && heure_sec < 574 && heure_sec >= 0) 
        printf("L'heure de depart la plus proche est 8h00 a.m., arrivant a 10h16 a.m.");
    else if (heure_sec > 574 && heure_sec < 679)
        printf("L'heure de depart la plus proche est 9h43 a.m., arrivant a 11h52 a.m.");
    else if (heure_sec > 679 && heure_sec < 767)
        printf("L'heure de depart la plus proche est 11h19 a.m., arrivant a 1h31 p.m.");
    else if (heure_sec > 767 && heure_sec < 840)
        printf("L'heure de depart la plus proche est 12h47 p.m., arrivant a 3h00 p.m.");
    else if (heure_sec > 840 && heure_sec < 945)
        printf("L'heure de depart la plus proche est 2h00 p.m., arrivant a 4h08 p.m.");
    else if (heure_sec > 945 && heure_sec < 1140)
        printf("L'heure de depart la plus proche est 8h00 a.m., arrivant a 5h55 p.m.");
    else if (heure_sec > 1140 && heure_sec < 1305)
        printf("L'heure de depart la plus proche est 8h00 a.m., arrivant a 9h20 p.m.");
    else if (heure_sec > 1304 && heure_sec < 1500)
        printf("L'heure de depart la plus proche est 8h00 a.m., arrivant a 10h16 a.m.");
    else
        printf("Aucun depart a cette heure");
    return 0;
}