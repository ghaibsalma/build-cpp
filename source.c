#include "builder.h"

int		ft_make_source(t_build *to_build, int i) {
	t_class	*c;
	char	*s;
	int		fd;

	c = to_build->classes[i];
	s = ft_strjoin(c->name, ".cpp");
	fd = open(s, O_CREAT | O_RDWR, 0777);
	free(s);
	s = ft_strjoin(c->name, ".hpp");
	dprintf(fd, "#include \"%s\"\n\n%s::%s(void) {}\n\n", s, c->name, c->name);
	free(s);
	dprintf(fd, "%s::%s(const %s& other) {\n\t*this = other;\n}\n\n", c->name, c->name, c->name);
	dprintf(fd, "%s& %s::operator=(const %s& other) {\n\t(void)other;\n\treturn (*this);\n}\n\n%s::~%s(void) {}\n", c->name, c->name, c->name, c->name, c->name);
	close(fd);
	return (1);
}