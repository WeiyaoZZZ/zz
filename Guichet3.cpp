/* Guichet3.cpp */
#include "Guichet3.hpp"
#include "Client.hpp"
#include<cstring>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

/**
 * @brief la fonction Servir ici fait 4 choses:
 * 			1. lire un fichier .csv
 * 			2. demander le numéro de colis
 * 			3. vérifier si le colis est bien ici
 * 			4. le supprime si le colis est retiré.
 * @param status: dès le service commence, faut le poser en faux et le changer juste après le travail fini
 * @param l : sert à lire ce qu'il insert au clavier
 * @param noClient : on utilise son noClient comme le numéro de colis
 *
 * @note il utilise find pour séparer la ligne de type string qui contient deux int et reliés par un virgule
 * @note il écrit "\n" sur la ligne pour supprimer cette ligne et dire que le colis est retirer
 */


Guichet3::Guichet3()
    {   service = 3;
        status = true;};

void Guichet3::Servir(Client& c)
		{
			ifstream inFile("post.csv", ios::in);

            string NewFile = "";/* pour enregistrer les nouveaux data*/
			string ligne;
			char p = ',';
			string noC = c.noClient;

			if (getline(inFile, ligne))
			{
				int i =ligne.find(p);
				string e1=ligne.substr(0,i);
				string e2=ligne.substr(i+1,20);
				if(e1 == noC)/* en cas qu'on a trouvé la ligne*/
				{
					cout << "Voici votre colis!"<< endl;
                    string nl = "\n";
                    NewFile += nl;
                    NewFile += "\n";
					}
                else /* en cas où ce n'est pas la ligne qu'on cherche*/
                    {
                        NewFile += ligne;
                        NewFile += "\n";}
			}
			else 
			{cout << "Il n'y a pas de votre colis "<< endl; ;}
			inFile.close();

			/* écrire dans le ficher les nouveaux datas */
			ofstream outFile("post.csv", ios::out);
			outFile.flush();
			outFile << NewFile;
			outFile.close();

			};



Guichet3::~Guichet3()
    {};
/* end of Guichet3.cpp */
