#include "main.h"

/**
 * prompt - call prompt to start shell input
 *
 **/
void prompt(void)
{
	for (;;)
	{
		size_t buffer_size = 0;
		char *prompt_text = NULL;
		int buff_len;
		int status;
		pid_t child_pid;

		_stream_writer("$ ");
		buff_len = getline(&prompt_text, &buffer_size, stdin);

		if (buff_len == -1)
			exit(98);
		if (_strcmp(prompt_text, "exit") == 0)
			exit(0);
		if (_strcmp(prompt_text, "env") == 0)
		{
			while (*environ != NULL)
			{
				if (!(_strcmp(*environ, "USER")) ||
						!(_strcmp(*environ, "LANGUAGE")) ||
						!(_strcmp(*environ, "SESSION")) ||
						!(_strcmp(*environ, "COMPIZ_CONFIG_PROFILE")) ||
						!(_strcmp(*environ, "SHLV")) ||
						!(_strcmp(*environ, "C_IS")) ||
						!(_strcmp(*environ, "DESKTOP_SESSION")) ||
						!(_strcmp(*environ, "LOGNAME")) ||
						!(_strcmp(*environ, "TERM")) ||
						!(_strcmp(*environ, "PATH")) ||
						!(_strcmp(*environ, "DISPLAY")))
				{
					_stream_writer(*environ), _stream_writer("\n");
				}
				environ++;
			}
		}

		child_pid = fork();

		if (child_pid < 0)
			perror("Error creating child fork");

		if (child_pid == 0)
			call_params(prompt_text);
		else
			wait(&status);
    }

}
