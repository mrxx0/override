#include <string.h>
#include <stdio.h>

unsigned int get_unum(void)
{
    unsigned int res = 0;
    fflush(stdout);
    scanf("%u", &res);
    return res;
}

int			store_number(unsigned int *tab)
{
	unsigned int 	number = 0;
	unsigned int 	index = 0;

	printf("Number:");
	number = get_unum();

	printf("Index:");
	index = get_unum();
	
	if (index % 3 == 0) {
		printf(" *** ERROR! ***\n");
		printf("This index is reserved for wil!\n");
		printf(" *** ERROR! ***\n");
		return (1);
	}
	tab[index] = number;
	return (0);
}

int			read_number(unsigned int *tab)
{
	unsigned int	index = 0;

	printf(" Index: ");
	index = get_unum();
	
	printf(" Number at data[%u] is %u\n", index , tab[index]);
	return (0);
}

int 		main()
{
	char		cmd[20];
	unsigned int 	tab[100];

	printf("----------------------------------------------------\n"\
		"  Welcome to wil's crappy number storage service!   \n"\
		"----------------------------------------------------\n"\
		" Commands:                                          \n"\
		"    store - store a number into the data storage    \n"\
		"    read  - read a number from the data storage     \n"\
		"    quit  - exit the program                        \n"\
		"----------------------------------------------------\n"\
		"   wil has reserved some storage :>                 \n"\
		"----------------------------------------------------\n");

	while (1) {
		printf("Input command: ");
		fgets(cmd, 20, stdin);
		cmd[strlen(cmd)-1] = '\0';
		if (strncmp(cmd, "store", 4) == 0) {
			if (!(store_number(tab)))
				printf("Completed %s command successfully\n", cmd);
			else 
				printf(" Failed to do %s command\n", cmd);
		}
		if (strncmp(cmd, "read", 3) == 0) {
			read_number(tab);
			printf("Completed %s command successfully\n", cmd);
		}
		if (strncmp(cmd, "quit", 4) == 0) {
			return (0);
		}
	}
	return (0);
}
