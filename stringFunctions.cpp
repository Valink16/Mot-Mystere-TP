#include <ctype.h>
#include <iostream>
#include <string>

void upperString(std::string &str) {
	/*
	Change tous les charactères d'un str en majsucules
	VARS: 
		str: string à traîter
	*/
	for (unsigned int i(0); i < str.size(); i++) 
		str[i] = toupper(str[i]);
}

void swapChars(std::string &str, int p1, int p2) {
	/*
	la fonction modifie str en échangeant les valeurs de str[p1] et str[p2]
	VARS: 
		str: string à modifier
		p1: indice du premier caractère
		p1: indice du deuxième caractère
	*/
	char tmp(str[p1]);
	str[p1] = str[p2];
	str[p2] = tmp;
}

bool askClosed(std::string str, std::string errStr, std::string positive, std::string negative) {
	/*
	Affiche la question str, retourne un bool en fonction de la réponse
	VARS:
		str: La question ("/!\ inclure un '?' ")
		errStr: Message à afficher quand l'utilisateur 
		positive: caractère à rentrer si on répond positivement à la question
		negative: même principe que positive
	*/
	std::string answer;
	upperString(positive); upperString(negative);

	do {
		std::cout << str << "( " << positive << " / " << negative << " )" << ": ";
		std::cin >> answer;
		upperString(answer);

		if (answer == positive)
			return true;
		else if (answer == negative)
			return false;
		else
			std::cout << errStr << std::endl;
	} while (true);
}