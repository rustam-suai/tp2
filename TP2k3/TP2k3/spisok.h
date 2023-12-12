#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Spisok {
	class Element1 {
	public:
		string value;
		int index;
		Element1* prev;
		Element1(string data, Element1* prev = nullptr) {
			this->value = data;
			this->prev = prev;
		}
		~Element1() {}
	};
	int count;
	Element1* head;
	Element1* end;
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
			head = new Element1(et);
			head->value = et;
		}
		else {
			end = new Element1(et);
			end->prev = head;
			head = end;
			head->value = et;
		}
		count++;
	}
	void print() {
		try {
			if (getCount() == 0) throw exception("EMPTY\n");
			cout << endl;
			end = head;
			int i = getCount();
			while (end != nullptr && i != 0) {

				//cout << "#" << i <<" ";
				cout<<end->value<<endl;
				end = end->prev;
				i--;
			}
			cout << endl;
		}
		catch (const exception& ex) {
			cout << ex.what();
		}
	}
	bool kp( string h) {
		for (int i = 0; i < h.size(); i++) {
			if (h[i] == '!' or h[i] == '?' or h[i] == '.') {
				return true;
			}
		}
		return false;
	}
	void func2(ifstream& filik) {
		string word,ow;
		string sentence;
		while (filik >> word) { // Читаем каждое слово из файла
			sentence += word + " "; // Добавляем слово в текущее предложени
			if (kp(word)) {
				this->add(sentence);
				sentence = "";
			}
			ow = word;
		}
		filik.close(); // Закрываем файл после чтения
	}
};