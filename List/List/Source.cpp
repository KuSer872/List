#include <iostream>
#include <fstream>
#include "Worker.h"
#include "List.h"
using namespace std;

int main()
{
	fstream in("text.txt");
	if (!in) cout << "Error" << endl;

	List myList;
	in >> myList;

	cout << myList << endl;

	Worker a("Konstantinov", "T.A.", "Programmer", 2010);
	Worker b("Alexeev", "R.P.", "Plumber", 1996);
	myList.addstart(a);
	myList.add(b);

	cout << myList << endl;

	myList.sort();

	cout << myList << endl;

	Worker c("Nikolaev", "S.A.", "SMM", 2005);
	myList.delv(c);

	cout << myList << endl;

	myList.insert(c);

	cout << myList << endl;

	myList.reverse();

	cout << myList << endl;

	cout << "Empty? " << myList.empty() << endl;
}