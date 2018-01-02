#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "functions.h"

using namespace std;
int main() {
	bool win(false); //Utilisée pour déterminer si on a gagné
	string mot; //Mot mystère
	string input; //Utilisée pour stocker la saisie de l'utilisateur
	srand(time(0)); //Initialisation de la génération de nombre aléatoires

	//Définition du mot à deviner
	cout << "Entrez le mot a deviner : ";
	cin >> mot;
	upperString(mot); //On met en majuscules pour mieux le comparer avec d'autres strings
	
	//Mélange des lettres du mot
	string motMelange(mot);
	for (int i(0); i < mot.size(); i++) 
		swapChars(motMelange, rand() % mot.size(), rand() % mot.size());

	while (!win) {
		//Demander de deviner le mot mystère tant qu'on l'a pas trouvé
		cout << motMelange << endl;
		cout << "Essayez de deviner le mot mystere: ";
		cin >> input;
		upperString(input); //On met en majuscules pour mieux le comparer avec d'autres strings

		if (input == mot)
			win = true;
	}

	cout << "Vous avez gagne !" << endl;
	system("PAUSE");
	return 0;
}