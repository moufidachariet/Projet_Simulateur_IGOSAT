#include "Connexion.h"

#include <sstream>

#include "Socket.h"

#include "CLI.h"
using namespace std;

Connexion::Connexion(Socket *a, Socket *b) : socketA(a), socketB(b){
    a->setConnexion(*this);
    b->setConnexion(*this);
}

Connexion::Connexion(const Connexion& c) {
    //cout << "Copie de connexion" << endl;
    socketA = c.socketA;
    socketB = c.socketB;

    //On actualise la connexion !
    socketA->setConnexion(*this);
    socketB->setConnexion(*this);
}

Connexion::~Connexion(){
}

void Connexion::dispatch(Message *m, Socket *s){
    //Pour le log:
    stringstream mess;
    if (s->getName() == socketA->getName()) {
        socketB->receive(m);
        //On log:
        mess << "Socket " << socketB->getName() << " received " << m->getName() << "(" /*! \todo On peut pas faire �a c'est nul ! << m->getPayload()*/ << ") sent by " << socketA->getName() << endl;
        CLI::getInstance().log(CLI::INFO, mess.str());

    } else if(s->getName() == socketB->getName()) {
        socketA->receive(m);

        //On log:
        mess << "Socket " << socketA->getName() << " received " << m->getName() << "(" << ") sent by " << socketB->getName() << endl;
        CLI::getInstance().log(CLI::INFO, mess.str());

    } else {
        cout << "Unrecognized sender" << endl;
    }
}
