#include "Timer.h"
#include "CLI.h"

#include "Physics.h"
#include "Module.h"

using namespace std;
void Timer::add(Module *m){
    synchronizedModules.push_back(m);
}

void Timer::add(Physics *p){
    synchronizedPhysics.push_back(p);
}

void Timer::start(unsigned int c){
    for (counter=0; counter<c; ++counter) {

        //On clock la physique:
        for (vector<Physics *>::iterator it = synchronizedPhysics.begin(); it != synchronizedPhysics.end(); ++it) {
            (*it)->clock(counter);
        }

        //On clock les modules:
        for(vector<Module *>::iterator it = synchronizedModules.begin(); it != synchronizedModules.end(); ++it) {
            (*it)->clock(counter);
        }
    }
}

void Timer::stop(){
    
}


unsigned int Timer::getCounter() const {
    return counter;
}