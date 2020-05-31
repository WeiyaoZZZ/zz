/* Guichet2.hpp */
#ifndef GUICHET2_HPP
#define GUICHET2_HPP
#include<cstring>
#include<string>
#include<iostream>
#include<fstream>
#include "Guichet.hpp"
#include "Client.hpp"

/**
 * @brief Guichet2 hérite Guichet et il décrit un cas où le client fait le dépôt de l'argent
 * @param service : égale à 2 ici pour indique le deuxième cas
 * @param num[]: il utilse le tableau de string qui est défini dans la classe QueueClient
 */
class Guichet2 : public Guichet{
public:

    Guichet2();
    void Servir(Client& c);
    virtual ~Guichet2();
};
#endif
/* end of Guichet2.hpp */
