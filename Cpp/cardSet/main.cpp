#include <iostream>
#include "set.h"
int main()
{
   Jeu jeu = Jeu();
   Carte* cartes = jeu.getCartes();
   //Carte carte = Carte();
   std::cout<<*cartes[0].getCouleur();
}
