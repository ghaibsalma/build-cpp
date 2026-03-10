#include "builder.h"

void	ft_make_files(t_class **c, int size) {
	int	i = 0;

	while (i < size) {
		ft_make_header(c[i]);
		ft_make_source(c[i]);
		i++;
	}

}