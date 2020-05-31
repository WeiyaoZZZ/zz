/* Client.cpp */
#include "Client.hpp"
#include<cstring>
#include<string>
#include<iostream>

using namespace std;

Client::Client(string no, int s)
    {   noClient = no;
        Service = s;
        Status = true;
            };

/* en cas d'initialiser un compte */
void Client::setNo(string no)
    {   noClient = no; };

/* faire le status au vrai pour un status d'attendre */
void Client::Attendre()
	{   Status = true; };

/* faire le status au faux vaut dire en train de traiter */
void Client::Traiter()
	{   Status = false; };
/* end of Client.cpp */
