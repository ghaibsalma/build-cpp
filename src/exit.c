#include "builder.h"

void get_out(t_class **c) {
	int i = 0;
	while (c[i]) {
		free(c[i]->name);
		free(c[i]);
		i++;
	}
	free(c);
}