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

int		fill(int *i, t_class **c, char* av) {
	c[*i] = malloc(sizeof(t_class));
	c[*i]->name = strdup(av);
	if (!c[*i]->name || is_not_name(c[*i]->name))
		return (0);
	*i += 1;
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

int		flag(char *f, char *arg) {
	if (arg[0] != '-' || strlen(arg) != 2 || !*strchr("hom", arg[1]))
		return (0);
	if (arg[1] == 'h')
		f[0] = HELP_FLAG;
	else if (arg[1] == 'o' && !f[1])
		f[1] = ORTHDX_FLAG;
	else if (arg[1] == 'm' && !f[1])
		f[1] = MIN_FLAG;
	return (1);
}

int		parser(int ac, char **av, t_build *to_build) {
	int		i = 0;
	int		j = 0;

	to_build->classes = malloc(sizeof(t_class*) * (ac + 1));
	while (i < ac) {
		if (!flag(to_build->flags, av[i]) && !fill(&j, to_build->classes, av[i]))
			return (free_classes(to_build->classes, j));
		i++;
	}
	to_build->classes[j] = NULL;
	return (0);
}