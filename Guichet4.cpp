/* Guichet4.cpp */
#include "Guichet4.hpp"
#include "Client.hpp"
#include<cstring>
#include<string>
#include<iostream>
#include<fstream>


using namespace std;

/**
 * @brief la fonction Servir ici fait trois choses:
 * 			1. lire un fichier .csv
 * 			2. demander les informations de colis et du personne qui va le recevoir
 * 			3. enregistrer les nouveaux infos
 * @param status: dès le service commence, faut le poser en faux et le changer juste après le travail fini
 * @param l : sert à lire ce qu'il insert au clavier
 * @param noClient : on utilise son noClient comme le numéro de colis
 *
 * @note il utilise find pour séparer la ligne de type string qui contient deux int et reliés par un virgule
 */

Guichet4::Guichet4()
    {   service = 4;
        status = true; };

void Guichet4::Servir(Client& c)
		{
			string res;
			ifstream inFile("post.csv", ios::in);

            string NewFile = "";/* pour enregistrer les nouveaux data*/
			string ligne,l,v;
			int i,j;
			char p = ',';
			string noC = c.noClient;

			while (getline(inFile, ligne))
			{
				i =ligne.find(p);
				string e=ligne.substr(0,i);
				j = std::stoi(e);
				NewFile += ligne;
				NewFile += "\n";
			}
			inFile.close();
			
			j = j+1; /* définir le noClient */
			v = to_string(j);
			c.setNo(v);
            cout << "Veuillez insérer votre nom, prénom et la date d'aujourd'hui (jjmmaaaa) sans space, par exemple : MD01012001 \n" << endl;
			cin >> l; /* définir le numéro de colis*/
			ligne = v + l;
			cout << "Voici votre noClient et numéro de colis : " + ligne << endl;
			NewFile += ligne;
			NewFile += "\n";

			/* écrire dans le ficher les nouveaux datas */
			ofstream outFile("post.csv", ios::out);
			outFile.flush();
			outFile << NewFile;
			outFile.close();
            cout << "C'est fait !  \n" << endl;
			};



Guichet4::~Guichet4()
    {};
/* end of Guichet4.cpp */
