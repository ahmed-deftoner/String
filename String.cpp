#include "String.h"

//Constructor
String::String() {
	size = 0;
	data = NULL;
}

//Parameterized Constructor. Takes char array as param
String::String(const char* x) {
	size = strlen(x);
	data = new char[size];
	for (int i = 0; i < size; ++i)
		data[i] = x[i];
}

//Copy Constructor
String::String(const String& obj) {
	size = obj.size;
	data = new char[size];
	for (int i = 0; i < size; ++i)
		data[i] = obj.data[i];
}

//Function to return length of string
int String::length() {
	return size;
}

//Function that returns substring
//Two params. Start and end index.
//Inclusive
//returns a char array
char* String::substring(int start, int end) {
	if (start < end && start>=0 && end >=0 && start < size && end < size) {
		char* x = new char[size];
		int count = 0;
		for (int i = start; i <= end; ++i) {
			x[count] = data[i];
			++count;
		}
		x[count] = '\0';
		return x;
	}
	return NULL;
}

//Function that converts string to upper case
void String::upper() {
	for (int i = 0; i <= strlen(data); i++) {
		if (data[i] >= 97 && data[i] <= 122){
			data[i] = data[i] - 32;
		}
	}
}

//Function that converts string to lower case
void String::lower() {
	for (int i = 0; i <= strlen(data); i++) {
		if (data[i] >= 65 && data[i] <= 91){
			data[i] = data[i] + 32;
		}
	}
}

//Function that returns char at given index
char String::at(int index) {
	if (index >= 0 && index < size) {
		return data[index];
	}
	return NULL;
}

//Function that returns index given a substring
int String::index(const char* x) {
	int index = 0;
	bool found = false;
	for (int i = 0; i < strlen(data); ++i) {
		if (data[i] == x[0]) {
			int c = i+1;
			found = true;
			for (int j = 1; j < strlen(x); ++j) {
				if (data[c] != x[j]) {
					found = false;
					break;
				}
				++c;
			}
			if (found == true)
				return i;
		}
	}
	return -1;
}

//Function to compare strings
bool String::compare(String obj1) {
	if (obj1.size == size) {
		bool found = true;
		for (int i = 0; i < obj1.size; ++i) {
			if (obj1.data[i] != data[i]) {
				found = false;
				break;
			}
		}
		if (found == true)
			return true;
	}
	return false;
}

/*
Concatenation functions
Params: integer, char, string, double, char array
Cascading functionality
*/
String* String::concat(const char* x) {
	char* temp = new char[size + strlen(x)];
	for (int i = 0; i < size; ++i)
		temp[i] = data[i];
	for (int i = 0; i < strlen(x); ++i)
		temp[i + size] = x[i];
	size = size + strlen(x);
	data = new char[size];
	for (int i = 0; i < size; ++i)
		data[i] = temp[i];
	return this;
}

String* String::concat(String x) {
	char* temp = new char[size + x.size];
	for (int i = 0; i < size; ++i)
		temp[i] = data[i];
	for (int i = 0; i < x.size; ++i)
		temp[i + size] = x.data[i];
	size = size + x.size;
	data = new char[size];
	for (int i = 0; i < size; ++i)
		data[i] = temp[i];
	return this;
}

void reverse(char* str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}

	// If number of digits required is more, then 
	// add 0s at the beginning 
	while (i < d)
		str[i++] = '0';

	reverse(str, i);
	str[i] = '\0';
	return i;
}

void ftoa(float n, char* res, int afterpoint)
{
	// Extract integer part 
	int ipart = (int)n;

	// Extract floating part 
	float fpart = n - (float)ipart;

	// convert integer part to string 
	int i = intToStr(ipart, res, 0);
	if (afterpoint != 0) {
		res[i] = '.'; 
		fpart = fpart * pow(10, afterpoint);
		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}

String* String::concat(int x) {
	char* temp = new char[size + 20];
	for (int i = 0; i < size; ++i)
		temp[i] = data[i];
	char intpart[20];
	int i = intToStr(x, intpart, 0);
	int j = size;
	size = size + strlen(intpart);
	data = new char[size];
	for (int i = 0; i < j; ++i)
		data[i] = temp[i];
	for (int i = 0; i < strlen(intpart); ++i) {
		data[i + j] = intpart[i];
	}
	return this;
}

String* String::concat(char x) {
	char* temp = new char[size + 1];
	for (int i = 0; i < size; ++i)
		temp[i] = data[i];
	temp[size] = x;
	size = size + 1;
	data = new char[size];
	for (int i = 0; i < size; ++i)
		data[i] = temp[i];
	return this;
}

String* String::concat(double x) {
	char* temp = new char[size + 30];
	for (int i = 0; i < size; ++i)
		temp[i] = data[i];
	char floatpart[30];
	ftoa(x, floatpart, 2);
	int j = size;
	size = size + strlen(floatpart);
	data = new char[size];
	for (int i = 0; i < j; ++i)
		data[i] = temp[i];	 
	for (int i = 0; i < strlen(floatpart); ++i) {
		data[i + j] = floatpart[i];
	}
	return this;
}

/*
Concatenation functions	at start of string
Params: integer, char, string, double, char array
Cascading functionality
*/
String* String::prepend(const char* x) {
	char* temp = new char[size + strlen(x)];
	for (int i = 0; i < strlen(x); ++i)
		temp[i] = x[i];
	for (int i = 0; i < size; ++i)
		temp[i+strlen(x)] = data[i];
	size = size + strlen(x);
	data = new char[size];
	for (int i = 0; i < size; ++i)
		data[i] = temp[i];
	return this;
}

String* String::prepend(String x) {
	char* temp = new char[size + x.size];
	for (int i = 0; i < x.size; ++i)
		temp[i + size] = x.data[i];
	for (int i = 0; i < size; ++i)
		temp[i+x.size] = data[i];
	size = size + x.size;
	data = new char[size];
	for (int i = 0; i < size; ++i)
		data[i] = temp[i];
	return this;
}

String* String::prepend(int x) {
	char* temp = new char[size + 20];
	for (int i = 0; i < size; ++i)
		temp[i] = data[i];
	char intpart[20];
	int i = intToStr(x, intpart, 0);
	int j = strlen(intpart);
	size = size + strlen(intpart);
	data = new char[size];
	for (int i = 0; i < strlen(intpart); ++i) {
		data[i] = intpart[i];
	}
	for (int i = 0; i < size; ++i)
		data[i+j] = temp[i];
	return this;
}

String* String::prepend(char x) {
	char* temp = new char[size + 1];
	temp[0] = x;
	for (int i = 0; i < size; ++i)
		temp[i+1] = data[i];
	size = size + 1;
	data = new char[size];
	for (int i = 0; i < size; ++i)
		data[i] = temp[i];
	return this;
}

String* String::prepend(double x) {
	char* temp = new char[size + 30];
	for (int i = 0; i < size; ++i)
		temp[i] = data[i];
	char floatpart[30];
	ftoa(x, floatpart, 2);
	int j = strlen(floatpart);
	size = size + strlen(floatpart);
	data = new char[size];
	for (int i = 0; i < strlen(floatpart); ++i) {
		data[i] = floatpart[i];
	}
	for (int i = 0; i < size; ++i)
		data[i+j] = temp[i];
	return this;
}

//assigns char array to string. Initializer
String* String::operator =(const char* x) {
	size = strlen(x);
	data = new char[size];
	for (int i = 0; i < size; ++i)
		data[i] = x[i];
	return this;
}

//inputs string
//resizable, hence it can take as much space available in heap
istream& operator>> (istream& in, String& obj) {
	char x=NULL;
	int n = 10;
    char* m = new char[n];
	int y = 0;
	while(true) {
		if (y >= n) {
			n = n * 2;
			char* temp = new char[n];
			for (int i = 0; i <= n / 2; ++i)
				temp[i] = m[i];
			m = new char[n];
			for (int i = 0; i <= n / 2; ++i)
				m[i] = temp[i];
			delete[] temp;
		}
		in.get(x);
		if (x == '\n')
			break;
		m[y] = x;
		in.clear();
		++y;
	} 
	m[y] = '\0';
	obj.size = y;
	obj.data = new char[obj.size];
	for (int i = 0; i < obj.size; ++i)
		obj.data[i] = m[i];	 
	delete[] m;
	return in;	
}

//outputs string
ostream& operator<< (ostream& out, String& obj) {
	for (int i = 0; i < obj.size; i++)
		out << obj.data[i];
	return out;
}

/*
Concatenation functions	using + overloaded operator	(both at start and end)
Params: integer, char, string, double, char array
Cascading functionality
*/
String operator +(const String& obj1, const String& obj2) {
	String obj3(obj1);
	obj3.concat(obj2);
	return obj3;
}

String operator +(const String& obj1, const char* x) {
	String obj3(obj1);
	obj3.concat(x);
	return obj3;
}

String operator +(const char* x, const String& obj2) {
	String obj3(obj2);
	obj3.prepend(x);
	return obj3;
}

String operator +(const String& obj1, int x) {
	String obj3(obj1);
	obj3.concat(x);
	return obj3;
}

String operator +(int x, const String& obj2) {
	String obj3(obj2);
	obj3.prepend(x);
	return obj3;
}

String operator +(const String& obj1, double x) {
	String obj3(obj1);
	obj3.concat(x);
	return obj3;
}

String operator +(double x, const String& obj2) {
	String obj3(obj2);
	obj3.prepend(x);
	return obj3;
}

String operator +(const String& obj1, char x) {
	String obj3(obj1);
	obj3.concat(x);
	return obj3;
}

String operator +(char x, const String& obj2) {
	String obj3(obj2);
	obj3.prepend(x);
	return obj3;
}

//string comparisons
bool operator== (const String& obj1, const String& obj2) {
	String obj3(obj1);
	bool x=obj3.compare(obj2);
	return x;
}

bool operator!= (const String& obj1, const String& obj2) {
	String obj3(obj1);
	bool x = obj3.compare(obj2);
	return !x;
}

bool operator < (const String& obj1, const String& obj2) {
	if (obj1.size < obj2.size)
		return true;
	return false;
}

bool operator > (const String& obj1, const String& obj2) {
	if (obj1.size < obj2.size)
		return false;
	return true;
}

//returns char at given index
char String::operator[] (unsigned j) {
	if (j >= 0 && j < size)
		return data[j];
	return NULL;
}