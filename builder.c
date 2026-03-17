#include "builder.h"

void	ft_make_files(t_build *to_build, int size) {
	int	i = 0;

	while (to_build->classes[i]) {
		ft_make_header(to_build, i);
		ft_make_source(to_build, i);
		i++;
	}

}