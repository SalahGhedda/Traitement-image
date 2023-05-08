#ifndef ___M_NOYAU_CONVOLUTION___
#define ___M_NOYAU_CONVOLUTION___

#include<stdio.h>
#include<stdlib.h>
#include "m_tableau_2D.h"

typedef double** t_filtre;

t_filtre filtre_passe_haut()
{
	t_filtre filtre = creer_tableau_2D(3, 3);

	initialiser_tableau_2D(filtre, 3, 3, 1);

	filtre[1][1] = 4;

	return filtre;
}


t_filtre filtre_passe_bas()
{
	t_filtre filtre = creer_tableau_2D(3, 3);

	filtre[0][0] = 0;      filtre[0][1] = -1;             filtre[0][2] = 0;
	filtre[1][0] = -1;      filtre[1][1] = 5;             filtre[1][2] = -1;
	filtre[2][0] = 0;      filtre[2][1] = -1;             filtre[2][2] = 0;

	return filtre;
}

t_filtre filtre_moyenneur()
{
	t_filtre filtre = creer_tableau_2D(3, 3);

	float valeur = (1.0 / 9.0);
	initialiser_tableau_2D(filtre, 3, 3, valeur);

	return filtre;

}

t_filtre filtre_laplacien()
{
	t_filtre filtre = creer_tableau_2D(3, 3);

	initialiser_tableau_2D(filtre, 3, 3, 1);

	filtre[1][1] = -8;

	return filtre;
}

void detruire_filtre(t_filtre tableau, int nb_lingnes)
{
	detruire_tableau_2D(tableau, nb_lingnes);
}




#endif // !___M_NOYAU_CONVOLUTION___
