#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	printf("%u\n", (UINT_MAX / 4) + atoi(argv[1]) + 1);
	return (0);
}
