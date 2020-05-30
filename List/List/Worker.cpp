#include "Worker.h"

void Worker::reset()
{
	f = "";
	name = "";
	post = "";
	year = 0;
}

bool Worker::operator>(const Worker& a)
{
	return f.compare(a.f) > 0;
}

bool Worker::operator<(const Worker& a)
{
	return f.compare(a.f) < 0;
}

bool Worker::operator==(const Worker& a)
{
	return f.compare(a.f) == 0;
}

bool Worker::operator!=(const Worker& a)
{
	return f.compare(a.f) != 0;
}


string Worker::get_f()
{
	return this->f;
}

string Worker::get_post()
{
	return this->post;
}

int Worker::get_year()
{
	return this->year;
}

int Worker::sort_f(const void* a, void const* b)
{
	Worker* A = (Worker*)a;
	Worker* B = (Worker*)b;
	return A->get_f().compare(B->get_f());
}

int Worker::sort_post(const void* a, const void* b)
{
	Worker* A = (Worker*)a;
	Worker* B = (Worker*)b;
	return A->get_post().compare(B->get_post());
}

int Worker::sort_year(const void* a, const void* b)
{
	Worker A = *(Worker*)a;
	Worker B = *(Worker*)b;
	if (A.get_year() > B.get_year())
		return 1;
	else if (A.get_year() == B.get_year())
		return 0;
	else
		return -1;
}

int Worker::sort_x3(const void* a, const void* b)
{
	if (!sort_f(a, b))
		if (!sort_post(a, b))
			return sort_year(a, b);
		else
			return sort_post(a, b);
	else
		return sort_f(a, b);
}

void Worker::writeBin(fstream& file)
{
	file.write((char*)this, sizeof(*this));
}
void Worker::readBin(fstream& file)
{
	file.read((char*)this, sizeof(*this));
}

Worker::Worker(Worker& a)
{
	this->f = a.f;
	this->name = a.name;
	this->post = a.post;
	this->year = a.year;
}

Worker::Worker()
{
	f = "";
	name = "";
	post = "";
	year = 0;
}

Worker::Worker(string f, string name, string post, int year)
{
	this->f = f;
	this->name = name;
	this->post = post;
	this->year = year;
}

ostream& operator<<(ostream& os, const Worker a)
{
	return os << a.f << " " << a.name << " " << a.post << " " << a.year;
}

istream& operator>>(istream& is, Worker& a)
{
	return is >> a.f >> a.name >> a.post >> a.year;
}