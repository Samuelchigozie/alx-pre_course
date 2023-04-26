#include "shell.h"
/**
* main - main entry point
* Return: returns (0)
* collaborators: Chura33 && Tobestfol2
*/

int main(void)
{
	char *cmd = NULL;
	int status;
	size_t line_len = 0;
	char *arg = NULL;
	char *args[MAX_ARGS];
	int argc = 0;
	pid_t pid;
	char *envp[] = {NULL};

	while (1)
	{
	printf("$ ");
	if (getline(&cmd, &line_len, stdin) == -1)
		break;
	arg = strtok(cmd, " \n");
	while (arg != NULL && argc < 1)
	{
		args[argc++] = arg;
		arg = strtok(NULL, " \n");
	}
	args[argc] = NULL;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror("execve");
			free(cmd);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
	}
	free(cmd);
	return (0);
}

