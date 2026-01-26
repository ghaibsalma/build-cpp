#include "builder.h"

int	syntax_error() {
	write(2, "Syntax error", sizeof("Syntax error"));
	return (2);
}