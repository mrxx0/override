#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void		decrypt(int val)
{
	char 	str[] = "Q}|u`sfg~sf{}|a3";
	int		i = 0;
	int		j = 0;

	while (str[i] != '\0')
		i++;
	while (j < i ) {
		char c = str[j] ^ val;
		str[j] = c;
		j++;
	}
	printf("%s \n", str);
	if (!strncmp(str, "Congratulations!", 17)) {
		system("/bin/sh");
	} else {
		printf("\nInvalid Password\n");
	}
}

void 		test(int pass, int val)
{
	val = val - pass;
	if (val == 0x15) {
		int decalage = val << 2;
		decalage += 134515184;
		//jmp louche
		decrypt(val);
	} else {
		decrypt(rand());
	}
}

int		main(void)
{
		int password;

		srand(time(NULL));
		printf("***********************************\n");
		printf("*		level03		**\n");
		printf("***********************************\n");
		printf("Password:");
		scanf("%d", &password);
		test(password, 0x1337d00d);
		return (0);
}
