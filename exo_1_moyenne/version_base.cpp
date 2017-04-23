#include <iostream> // pour l'affichage


int main ()
{

    const std::string STOP = "stop"; // une constant pour la fin de saisi de note

    std::string saisie;

    bool fini = false;
	double somme = 0;
	unsigned int nombre = 0;

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
            somme += note;
			nombre++;
            std::cout << " nouvelle note : " << note << std::endl;

        }
    }

    if ( nombre > 0 ) // les divisions par 0 c'est le mal
	{
        std::cout << "la moyenne des notes est : " << somme / nombre << std::endl;
    }
    else
    {
        std::cout << "Vous n'avez pas saisi de note" << std::endl;
    }
    return 0; // optionel pour dire que le programme c'est bien terminé
}
