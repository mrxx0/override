#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int 	res;

	res = 0;
	printf("***********************************\n");
	printf("* 	     -Level00 -		  *\n");
	printf("***********************************\n");
	printf("Password:");
	scanf("%d", &res);
	if (res == 0x149c)
	{
		printf("Authenticated!\n");
		system("/bin/sh");
	}
	else
		printf("\nInvalid Password!\n");
	return (0);
}
