#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 6
#define POS_MAX 39

int main(void)
{
    srand(time(NULL));
    int pos_1 = 0, pos_2 = 0, balance_1 = 100, balance_2 = 100, punteggio_1 = 0, punteggio_2 = 0, effetto;
    int pattern[10] = {0, 5, -30, 10, -25, 5, -40, 15, -35, 0};
    int salta_turno_1 = 0, salta_turno_2 = 0;

    while (balance_1 > 0 && balance_2 > 0)
    {
        //inizio turno giocatore 1
        punteggio_1 = 0;

        if (salta_turno_1)
        {
            puts("Giocatore 1 e' in prigione e saltera' il turno");
            salta_turno_1 = 0;
        }else{
            printf("Giocatore 1 inizia il turno con %d euro.\n", balance_1);

            int dado_1 = MIN + rand() % (MAX - MIN + 1);
            punteggio_1 += dado_1;
            int dado_2 = MIN + rand() % (MAX - MIN + 1);
            punteggio_1 += dado_2;

            printf("Giocatore 1 ha tirato i dadi e ha ottenuto: %d. \n", punteggio_1);

            pos_1 += punteggio_1;

            printf("Giocatore 1 si trova nella casella: %d.\n", pos_1);

            if (pos_1 >= POS_MAX)
            {
                pos_1 %= POS_MAX;
                puts("Giocatore 1 e' passato per il via e ritira 20 euro");
                balance_1 += 20;
            }else if (pos_1 == 19)
            {
                puts("Giocatore 1 va' in prigione (casella 9) e salta un turno");
                pos_1 = 9;
                salta_turno_1 = 1;
            }else if (pos_1 == 29)
                puts("Giocatore 1 si trova sul transito libero, il suo saldo non subira' variamenti");
            else
            {
                int indice_1 = pos_1 % 10;
                effetto = pattern[indice_1];

                if (effetto < 0){
                    printf("Giocatore 1 perde %d euro dal saldo.\n", pattern[indice_1]);
                }
                else
                {
                    printf("Giocatore 1 guadagna %d euro.\n", pattern[indice_1]);
                }
                balance_1 += pattern[indice_1];
            }

            printf("Saldo a fine turno del giocatore 1: %d.\n", balance_1);
            if (balance_1 <= 0)
            {
                puts("Giocatore 1 e' andato in bancarotta.");
                break;
            }
        }
        puts("");
        //fine turno giocatore 1


        //inizio turno giocatore 2
        puts("");

        if (salta_turno_2)
        {
            printf("Giocatore 2 e' in prigione e saltera' il turno.");
            salta_turno_2 = 0;
        }else{
            printf("Giocatore 2 inizia il turno con %d euro.\n", balance_2);

            int dado_3 = MIN + rand() % (MAX - MIN + 1);
            int dado_4 = MIN + rand() % (MAX - MIN + 1);
            punteggio_2 = dado_3 + dado_4;

            printf("Giocatore 2 ha tirato i dadi e ha ottenuto: %d.\n", punteggio_2);

            pos_2 += punteggio_2;

            printf("Giocatore 2 si trova nella casella: %d.\n", pos_2);

            if (pos_2 >= POS_MAX)
            {
                pos_2 %= POS_MAX;
                puts("Giocatore 2 e' passato per il via e ritira 20 euro");
                balance_2 += 20;
            }else if (pos_2 == 19)
            {
                puts("Giocatore 2 va' in prigione (casella 9) e salta un turno");
                pos_2 = 9;
                salta_turno_2 = 1;
            }else if (pos_2 == 29)
                puts("Giocatore 2 si trova sul transito libero, il suo saldo non subira' variamenti");
            else
            {
                int indice_2 = pos_2 % 10;
                effetto = pattern[indice_2];
                if (effetto < 0)
                    printf("Giocatore 2 perde %d euro dal saldo.\n", pattern[indice_2]);
                else
                    printf("Giocatore 2 guadagna %d euro.\n", pattern[indice_2]);

                balance_2 += effetto;
            }

            printf("Saldo attuale Giocatore 2: %d euro.\n", balance_2);
            if (balance_2 <= 0) {
                puts("Giocatore 2 e' andato in bancarotta!");
                break;
            }
        }
        //fine turno giocatore 2
        puts("");
    }

    puts("");
    puts(("------FINE PARTITA------"));
    printf("Saldo finale giocatore 1: %d.\n", balance_1);
    printf("Saldo finale giocatore 2: %d.\n", balance_2);

    if (balance_1 > balance_2)
        puts("Vince Giocatore 1.");
    else if (balance_2 > balance_1)
        puts("Vince Giocatore 2");
    else
        puts("Pareggio.");
    return 0;
}