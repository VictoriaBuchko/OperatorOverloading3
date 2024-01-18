#include <iostream>
using namespace std;

#define TASK 1// поменяйте значение TASK что бы разблоуировать задание 

#if TASK == 1

class Fraction
{
	int Numerator;   // числитель
	int Denominator; // знаменатель
public:

	Fraction() {
		Numerator = 0;
		Denominator = 1;
	}

	Fraction(int numerator, int denominator) {
		Numerator = numerator;
		Denominator = denominator;
	}

	void SetNumeratorFirst() {
		do
		{
			cout << "Enter the numerator for the first fraction: \n";
			cin >> Numerator;

		} while (Numerator == 0);

	}
	void SetDenominatorFirst() {

		do
		{
			cout << "Enter the denominator for the first fraction: \n";
			cin >> Denominator;

		} while (Denominator == 0);
	}
	void SetNumeratorSecond() {

		do
		{
			cout << "Enter the numerator for the second fraction: \n";
			cin >> Numerator;

		} while (Numerator == 0);
	}

	void SetDenominatorSecond() {
		do
		{
			cout << "Enter the denominator for the second fraction: \n";
			cin >> Denominator;

		} while (Denominator == 0);
	}
	void SetNumerator(double result) {

		Numerator = result;
	}

	void SetDenominator(double result) {

		Denominator = result;
	}

	int GetNumerator() const {
		return Numerator;
	}

	int GetDenominator() const {
		return Denominator;
	}

	Fraction operator + (const Fraction& fraction2) const {
		Fraction sum;

		sum.Numerator = (Numerator) * (fraction2.Denominator) + (fraction2.Numerator) * (Denominator);
		sum.Denominator = Denominator * fraction2.Denominator;

		return sum;
	}

	Fraction operator - (const Fraction& fraction2) const {
		Fraction difference;

		difference.Numerator = Numerator * (fraction2.Denominator) - (fraction2.Numerator) * Denominator;
		difference.Denominator = Denominator * fraction2.Denominator;

		return difference;
	}

	Fraction operator *(const Fraction& fraction2) const {
		Fraction product;

		product.Numerator = Numerator * fraction2.Numerator;
		product.Denominator = Denominator * fraction2.Denominator;

		return product;
	}

	Fraction operator*(int value) const
	{
		Fraction product;
		product.Numerator = Numerator * value;
		product.Denominator = Denominator;
		return product;
	}



	Fraction operator /(const Fraction& fraction2) const {
		Fraction fraction;

		fraction.Numerator = Numerator * fraction2.Denominator;
		fraction.Denominator = Denominator * fraction2.Numerator;

		return fraction;
	}

	Fraction operator++() {

		Numerator++;
		Denominator++;

		return *this;
	}

	Fraction operator++(int) {

		Fraction temp = *this;

		Numerator++;
		Denominator++;

		return temp;
	}

	operator double() {
		return double(Numerator) / double(Denominator);
	}
};

void printResult(const Fraction& result) {

	if ((result.GetNumerator() == result.GetDenominator()) || result.GetNumerator() == 0)
		cout << result.GetNumerator() / result.GetDenominator();
	else
		cout << result.GetNumerator() << "/" << result.GetDenominator();
}

Fraction& operator*(int value, const Fraction& fraction)
{
	Fraction product;
	product.SetNumerator(value * fraction.GetNumerator());
	product.SetDenominator(fraction.GetDenominator());
	return product;
}

int main()
{
	Fraction fraction1;
	Fraction fraction2;

	fraction1.SetNumeratorFirst();
	fraction1.SetDenominatorFirst();
	fraction2.SetNumeratorSecond();
	fraction2.SetDenominatorSecond();
	cout << endl;

	int number = 5;
	cout << "+, -, *, /, using operator overloading" << endl;
	Fraction sum = fraction1 + fraction2;
	Fraction difference = fraction1 - fraction2;
	Fraction product = fraction1 * fraction2;
	Fraction product2 = fraction1 * number;
	Fraction product3 = number * fraction2;
	Fraction fraction = fraction1 / fraction2;


	cout << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << " + " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << " = ";
	printResult(sum);
	cout << endl;

	printResult(sum);
	double Sum = sum;
	cout << " = " << Sum << "\n\n";

	cout << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << " - " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << " = ";
	printResult(difference);
	cout << endl;

	printResult(difference);
	double Difference = difference;
	cout << " = " << Difference << "\n\n";

	cout << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << " * " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << " = ";
	printResult(product);
	cout << endl;

	printResult(product);
	double Product = product;
	cout << " = " << Product << "\n\n";

	cout << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << " * " << number << " = ";
	printResult(product2);
	cout << endl;

	cout << number << " * " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << " = ";
	printResult(product3);
	cout << "\n\n";

	cout << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << " / " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << " = ";
	printResult(fraction);
	cout << endl;

	printResult(fraction);
	double Fraction = fraction;
	cout << " = " << Fraction << "\n\n";

	fraction1++;
	cout << "Postfix increment: " << fraction1.GetNumerator() << "/" << fraction1.GetDenominator() << endl;

	++fraction2;
	cout << "Prefix increment: " << fraction2.GetNumerator() << "/" << fraction2.GetDenominator() << endl;


	return 0;
}

#elif TASK == 2

class MyString
{
	char* str;
	int size;
	static int count;//статическое поле 

public:


	MyString() : MyString(80) {}//конструктор по умолчанию

	MyString(int length) : size(length)//используем инициализатор
	{
		str = new char[size + 1];
		strcpy_s(str, size + 1, "");
		count++;
	}

	MyString(const char* Str) : MyString(strlen(Str))//при делегировании мы вызываем 2 коструктор
		//где определяем длину строки и выделяем под нее динамическую память и инициализирует ее пустой строкой
	{
		strcpy_s(str, size + 1, Str);//копирует содержимое строки Str в созданную строку(мы поручили создание этой строки коструктору 2)
		cout << "The copy constructor worked" << endl;
	}

	MyString(const MyString& string) : MyString(string.size)//использую делегирование, так как было предупреждение про неинициализированный размер
	{
		strcpy_s(str, size + 1, string.str);
	}


	void StrInput() {

		cout << "Enter a string: ";
		cin.getline(str, size + 1);
	}

	void Output()
	{
		cout << "String: " << str << endl;
	}

	static int GetCount()
	{
		return count;
	}


	int GetSize() const
	{
		return size;
	}

	char* GetStr() const
	{
		return str;
	}

	void SetSize(int newSize) {
		size = newSize;
	}

	void SetStr(char* newStr) {
		str = newStr;
	}


	MyString& operator++ () {

		int newSize = size + 1;
		char* newString = new char[newSize + 1];

		strcpy_s(newString, newSize + 1, str);
		newString[size] = 'x';
		newString[newSize] = '\0';

		delete[] str;
		str = newString;
		size = newSize;

		return *this;
	}

	MyString& operator-- () {

		if (size > 0) {

			int newSize = size - 1;
			char* newString = new char[newSize + 1];

			strncpy_s(newString, newSize + 1, str, newSize);
			newString[newSize] = '\0';

			delete[] str;
			str = newString;
			size = newSize;
		}

		return *this;
	}

	MyString operator+(int number) const {

		if (number < 0) {
			return *this;
		}

		int newSize = size + number;
		char* newStr = new char[newSize + 1];

		strcpy_s(newStr, newSize + 1, str);

		for (int i = size; i < newSize; ++i) {

			newStr[i] = 'x';
		}
		newStr[newSize] = '\0';

		MyString newString(newStr);

		delete[] newStr;

		return newString;

	}

	MyString operator-(int number) const {

		if (number <= 0 || number > size) {
			return *this;
		}

		int newSize = size - number;
		char* newStr = new char[newSize + 1];

		strncpy_s(newStr, newSize + 1, str, newSize);

		newStr[newSize] = '\0';

		MyString newString(newStr);

		delete[] newStr;
		return newString;
	}

	MyString& operator=(const MyString& object)
	{
		cout << "Copy assignment\n";
		if (!(this == &object))
		{
			if (str != nullptr)
			{
				delete[] str;
			}
			if (object.str == nullptr)
			{
				str = nullptr;
				size = object.size;
				return *this;
			}
			str = new char[strlen(object.str) + 1];
			strcpy_s(str, strlen(object.str) + 1, object.str);
			size = object.size;
			return *this;
		}
		return *this;
	}


	MyString operator++ (int) {

		MyString temp(*this);
		operator++();
		return temp;
	}

	MyString operator-- (int) {

		MyString temp(*this);
		operator--();
		return temp;
	}

	~MyString() {

		delete[] str;
		count--;
	}
};

int MyString::count = 0;

MyString operator+(int number, const MyString& myString) {

	if (number < 0) {
		return myString;
	}

	MyString temp;

	temp.SetSize(myString.GetSize() + number);
	temp.SetStr(new char[temp.GetSize() + 1]);

	for (int i = 0; i < number; ++i) {

		temp.GetStr()[i] = 'x';
	}

	if (myString.GetStr() != nullptr) {
		strcpy_s(temp.GetStr() + number, myString.GetSize() + 1, myString.GetStr());
	}

	return temp;
}

int main()
{
	MyString str1;
	str1.StrInput();

	MyString str2(20);
	str2.StrInput();

	MyString str3("Hello");

	cout << "\nObjects str: \n\n";

	str1.Output();
	str2.Output();
	str3.Output();

	MyString str4 = str3;
	str4.Output();

	MyString increment = ++str3;
	increment.Output();

	MyString decrement = --str3;
	decrement.Output();

	MyString plus = str3 + 4;
	plus.Output();


	MyString minus = str3 - 2;
	minus.Output();

	str1 = str2;
	str1.Output();

	cout << "Operation of the postfix form of increment" << endl;
	increment++;
	increment.Output();
	cout << "Operation of the postfix form of dikrimenta" << endl;
	decrement--;
	decrement.Output();

	MyString HelloWorld = "Hello Word";
	MyString newString;
	newString = 4 + HelloWorld;
	newString.Output();


	cout << "\nNumber of objects created " << MyString::GetCount() << endl;
	return 0;
}

#endif