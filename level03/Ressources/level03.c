#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	char source[17]="Q}|u`sfg~sf{}|a3";
	char search[17];
	size_t len = 17;
	size_t i = 0;
	long key = 0x1337d00d;
	int j = 0;
	while (j < 3000)
	{
		bzero(&search, len);
		while (i < len)
		{
			char tmp = source[i] ^ j;
			search[i] = tmp;
			i++;
		}
		search[i] = '\0';
		if (strncmp(search, "Congratulations!", 16) == 0)
			printf("Match [%s] at id = %ld\n", search, key - j);
		j++;
		i = 0;
	}
}
