#include <iostream> // pour l'affichage


int main ()
{

    const std::string STOP = "stop"; // une constant pour la fin de saisi de note

    std::string saisie;

    bool fini = false;
	
	unsigned int taille = 2;
	unsigned int facteur = 1;
	unsigned int nombre_notes = 0;
    double* notes = new double [taille*facteur]; // double car on veut des virgules
												 // et on allou de la mémoire pour nos nombre

    std::cout << "Saisir notes : (" << STOP << " pour finir)" << std::endl;
    while ( not fini )
    {
        std::getline(std::cin, saisie);

        if ( saisie == STOP )
        {
            fini = true;
        }
        else
        {
            double note = std::stod(saisie);
			
			if ( nombre_notes >= (taille*facteur) )
			{
				facteur ++;
				double* temps = new double [taille*facteur]; // creation d'un tableau temporaire
				
				for (unsigned int i = 0 ; i < nombre_notes ; i ++ ) // copie des notes
				{
					temps[i] = notes[i];
				}
				
				delete [] notes; // on libère la memoire
				
				notes = temps;  // on met a jours les pointeur
			}
			notes[nombre_notes] = note;
			nombre_notes++;
            std::cout << " nouvelle note : " << note << std::endl;

        }
    }

    if ( nombre_notes > 0 )  // on ne veut pas faire de division par 0
    {
        std::cout << "la moyenne des notes suivantes : " << std::endl;
        double somme = 0;
        for (unsigned int i = 0 ; i < nombre_notes ; i ++ )
        {
            std::cout << notes[i] << std::endl;
            somme += notes[i];
        }
        std::cout << "est : " <<somme / nombre_notes << std::endl;
    }
    else
    {
        std::cout << "Vous n'avez pas saisi de note" << std::endl;
    }
    
    delete [] notes;
    return 0; // optionel pour dire que le programme c'est bien terminé
}
