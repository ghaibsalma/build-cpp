#ifndef _BUILDER_H
#define _BUILDER_H

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct	s_attr {
	int			type;
	char		t;
	char		*name;
}				t_attr;

typedef struct	s_class {
	char		*name;
	// char		parent;
	// char		*p_name;
	// t_attr		*attr;
}				t_class;

t_class	*parser(int ac, char **av);

// file ft_makers
int		ft_make_header(t_class *c);
void	ft_make_files(t_class *c, int size);
int		ft_make_source(t_class *c);

// utils
char	*ft_strjoin(char const *s1, char const *s2);

// error return
int		syntax_error();

#endif