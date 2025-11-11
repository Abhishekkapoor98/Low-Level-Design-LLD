#include<bits/stdc++.h>
using namespace std;

class AirConditioner {
public:
	int temprature;
	bool onOff;

	void turnACOnCommand() {
		cout << "AC is on" << endl;
		onOff = true;
	}

	void turnACOffCommand() {
		cout << "AC is off" << endl;
		onOff = false;
	}

	void SetTemp(int temp) {
		cout << "Temprature is set to " << temp << endl;
		temprature = temp;
	}
};

class Invoker {
public:

	AirConditioner* ac;

	Invoker() {}
	virtual ~Invoker() {}
	Invoker(AirConditioner* ac) {
		this->ac = ac;
	}
	virtual void execute() = 0;
	virtual void undo() = 0;
};

class TurnAcOnCommand: public Invoker {
public:
	TurnAcOnCommand(AirConditioner* command): Invoker(command) {}
	TurnAcOnCommand() {}
	void execute() {
		ac->turnACOnCommand();
	}

	void undo() {
		ac->turnACOffCommand();
	}
};

class TurnAcOffCommand: public Invoker {
public:
	TurnAcOffCommand(AirConditioner* command): Invoker(command) {}
	TurnAcOffCommand() {}
	void execute() {
		ac->turnACOffCommand();
	}

	void undo() {
		ac->turnACOnCommand();
	}
};

class ACRemote {
public:
	Invoker* invoker;
	Invoker* turnOnCommand;
	Invoker* turnOffCommand;

	ACRemote(AirConditioner* ac) {
		turnOnCommand = new TurnAcOnCommand(ac);
		turnOffCommand = new TurnAcOffCommand(ac);
	}

	virtual ~ACRemote() {
		delete turnOnCommand;
		delete turnOffCommand;
	}

	void turnOn() {
		if (turnOnCommand) turnOnCommand->execute();
	}

	void turnOff() {
		if (turnOffCommand) turnOffCommand->execute();
	}
};

int main() {
	AirConditioner* ac = new AirConditioner();
	ACRemote* remote = new ACRemote(ac);

	remote->turnOn();
	remote->turnOff();

	delete ac;
	delete remote;

	return 0;
}







