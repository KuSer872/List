#pragma once
#include <fstream>
#include <string>

using namespace std;

class Worker {
private:
	string f;
	string name;
	string post;
	int year;
public:
	Worker();
	Worker(string f, string name, string post, int year);
	Worker(Worker& a);
	void reset();
	friend ostream& operator<<(ostream& os, const Worker a);
	friend istream& operator>>(istream& is, Worker& a);
	bool operator>(const Worker& a);
	bool operator<(const Worker& a);
	bool operator==(const Worker& a);
	bool operator!=(const Worker& a);
	string get_f();
	string get_post();
	int get_year();
	static int sort_f(const void* a, void const* b);
	static int sort_post(const void* a, const void* b);
	static int sort_year(const void* a, const void* b);
	static int sort_x3(const void* a, const void* b);
	void writeBin(fstream& file);
	void readBin(fstream& file);
};
