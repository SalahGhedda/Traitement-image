#ifndef ___m_tableau_1D___
#define ___m_tableau_1D___

#include <stdlib.h>

void afficher_tableau_1D(double tableau[], int nb_element)
{
	for (int i = 0; i < nb_element; i++)
	{
		printf("%lf ", tableau[i]);
	}
	printf("\n");
}

double somme_tableau_1D(double tableau[], int nb_element)
{
	double somme = 0;
	int i = 0;

	while (i < nb_element)
	{
		somme += tableau[i];
		i++;
	}


	return somme;
}

void produit_tableau1D(double tableau[], int nb_element, double valeur)
{

	int i = 0;

	while (i < nb_element)
	{
		 tableau[i] = tableau[i] * valeur;

		i++;
	}
}

double produit_scalaire(double tableau1[], double tableau2[], int nb_element)
{
	double scalaire = 0;
	int i = 0;
	while ( i < nb_element)
	{
		scalaire += tableau1[i] * tableau2[i];

		i++;
	}


	return scalaire;
}

double* creer_tableau_1D(int nb_element)
{
	double* tableau = NULL;
	tableau = (double*) malloc(nb_element * sizeof(double));
	for(int i = 0; i < nb_element; i++)
	{
		tableau[i] = 0;
	}
	return tableau;
}

void detruire_tableau_1D(double* tableau)
{
	free(tableau);
}

#endif // !___m_tableau_1D___
