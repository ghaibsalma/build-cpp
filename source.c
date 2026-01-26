#include "builder.h"

int		ft_make_source(t_class *c) {
	char *s;
	s = ft_strjoin(c->name, ".cpp");
	int fd = open(s, O_CREAT | O_RDWR, 0777);
	if (fd == -1)
		return (0);
	free(s);
	s = ft_strjoin(c->name, ".hpp");
	int i;
	i = dprintf(fd, "#include \"%s\"\n\n%s::%s(void) {}\n\n", s, c->name, c->name);
	free(s);
	if (i == -1)
		return (0);
	i = dprintf(fd, "%s::%s(const %s& other) {\n\t*this = other;\n}\n\n", c->name, c->name, c->name);
	if (i == -1)
		return (0);
	i = dprintf(fd, "%s& %s::operator=(const %s& other) {\n\t(void)other;\n\treturn (*this);\n}\n\n%s::~%s(void) {}\n", c->name, c->name, c->name, c->name, c->name);
	if (i == -1)
		return (0);
	return (1);
}