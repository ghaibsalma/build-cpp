#include "builder.h"

int main(int ac, char *av[])
{
	t_class	**c;

	if (ac < 2)
		return (error(NUM_PARAM_ERR));
	c = parser(ac - 1, &av[1]);
	if (!c)
		return (error(SYNTAX_ERR));
	ft_make_files(c, ac - 1);
	get_out(c);
}
