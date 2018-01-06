#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "stringFunctions.h"
#include "loadWord.h"
//A
using namespace std;
int main() {
	bool win; //Utilisée pour déterminer si on a gagné | Pour déterminer si on continue de jouer
	int tries;
	string mot, input; //Mot mystère | Utilisée pour stocker la saisie de l'utilisateur
	srand(time(0)); //Initialisation de la génération de nombre aléatoires

	do {
		//Définition du mot à deviner
		win = false;
		tries = 5;
		cout << "Entrez le mot a deviner : ";
		cin >> mot;
		upperString(mot); //On met en majuscules pour mieux le comparer avec d'autres strings

		//Mélange des lettres du mot
		string motMelange(mot);
		for (int i(0); i < mot.size(); i++)
			swapChars(motMelange, rand() % mot.size(), rand() % mot.size());

		do {
			//Demander de deviner le mot mystère tant qu'on l'a pas trouvé
			cout << motMelange << endl;
			cout << "Nombre d'essais restants: " << tries << endl << "Essayez de deviner le mot mystere: ";
			cin >> input; 
			upperString(input); //On met en majuscules pour mieux le comparer avec d'autres strings

			if (input == mot)
				win = true;

		} while (!win && --tries > 0);

		if (win)
			cout << "Vous avez gagne !" << endl;
		else
			cout << "Vous avez depasse la limite des essais, dommage !" << endl;

	} while (askClosed("Voulez vous recommencer ?", "Entrez O ou N", "o", "n"));
	
	system("PAUSE");
	return 0;
}