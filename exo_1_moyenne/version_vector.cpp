#include <iostream> // pour l'affichage
#include <vector>   // pour les vectors \o/


int main ()
{

    const std::string STOP = "stop"; // une constant pour la fin de saisi de note

    std::string saisie;

    bool fini = false;
    std::vector<double> notes; // double car on veut des virgules

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
            notes.push_back(note);
            std::cout << " nouvelle note : " << note << std::endl;

        }
    }

    if ( notes.size() > 0 )  // on ne veut pas faire de division par 0
    {
        std::cout << "la moyenne des notes suivantes : " << std::endl;
        double somme = 0;
        for (unsigned int i = 0 ; i < notes.size() ; i ++ )
        {
            std::cout << notes[i] << std::endl;
            somme += notes[i];
        }
        std::cout << "est : " <<somme / notes.size() << std::endl;
    }
    else
    {
        std::cout << "Vous n'avez pas saisi de note" << std::endl;
    }
    return 0; // optionel pour dire que le programme c'est bien terminé
}
