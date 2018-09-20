#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
class Observer;

class Subject {
protected:
    std::vector<Observer*> observers;
public:
    void attach(Observer *o);
    void detach(Observer *o);
    virtual void notifyObservers();
    virtual ~Subject() = 0;
};

#endif // SUBJECT_H
