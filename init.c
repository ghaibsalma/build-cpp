#include "builder.h"

int main(int ac, char *av[])
{
	t_build	to_build;

	if (ac < 2)
		return (error(NUM_PARAM_ERR));
	bzero(&to_build, sizeof(t_build));
	if (parser(ac - 1, &av[1], &to_build))
		return (error(SYNTAX_ERR));
	ft_make_files(&to_build, ac - 1);
	get_out(to_build.classes);
}
