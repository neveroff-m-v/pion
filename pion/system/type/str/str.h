#pragma once

class str : private obj
{
public:
	str();
	str(const utf8& Buffer);

	explicit str(utf8* Buffer);

	utf8& operator[](u32 i);

	u32 Length;
//private:
	utf8* Buffer;
};

str::str()
{
	Length = 0;
	Buffer = nullptr;
}

str::str(const utf8& Buffer)
{
	Length = 0;
	for (; (Buffer + Length) != '\n'; Length++);
	for (u32 i = 0; i < Length; i++) this->Buffer[i] = Buffer + i;
}

str::str(utf8* Buffer)
{
	this->Buffer = Buffer;
	Length = sizeof(Buffer);
}

utf8& str::operator[](u32 i)
{
	return Buffer[i];
}