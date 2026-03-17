#include "builder.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (strdup(s2));
	if (!s2)
		return (strdup(s1));
	i = strlen(s1);
	len = strlen(s1) + strlen(s2);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	memmove(str, s1, i);
	memmove(&str[i], s2, strlen(s2));
	str[len] = '\0';
	return (str);
}