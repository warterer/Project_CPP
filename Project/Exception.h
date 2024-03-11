#pragma once
#include <iostream>
using namespace std;

class Exception {
public:
	virtual string message()const = 0;
};
class InputException : public Exception {
public:
	virtual string message()const override {
		return "Wrong input!";
	}
};
class NothingFoundException : public Exception {
public:
	virtual string message()const override {
		return "Nothing found!";
	}
};
class EmptyException : public Exception {
public:
	virtual string message()const override {
		return "List is empty!";
	}
};
class OpeningException : public Exception {
public:
	virtual string message()const override {
		return "File opening error!";
	}
};