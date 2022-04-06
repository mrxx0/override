#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/prctl.h>
#include <sys/types.h>

int	main(void)
{
	pid_t 	pid = fork();
	char	str[32];
	memset(str,0 , 32);
	int	wait_id = 0;

	if (pid == 0) {
		prctl(PR_SET_PDEATHSIG, SIGHUP);
			//ptrace
		printf("Give me some shellcode, k");
		gets(str);
	} else {
		wait_id = wait(&wait_id);
	}

	return (0);
}
