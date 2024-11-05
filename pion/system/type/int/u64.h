#pragma once

/// <summary>
/// Represents an 64-bit unsigned integer. [0 ... 18 446 744 073 709 551 615]
/// </summary>
class u64 : private obj
{
public:
	u64();

	void operator=(__int Value);
	operator __int();

	__int operator[](__int Mask);

private:
	unsigned char Value;
};

u64::u64()
{
	Value = 0;
}

void u64::operator=(__int Value)
{
	this->Value = Value;
}

u64::operator __int()
{
	return (__int)Value;
}

__int u64::operator[](__int Mask)
{
	__int Result = (__int)Value & Mask;
	for (; !(Mask & 0x1) && Result; Mask >>= 1, Result >>= 1) {}
	return Result;
}