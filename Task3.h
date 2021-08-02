#pragma once
#include<cstdint>
#include<string>
#include<iostream>


class Fraction
{
public:
	Fraction() : numerator{ 0 }, denominator{ 1 }, val{ "" }
	{};

	bool read();
	const std::string& get();

	Fraction& operator+=(Fraction fr);
	
	friend Fraction operator+(Fraction fr1, const Fraction& fr2);
	friend Fraction operator-(const Fraction& fr1, const Fraction& fr2);
	friend Fraction operator*(const Fraction& fr1, const Fraction& fr2);
	friend Fraction operator/(const Fraction& fr1, const Fraction& fr2);

protected:
	Fraction(int64_t num, int64_t den) : numerator{ num }, denominator{ den }
	{};

private:
	int64_t numerator, denominator;
	std::string val;

	void cinFail();
};

uint64_t NOD(uint64_t a, uint64_t b);
uint64_t NOK(const uint64_t& a, const uint64_t& b);