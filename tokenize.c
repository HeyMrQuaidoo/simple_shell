#include "main.h"

#define TOKEN_BUFFER_SIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"

/**
 *  read_prompt - Reads the line from the command prompt
 *
 *  Return: returns input from commmand line
 **/
char *read_prompt(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(0);
		}
		else
		{
			perror("Failed to read prompt line");
			exit(1);
		}
	}
	
	return line;
}

/**
 *  tokenize - tokenizes given arguments
 *  @readline: line from the cmd prompt to tokenize
 *
 *  Return: returns input from commmand line
 **/
char **tokenize(char *readline)
{
	int position = 0;
	char *get_token;
	int buffer_size = TOKEN_BUFFER_SIZE;
	char **tokens = malloc(buffer_size * sizeof(char*));

	check_alloc_error(tokens);
	get_token = strtok(readline, TOKEN_DELIMITER);

	while (get_token != NULL)
	{
		tokens[position] = get_token;
		position++;
		
		tokens = check_realloc(position, buffer_size, tokens);
		get_token = strtok(NULL, TOKEN_DELIMITER);
	}
	tokens[position] = NULL;
	return tokens;
} 

/**
 * check_realloc - Check if reallocation of mem is needed
 * @position: current pointer to cursor of token
 * @buffer_size: current buffer size
 * @tokens: current token string
 *
 * Return: tokens
 **/
char **check_realloc(int position, int buffer_size, char **tokens)
{
	if (position >= buffer_size) {
		buffer_size += TOKEN_BUFFER_SIZE;
		tokens = realloc(tokens, buffer_size * sizeof(char*));
		check_alloc_error(tokens);
	}

	return (tokens);
}

/**
 * check_alloc_error - Check if there was an error in allocating token mem
 * @token: current token string
 * 
 * Return: Failure if there was an allocation error. Exits shell
 **/
void check_alloc_error(char **token)
{
	if (!token) {
		fprintf(stderr, "Failed to allocate memory!\n");
		exit(EXIT_FAILURE);
	}
}