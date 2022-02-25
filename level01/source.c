#include <stdio.h>
#include <string.h>


int verify_user_pass(char *password)
{
	if (strcmp(password, "admin") == 0)
		return (1);
	else
		return (0);
}

int verify_user_name(char *user)
{
	if (strncmp(user, "dat_wil", 7) == 0)
		return (1);
	else
		return (0);
}
int main()
{
	char user[20];
	char password[80];
	printf("********* ADMIN LOGIN PROMPT *********\n");
	printf("Enter Username: ");
	fgets(user, 256, stdin);
	printf("verifying username....\n\n");
	if (verify_user_name(user) == 0)
	{
		printf("\nnope, incorrect username...\n");
		return (0);
	}
	else
	{
		printf("Enter Password:\n");
		fgets(password, 100, stdin);
		if (verify_user_pass(password) == 0)
		{
			printf("nope, incorrect password...\n\n");
			return (0);
		}
		
	}
}
