#include "builder.h"

int	is_not_name(char *s) {
	int i = 0;
	while(s[i]) {
		if (!isalnum(s[i]) && !isspace(s[i]))
			return (1);
		i++;
	}
	return (0);
}

int	fill(int i, t_class *c, char** av) {
	c[i].name = strdup(av[i]);
	if (!c[i].name || is_not_name(c[i].name))
		return (0);
	return (1);
}

t_class *parser(int ac, char **av) {
	t_class	*classes;
	int		i = 0;

	classes = malloc(sizeof(t_class) * (ac + 1));
	while (i < ac) {
		if (!fill(i, classes, av)) {
			free(classes);
			return (NULL);
		}
		i++;
	}
	return (classes);
}