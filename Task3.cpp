#include"Task3.h"

bool Fraction::read()
{
	int64_t input;
	using std::cin;
	cin >> input;
	if (cin.fail())
	{
		cinFail();
	}
	else
	{
		if (cin)
		{
			if (cin.peek() == ' ')
			{
				cin.ignore();
				checkIsNegative(input);				
				wholePart = input;
				cin >> input;
				if (cin.fail())
				{
					cinFail();
					return false;
				};
			}
			else
			{
				wholePart = 0;
				isNegative = false;
			}
			if (cin.peek() == '/')
			{				
				cin.ignore();
				checkIsNegative(input);
				numerator = input;
				cin >> input;
				if (cin.fail()) 
				{
					cinFail();
					return false;
				};
				if (input == 0)
				{
					std::cout << "Нулевой делитель невозможен! Повторите ввод: ";
					denominator = 1;
					return false;
				}
				checkIsNegative(input);
				denominator = input;
			}
			else
			{
				denominator = 1;
			}
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			simplifyAfraction();
			return true;
		}
	}
	return false;
}

const std::string& Fraction::get()
{
	val = "";
	if (isNegative)
	{
		val += "-";
	}
	if (wholePart)
	{
		val += std::to_string(wholePart) + " ";
	}
	if (numerator && (denominator != 1))
	{
		val += std::to_string(numerator) + "/" + std::to_string(denominator);
	}
	return val;
}

Fraction Fraction::operator-() const
{
	return Fraction(wholePart, numerator, denominator, !isNegative);
}

Fraction& Fraction::operator+=(const Fraction& fr)
{
	int64_t nok = NOK(denominator, fr.denominator);
	uint64_t thisNum, frNum;
	bool resFractNegativ;
	if (isNegative ^ fr.isNegative)
	{
		if (wholePart >= fr.wholePart)
		{
			wholePart -= fr.wholePart;
		}
		else
		{
			wholePart = fr.wholePart - wholePart;
			isNegative = fr.isNegative;
		}
		
		thisNum = numerator * nok / denominator;
		frNum = fr.numerator * nok / fr.denominator;
		if (thisNum >= frNum)
		{
			numerator = thisNum - frNum;
			resFractNegativ = isNegative;
		}
		else
		{
			numerator = frNum - thisNum;
			resFractNegativ = fr.isNegative;
		}
		
		if (isNegative ^ resFractNegativ)
		{
			if (wholePart > 0)
			{
				wholePart--;
				numerator = nok - numerator;
			}
			else
			{
				isNegative = resFractNegativ;
			}
		}
	}
	else
	{
		wholePart += fr.wholePart;
		numerator = numerator * nok / denominator + fr.numerator * nok / fr.denominator;
	}	
	denominator = nok;
	simplifyAfraction();
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& fr)
{
	*this += -fr;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& fr)
{

	return *this;
}

Fraction& Fraction::operator/=(const Fraction& fr)
{

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

void Fraction::checkIsNegative(int64_t& val)
{
	if (val < 0)
	{
		isNegative = !isNegative;
		val = -val;
	}
}

void Fraction::simplifyAfraction()
{
	if (numerator >= denominator)
	{
		wholePart += numerator / denominator;
		numerator %= denominator;
	}
	uint64_t nod = NOD(numerator, denominator);
	if (nod > 1)
	{
		numerator /= nod;
		denominator /= nod;
	}
}


Fraction operator+(Fraction fr1, const Fraction& fr2)
{
	fr1 += fr2;
	return fr1;
};

Fraction operator-(Fraction fr1, const Fraction& fr2)
{
	fr1 -= fr2;
	return fr1;
};

Fraction operator*(Fraction fr1, const Fraction& fr2)
{
	fr1 *= fr2;
	return fr1;
};

Fraction operator/(Fraction fr1, const Fraction& fr2)
{
	fr1 /= fr2;
	return fr1;
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