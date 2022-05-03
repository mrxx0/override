#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_msg{
	char msg[140];
	char username[40];
	int msg_len;
} t_msg;

void secret_backdoor(void)
{
	char input[128];

	fgets(input, 128, stdin);
	system(input);
	return ;
}

void set_msg(t_msg *message)
{
	char new_message[1024];

	memset(new_message, 0, 1024);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(new_message, 1024, stdin);
	strncpy(message->msg, new_message, message->msg_len);
	return ;
}

void set_username(t_msg *message)
{
	char username[128];
	int  i = 0;

	memset(username, 0, 128);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(username, 128, stdin);
	while (i <= 40 && username[i])
	{
		message->username[i] = username[i];
		i++;
	}
	printf(">: Welcome, %s", message->username);
	return ;
}

void handle_message(void)
{
	t_msg message;

	memset(message.username, 0, 40);
	message.msg_len = 140;
	set_username(&message);
	set_msg(&message);
	puts(">: Msg sent!");
	return ;
}

int main ()
{
	puts(
			"--------------------------------------------\n" \
			"|   ~Welcome to l33t-m$n ~    v1337        |\n" \
			"--------------------------------------------\n");
	handle_message();
	return (1);
}
