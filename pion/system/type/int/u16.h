#pragma once

/// <summary>
/// Represents an 16-bit unsigned integer. [0 ... 65 535]
/// </summary>
class u16 : private obj
{
public:
	u16();
	u16(__int&& Value);

	void operator=(__int Value);
	operator __int();

	void operator++();
	void operator--();
	__int operator[](__int Mask);

private:
	unsigned char Value;
};

u16::u16()
{
	Value = 0;
}

u16::u16(__int&& Value)
{
	this->Value = Value;
}

void u16::operator=(__int Value)
{
	this->Value = Value;
}

u16::operator __int()
{
	return (__int)Value;
}

void u16::operator++()
{
	Value++;
}

void u16::operator--()
{
	Value--;
}

__int u16::operator[](__int Mask)
{
	__int Result = (__int)Value & Mask;
	for (; !(Mask & 0x1) && Result; Mask >>= 1, Result >>= 1) {}
	return Result;
}