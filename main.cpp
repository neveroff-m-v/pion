#include <stdio.h>

#include "pion/.h"

void main()
{
	u32 A = 1111111;
	u32 B = 10;

	B = 23;

	printf("\n %d %d %d %d %d \n"
		, A[0xFF000000]
		, A[0x00FF0000]
		, A[0x0000FF00]
		, A[0x000000FF]
	);
}