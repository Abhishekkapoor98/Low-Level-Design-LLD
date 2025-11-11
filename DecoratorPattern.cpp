#include<bits/stdc++.h>
using namespace std;

class Decorator;

class BasePizza {
public:
	int cost = 0;
	string name;

	virtual void setCost(int data) = 0;
	virtual int getCost() = 0;

	virtual ~BasePizza() {};

	BasePizza(Decorator* decorate = nullptr) {
		if (decorate) decorate->addFeature();
	};
};

class Decorator: public BasePizza {
public:
	BasePizza* pizza;
	int featureCost;

	Decorator(BasePizza* p) : pizza(p) {}
	virtual void setFeatureCost(int data) = 0;
	virtual void addFeature() = 0;
};

class Mashrooms: public Decorator {
public:
	Mashrooms(BasePizza* p) : Decorator(p) {}

	void setFeatureCost(int Fcost) override {
		featureCost = Fcost;
	}

	void addFeature() override {
		pizza->cost += featureCost;
	}

	void setCost(int myCost) override {
		cost = myCost;
	}

	int getCost() override {
		return cost;
	}
};

class Cheese: public Decorator {
public:

	Cheese(BasePizza* p) : Decorator(p) {}

	void setFeatureCost(int Fcost) override {
		featureCost = Fcost;
	}

	void addFeature() override {
		pizza->cost += featureCost;
	}

	void setCost(int myCost) override {
		cost = myCost;
	}

	int getCost() override {
		return cost;
	}
};

class Margarita: public BasePizza {
public:
	Margarita() : BasePizza(nullptr) {}

	void setCost(int myCost) override {
		cost = myCost;
	}

	int getCost() override {
		return cost;
	}
};

class VeggieDelight: public BasePizza {
public:
	void setCost(int myCost) override {
		cost = myCost;
	}

	int getCost() override {
		return BasePizza::cost;
	}
};

int main() {
	BasePizza *margarita = new Margarita();
	margarita->setCost(100);

	Decorator *cheeseDecorator = new Cheese(margarita);
	cheeseDecorator->setFeatureCost(30);
	cheeseDecorator->addFeature();

	BasePizza *margaritaWithCheese = new Margarita();
	margaritaWithCheese->setCost(100);
	Decorator *cheeseDecorator2 = new Cheese(margaritaWithCheese);
	cheeseDecorator2->setFeatureCost(30);
	cheeseDecorator2->addFeature();

	cout << "Margarita cost: " << margarita->getCost() << endl;
	cout << "Margarita with Cheese cost: " << margaritaWithCheese->getCost() << endl;
}

