#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 100;
	while (i < 200)
	{
		if (i % 3 == 0)
		{
			printf("i = %d\n", i);
		}
		i++;
	}
	return (0);
}
