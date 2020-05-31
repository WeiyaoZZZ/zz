/* Guichet1.hpp */
#ifndef GUICHET1_HPP
#define GUICHET1_HPP
#include<cstring>
#include<string>
#include<iostream>
#include<fstream>
#include "Guichet.hpp"
#include "Client.hpp"

/**
 * @brief Guichet1 hérite Guichet et il décrit un cas où le client retire de l'argent, faut d'abord vérifier s'il y a assez de l'argent
 * @param service : égale à 1 ici pour indique le premier cas
 * @param num[]: il utilse le tableau de string qui est défini dans la classe QueueClient
 */
class Guichet1 : public Guichet{
public:

    Guichet1();
    void Servir(Client& c);
    virtual ~Guichet1();
};
#endif
/* end of Guichet1.hpp */
