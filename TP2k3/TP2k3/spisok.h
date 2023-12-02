#pragma once
#include <iostream>
using namespace std;
class Spisok {
	class Element {
	public:
		string value;
		int index;
		Element* prev;
		Element(string data, Element* prev = nullptr) {
			this->value = data;
			this->prev = prev;
		}
		~Element() {
			
		}
	};
	int count;
	Element* head;
	Element* end;
public:
	Spisok() {
		count = 0;
		head = nullptr;
		end = nullptr;
	}
	~Spisok() {
		while (head != nullptr and count != 0) {
			end = head;
			head = head->prev;
			delete end;
			count--;
		}
		delete head;
	}
	int getCount() {
		return count;
	}
	void add(string et) {

		if (head == nullptr) {
			head = new Element(et);
			head->value = et;
		}
		else {
			end = new Element(et);
			end->prev = head;
			head = end;
			head->value = et;
		}
		count++;
	}
	void print() {
		try {
			if (getCount() == 0) throw exception("EMPTY\n");
			end = head;
			int i = getCount();
			while (end != nullptr && i != 0) {

				cout << "#" << i << " ";
				cout<<end->value;
				end = end->prev;
				i--;
			}
		}
		catch (const exception& ex) {
			cout << ex.what();
		}
	}
};