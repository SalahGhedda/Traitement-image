
#include <stdio.h>
#include <stdlib.h>

#include "m_bitmap.h"
#include "m_tableau_1D.h"
#include "m_tableau_2D.h"
#include "m_noyau_convolution.h"
#include "m_image_gris.h"

void executer_test_tableau_1D();
void executer_test_tableau_2D();
void executer_test_noyau();
void executer_test_image_gris();


int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);


	//------------------------------------------------------------//

	executer_test_image_gris();


    return EXIT_SUCCESS;
}

void executer_test_tableau_1D()
{
	double tableau1[5] = { 1, 2, 3, 4, 5 };
	double tableau2[5] = { 1.1, 2.5, 3.0, 4.25, 5.123 };
	double tableau3[5] = { 1.0, 1.0, 1.0, 1.0, 1.0 };
	double tableau4[5] = { 1, 2, 3, 4, 5 };
	double tableau5[5] = { 1.5, 2.0, 1.25, 0.5, 0 };
	double tableau6[5] = { 0 };

	double somme1;
	double somme2;
	double somme3;

	double scalaire1;
	double scalaire2;

	printf("***************************************************\n");
	printf("FONCTION AFFICHAGE\n");

	afficher_tableau_1D(tableau1, 5);
	afficher_tableau_1D(tableau2, 5);
	afficher_tableau_1D(tableau3, 5);
	afficher_tableau_1D(tableau4, 5);
	afficher_tableau_1D(tableau5, 5);
	afficher_tableau_1D(tableau6, 5);

	printf("\n\n");
	printf("FONCTION SOMME\n");

	somme1 = somme_tableau_1D(tableau1, 5);
	somme2 = somme_tableau_1D(tableau2, 5);
	somme3 = somme_tableau_1D(tableau2, 0);

	printf("%lf\n", somme1);
	printf("%lf\n", somme2);
	printf("%lf\n", somme3);


	//Le test qui doit faire les printf ou appel a la fonction afficher.

	printf("\n\n");
	printf("FONCTION PRODUIT\n");

	produit_tableau1D(tableau1, 5, 5);
	afficher_tableau_1D(tableau1, 5);
	produit_tableau1D(tableau2, 5, 0.10);
	afficher_tableau_1D(tableau2, 5);
	produit_tableau1D(tableau3, 3, 0);
	afficher_tableau_1D(tableau3, 5);

	//Le test qui doit faire les printf ou appel a la fonction afficher.

	printf("\n\n");
	printf("FONCTION PRODUIT SCALAIRE\n");

	scalaire1 = produit_scalaire(tableau4, tableau5, 5);
	scalaire2 = produit_scalaire(tableau2, tableau3, 5);

	printf("%lf\n", scalaire1);
	printf("%lf\n", scalaire2);

	printf("**************************************************************\n");
}

 void executer_test_tableau_2D()
{

	double somme;
	double somme2;

	printf("TEST TABLEU 2D\n");

	double** tableau1 = creer_tableau_2D(3, 2);
	double** tableau2 = creer_tableau_2D(3, 4);
	double** tableau3 = creer_tableau_2D(3, 2);
	double** tableau4 = NULL;
	double* tableau5 = NULL;

	//tableau 1
	tableau1[0][0] = 1;      tableau1[0][1] = 2;
	tableau1[1][0] = 4;      tableau1[1][1] = 5;
	tableau1[2][0] = 7;      tableau1[2][1] = 8;


	//tableau 2
	tableau2[0][0] = 1.1;      tableau2[0][1] = 2.1;      tableau2[0][2] = 3.1;      tableau2[0][3] = 0.25;
	tableau2[1][0] = 4.1;      tableau2[1][1] = 5.1;      tableau2[1][2] = 6.1;      tableau2[1][3] = 0.33;
	tableau2[2][0] = 7.1;      tableau2[2][1] = 8.1;      tableau2[2][2] = 9.1;      tableau2[2][3] = 0.80;


	//tableau 3
	tableau3[0][0] = 0.25;      tableau3[0][1] = 0.5;
	tableau3[1][0] = 0.75;      tableau3[1][1] = 1.0;
	tableau3[2][0] = 0.33;      tableau3[2][1] = 0.66;

	printf("T1: \n");
	afficher_tableau_2D(tableau1, 3, 2);
	printf("\n\n");

	printf("T2: \n");
	afficher_tableau_2D(tableau2, 3, 4);
	printf("\n\n");

	printf("T3: \n");
	afficher_tableau_2D(tableau3, 3, 2);
	printf("\n\n");

	printf("FONCTION SOMME\n");

	somme = somme_tableau_2D(tableau1, 3, 2);
	printf("somme T1 : %lf\n", somme);
	somme2 = somme_tableau_2D(tableau2, 3, 4);
	printf("somme T2 : %lf\n\n", somme2);

	printf("FONCTION PRODUIT SCALAIRE\n");

	produit_par_scalaire(tableau1, 0.1, 3, 2);
	printf("T1 \n");
	afficher_tableau_2D(tableau1, 3, 2);
	printf("\n");

	produit_par_scalaire(tableau2, 10, 3, 4);
	printf("T2 \n");
	afficher_tableau_2D(tableau2, 3, 4);
	printf("\n\n");


	printf("FONCTION PUISSANCE\n");
	puissance_tableau_2D(tableau1, 2, 3, 2);
	printf("T1 \n");
	afficher_tableau_2D(tableau1, 3, 2);
	printf("\n");

	puissance_tableau_2D(tableau2, 0.5, 3, 4);
	printf("T2 \n");
	afficher_tableau_2D(tableau2, 3, 4);
	printf("\n\n");


	printf("FONCTION PRODUIT\n");

	tableau4 = produit_tableau_2D(tableau1, tableau3, 3, 2);
	afficher_tableau_2D(tableau4, 3, 2);
	detruire_tableau_2D(tableau4, 3);
	printf("\n\n");

	printf("FONCTION SOMMES DES COLONNES\n");
	tableau5 = sommes_des_colonnes(tableau2, 3, 4);
	afficher_tableau_1D(tableau5, 3);
	detruire_tableau_1D(tableau5);
	printf("\n\n");

	printf("FONCTION SOMMES DES LIGNES\n");
	//var = fct();
	tableau5 = sommes_des_lignes(tableau2, 3, 4);
	//afficher(var)
	//detruire(var)
	afficher_tableau_1D(tableau5, 4);
	detruire_tableau_1D(tableau5);
	printf("\n\n");

	printf("FONCTION SOUS-TABLEAU\n");
	tableau4 = sous_tableau(tableau2, 3, 4, 0, 0, 1, 3);
	afficher_tableau_2D(tableau4, 1, 3);
	detruire_tableau_2D(tableau4, 1);
	printf("\n");

	tableau4 = sous_tableau(tableau2, 3, 4, 1, 2, 2, 1);
	afficher_tableau_2D(tableau4, 2, 1);
	detruire_tableau_2D(tableau4, 2);
	printf("\n");

	tableau4 = sous_tableau(tableau2, 3, 4, 1, 1, 2, 2);
	afficher_tableau_2D(tableau4, 2, 2);
	detruire_tableau_2D(tableau4, 2);

}

void executer_test_noyau()
{
	t_filtre tableau1 = filtre_passe_haut();
	afficher_tableau_2D(tableau1, 3, 3);
	printf("\n\n");

	t_filtre tableau2 = filtre_passe_bas();
	afficher_tableau_2D(tableau2, 3, 3);
	printf("\n\n");

	t_filtre tableau3 = filtre_moyenneur();
	afficher_tableau_2D(tableau3, 3, 3);
	printf("\n\n");

	t_filtre tableau4 = filtre_laplacien();
	afficher_tableau_2D(tableau4, 3, 3);
	printf("\n\n");

	detruire_filtre(tableau1, 3);
	detruire_filtre(tableau2, 3);
	detruire_filtre(tableau3, 3);
	detruire_filtre(tableau4, 3);

}

void executer_test_image_gris()
{
	setvbuf(stdout, NULL, _IONBF, 0);

		void* 		image = 0;
		double** 	image_convertie;

		int nb_ligne;
		int nb_colone;
		double* tableau;


	    lire("images/plaque_test_1.bmp", &image, &nb_ligne, &nb_colone);
	    image_convertie = (double **) image;

		// Travailler sur image_convertie...

		image_convertie = negatif(image, nb_ligne, nb_colone);

		//On sauvgarde l'image modifiée sous un autre nom et on libère la mémoire utilisée.
		ecrire("resultat/resultat_negatif1.bmp", image_convertie, nb_ligne, nb_colone);
		detruire(image, nb_ligne, nb_colone);

		//--------------------------------------------------------------------//

		lire("images/plaque_test_2.bmp", &image, &nb_ligne, &nb_colone);
	    image_convertie = (double **) image;

	    image_convertie = negatif(image, nb_ligne, nb_colone);

	    ecrire("resultat/resultat_negatif2.bmp", image_convertie, nb_ligne, nb_colone);
	    detruire(image, nb_ligne, nb_colone);

	    //==============================================================//
	    lire("images/plaque_test_1.bmp", &image, &nb_ligne, &nb_colone);
	    image_convertie = (double **) image;

	    image_convertie = seuiller(image, nb_ligne, nb_colone, 0.5);

	    ecrire("resultat/resultat_seuil1.bmp", image_convertie, nb_ligne, nb_colone);
	    detruire(image, nb_ligne, nb_colone);
	    //-------------------------------------------------------------------//
	    lire("images/plaque_test_2.bmp", &image, &nb_ligne, &nb_colone);
	    image_convertie = (double **) image;

	    image_convertie = seuiller(image, nb_ligne, nb_colone, 0.25);

	    ecrire("resultat/resultat_seuil2.bmp", image_convertie, nb_ligne, nb_colone);
	    detruire(image, nb_ligne, nb_colone);
	    //==============================================================/

	    lire("images/plaque_test_1.bmp", &image, &nb_ligne, &nb_colone);
	    image_convertie = (double **) image;

	    tableau = histogramme(image, nb_ligne, nb_colone, 10);
	    afficher_tableau_1D(tableau, 10);

	    //------------------------------------------------------------------//

	    lire("images/plaque_test_1.bmp", &image, &nb_ligne, &nb_colone);
	    image_convertie = (double **) image;

	    tableau = histogramme(image, nb_ligne, nb_colone, 15);
	    afficher_tableau_1D(tableau, 15);


	    //==============================================================/


	    lire("images/plaque_test_1.bmp", &image, &nb_ligne, &nb_colone);
	   	image_convertie = (double **) image;


	   	double**  un_filtre = filtre_passe_bas();
	   	image_convertie = filtrer_image_gris (image, nb_ligne, nb_colone, un_filtre);

	    ecrire("resultat/resultat_passe_bas1.bmp", image_convertie, nb_ligne, nb_colone);
	    detruire(image, nb_ligne, nb_colone);

	    //-----------------------------------------------------------------------//

	    lire("images/plaque_test_2.bmp", &image, &nb_ligne, &nb_colone);
	    image_convertie = (double **) image;


	    un_filtre = filtre_passe_haut();
	    image_convertie = filtrer_image_gris (image, nb_ligne, nb_colone, un_filtre);

	    ecrire("resultat/resultat_passe_haut2.bmp", image_convertie, nb_ligne, nb_colone);
	    detruire(image, nb_ligne, nb_colone);

	    //--------------------------------------------------------------------------------//

	    lire("images/plaque_test_1.bmp", &image, &nb_ligne, &nb_colone);
	    image_convertie = (double **) image;

	    image_convertie = seuiller(image, nb_ligne, nb_colone, 0.5);

	    un_filtre = filtre_laplacien();
	    image_convertie = filtrer_image_gris(image_convertie, nb_ligne, nb_colone, un_filtre);
	    image_convertie = negatif(image_convertie, nb_ligne, nb_colone);

	    ecrire("resultat/resultat_laplacien1.bmp", image_convertie, nb_ligne, nb_colone);
	    detruire(image, nb_ligne, nb_colone);

	    //-------------------------------------------------------------------------------------//

	    lire("images/plaque_test_2.bmp", &image, &nb_ligne, &nb_colone);
	    image_convertie = (double **) image;

	    image_convertie = seuiller(image, nb_ligne, nb_colone, 0.25);

	    un_filtre = filtre_laplacien();
	    image_convertie = filtrer_image_gris (image, nb_ligne, nb_colone, un_filtre);

	    ecrire("resultat/resultat_laplacien2.bmp", image_convertie, nb_ligne, nb_colone);
	    detruire(image, nb_ligne, nb_colone);
}
