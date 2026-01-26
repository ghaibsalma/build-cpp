#include "builder.h"

int main(int ac, char *av[])
{
	t_class	*c;
	if (ac < 2)
		return (0);
	c = parser(ac - 1, &av[1]);
	if (!c)
		return (2);
	ft_make_files(c, ac - 1);
}
