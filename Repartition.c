#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//execution => Repartition [nb tour] [val min tentative] [afficher tab : 1]

int main(int argc, char * argv[]){
    int nJour = 5;
    char eleve_tab [10] = {'A','B','C','D','E','F','G','H','I','J'};
    char tables_tab [nJour][10];
    char jours[5][10] = {"Lundi----", "Mardi----", "Mercredi-", "Jeudi----", "Vendredi-"};
    srand( time( NULL ) );
    int randN = 0;
    int valide = 1;
    int fin = 0;
    int essai = 0;
    int tentative = 0;

    for(int z=0; z<atoi(argv[1]); z++){

        tentative = 0;
        do{
            fin=1;


            for(int l=0; l<nJour; l++){
                for(int k=0; k<10; k++){
                    tables_tab[l][k] ='Z';
                }
            }

            for(int j=0; j<nJour; j++){
                for(int i=0; i<10; i++){
                    
                    essai = 0;
                    do{
                        valide = 1;
                        randN = rand() % 10;

                        for(int k=0; k<nJour; k++){//pas 2 fois meme sur une colonne
                            if(tables_tab[k][i] == eleve_tab[randN]){
                                valide = 0;
                            }
                        }

                        for(int k=0; k<10; k++){
                            if(tables_tab[j][k] == eleve_tab[randN]){
                                valide = 0;
                            }
                        }

                        

                        //printf("j=%d, i=%d, v=%d, lettre=%c, fin=%d, e=%d\n", j, i, valide, eleve_tab[randN], fin, essai);

                        essai++;

                    }while(valide != 1 && essai<20);


                    tables_tab[j][i] = eleve_tab[randN];

                    for(int k=0; k<10; k++){//pas 2 fois le meme sur une ligne
                        for(int l=10; l<k+1; l--){
                            if(tables_tab[j][l] == tables_tab[j][k]){
                                fin = 0;
                            }
                        }
                    }
                }
            }

            if(essai == 19){
                fin = 0;
            }

            tentative++;
        }while(fin != 1);
    

        if(atoi(argv[3]) == 1){ //affichage du tableau seulement si on choisi 1
            for(int l=0; l<nJour; l++){
                printf("%s ",jours[l]);

                printf("Table 1 : |");
                printf("%c,",tables_tab[l][0]);
                printf("%c|",tables_tab[l][1]);

                printf(" Table 2 : |");
                printf("%c,",tables_tab[l][2]);
                printf("%c,",tables_tab[l][3]);
                printf("%c,",tables_tab[l][4]);
                printf("%c|",tables_tab[l][5]);

                printf(" Table 3 : |");
                printf("%c,",tables_tab[l][6]);
                printf("%c,",tables_tab[l][7]);
                printf("%c,",tables_tab[l][8]);
                printf("%c|",tables_tab[l][9]);

                printf("\n");
            }
            printf("\n");
        }

        if(tentative > atoi(argv[2]) ){
            printf("test %d, Tentatives : %d\n", z, tentative);
        }

       // printf("test %d, Tentatives : %d\n", z, tentative);
        

    }//fin big for
}//fin main

