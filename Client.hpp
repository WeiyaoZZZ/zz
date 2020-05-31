/* Client.hpp */
#ifndef CLIENT_HPP
#define CLIENT_HPP
#include<cstring>
#include<string>
#include<iostream>

using namespace std;
/**
 * @brief cette classe Client contiendra principalement le numéro d'identité du client
 * @param Status : attendre vaut faux et sinon vaut vrai
 * @param Service : un integer qui indique les 4 types de service
 * @param noClient : un string qui indique le numéro d'id du client
 */
class Client
{
public:
	bool Status;
	int Service;
	string noClient;

	Client(string no, int s);
	void setNo(string no);
	void Attendre();
	void Traiter();
	};
#endif
/* end of Client.hpp */
