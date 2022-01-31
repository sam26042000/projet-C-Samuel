//structures de donnees

struct Etudiant {
    char nom[20];
    char prenom[20];
    char sexe;
    int age;
    float *notes;
    float moyenne;
};

typedef struct Etudiant* Filiere;

//declaration de fonctions
int aficherMenu();
void calculMoyenne(Filiere, int, int);
void afficherMoyenneEtudiant(Filiere, int);
Filiere obtenirListeOrdonneEtudiant(Filiere, int);
float moyenneDeLaSalle(Filiere, int);
int obtenirMeileureMoyenne(Filiere, int);

//definition de fonctions
int afficherMenu() {
    int choix;

    printf("+-------------------------------- MENU --------------------------------+\n\n");
    printf("  1: Afficher les moyennes de chaque etudiant \n");
    printf("  2: Afficher les moyennes de chaque etudiant par ordre d'excellence\n");
    printf("  3: Afficher la moyenne de la salle \n");
    printf("  4: Afficher les moyennes des trois meilleurs etudiants \n");
    printf("  5: Afficher l'etudiant ayant la meilleure moyenne \n");
    printf("  0: Sortir \n\n");
    printf("+----------------------------------------------------------------------+\n\n");

    printf("Faites un choix entre 0 et 5 : ");
    scanf("%d", &choix);

    return choix;
};

calculMoyenne(Filiere filiere, int effectif, int nombreMatiere) {
    for(int i = 0; i < effectif; i++) {
        float average = 0;
        for(int j = 0; j < nombreMatiere; j++) {
            average += *((filiere[i].notes)+j);
        }
        filiere[i].moyenne = average / nombreMatiere;
    }
};

afficherMoyenneEtudiant(Filiere filiere, int effectif) {
    for(int i = 0; i < effectif; i++) {
        printf("%s %s ------> %f\n", filiere[i].nom, filiere[i].prenom, filiere[i].moyenne);
    };
};

Filiere obtenirListeOrdonneEtudiant(Filiere filiere, int effectif) {
    struct Etudiant temp;
    Filiere newFiliere;
    int max;
    newFiliere = (Filiere)malloc(effectif * sizeof(struct Etudiant));

    for(int i = 0; i < effectif; i++) {
        newFiliere[i] = filiere[i];
    };

    for(int i = 0; i < effectif-1; i++) {
        max = i;
        for(int j = i; j < effectif; j++) {
            if(newFiliere[j].moyenne > newFiliere[max].moyenne) {
                max = j;
            }
        };
        temp = newFiliere[max];
        newFiliere[max] = newFiliere[i];
        newFiliere[i] = temp;
    };

    return newFiliere;
};

float moyenneDeLaSalle(Filiere filiere, int effectif) {
    float somme = 0;
    for(int i = 0; i < effectif; i++) {
        somme += filiere[i].moyenne;
    };
    return somme / effectif;
};

int obtenirMeileureMoyenne(Filiere filiere, int effectif) {
    int max = 0;
    for(int i = 1; i < effectif; i++) {
        if(filiere[i].moyenne > filiere[max].moyenne) {
            max = i;
        }
    };
    return max;
}
