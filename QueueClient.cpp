/* QueueClient.cpp */
#include "QueueClient.hpp"
#include "Client.hpp"
#include<vector>
#include<string>
#include<iostream>

using namespace std;

/**
 * @brief AjouterClient sert à ajouter l'id du client à la fin du queue puis changer le nombre du clients
 *
 * @param nbClient: du type de int qui indique le nombre total des clients dans la queue
 * @param p: pour changer le type de noClient et le donner au num
 *
 * @note il utilise .c_str() pour changer le type de noClient aux const char*, puis strcpy pour copier ce que dans noClient au p sous un type de char*
 * @attention il est impossible de donner const char* au char* dans c++
 */


Client QueueClient::getClient()
    {   Client c("",0);
        c = queueClient.front();
        return c; };

void QueueClient::Ajouter(Client& cl)
    {   queueClient.push_back(cl); };

void QueueClient::Avancer()
    {   queueClient.erase(queueClient.begin()); };

QueueClient::~QueueClient()
    {};
/* end of QueueClient.cpp */
