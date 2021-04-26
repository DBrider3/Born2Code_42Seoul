#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int			c_cnt(char const *s, char c)
{
	int		cnt;
	int		i;

	i = 0;
	cnt = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
		{
			while (*(s + i) == c)
				i++;
		}
		else
		{
			if (i == 0)
			{
				if (*(s + i) != c)
					cnt++;
			}
			else if (*(s + i - 1) == c && *(s + i) != 0)
				cnt++;
			i++;
		}
	}
	return (cnt);
}

char const	*input_table(char const *s, char c, char **res)
{
	char	*end;
	int		len;
	int		i;

	while (1)
	{
		if (*s == c)
			s++;
		else
			break ;
	}
	end = strchr(s, c);
	if (end == 0)
		end = strchr(s, 0);
	len = end - s + 1;
	if (!(*res = malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (i < len - 1)
		(*res)[i++] = *s++;
	(*res)[i] = 0;
	s++;
	return (s);
}

char		**ft_split(char const *s, char c)
{
	int		cnt;
	char	**res;
	int		i;
	int		j;

	cnt = c_cnt(s, c);
	if (!(res = malloc(sizeof(char*) * (cnt + 1))))
		return (NULL);
	i = 0;
	while (i < cnt)
	{
		if ((s = input_table(s, c, &res[i++])) == NULL)
		{
			j = 0;
			while (j < i)
				free(res[j++]);
			free(res);
			return (NULL);
		}
	}
	res[i] = NULL;
	i = 0;
	return (res);
}


void		free_inside(char **ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
int main(void)
{
    char    **input;
    char    *line = "123 456 789";

	input = ft_split(line, ' ');
    free_inside(input);

    while (1)
    {

    }
    return (0);
}
