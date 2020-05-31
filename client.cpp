#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
#include<fstream>
#include<thread>
#include<vector>
#include "Client.hpp"
#include "Guichet1.hpp"
#include "Guichet2.hpp"
#include "Guichet3.hpp"
#include "Guichet4.hpp"
#include "QueueClient.hpp"


string run(Client cl, QueueClient qa, QueueClient qb, QueueClient qc, QueueClient qd, Guichet1 G1, Guichet2 G2, Guichet3 G3, Guichet4 G4)
{
Client c("",0);
string phrase;



if (cl.Service == 1) 
{
    if(G1.status)/*Cas où le guichet est disponible */
        {
		G1.traiter();
        if(!qc.queueClient.empty())/*cas où le queue n'est pas vide*/
          {
             qc.Ajouter(cl);/*push ce nouveau client à la fin de queue*/
             cl.Attendre();
             c = qc.getClient();
             while (!c.Status)/*Tant que le status du client est vrai, on le supprime sur le queue et prenons le prochain */
                {
                    qc.Avancer();
                    c = qc.getClient();
                }
            }
            else /*Cas où le queue est vide*/
            {   c = cl; }
        c.Traiter();/*changer le status du client au faux*/
        if (!qc.queueClient.empty())
            {qc.Avancer();}
        G1.Servir(c);
        phrase = "le client " + cl.noClient + " a fait retrait de l'argent ! \n" ;
        }
    else
        {   cl.Attendre();
            qc.Ajouter(cl);
            }; 
    G1.disponible();
 }

if (cl.Service == 2) 
{
    if(G2.status)/*Cas où le guichet est disponible */
        {
		G2.traiter();
        if(!qc.queueClient.empty())/*cas où le queue n'est pas vide*/
          {
             qc.Ajouter(cl);/*push ce nouveau client à la fin de queue*/
             cl.Attendre();
             c = qc.getClient();
             while (!c.Status)/*Tant que le status du client est vrai, on le supprime sur le queue et prenons le prochain */
                {
                    qc.Avancer();
                    c = qc.getClient();
                }
            }
            else /*Cas où le queue est vide*/
            {   c = cl; }
        c.Traiter();/*changer le status du client au faux*/
        if (!qc.queueClient.empty())
            {qc.Avancer();}
        G2.Servir(c);
        phrase = "le client " + cl.noClient + " a fait déposé de l'argent ! \n" ;
        }
    else
        {   cl.Attendre();
            qc.Ajouter(cl);
            };
    G2.disponible();
}
if (cl.Service == 3) 
{
    if(G3.status)/*Cas où le guichet est disponible */
        {
		G3.traiter();
        if(!qc.queueClient.empty())/*cas où le queue n'est pas vide*/
          {
             qc.Ajouter(cl);/*push ce nouveau client à la fin de queue*/
             cl.Attendre();
             c = qc.getClient();
             while (!c.Status)/*Tant que le status du client est vrai, on le supprime sur le queue et prenons le prochain */
                {
                    qc.Avancer();
                    c = qc.getClient();
                }
            }
            else /*Cas où le queue est vide*/
            {   c = cl; }
        c.Traiter();/*changer le status du client au faux*/
        if (!qc.queueClient.empty())
            {qc.Avancer();}
        G3.Servir(c);
        phrase = "le client " + cl.noClient + " a fait retrait du colis ! \n" ;
        }
    else
        {   cl.Attendre();
            qc.Ajouter(cl);
            };
    G3.disponible();
}
if (cl.Service == 4) 
{
   if(G4.status)/*Cas où le guichet est disponible */
        {
		G4.traiter();
        if(!qc.queueClient.empty())/*cas où le queue n'est pas vide*/
          {
             qc.Ajouter(cl);/*push ce nouveau client à la fin de queue*/
             cl.Attendre();
             c = qc.getClient();
             while (!c.Status)/*Tant que le status du client est vrai, on le supprime sur le queue et prenons le prochain */
                {
                    qc.Avancer();
                    c = qc.getClient();
                }
            }
            else /*Cas où le queue est vide*/
            {   c = cl; }
        c.Traiter();/*changer le status du client au faux*/
        if (!qc.queueClient.empty())
            {qc.Avancer();}
        G4.Servir(c);
        phrase = "le client " + cl.noClient + " a fait envoyer un colis ! \n" ;
        }
    else
        {   cl.Attendre();
            qc.Ajouter(cl);
            };
    G4.disponible();
}
    return phrase;

};



int main()
{
	Guichet1 g1;
    Guichet2 g2;
    Guichet3 g3;
    Guichet4 g4;
    QueueClient qc1,qc2,qc3,qc4;
	string l1,l2,p;
	int s;

    int socket_fd = socket(AF_INET, SOCK_STREAM,0);
    if(socket_fd == -1)
    {
        cout<<" Erreur  !"<<endl;
        exit(-1);
    }
    
    struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);
	addr.sin_addr.s_addr = INADDR_ANY;

    int res = connect(socket_fd,(struct sockaddr*)&addr,sizeof(addr));
    if(res == -1)
    {
        cout<<"Perdu de construire bind"<<endl;
        exit(-1);        
    }
    cout<<"bind avec succés !"<<endl;
    

	cout << "Votre numéro de client ? " << endl;
	cin >> l1;
	cout << "Vous voulez faire quel genre de service ? \n 1. Retirer de l'argent \n 2. Déposer de l'argent \n 3. Retirer un colis \n 4. Envoyer un colis \n" << endl;
	cin >> l2;
	s = std::stoi(l2);
	string l = l1+ " , " + l2;
	Client cl(l1,s);
	
	send(socket_fd,l.c_str(),sizeof(l),0);
	
	p = run(cl,qc1,qc2,qc3,qc4,g1,g2,g3,g4);
	
    send(socket_fd,p.c_str(),sizeof(p),0);
    
    close(socket_fd);
    return 0;
}
