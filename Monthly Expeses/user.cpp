#include "user.h"
#include<string>
#include<cctype>
#include "expense.h"
#include<vector>
#include<iostream>
using namespace std;
void user::view(vector<expense> expenses) {
	if (expenses.size()) {
		cout << "\tYour expenses are\n";
		for (int i = 0; i < expenses.size(); i++) {
			cout << i + 1 << ") Name: " << expenses[i].name << "\n Category: " <<
				expenses[i].category << "\n Price: " << expenses[i].amount <<
				"\n Date: " << expenses[i].date.day << "/" << expenses[i].date.month << "/" << expenses[i].date.year <<"\n" << "\n";
		}
	}
}
vector<expense> user::filterByCategory(string category, vector<expense> expenses) {
	vector<expense> categoryVec;
	for (int i = 0; i < expenses.size(); i++) {
		if (expenses[i].category == category) {
			categoryVec.push_back(expenses[i]);
		}
	}
	return categoryVec;
}
vector<expense> user::filterByAmount(float start, float end, vector<expense> expenses) {
	vector<expense> amountVec;
	for (int i = 0; i < expenses.size(); i++) {
		if (expenses[i].amount <= end && expenses[i].amount >= start) {
			amountVec.push_back(expenses[i]);
		}
	}
	return amountVec;
}
vector<expense> user::filterByDate(int startDay, int startMonth, int endDay, int endMonth, vector<expense> expenses) {
	vector<expense> dateVec;
	for (int i = 0; i < expenses.size(); i++) {
		if (expenses[i].date.month == startMonth && expenses[i].date.day >= startDay) {
			dateVec.push_back(expenses[i]);
		}
		if (expenses[i].date.month > startMonth && expenses[i].date.month < endMonth) {
			dateVec.push_back(expenses[i]);
		}
		else if (expenses[i].date.month == endMonth && expenses[i].date.day <= endDay) {
			dateVec.push_back(expenses[i]);
		}
	}
	return dateVec;
}
vector<expense> user::filter(vector<expense> expenses, bool &viewExpenses) {
	int choice;
	vector<expense> filterVec = expenses;
	do {
		cout << "Would you like to filter by price ?\n1)Yes\t2)No\n";
		cin >> choice;
		if (choice != 1 && choice != 2) {
			cout << "Invalid choice!\n";
		}
		else if (choice == 1) {
			viewExpenses = true;
			cout << "Minimum price: ";
			int start, end;
			cin >> start;
			cout << "\nMaximum price: ";
			cin >> end;
			filterVec = filterByAmount(start, end, filterVec);
		}
	} while (choice != 1 && choice != 2);
	if (!filterVec.size()) {
		cout << "There are no expenses mathcing your filter conditions!\n";
		return filterVec;
	}
		
	do {
		cout << "Would you like to filter by category ?\n1)Yes\t2)No\n";
		cin >> choice;
		if (choice != 1 && choice != 2) {
			cout << "Invalid choice!\n";
		}
		else if (choice == 1) {
			viewExpenses = true;
			cout << "Category: ";
			string category;
			cin >> category;
			for (int i = 0; i < category.size(); i++) {
				category[i] = tolower(category[i]);
			}
			filterVec = filterByCategory(category, filterVec);
		}
	} while (choice != 1 && choice != 2);
	if (!filterVec.size()) {
		cout << "There are no expenses mathcing your filter conditions!\n";
		return filterVec;
	}
	do {
		cout << "Would you like to filter by date ?\n1)Yes\t2)No\n";
		cin >> choice;
		if (choice != 1 && choice != 2) {
			cout << "Invalid choice!\n";
		}
		else if (choice == 1) {
			viewExpenses = true;
			int startDay, startMonth, endDay, endMonth;
			do {
				cout << "Start day: ";
				cin >> startDay;
				if (startDay <= 0 || startDay > 31) {
					cout << "Invalid choice!";
				}
			} while (startDay <= 0 || startDay > 31);
			do{
				cout << "Start month: ";
				cin >> startMonth;
				if (startMonth <= 0 || startMonth > 12) {
					cout << "Invalid choice!\n";
				}
			} while (startMonth <= 0 || startMonth > 12);
			do{
				cout << "End day: ";
				cin >> endDay;
				if (endDay <= 0 || endDay > 31) {
					cout << "Invalid choice!\n";
				}
			} while (endDay <= 0 || endDay > 31);
			do{
				cout << "End month: ";
				cin >> endMonth;
				if (endMonth <= 0 || endMonth > 12) {
					cout << "Invalid choice!\n";
				}
			} while (endMonth <= 0 || endMonth > 12);
			filterVec = filterByDate(startDay, startMonth, endDay, endMonth, filterVec);
		}
	} while (choice != 1 && choice != 2);
	if (!filterVec.size()) {
		cout << "There are no expenses mathcing your filter conditions!\n";
	}
	return filterVec;
}

