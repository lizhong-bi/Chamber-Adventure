#include "subject.h"
#include "observer.h"

void Subject::attach(Observer *o) {
    observers.push_back(o);
}

void Subject::detach(Observer *o) {
    for(unsigned int i=0; i<observers.size(); i++){
        if(observers[i]==o){
            observers.erase(observers.begin()+i);
            return;
        }
    }
}

void Subject::notifyObservers() {
    for(Observer *ob : observers){
        ob->notify(this);
    }
}


Subject::~Subject(){

}
