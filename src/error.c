#include "builder.h"

int	error(int err) {
	char *str;

	if (err == NUM_PARAM_ERR)
		str = strdup("This program requires at least one parameter.\n");
	else if (err == SYNTAX_ERR)
		str = strdup("Syntax error.\n");
	else
		str = strdup("Error.\n");
	write(2, str, strlen(str));
	free(str);
	return (err + 1);
}