#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

char		PATH[255 + 10];

int		main(int arc, char ** arv)
{
	char	cp = 0;
	int	fdNewFile = 0;
	FILE 	*log_file = NULL;
	FILE 	*source_file = NULL;

	if (arc != 2) {
		printf("Usage: %s filename\n", arv[0]);
	}
	if (!(log_file = fopen("./backups/.log", "w"))) {
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	// log Wrapper
	if (!(source_file = fopen(arv[1], "r"))) {
		printf("ERROR: Failed to open %s\n", arv[1]);
		exit(1);
	}
	memcpy(PATH, "./backups/", 10);
	strncat(PATH, arv[1], strlen(arv[1]) + 10);
	if ((fdNewFile = open(PATH, O_WRONLY|O_CREAT|O_EXCL, 660)) < 0) {
		printf("ERROR: Failed to open %s\n", PATH);
		exit(1);
	}
	while ((cp = fgetc(source_file)) != EOF) {
		write(fdNewFile, &cp, 1);
	}
	//log_wrapper
	fclose(source_file);
	close(fdNewFile);
	return (0);
}
