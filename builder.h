#ifndef _BUILDER_H
#define _BUILDER_H

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>


enum {
	NUM_PARAM_ERR,
	SYNTAX_ERR
};


// plan to add attributes to the builder
typedef struct	s_attr {
	int			type;
	char		t;
	char		*name;
}				t_attr;

// plan to add inheritence to the builder
typedef struct	s_class {
	char		*name;
	// char		parent;
	// char		*p_name;
	// t_attr		*attr;
}				t_class;

t_class	**parser(int ac, char **av);

// file ft_makers
int		ft_make_header(t_class *c);
void	ft_make_files(t_class **c, int size);
int		ft_make_source(t_class *c);

// utils
char	*ft_strjoin(char const *s1, char const *s2);

// error return
int		error(int err);

// exit
void get_out(t_class **c);

#endif