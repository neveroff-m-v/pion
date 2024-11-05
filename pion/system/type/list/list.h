#pragma once

template <typename type>
class list : private obj
{
public:
	list();

	type& operator[](u32 i);

	void add(type Value);
	void add(type* Value);

	u32 Size;
//private:
	type* Array;
};

template <typename type>
list<type>::list()
{
	Size = 0;
	Array = nullptr;
}

template <typename type>
type& list<type>::operator[](u32 i)
{
	return Array[i];
}

template <typename type>
void list<type>::add(type Value)
{
	type* Buffer = new type[Size + 1]{};

	for (u32 i = 0; i < Size; i++)
	{
		Buffer[i] = Array[i];
	}
	Buffer[Size] = Value;
	Size++;

	delete[] Array;
	Array = Buffer;	
}

template <typename type>
void list<type>::add(type* Value)
{
	if (Value == nullptr) return;

	type* Buffer = new type[Size + 1]{};

	for (u32 i = 0; i < Size; i++)
	{
		Buffer[i] = Array[i];
	}
	Buffer[Size] = *Value;
	Size++;

	delete[] Array;
	Array = Buffer;
}