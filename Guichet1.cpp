/* Guichet1.cpp */
#include "Guichet1.hpp"
#include "Client.hpp"
#include<cstring>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

/**
 * @brief la fonction Servir ici fait quatre choses:
 * 			1. lire un fichier .csv
 * 			2. demander le valeur que notre client veut retirer
 * 			3. vérifier si le montant saitisfait
 * 			4. enregistrer le nouveau montant (ou pas) dans le fichier.
 * @param status: dès le service commence, faut le poser en faux et le changer juste après le travail fini
 * @param ss: pour changer le type entre stringstream et string
 * @param l : sert à lire ce qu'il insert au clavier
 * @param v : même fonction que ss
 * @param noClient : on prend le premier élément dans la queue
 *
 * @note il utilise find pour séparer la ligne de type string qui contient deux int et reliés par un virgule
 */

Guichet1::Guichet1()
    {   service = 1;
        status = true; };

void Guichet1::Servir(Client& c)
		{
			ifstream inFile("banque.csv", ios::in);

            string NewFile = "";/* pour enregistrer les nouveaux data*/
			string ligne;
			string l,nl,v;
			int v3,v1,v2;
			char p=',';

			cout << "Vous voulez retirer combient de l'argent ? " << endl;
			cin >> l;
			v1 = std::stoi(l);
			string noC = c.noClient;
			while (getline(inFile, ligne))
			{
				int i =ligne.find(p);
				string e1=ligne.substr(0,i);
				string e2=ligne.substr(i+1,20);
				if(e1 == noC)/* en cas qu'on a trouvé la ligne*/
				{
                    v2 = std::stoi(e2);
					while (v2-v1 < 0)
                        {
                            cout << "Vous n'avez pas assez d'argent, veuillez rechoisir \n " << endl;
                            cin >> l;
                            v1 = std::stoi(l);}
                    v3 = v2 - v1;
                    v = to_string(v3);
                    nl = e1 + "," +v ;
                    NewFile += nl;
                    NewFile += "\n";
					}
                else /* en cas où ce n'est pas la ligne qu'on cherche*/
                    {NewFile += ligne;
					 NewFile += "\n";}
			}
			inFile.close();

			/* écrire dans le ficher les nouveaux datas */
			ofstream outFile("banque.csv", ios::out);
			outFile.flush();
			outFile << NewFile;
			outFile.close();

			};
Guichet1::~Guichet1()
    { };

/* end of Guichet1.cpp */
