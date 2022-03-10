#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void 	test(int pass, int val)
{
	printf("%d %d", pass, val);

}

int		main(void)
{
		int password;

		srand(time(0));
		printf("***********************************\n");
		printf("*		level03		**\n");
		printf("***********************************\n");
		printf("Password:");
		scanf("%d", &password);
		test(password, 0x1337d00d);
		return (0);
}
