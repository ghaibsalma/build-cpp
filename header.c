#include "builder.h"

char *str_toupper(char *c) {
	char *s;
	s = malloc(strlen(c) + 1);
	int i = 0;
	while (c[i]) {
		s[i] = toupper(c[i]);
		i++;
	}
	s[i] = 0;
	return (s);
}

int		ft_make_header(t_class *c) {
	char	*s;
	char	*t;
	int		fd;

	s = ft_strjoin(c->name, ".hpp");
	fd = open(s, O_CREAT | O_RDWR, 0777);
	free(s);
	s = str_toupper(c->name);
	t = ft_strjoin(s, "_HPP");
	free(s);
	dprintf(fd, "#ifndef %s\n#define %s\n\nclass %s {\n\tpublic:\n\t\t%s(void);\n", t, t, c->name, c->name);
	free(t);
	dprintf(fd, "\t\t%s(const %s& other);\n\t\t%s& operator=(const %s& other);", c->name, c->name, c->name, c->name);
	dprintf(fd, "\n\t\t~%s(void);\n};\n\n#endif\n", c->name);
	close(fd);
	return (1);
}