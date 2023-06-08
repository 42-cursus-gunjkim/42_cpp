#include <cstring>
#include <iostream>

class MyString {
private:
	char *stringContent;
	int stringLength;
	int memoryCapacity;

public:
	MyString(char c);
	MyString(const char *str);
	MyString(const MyString& str);
	explicit MyString(int capacity);
	~MyString();

	MyString& assign(const MyString& str);
	MyString& assign(const char *str);
	int capacity() const;
	void reserve(int size);

	char at(int i) const;

	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);

	MyString& erase(int loc, int num);

	int compare(const MyString& str) const;
	int compare(const char* str) const;

	int find(int find_from, const MyString& str) const;
	int find(int find_from, const char *str) const;
	int find(int find_from, char c) const;

	int length() const;
	void print() const;
	void println() const;

	bool operator==(MyString& str);
};