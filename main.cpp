#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "stringFunctions.h"
#include "loadWord.h"

using namespace std;
int main() {
	bool win; //Utilisée pour déterminer si on a gagné | Pour déterminer si on continue de jouer
	int tries;
	string mot, input, playerMode; //Mot mystère | Utilisée pour stocker la saisie de l'utilisateur
	vector<string> words; //Contiendra les mots si le joueur joue seul
	srand(time(0)); //Initialisation de la génération de nombre aléatoires

	if (askClosed("(S)ingle player or (M)ultiplayer ?", "Entrez S ou M", "S", "M")) //Utilisation un peu alternatif de la fonction
		playerMode = "SP";
	else
		playerMode = "MP";

	if (playerMode == "SP") {//Chargement du fichier
		cout << "Chargement des mots..." << endl;
		loadWords("dico.txt", words);
	}

	do {
		win = false;
		tries = 5;

		//Définition du mot à deviner
		if (playerMode == "MP") {
			cout << "Entrez le mot a deviner : ";
			cin >> mot;
		}
		else {
			mot = getWord(words);
		}

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