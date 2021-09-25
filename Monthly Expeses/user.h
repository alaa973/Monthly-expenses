#pragma once
#include<vector>
#include"expense.h"
class user
{
public:
	void view(vector<expense> expenses);
	vector<expense> filter(vector<expense> expenses, bool &viewExpenses);
	vector<expense> filterByCategory(string category, vector<expense> expenses);
	vector<expense> filterByAmount(float start, float end, vector<expense> expenses);
	vector<expense> filterByDate(int startDay, int startMonth, int endDay, int endMonth, vector<expense> expenses);
};
