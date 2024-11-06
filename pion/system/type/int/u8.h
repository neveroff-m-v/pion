#pragma once

/// <summary>
/// Represents an 8-bit unsigned integer. [0 ... 255]
/// </summary>
class u8 : private obj
{
public:
	u8();
	u8(__int&& Value);

	void operator=(__int& Value);
	operator __int();

	void operator++();
	void operator--();
	__int operator[](__int Mask);

private:
	unsigned char Value;
};

u8::u8()
{
	Value = 0;
}

u8::u8(__int&& Value)
{
	this->Value = Value;
}

void u8::operator=(__int& Value)
{
	this->Value = Value;
}

u8::operator __int()
{
	return (__int) Value;
}

void u8::operator++()
{
	Value++;
}

void u8::operator--()
{
	Value--;
}

__int u8::operator[](__int Mask)
{
	__int Result = (__int)Value & Mask;
	for (; !(Mask & 0x1) && Result; Mask >>= 1, Result >>= 1) {}
	return Result;
}