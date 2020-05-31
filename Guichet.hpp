/* Guichet.hpp */
#ifndef GUICHET_HPP
#define GUICHET_HPP
#include<string>
#include<iostream>

/**
 * @brief Guichet est une classe qui contient les deux param principales pour tous les guichets
 * @param service : un integer qui indique les 4 types de service
 * @param status : faux vaut dire qu'il est occupé et vrai sinon
 */
class Guichet
{
	public:
        bool status;
        int service;

		Guichet();
        void traiter();
        void disponible();
		};

#endif
/* end of Guichet.hpp */
