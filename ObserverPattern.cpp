#include<bits/stdc++.h>
using namespace std;


class Observer {
public:
    string name;
    Observer(const string &n) : name(n) {}
    virtual void update() = 0;
    virtual ~Observer() = default;
};

class observer1: public Observer {
public:
    observer1() : Observer("observer1") {}
    void update() override {
        cout << "Observer 1 updated" << endl;
    }
};

class observer2: public Observer {
public:
    observer2() : Observer("observer2") {}
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
    virtual ~Observable() = default;
};

class Observable_concrete: public Observable {

public:
    vector<Observer*> observer_list;
    int data;

    void addObserver(Observer* observer) override {
        observer_list.push_back(observer);
    }

    void removeObserver(Observer *observer) override {
        observer_list.erase(remove(observer_list.begin(), observer_list.end(), observer), observer_list.end());
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

    ~Observable_concrete() override = default;
};


int main() {
    Observable_concrete *observable = new Observable_concrete();

    Observer *observer_1 = new observer1();
    Observer *observer_2 = new observer2();

    observable->addObserver(observer_1);
    observable->addObserver(observer_2);

    observable->setData(10);

    observable->setData(20);
    observable->setData(30);

    observable->removeObserver(observer_1);

    observable->setData(40);

    delete observer_1;
    delete observer_2;
    delete observable;

    return 0;
}