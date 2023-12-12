#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Price {
private:
	string good;
	string market;
	int cost;
	friend istream& operator>>(istream& os, Price& pt);
	friend ostream& operator<<(ostream& os, Price& pt);
public:
	Price() {
		cout << "CONSTRUCTOR PRICE\n";
		good = "";
		market = "";
		cost = 0;
	}
	~Price() { cout << "DESTRUCTOR PRICE\n"; }
	void setGood(string a) {
		good = a;
	}

	void setMarket(string a) {
		market = a;
	}

	void setCost(int a) {
		cost = a;
	}

	string getGood() {
		return good;
	}
	string getMarket() {
		return market;
	}
	int getCost() {
		return cost;
	}
	void info() {
		cout << "good: " << good << "; market: " << market << "; cost: " << cost<<endl;
	}
};

istream& operator>>(istream& os, Price& pt) {
	cout << "¬ведите название товара: ";
	os >> pt.good;
	system("cls");
	cout << "¬ведите название магазина: ";
	os >> pt.market;
	system("cls");
	cout << "¬ведите цену товара: ";
	os >> pt.cost;
	system("cls");
	return os;
}
ostream& operator<<(ostream& os, Price& pt) {
	os << "good: " << pt.good << "; market: " << pt.market << "; cost: " << pt.cost << endl;
	return os;
}
