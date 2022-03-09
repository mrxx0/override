#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	FILE 	*file;
	char	userName[70];
	char	flag[160];
	char	password[272];
	
	memset(userName, 0, 12);
	memset(flag, 0, 5);
	memset(password, 0, 12);
	if (!(file = fopen("/home/users/level03/.pass", "r"))) {
		fwrite("ERROR:failed to open password file\n", 36, 1,stderr);
		exit(1);
	}
	fread(flag, 41, 1, file);
	strcspn(flag, "\n");
	if (!fread) { //louche
		fwrite("ERROR: failed to read password file\n", 36, 1, stderr);
		exit(1);
	}	
	fclose(file);

	printf("===== [ Secure Access System v1.0 ] =====\n");
	printf("/***************************************\\\n");
	printf("| You must login to access this system. |\n");
	printf("\\**************************************/\n");

	printf("--[Username: ");
	fgets(userName, 100, stdin);
	userName[strcspn(userName, "\n")] = '\0';

	printf("\n--[Password: ");
	fgets(password, 100, stdin);
	password[strcspn(password, "\n")] = '\0';

	puts("*****************************************");

	if (strncmp(password, flag, 41) == 0) {
		printf("Greeting, %s!\n", userName);
		system("/bin/sh");
		exit(1);
	}
	printf(userName);
	printf(" does not have access!\n");
	exit(1);
}
