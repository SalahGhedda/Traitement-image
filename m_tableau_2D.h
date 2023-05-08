#ifndef ___M_TABLEAU_2D___
#define ___M_TABLEAU_2D___

#include<stdio.h>
#include<math.h>
#include "m_tableau_1D.h"

void afficher_tableau_2D(double** tableau, int nb_lignes, int nb_colonnes)
{
	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			printf("%lf ", tableau[i][j]);

		}
		printf("\n");
	}
}

double** creer_tableau_2D(int nb_lignes, int nb_colonnes)
{
	double** tableau = (double**)malloc(nb_lignes * sizeof(double*));
	for (int i = 0; i < nb_lignes; i++)
	{
		tableau[i] = (double*)malloc(nb_colonnes * sizeof(double));

		for (int j = 0; j < nb_colonnes; j++)
		{
			tableau[i][j] = 0;
		}
	}

	return tableau;
}

double** initialiser_tableau_2D(double** tableau, int nb_lignes, int nb_colonnes, double valeur)
{

	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			tableau[i][j] = valeur;
		}
	}

	return tableau;
}

double somme_tableau_2D(double** tableau, int nb_lignes, int nb_colonnes)
{
	double somme = 0;
	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			somme = somme + tableau[i][j];

		}
	}
	return somme;
}

void produit_par_scalaire(double** tableau, double valeur, int nb_lignes, int nb_colonnes)
{

	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			tableau[i][j] = tableau[i][j] * valeur;

		}
	}
}

void puissance_tableau_2D(double** tableau, double puissance, int nb_lignes, int nb_colonnes)
{
	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			tableau[i][j] = pow(tableau[i][j], puissance);

		}
	}
}

double** produit_tableau_2D(double** tableau1, double** tableau2, int nb_lignes, int nb_colonnes)
{
	double** resultat = creer_tableau_2D(nb_lignes, nb_colonnes);
	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			resultat[i][j] = tableau1[i][j] * tableau2[i][j];
		}
	}

	return resultat;

}

void detruire_tableau_2D(double** tableau, int nb_lignes)
{
	for (int i = 0; i < nb_lignes; i++)
	{
		free(tableau[i]);
	}

	free(tableau);
}

double* sommes_des_colonnes(double** tableau, int nb_lignes, int nb_colonnes)
{
	double* resultat = creer_tableau_1D(nb_lignes);

	for (int i = 0; i < nb_lignes; i++)
	{
		resultat[i] = 0;
	}


	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			resultat[i] += tableau[i][j];

		}

	}
	return resultat;
}

double* sommes_des_lignes(double** tableau, int nb_lignes, int nb_colonnes)
{
	double* resultat = creer_tableau_1D(nb_colonnes);

	for (int j = 0; j < nb_colonnes; j++)
	{
		resultat[j] = 0;
	}

	for (int j = 0; j < nb_colonnes; j++)
	{
		for (int i = 0; i < nb_lignes; i++)
		{
			resultat[j] += tableau[i][j];

		}

	}
	return resultat;

}

double** sous_tableau(double** tableau, int nb_lignes, int nb_colonnes, int debut_ligne, int debut_colonne, int taille_ligne, int taille_colonne)
{
	double** section_tableau = creer_tableau_2D(taille_ligne, taille_colonne);

	for (int i = 0; i < taille_ligne; i++) //addition
	{
		for (int j = 0; j < taille_colonne; j++) //adition
		{
			section_tableau[i][j] = tableau[debut_ligne + i] [debut_colonne + j]; //soustartion

		}
	}
	return section_tableau;
}


#endif // !___M_TABLEAU_2D___
