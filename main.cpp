#include <stdio.h>

#include "pion/.h"

void main()
{
	//Array.add();


	u8 X;
	X = 0x07;

	u32 i;
	for (i = 0; i < 32; i = i + 1)
	{
		printf("%d\n", i);
	}

	u32 A;
	A = 1200;

	printf("%d \n"
		, X[0x0E]
	);

	printf("%d %d %d %d %d \n"
		, X[0x0E]
		, A[0xFF000000]
		, A[0x00FF0000]
		, A[0x0000FF00]
		, A[0x000000FF]
	);
}