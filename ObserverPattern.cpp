#include<bits/stdc++.h>
using namespace std;


class Observer {
public:
    string name;
    virtual void update() = 0;
};

class observer1: public Observer {
public:
    string name = "observer1";
    void update() override {
        cout << "Observer 1 updated" << endl;
    }
};

class observer2: public Observer {
public:
    string name = "observer2";
    void update() override {
        cout << "Observer 2 updated" << endl;
    }
};

class Observable {
public:
    virtual void addObserver(Observer*) = 0;
    virtual void removeObserver(Observer*) = 0;
    virtual void notifyObservers() = 0;
    virtual void setData(int data) = 0;
};

class Observable_concrete: public Observable {

public:
    vector<Observer*> observer_list;
    int data;

    void addObserver(Observer* observer) override {
        observer_list.push_back(observer);
    }

    void removeObserver(Observer *observer) override {
        for (auto observerIt : observer_list) {
            if (observerIt->name == observer->name) {
                observer_list.erase(remove(observer_list.begin(), observer_list.end(), observerIt), observer_list.end());
                break;
            }
        }
    }

    void notifyObservers() override {
        for (auto observerIt : observer_list) {
            observerIt->update();
        }
    }

    void setData(int value) override {
        data = value;
        notifyObservers();
    }
};


int main() {
    Observable_concrete *observable = new Observable_concrete();

    Observer *observer_1 = new observer1();
    Observer *observer_2 = new observer2();

    observable->addObserver(observer_1);
    observable->addObserver(observer_2);

    observable->setData(10);

    observable->removeObserver(observer_1);

    observable->setData(20);
    observable->setData(30);
    observable->setData(40);

    return 0;
}
