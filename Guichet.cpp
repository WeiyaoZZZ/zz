/* Guichet.cpp */
#include "Guichet.hpp"
#include<iostream>

using namespace std;

Guichet::Guichet()
    {   status = true;
        service = 0;};

void Guichet::traiter()
    {   status = false; };

void Guichet::disponible()
    {   status = true; };

/* end of Guichet.cpp */
