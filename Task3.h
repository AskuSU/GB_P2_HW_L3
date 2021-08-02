#pragma once
#include<cstdint>
#include<string>
#include<iostream>


class Fraction
{
public:
	Fraction() : wholePart{ 0 }, isNegative{ false }, numerator{ 0 }, denominator{ 1 }, val{ "" }
	{};

	bool read();
	const std::string& get();

	Fraction& operator+=(const Fraction& fr);
	Fraction& operator-=(const Fraction& fr);
	Fraction& operator*=(const Fraction& fr);
	Fraction& operator/=(const Fraction& fr);

private:
	uint64_t wholePart, numerator, denominator;
	bool isNegative;
	std::string val;

	void cinFail();
	void checkIsNegative(int64_t& val);
	void simplifyAfraction();
};

Fraction operator+(Fraction fr1, const Fraction& fr2);
Fraction operator-(Fraction fr1, const Fraction& fr2);
Fraction operator*(Fraction fr1, const Fraction& fr2);
Fraction operator/(Fraction fr1, const Fraction& fr2);

uint64_t NOD(uint64_t a, uint64_t b);
uint64_t NOK(const uint64_t& a, const uint64_t& b);