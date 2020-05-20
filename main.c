#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define true 1
#define false 0

struct Personne{

    char Prenom[30] ;
    char Nom[30]  ;
    int   Age ;
    char Numero[7]  ;

};

void Saisir_N(int *N);
void Saisir(struct Personne Tab_P[] , int Taille);
void Affichage(struct Personne Tab_P[] ,int Taille);
void Enregistrer(struct Personne Tab_P[] ,int Taille);
void Menu();



int main()
{
    char choix;
    struct Personne P[100]  ;
    int est_rempli = false ;
     int N ;


   do
    {

     Menu();
     printf("\nEntrez votre choix : \n");
     scanf(" %c",&choix);

      switch(choix)
      {
      case '1':
          //Saisir
            Saisir_N(&N);
            Saisir(P ,N);
            est_rempli = true ;
        break;
      case '2':
          //Affichage
          if(est_rempli){
             Affichage(P ,N);
          }else{
              printf("\nThe table is empty.\n");
              printf("You Should fill the table : \n");
             Saisir_N(&N);
             Saisir(P ,N);
              Affichage(P ,N);
          }
        break;
      case '3':
          //Enregistrer
            if(est_rempli){
                 Enregistrer(P ,N);
                   printf("\nSaved !!.\n");
            }else{
                 printf("\nThe table is empty.\n");
            }

        break ;
      case '4':
          //Quitter
            printf("\n********  Merci ********\n");
        break;
      default :
          printf("Your choice is inrecognised !");
           break;
      }

    }while(choix != '4');

}



void Saisir(struct Personne Tab_P[] , int Taille){

for(int i = 0 ; i < Taille ; i++){
    printf("Entrer les informations de la personne %d : \n",i+1);
    printf("Entrer le Nom : \n ");
    scanf("%s",&Tab_P[i].Nom);
    printf("Entrer le Prenom : \n ");
    scanf("%s",&Tab_P[i].Prenom);
    printf("Entrer l' Age : \n ");
    scanf("%d",&Tab_P[i].Age);
    printf("Entrer le Numero : \n ");
    scanf("%s",&Tab_P[i].Numero);
}

}


void Affichage(struct Personne Tab_P[],int Taille){
   printf("\nLes informations des personnes sont :\n");
   for(int i=0 ; i < Taille ; i++){
        printf("\n************\n");
        printf("  ID : %s\n",Tab_P[i].Numero);
        printf("  Prenom : %s\n",Tab_P[i].Prenom);
        printf("  Nom : %s\n",Tab_P[i].Nom);
        printf("  Age : %d\n",Tab_P[i].Age);

   }

}

void Enregistrer(struct Personne Tab_P[],int Taille){

      FILE *fwrite ;
      fwrite = fopen("Informations.txt" ,"w");

      for(int i=0 ; i < Taille ; i++){
            fprintf(fwrite ,"ID : %s\n Prenom :  %s\n Nom : %s\n Age : %d\n ",Tab_P[i].Numero ,Tab_P[i].Prenom ,Tab_P[i].Nom ,Tab_P[i].Age );
      }

      fclose(fwrite);
}

void Menu()
{
     printf(" *****Menu*****\n\n ")  ;
     printf("1 - Saisir Personnes\n");
     printf("2 - Afficher Personnes\n");
     printf("2 - Afficher Personnes de l'age plus de 20 ans\n");
     printf("3 - Enregistrer\n");
     printf("4 - Quitter\n");
     printf("*******************\n");
}


void Saisir_N(int *N){
    do
        {
        printf("Entrer le nombre total de personnes : \n");
        scanf("%d",&*N);
        if(N <=0 || *N>=100)
           printf("Le nombre est invalide. Reessayer !!");
     }while(*N <= 0 || *N >= 100);
}





