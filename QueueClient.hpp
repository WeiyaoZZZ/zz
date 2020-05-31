/* QueueClient.hpp */
#ifndef QUEUECLIENT_HPP
#define QUEUECLIENT_HPP
#include<vector>
#include<string>
#include<iostream>
#include "Client.hpp"

using namespace std;
/**
 * @brief cette classe QueueClient contient principalement les infos sur les queues.
 *
 * @param num[50] : un tableau d'id de client
 * @param nbClient : le nombre total des clients dans cette queue
 */
class QueueClient
{
public:
    vector<Client> queueClient;

    Client getClient();
    void Ajouter(Client& cl);
    void Avancer();
    virtual ~QueueClient();

};
#endif
/* end of QueueClient.hpp */
