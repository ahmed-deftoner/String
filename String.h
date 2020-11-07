#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class String
{
	char* data;
	int size;

public:
	String();
	String(const char* x);
	String(const String& obj);
	int length();
	char* substring(int start, int end);
	void upper();
	void lower();
	char at(int index);
	int index(const char* x);
	bool compare(String obj1);
	String* concat(const char* x);
	String* concat(String x);
	String* concat(int x);
	String* concat(char x);
	String* concat(double x);
	String* prepend(const char* x);
	String* prepend(String x);
	String* prepend(int x);
	String* prepend(char x);
	String* prepend(double x);	  
	friend istream& operator>> (istream& in, String& obj);
	friend ostream& operator<< (ostream& out, String& obj);
	String* operator =(const char* x);
	friend String operator +(const String& obj1, const String& obj2);
	friend String operator +(const String& obj1, const char* x);
	friend String operator +(const char* x, const String& obj2);
	friend String operator +(const String& obj1, int x);
	friend String operator +(int x, const String& obj2);
	friend String operator +(const String& obj1, double x);
	friend String operator +(double x, const String& obj2);
	friend String operator +(const String& obj1, char x);
	friend String operator +(char x, const String& obj2);
	friend bool operator== (const String& obj1, const String& obj2);
	friend bool operator!= (const String& obj1, const String& obj2);
	friend bool operator < (const String& obj1, const String& obj2);
	friend bool operator > (const String& obj1, const String& obj2);
	char operator[] (unsigned j);  
};

