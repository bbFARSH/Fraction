//Fraction - описываем простую дробь
#include<iostream>
using namespace std;

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	// CONSTRUCTORS
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "default constructor" << this << endl;
	}
	Fraction(int integer)
	{ 
		// Конструктор с одним параметром
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor: " << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		// обычная дробь, без целой части
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << " CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	// OPERATORS
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << " CopyAssignmed:\t" << this << endl;
		return *this;
	}
	// METHODS
	void to_proper()
	{
		//переводит дробь в правильную
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		// переводить дробь в неправильную
		numerator += integer * denominator;
		integer = 0;
	}
	void reduce()
	{

	}
	void print()
	{
		//5
		//1/2;
		//2(3/4);
		if (integer)cout << integer; // Если есть целая часть, выводим ее на экран
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;

	}

};
//#define Constructor_check
Fraction operator*(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator() * right.get_numerator(), left.get_denominator() * right.get_denominator());
}
Fraction operator/(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(left.get_numerator() / right.get_numerator(), left.get_denominator() / right.get_denominator());
}
Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction(left.get_integer() + right.get_integer(), left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator());

}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	return Fraction(left.get_integer() - right.get_integer(), left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(), left.get_denominator() * right.get_denominator());
}
ostream& operator<<(ostream& os, const Fraction& point)
{
	os << point.get_integer() << "(" << point.get_numerator() << "/" << point.get_denominator() << ")";
	return os;
}
void main()
{
	setlocale(LC_ALL, "");
#ifdef Constructor_check
	Fraction A; // default constructor
	A.print();
	Fraction B = 5; // single-argument parametr - конструктор с одним параметром
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // Constructor_check
#ifdef else
	Fraction A(14, 4);
	A.to_proper();
	A.print();
	A.to_improper();
	A.print();
#endif // else
	Fraction A(4, 6);
	Fraction B(2, 3);
	Fraction C = A * B;
	C.print();
	Fraction D = A / B;
    cout << D;
	Fraction E = A + B;
	E.to_proper();
	cout << E;
	Fraction F = A - B;
	F.print();
}