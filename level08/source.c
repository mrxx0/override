#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


void	log_wrapper(FILE *file, char *str, char *name) {
    	char buff[300];

    	strcpy(buff, str);
    	snprintf(buff + strlen(buff), strlen(name), name);
   	fprintf(file, "LOG: %s\n", buff);
}

int		main(int arc, char ** argv)
{
	char	cp = 0;
	int	fd_new_file = 0;
	FILE 	*log_file = NULL;
	FILE 	*backup_file = NULL;
	char	backup[255 + 10];


	if (arc != 2) {
		printf("Usage: %s filename\n", argv[0]);
	}
	if (!(log_file = fopen("./backups/.log", "w"))) {
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}
	log_wrapper(log_file, "Starting back up:", argv[1]);
	if (!(backup_file = fopen(argv[1], "r"))) {
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}
	memcpy(backup, "./backups/", 10);
	strncat(backup, argv[1], strlen(argv[1]) + 10);
	if ((fd_new_file = open(backup, O_WRONLY|O_CREAT|O_EXCL, 0660)) < 0) {
		printf("ERROR: Failed to open %s\n", backup);
		exit(1);
	}
	while ((cp = fgetc(backup_file)) != EOF) {
		write(fd_new_file, &cp, 1);
	}
	log_wrapper(log_file, "Finished back up:", argv[1]);
	fclose(backup_file);
	close(fd_new_file);
	return (0);
}
