/* Guichet3.hpp */
#ifndef GUICHET3_HPP
#define GUICHET3_HPP
#include<cstring>
#include<string>
#include<iostream>
#include<fstream>
#include "Guichet.hpp"
#include "Client.hpp"

/**
 * @brief Guichet3 hérite Guichet et il décrit un cas où dans la poste et il veut retirer un colis
 * @param service  égale à 3 ici pour indique le troisième cas
 * @param num[] il utilse le tableau de string qui est défini dans la classe QueueClient
 */

class Guichet3 : public Guichet{
public:

    Guichet3();
    void Servir(Client& c);
    virtual ~Guichet3();
};
#endif
/* end of Guichet3.hpp */
