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
	if (!strncmp(str, "Congratulations!", 17)) {
		system("/bin/sh");
	} else {
		printf("\nInvalid Password\n");
	}
}

void 		test(int pass, int val)
{
	val = val - pass;
	switch(val)
	{
		case 0x1:
			decrypt(val);
			break;
		case 0x2:
			decrypt(val);
			break;
		case 0x3:
			decrypt(val);
			break;
		case 0x4:
			decrypt(val);
			break;
		case 0x5:
			decrypt(val);
			break;
		case 0x6:
			decrypt(val);
			break;
		case 0x7:
			decrypt(val);
			break;
		case 0x8:
			decrypt(val);
			break;
		case 0x9:
			decrypt(val);
			break;
		case 0xA:
			decrypt(val);
			break;
		case 0xB:
			decrypt(val);
			break;
		case 0xC:
			decrypt(val);
			break;
		case 0xD:
			decrypt(val);
			break;
		case 0xE:
			decrypt(val);
			break;
		case 0xF:
			decrypt(val);
			break;
		case 0x10:
			decrypt(val);
			break;
		case 0x11:
			decrypt(val);
			break;
		case 0x12:
			decrypt(val);
			break;
		case 0x13:
			decrypt(val);
			break;
		case 0x14:
			decrypt(val);
			break;
		case 0x15:
			decrypt(val);
			break;
		default:
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
