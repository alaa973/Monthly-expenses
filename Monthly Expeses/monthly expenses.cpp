#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<string>
#include "expense.h"
#include "user.h"
#include <algorithm>
using namespace std;



vector < expense> expenses;
string name;
string category;
float amount, wallet_expenses = 0, current_wallet = 0, money = 0, all_money = 0, month_income, cash_income = 0, credit_income = 0, debit_income = 0;
float monthly_income, cash_money = 0, credit_money = 0, debit_money = 0, saves = 0, dept = 0;
int chooseWallet;
int dday;
int dmonth;
int dyear;
char choose;
void dateofexpense()
{
	time_t now;
	struct tm timenow;
	now = time(NULL);
	timenow = *localtime(&now);
	dday = timenow.tm_mday;
	dmonth = timenow.tm_mon + 1;
	dyear = timenow.tm_year + 1900;

}
int num1, num2, num3;
void currentexpenses(float cost)
{
	current_wallet -= cost;
	if (current_wallet == num1)
		num1 -= cost;
	else if (current_wallet == num2)
		num2 -= cost;
	else if (current_wallet == num3)
		num3 -= cost;
}

void data_from_Cash_to_code() {

	ifstream Cash_expenses_file("Cash_expenses_file.txt");

	ifstream Cash_monthly_file("Cash_monthly_file.txt");



	while (Cash_monthly_file >> cash_income >> current_wallet)
	{
		dateofexpense();
		if (dday == 1)
		{
			current_wallet += cash_income;
		}
		month_income = cash_income;
		monthly_income = cash_income;
	}



	while (Cash_expenses_file >> name >> category >> amount >> dday >> dmonth >> dyear)
	{

		expense expenseobject(name, category, amount, dday, dmonth, dyear);
		expenses.push_back(expenseobject);

	}
	if (Cash_expenses_file.is_open())
	{
		Cash_expenses_file.close();
	}
	if (Cash_monthly_file.is_open())
	{
		Cash_monthly_file.close();
	}
}
void data_from_code_to_Cash() {


	ofstream expenses_file("Cash_expenses_file.txt");

	for (int i = 0; i < expenses.size(); i++) {
		expenses_file << expenses[i].name << " ";
		expenses_file << expenses[i].category << " ";
		expenses_file << expenses[i].amount << " ";

		//date 1/1/2001

		expenses_file << expenses[i].date.day << " ";
		expenses_file << expenses[i].date.month << " ";
		expenses_file << expenses[i].date.year << " ";
		expenses_file << "\n";
	}

	ofstream monthly_file("Cash_monthly_file.txt");
	monthly_file << cash_income << " " << current_wallet << "n";

	if (expenses_file.is_open())
	{
		expenses_file.close();
	}
	if (monthly_file.is_open())
	{
		monthly_file.close();
	}
}

void data_from_Credit_to_code() {

	ifstream expenses_file("credit_expenses_file.txt");

	ifstream monthly_file("credit_monthly_file.txt");



	while (monthly_file >> credit_income >> current_wallet)
	{
		dateofexpense();
		if (dday == 1)
		{
			current_wallet += credit_income;
		}
		month_income = credit_income;
		monthly_income = credit_income;
	}



	while (expenses_file >> name >> category >> amount >> dday >> dmonth >> dyear)
	{

		expense expenseobject(name, category, amount, dday, dmonth, dyear);
		expenses.push_back(expenseobject);

	}
	if (expenses_file.is_open())
	{
		expenses_file.close();
	}
	if (monthly_file.is_open())
	{
		monthly_file.close();
	}
}
void data_from_code_to_Credit() {


	ofstream expenses_file("credit_expenses_file.txt");

	for (int i = 0; i < expenses.size(); i++) {
		expenses_file << expenses[i].name << " ";
		expenses_file << expenses[i].category << " ";
		expenses_file << expenses[i].amount << " ";

		//date 1/1/2001

		expenses_file << expenses[i].date.day << " ";
		expenses_file << expenses[i].date.month << " ";
		expenses_file << expenses[i].date.year << " ";
		expenses_file << "\n";
	}

	ofstream monthly_file("credit_monthly_file.txt");

	monthly_file << credit_income << " " << current_wallet << "n";

	if (expenses_file.is_open())
	{
		expenses_file.close();
	}
	if (monthly_file.is_open())
	{
		monthly_file.close();
	}
}

void data_from_debit_to_code() {

	ifstream expenses_file("debit_expenses_file.txt");

	ifstream monthly_file("debit_monthly_file.txt");



	while (monthly_file >> debit_income >> current_wallet)
	{
		dateofexpense();
		if (dday == 1)
		{
			current_wallet += debit_income;
		}
		month_income = debit_income;
		monthly_income = debit_income;
	}



	while (expenses_file >> name >> category >> amount >> dday >> dmonth >> dyear)
	{

		expense expenseobject(name, category, amount, dday, dmonth, dyear);
		expenses.push_back(expenseobject);

	}
	if (expenses_file.is_open())
	{
		expenses_file.close();
	}
	if (monthly_file.is_open())
	{
		monthly_file.close();
	}
}
void data_from_code_to_debit() {


	ofstream expenses_file("debit_expenses_file.txt");

	for (int i = 0; i < expenses.size(); i++) {
		expenses_file << expenses[i].name << " ";
		expenses_file << expenses[i].category << " ";
		expenses_file << expenses[i].amount << " ";

		//date 1/1/2001

		expenses_file << expenses[i].date.day << " ";
		expenses_file << expenses[i].date.month << " ";
		expenses_file << expenses[i].date.year << " ";
		expenses_file << "\n";
	}

	ofstream monthly_file("debit_monthly_file.txt");

	monthly_file << debit_income << " " << current_wallet << "n";

	if (expenses_file.is_open())
	{
		expenses_file.close();
	}
	if (monthly_file.is_open())
	{
		monthly_file.close();
	}
}

void  all_remaining_money() {

	num1 = 0;
	num2 = 0;
	num3 = 0;

	ifstream Cash_monthly_file("Cash_monthly_file.txt");

	while (Cash_monthly_file >> cash_income >> num1)
	{
		cash_money = num1;
	}

	ifstream credit_monthly_file("credit_monthly_file.txt");

	while (credit_monthly_file >> credit_income >> num2)
	{
		credit_money = num2;
	}

	ifstream debit_monthly_file("debit_monthly_file.txt");



	while (debit_monthly_file >> debit_income >> num3)
	{
		debit_money = num3;
	}



	if (Cash_monthly_file.is_open())
	{
		Cash_monthly_file.close();
	}

	if (credit_monthly_file.is_open())
	{
		credit_monthly_file.close();
	}

	if (debit_monthly_file.is_open())
	{
		debit_monthly_file.close();
	}

	if (choose == '1')
	{
		all_money = max(current_wallet, 0.0f) + max(num2, 0) + max(num3, 0);
		num1 = current_wallet;
		cash_money = num1;
	}
	else if (choose == '2')
	{
		all_money = max(current_wallet, 0.0f) + max(num1,0) + max(num3,0);
		num2 = current_wallet;
		credit_money = num2;
	}
	else if (choose == '3')
	{
		all_money = max(current_wallet, 0.0f) + max(num1,0) + max(num2,0);
		num3 = current_wallet;
		debit_money = num3;
	}
}

void enterexpenses()
{
	int ans;
	float wallet = current_wallet;

	cout << "Please, enter your expense name" << endl;
	cin >> name;
	cout << "Please, enter the expense's category  " << endl;
	cin >> category;
	cout << "Please, enter your expense " << endl;
	cin >> amount;
	currentexpenses(amount);
	dateofexpense();
	expense expenseobject(name, category, amount, dday, dmonth, dyear);
	expenses.push_back(expenseobject);
	cout << "The process is successfully done " << endl << endl;
	cout << "If you want to add another expense  press:1" << endl;
	cout << "If not  press:2" << endl;
	cin >> ans;
	while (ans != 1 && ans != 2)

	{
		cout << " Invalid input ! " << endl;
		cout << "If you want to add another expense  press:1" << endl;
		cout << "If not  press:2" << endl;
		cin >> ans;

	}
	if (ans == 1)
	{
		enterexpenses();
	}
	else if (ans == 2)
	{
		return;


	}



}


float saving(int choosen_month)
{

	float save = 0;
	for (int i = 0; i < expenses.size(); i++) {

		if (expenses[i].date.month == choosen_month)
			save += expenses[i].amount;
	}
	save = month_income - save;

	return save;
}

int main()
{
	cout << "         welcome         " << endl << endl;
	bool open = true;
	
	while (open)
	{
		cout << "For cash press 1  " << endl << "For credit press 2  " << endl <<
			"For debit press 3  " << endl;
		cin >> choose;
		chooseWallet = choose;
		if (choose == '1')
		{
			data_from_Cash_to_code();
			open = false;
		}
		else if (choose == '2')
		{
			data_from_Credit_to_code();
			open = false;
		}
		else if (choose == '3')
		{
			data_from_debit_to_code();
			open = false;
		}
		else
			cout << "Your entered an invaild choice " << endl;

	}
	while (true) {

		char ans;
		cout << " press 1 : To edit your monthly income" << endl;
		cout << " press 2 : to enter your daily expense " << endl;
		cout << " press 3 : To view all expenses " << endl;
		cout << " press 4 : To view the remaining money in the current wallet " << endl;
		cout << " press 5 : To view the total remaining money " << endl;
		cout << " press 6 : To change the wallet " << endl;
		cout << " press 7 : To view your saving and your dept money " << endl;
		cout << " press 8 : To exit " << endl;

		cin >> ans;
		if (ans == '1')
		{
			if (chooseWallet == '1')
			{
				cout << "Your monthly income : " << month_income << endl;
				cout << "  Please , enter your income" << endl;
				cin >> cash_income;
				monthly_income = cash_income;
			}
			else if (chooseWallet == '2')
			{
				cout << "Your monthly income : " << month_income << endl;
				cout << "  Please , enter your income" << endl;
				cin >> credit_income;
				monthly_income = credit_income;
			}
			else if (chooseWallet == '3')
			{
				cout << "Your monthly income : " << month_income << endl;
				cout << "  Please , enter your income" << endl;
				cin >> debit_income;
				monthly_income = debit_income;
			}
			current_wallet += monthly_income;
			month_income = monthly_income;
			cout << "The process is successfully done " << endl << endl;

		}
		else if (ans == '2')
		{
			enterexpenses();


		}

		else if (ans == '3')
		{
			bool viewExpenses = false;
			user user1 = user();
			if (expenses.size())
			{
				user1.view(expenses);
				vector<expense> vec = user1.filter(expenses, viewExpenses);
				if(viewExpenses)
					user1.view(vec);
			}
			else
				cout << "There are no expenses yet\n";
		}


		else if (ans == '4')
		{
			if (current_wallet < 0)
			{
				cout << "Your remaining money in the current wallet : " << 0 << endl;
				cout << "Your total dept : " << abs(current_wallet) << endl;
			}
			else
				cout << "Your remaining money in the current wallet : " << current_wallet << endl;

		}

		else if (ans == '5')
		{
			all_remaining_money();
			if (cash_money < 0)
			{
				cash_money = 0;
			}
				cout << "Your remaining money in cash wallet : " << cash_money << endl;
			if (credit_money < 0)
			{
				credit_money = 0;
			}
				cout << "Your remaining money in credit wallet : " << credit_money << endl;
			if (debit_money < 0)
			{
				debit_money = 0;
			}
				cout << "Your remaining money in debit wallet : " << debit_money << endl;
			if (all_money < 0) {
				cout << "Your total remaining money : " << 0 << endl;
				cout << "Your total dept : " << abs(all_money) << endl;
			}
			else
				cout << "Your total remaining money : " << all_money << endl << endl;
		}

		else if (ans == '6') {
			if (chooseWallet == '1')
			{
				data_from_code_to_Cash();

			}
			else if (chooseWallet == '2')
			{
				data_from_code_to_Credit();

			}
			else if (chooseWallet == '3')
			{
				data_from_code_to_debit();

			}
			month_income = 0;
			current_wallet = 0;
			expenses.clear();
			main();
		}

		else if (ans == '7')
		{
			int choosen_month;
			
				cout << "Enter the month: ";
				cin >> choosen_month;
			
				int savingg = saving(choosen_month);
				dept = 0;
				saves = 0;
				if (savingg < 0) {
					dept = abs(savingg);
				}
				else {
					saves = savingg;
				}
				cout << "your savings for this month is: " << saves << endl;
				cout << "your dept for this month is: " << dept << endl;

			
		}
		else if (ans == '8')
		{
			if (choose == '1')
				data_from_code_to_Cash();
			else if (choose == '2')
				data_from_code_to_Credit();
			else if (choose == '3')
				data_from_code_to_debit();

			exit(0);
		}
		else
		{
			cout << "Invalid input!" << endl;

		}
	}

	return 0;
}