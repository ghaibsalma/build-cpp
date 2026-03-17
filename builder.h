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

typedef struct	s_build {
	t_class		**classes;
	char		*flags;
}				t_build;

int		parser(int ac, char **av, t_build *to_build);

// file ft_makers
int		ft_make_header(t_build *to_build, int i);
void	ft_make_files(t_build *to_build, int size);
int		ft_make_source(t_build *to_build, int i);

// utils
char	*ft_strjoin(char const *s1, char const *s2);
void	skip_space(char *s, int *i);

// error return
int		error(int err);

// exit
void get_out(t_class **c);

#endif