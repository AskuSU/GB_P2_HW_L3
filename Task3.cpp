#include"Task3.h"

bool Fraction::read()
{
	using std::cin;
	cin >> numerator;
	if (cin.fail())
	{
		cinFail();
	}
	else
	{
		if (cin)
		{
			if (cin.peek() == '/')
			{
				cin.ignore();
				cin >> denominator;
				if (cin.fail()) 
				{
					cinFail();
					return false;
				};
				if (denominator == 0)
				{
					std::cout << "Нулевой делитель невозможен! Повторите ввод: ";
					denominator = 1;
					return false;
				}
				if (denominator < 0)
				{
					numerator = -numerator;
					denominator = -denominator;
				}
			}
			else
			{
				denominator = 1;
			}
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return true;
		}
	}
	return false;
}

const std::string& Fraction::get()
{
	val = "";
	val += std::to_string(numerator);
	if (denominator != 1) 
	{
		val += "/" + std::to_string(denominator); 
	};
	return val;
}

Fraction& Fraction::operator+=(Fraction fr)
{
	int64_t nok = NOK(denominator, fr.denominator);
	numerator = numerator * nok / denominator + fr.numerator * nok / fr.denominator;
	denominator = nok;
	return *this;
}

void Fraction::cinFail()
{
	using std::cin;
	using std::cout;

	cout << "Ошибка ввода, повторите ввод: ";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


Fraction operator+(Fraction fr1, const Fraction& fr2)
{
	fr1 += fr2;
	return fr1;
};

Fraction operator-(const Fraction& fr1, const Fraction& fr2)
{
	Fraction fr;

	return fr;
};

Fraction operator*(const Fraction& fr1, const Fraction& fr2)
{
	Fraction fr;

	return fr;
};

Fraction operator/(const Fraction& fr1, const Fraction& fr2)
{
	Fraction fr;

	return fr;
};

uint64_t NOD(uint64_t a, uint64_t b)
{
	while (a && b)
	{
		if (a > b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	return a + b;
};

uint64_t NOK(const uint64_t& a, const uint64_t& b)
{
	return a * b / NOD(a, b);
};