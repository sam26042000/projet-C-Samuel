#include <stdio.h>
#include <stdlib.h>
#include "function.h"

//declaration des fonctions


int main()
{
    //choix des variables
    int choix, effectif, nombreMatiere;
    char nomFiliere[20];

    //obtenir les informations de la filière
    printf("\nnom de la filiere : ");
    scanf("%s", &nomFiliere);

    printf("\nnombre d'etudiants de la filiere : ");
    scanf("%d", &effectif);

    printf("\nnombre de matieres de la filiere : ");
    scanf("%d", &nombreMatiere);

    //instancier la filiere
    Filiere filiere;
    filiere = (Filiere)malloc(effectif * sizeof(struct Etudiant));

    //enregistrer les etudiants
    for(int i = 0; i < effectif; i++) {
        printf("\nSaisie de l'etudiant numero %d\n", i+1);
        printf("Entrer le nom : ");
        scanf("%s", &filiere[i].nom);
        printf("Entrer le prenom : ");
        scanf("%s", &filiere[i].prenom);
        printf("Entrer le sexe : ");
        scanf("%s", &filiere[i].sexe);
        printf("Entrer l'age de l'etudiant: ");
        scanf("%d", &filiere[i].age);

        float *notes;
        notes = (float*)malloc(nombreMatiere * sizeof(float));

        for(int j = 0; j < nombreMatiere; j++) {
            printf("Entrer la note_%d: ", j+1);
            scanf("%f", &notes[j]);
        }

        filiere[i].notes = notes;

    }


    //afficher les informations de la filière
    printf("\n+----------------------------------------------------------------------+\n");
    printf("Filiere = %s\n", nomFiliere);
    printf("Effectif = %d\n", effectif);
    printf("Nombre de matieres = %d\n", nombreMatiere);
    printf("+----------------------------------------------------------------------+\n");
    printf("\n");

    //Calcul de moyennes
    calculMoyenne(filiere, effectif, nombreMatiere);

    Filiere newFiliere = obtenirListeOrdonneEtudiant(filiere, effectif);

    //gestion des choix du menu
    do {
        choix = afficherMenu();

        switch(choix) {
            case 1: printf("\v--------------MOYENNE DE CHAQUE ETUDIANT-------------\n");
                    afficherMoyenneEtudiant(filiere, effectif);
                    break;
            case 2: printf("\v-------MOYENNE DE CHAQUE ETUDIANT PAR ORDRE D'EXCELLENCE------\n");
                    afficherMoyenneEtudiant(newFiliere, effectif);
                    break;
            case 3: printf("\v--------------MOYENNE DE LA SALLE-------------\n");
                    printf("moyenne ------> %f\n", moyenneDeLaSalle(filiere, effectif) );
                    break;
            case 4: printf("\v-------MOYENNES DES TROIS MEILLEURS ETUDIANTS------\n");
                    int nombreAffichage = effectif;
                    if(effectif >= 3)
                        nombreAffichage = 3;
                    afficherMoyenneEtudiant(newFiliere, nombreAffichage);
                    break;
            case 5: printf("\v-------ETUDIANT AYANT LA MEILLEURE MOYENNE------\n");
                    int max = obtenirMeileureMoyenne(filiere, effectif);
                    printf("%s %s ------> %f\n", filiere[max].nom, filiere[max].prenom, filiere[max].moyenne);
                    break;
            case 0: printf("Au revoir !!!\n"); exit(1);
                    break;
            default: printf("Saisie erronee, veuillez reessayer\n");
                     break;
        };

    } while(choix != 0);


    free(filiere);
    free(newFiliere);

    return 0;
}
