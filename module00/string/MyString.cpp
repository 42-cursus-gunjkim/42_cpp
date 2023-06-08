#include "MyString.hpp"

MyString::MyString(char c) {
	stringContent = new char[1];
	stringContent[0] = c;
	stringLength = 1;
	memoryCapacity = 1;
}

MyString::MyString(const char *str) {
	stringLength = strlen(str);
	memoryCapacity = stringLength;
	stringContent = new char[stringLength];
	for (int i = 0; i < stringLength; i++) stringContent[i] = str[i];
}

MyString::MyString(const MyString& str) {
	stringLength = str.stringLength;
	memoryCapacity = stringLength;
	stringContent = new char[stringLength];
	for (int i = 0; i < stringLength; i++) stringContent[i] = str.stringContent[i];
}

MyString::MyString(int capacity)
{
	stringContent = new char[capacity];
	stringLength = 0;
	memoryCapacity = capacity;
}

MyString::~MyString() { delete[] stringContent; }

MyString& MyString::assign(const MyString& str) {
	if (memoryCapacity < str.stringLength)
	{
		delete[] stringContent;
		stringContent = new char[str.stringLength];
		memoryCapacity = str.stringLength;
	}
	for (int i = 0; i < str.stringLength; i++)
		stringContent[i] = str.stringContent[0];
	stringLength = str.stringLength;
	
	return *this;
}

MyString& MyString::assign(const char* str) {
	int strLength = strlen(str);
	if (memoryCapacity < strLength)
	{
		delete[] stringContent;
		stringContent = new char[strLength];
		memoryCapacity = strLength;
	}
	for (int i = 0; i < strLength; i++)
		stringContent[i] = str[0];
	stringLength = strLength;
	
	return *this;
}

int MyString::capacity() const { return memoryCapacity; }

void MyString::reserve(int size) {
	if (size > memoryCapacity)
	{
		char *prevContent = stringContent;
		stringContent = new char[size];
		memoryCapacity = size;
		for (int i = 0; i < stringLength; i++)
			stringContent[i] = prevContent[i];
		delete[] prevContent;
	}
}

char MyString::at(int i) const {
	if (i >= stringLength || i < 0)
		return 0;
	else
		return stringContent[i];
}

MyString& MyString::insert(int loc, const MyString& str) {
	if (loc < 0 || loc > stringLength) return *this;

	if (stringLength + str.stringLength > memoryCapacity)
	{
		if (memoryCapacity * 2 > stringLength + str.stringLength)
			memoryCapacity *= 2;
		else
			memoryCapacity = stringLength + str.stringLength;
		char *prevContent = stringContent;
		stringContent = new char[memoryCapacity];
		int i;
		for (i = 0; i < loc; i++)
			stringContent[i] = prevContent[i];
		for (int j = 0; j < str.stringLength; j++)
			stringContent[i + j] = str.stringContent[j];
		for (; i < stringLength; i++)
			stringContent[str.stringLength + i] = prevContent[i];
		delete[] prevContent;
		stringLength = stringLength + str.stringLength;
		return *this;
	}
	for (int i = stringLength - 1; i >= loc; i--)
		stringContent[i + str.stringLength] = stringContent[i];
	for (int i = 0; i < str.stringLength; i++)
		stringContent[i + loc] = str.stringContent[i];
	
	stringLength = stringLength + str.stringLength;
	return *this;
}

MyString& MyString::insert(int loc, const char *str)
{
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c)
{
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num)
{
	if (num < 0 || loc < 0 || loc > stringLength) return *this;

	if (loc + num >= stringLength)
		stringLength = loc;
	for (int i = loc + num; i < stringLength; i++)
		stringContent[i - num] = stringContent[i];
	stringLength -= num;
	return *this;
}

int MyString::find(int find_from, const MyString &str) const
{
	int i, j;

	if (str.stringLength == 0) return -1;
	for (i = find_from; i < stringLength - str.stringLength; i++)
	{
		for (j = 0; j < str.stringLength; j++)
			if (stringContent[i + j] != str.stringContent[j]) break;
		if (j == str.stringLength) return i;
	}
	return -1;
}


int MyString::find(int find_from, const char* str) const
{
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const
{
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const
{
	for (int i = 0; i < std::min(stringLength, str.stringLength); i++) {
    if (stringContent[i] > str.stringContent[i])
      return 1;

    else if (stringContent[i] < str.stringContent[i])
      return -1;
	}

	if (stringLength == str.stringLength) return 0;

	else if (stringLength > str.stringLength)
    	return 1;

  	return -1;
}

int MyString::compare(const char* str) const
{
	MyString temp(str);
	return compare(temp);
}

int MyString::length() const { return stringLength; }

void MyString::print() const { for (int i = 0; i != stringLength; i++) std::cout << stringContent[i]; }

void MyString::println() const
{
	for (int i = 0; i != stringLength; i++)
		std::cout << stringContent[i];
	std::cout << std::endl;
}

bool MyString::operator==(MyString& str)
{
	return !compare(str);
}
