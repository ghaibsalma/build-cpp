#include "builder.h"

void	skip_space(char *s, int *i) {
	while(s[*i] && !isspace(s[*i]))
		*i += 1;
}

int		is_not_name(char *s) {
	int i = 0;

	skip_space(s, &i);
	while(s[i]) {
		if (isspace(s[i]))
			break ;
		if (!isalnum(s[i]))
			return (1);
		i++;
	}
	skip_space(s, &i);
	if (s[i])
		return (1);
	return (0);
}

int		fill(int i, t_class **c, char** av) {
	c[i] = malloc(sizeof(t_class));
	c[i]->name = strdup(av[i]);
	if (!c[i]->name || is_not_name(c[i]->name))
		return (0);
	return (1);
}

int		free_classes(t_class **c, int id) {
	int		i;

	i = 0;
	while(i <= id) {
		free(c[i]->name);
		free(c[i]);
		i++;
	}
	free(c);
	return (1);
}

int		parser(int ac, char **av, t_build *to_build) {
	int		i = 0;

	to_build->classes = malloc(sizeof(t_class*) * (ac + 1));
	while (i < ac) {
		if (!fill(i, to_build->classes, av))
			return (free_classes(to_build->classes, i));
		i++;
	}
	to_build->classes[i] = NULL;
	return (0);
}