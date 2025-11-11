#include<bits/stdc++.h>
using namespace std;

class ItemProcessor {
public:
	ItemProcessor* next = nullptr;

	ItemProcessor() {}

	ItemProcessor(ItemProcessor* processor) {
		next = processor;
	}

	virtual void process(string item) {
		if (next) {
			next->process(item);
		} else {
			cout << "Item not found in chain" << endl;
		}
	}

	virtual ~ItemProcessor() {}
};

class Chocolate: public ItemProcessor {
public:
	Chocolate() {}

	Chocolate(ItemProcessor* ItemP) {
		next = ItemP;
	}

	void process(string item) override {
		if (item == "chocolate")
			cout << "Chocolate returned" << endl;
		else if (next)
			next->process(item);
		else
			cout << "Item not found" << endl;
	}
};

class Waffer: public ItemProcessor {
public:
	Waffer() {}

	Waffer(ItemProcessor* ItemP) {
		next = ItemP;
	}

	void process(string item) override {
		if (item == "waffer")
			cout << "Waffer returned" << endl;
		else if (next)
			next->process(item);
		else
			cout << "Item not found" << endl;
	}
};

class Coke: public ItemProcessor {
public:
	Coke() {}

	Coke(ItemProcessor* ItemP) {
		next = ItemP;
	}

	void process(string item) override {
		if (item == "coke")
			cout << "Coke returned" << endl;
		else if (next)
			next->process(item);
		else
			cout << "Item not found" << endl;
	}
};

int main() {
	ItemProcessor* processor = new Chocolate(new Waffer(new Coke()));
	processor->process("waffer");

	processor->process("sprite");
	return 0;
}