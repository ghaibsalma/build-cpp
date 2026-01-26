#include "builder.h"

int		_ft_make_file(t_class *c) {
	if (!ft_make_header(c))
		return (0);
	if (!ft_make_source(c))
		return (0);
}

int		ft_make_ft_make(t_class *c, int size) {

}

int		free_files(t_class *c, int size) {

}

void	ft_make_files(t_class *c, int size) {
	int	i = 0;

	while (i < size) {
		if (!_ft_make_file(&c[i])) {
			free_files(c, i);
			return ;
		}
		i++;
	}
	ft_make_ft_make(c, size);
}