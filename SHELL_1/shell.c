#include "shell.h"
/**
 * main - Entry point for the shell
 *
 * Description:
 * This function is the main entry point for the shell program.
 * It initializes the shell prompt, processes user input, tokenizes it,
 * and executes commands in a loop until the shell exits.
 *
 * Return: 0 for successful execution.
 */
int main(void)
{
	char *in;
	char **tokens;
	int state;
	char *prompt;

	prompt = ">>>>";
	do {
		write(1, prompt, 2);
		in = input();
		tokens = tokenizer(in);
		state = execute(tokens);

		free(in);
		free(tokens);
	} while (state);

	return (0);
}
