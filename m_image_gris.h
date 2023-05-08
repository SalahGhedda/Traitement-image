#ifndef ___M_IMAGE_GRIS___
#include "m_noyau_convolution.h"
#include "m_tableau_1D.h"
#include "m_tableau_2D.h"
#include <stdio.h>
#include <stdlib.h>


double** t_image_gris;

double** negatif(double** une_image,int nb_lignes,int nb_colonnes)
{

	for(int j = 0; j < nb_colonnes; j++)
	{
		for(int i = 0; i < nb_lignes; i++)
		{
			une_image[i][j] = 1 - une_image[i][j];
		}

	}

	return une_image;
}

double** seuiller(double** une_image,int nb_lignes,int nb_colonnes,double seuil)
{
	for(int j = 0; j < nb_colonnes; j++)
		{
			for(int i = 0; i < nb_lignes; i++)
			{
				if(une_image[i][j] >= seuil)
				{
					une_image[i][j] = 1;
				}
				else if(une_image[i][j] < seuil)
				{
					une_image[i][j] = 0;
				}
			}
		}

     return une_image;
}

double* histogramme(double** une_image,int nb_lignes,int nb_colonnes,int nb_classes)
{
	double* tableau = creer_tableau_1D(nb_classes);


	for(int k = 0; k < nb_classes + 1; k++)
	  {
		for(int i = 0; i < nb_lignes; i++)
			{
				for(int j = 0; j < nb_colonnes; j++)
				{

					if (k > 1)
					{
						if(une_image[i][j] <= k * (1.0 /  nb_classes) && une_image[i][j] > (k - 1) * (1.0 /  nb_classes))
						{
					  		tableau[k - 1] += 1;
					  	}
					}

			    }
			}
	 }

	return tableau;
}

double** filtrer_image_gris (double** une_image,int nb_lignes,int nb_colonnes,double** un_filtre)
{
	double** image_filtree = creer_tableau_2D(nb_lignes, nb_colonnes);
	double** tableau_source = creer_tableau_2D(3, 3);
	double** tableau_produit = creer_tableau_2D(3, 3);


	for(int j = 0; j < nb_colonnes - 2; j++)
	{
		for(int i = 0; i < nb_lignes - 2; i++)
		{
			tableau_source = sous_tableau(une_image, nb_lignes, nb_colonnes, i, j, 3, 3);
			tableau_produit = produit_tableau_2D(tableau_source, un_filtre, 3, 3);

			image_filtree[i + 1][j + 1] = somme_tableau_2D(tableau_produit, 3, 3);
		}
	}

	return image_filtree;
}



#endif // !___M_IMAGE_GRIS___
