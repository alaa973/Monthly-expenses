#include "expense.h"

expense::expense(){}

expense::expense(string name, string category, float amount, int day , int month , int year) {
	this->name = name;
	this->category = category;
	this->amount = amount;
	this->date.day = day;
	this->date.month = month;
	this->date.year = year;
}

expense::~expense(){}
