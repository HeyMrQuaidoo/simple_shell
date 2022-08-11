#include "main.h"

/**
 *_strlen - function that returns
 * the length of a string.
 *
 *@s: char s
 *Return: Always success
 */
int _strlen(char *s)
{
	int n = 0;

	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}


/**
 * _strcat - function that concatenates two strings.
 * @dest: dest string
 * @src: src string
 * Return: dest - concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
	{
		a++;
	}

	while (src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}


/**
 * call_params - Get parameters from command prompt and exec procedure
 * @parameter: Prompt to call
 * Return: result of function call
 **/
char **call_params(char *parameter)
{
	int i = 0;
	char *split_token;
	char *delim = " \t\n";
	char **buffer = malloc(1024 * sizeof(char *));

	split_token = strtok(parameter, delim);

	while (split_token != NULL)
	{
		buffer[i] = split_token;
		i++;
		split_token = strtok(NULL, delim);
	}
	exec_cmd(buffer);
	return (buffer);

}


/**
 * exec_cmd - function call to run commands from commmand prompt
 * @cmd: a pointer to cmd
 *
 * Return nothing
 */
void exec_cmd(char **cmd)
{

	char *param = (*(cmd + 1));
	char *s, *slash = "/";
	char *o;

	char *cmd_cpy = *cmd;
	char *argv[4];

	if ((access(cmd[0], F_OK) == 0))
	{
		argv[0] = cmd[0];
		argv[1] = param;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
	else
	{
		o = run_cmd(cmd_cpy);
		slash = _strcat(o, slash);
		s = _strcat(slash, *cmd);

		argv[0] = s;
		argv[1] = param;
		argv[2] = ".";
		argv[3] = NULL;

		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}

/**
 * run_cmd - exec command
 * @command: command to execute
 *
 * Return: string of folder for command to be executed.
 **/
char *run_cmd(char *command)
{
	DIR *folder;
	struct dirent *entry;
	char *cmd, comp, **str  = malloc(sizeof(char) * 1024);
	char **split = malloc(sizeof(char) * 1024);
	int i;

	while (*environ != NULL)
	{
		if (!(_strcmp(*environ, "PATH")))
		{
			*str = *environ;
			for (i = 0; i < 9; i++, split++, str++)
			{
				*split = strtok(*str, ":='PATH'");
				folder = opendir(*split);
				if (folder == NULL)
				{
					perror("Unable to read directory");
				}
				while ((entry = readdir(folder)))
				{
					cmd = entry->d_name;
					comp = _strcmp(cmd, command);
					if (comp == 0)
					{
						return (*split);
					}
					if (cmd == NULL)
					{
						perror("Error");
					}}}}
		environ++;
	}
	return ("Error");
}

