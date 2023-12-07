#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char    *ft_strjoin(char *s1, char *s2)
{
    if (!s1 || !s2)
        return (NULL);
    int        i;
    int        j;
    char    *new_str;

    i = 0;
    new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!new_str)
        return (NULL);
    while (s1[i])
    {
        new_str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        new_str[i] = s2[j];
        i++;
        j++;
    }
    new_str[i] = '\0';
    return (new_str);
}
