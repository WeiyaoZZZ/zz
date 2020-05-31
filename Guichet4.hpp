/* Guichet4.hpp */
#ifndef GUICHET4_HPP
#define GUICHET4_HPP
#include<cstring>
#include<string>
#include<iostream>
#include<fstream>
#include "Guichet.hpp"
#include "Client.hpp"

/**
 * @brief Guichet4 hérite Guichet et il décrit un cas où dans la poste et on veut envoyer un colis
 * @param service : égale à 4 ici pour indique le 4ème cas
 * @param num[]: il utilse le tableau de string qui est défini dans la classe QueueClient
 */

class Guichet4 : public Guichet{
public:

    Guichet4();
    void Servir(Client& c);
    virtual ~Guichet4();
};
#endif // GUICHET4_HPP
/* Guichet4.hpp */
