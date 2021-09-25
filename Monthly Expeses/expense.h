#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct date {
	int day;
	int month;
	int year;
};
class expense
{
public:
	string name, category;
	float amount;
	struct date date;
public:
	expense();
	expense(string name, string category, float amount, int day , int month , int year);
	~expense();
	
};
