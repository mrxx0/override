#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>

int	auth(char *login, unsigned int serial)
{
	size_t	loginSize = 0;
	char	test;
	int	i = 0;

	login [strcspn(login, "\n")] = 0;
	loginSize = strnlen(login, 32);
	if (loginSize <= 5)
		return (1);
	
	if (ptrace(0, 1, 0, 0) == 0xffffffff) {
		printf("---------------------------\n");
		printf("| !! TAMPERING DETECTED !!  |\n");
		printf("---------------------------\n");
		return (1);
	}
	
	test = login[3];
	test ^= 0x1337;
	test += 0x5eeded;
	
	while (i < loginSize)
	{
		if (login[i] <= 0x1f)
			return (1);
		

		
		i++;
	}
	if (test == serial)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	char		login[32];
	unsigned int	serial;

	printf("***********************************\n");
	printf("*		level06		  *\n");
	printf("***********************************\n");
	printf("-> Enter Login: ");
	fgets(login, 32, stdin);

	printf("***********************************\n");
	printf("***** NEW ACCOUNT DETECTED ********\n");
	printf("***********************************\n");
	printf("-> Enter Serial: ");
	scanf("%u", &serial);
	if (auth (login, serial) == 0) {
		printf("Authenticated!");
		system("/bin/sh");
		return (0);
	}
	return (1);
}
