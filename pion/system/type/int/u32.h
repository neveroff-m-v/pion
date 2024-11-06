#pragma once

/// <summary>
/// Represents an 32-bit unsigned integer. [0 ... 4 294 967 295]
/// </summary>
class u32 : private obj
{
public:
	u32();
	u32(__int&& Value);

	void operator=(__int& Value);
	operator __int();

	void operator++();
	void operator--();
	__int operator[](__int Mask);

private:
	unsigned long Value;
};

u32::u32()
{
	Value = 0;
}

u32::u32(__int&& Value)
{
	this->Value = Value;
}

void u32::operator=(__int& Value)
{
	this->Value = Value;
}

u32::operator __int()
{
	return (__int) Value;
}

void u32::operator++()
{
	Value++;
}

void u32::operator--()
{
	Value--;
}

__int u32::operator[](__int Mask)
{
	__int Result = (__int)Value & Mask;
	for (; !(Mask & 0x1) && Result; Mask >>= 1, Result >>= 1) {}
	return Result;
}