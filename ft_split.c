/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:48:04 by ahajji            #+#    #+#             */
/*   Updated: 2023/01/14 10:06:50 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lenword(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static int	lenofword(char const *s, char c, int *j)
{
	int	i;

	i = 0;
	while (s[*j])
	{
		if ((*j == 0 && s[*j] != c) || (s[*j] != c && s[*j - 1] == c))
		{
			while (s[*j] != c && s[*j])
			{
				i++;
				*j = *j + 1;
			}
			return (i);
		}
		*j = *j + 1;
	}
	return (0);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	int		i;
	int		k;
	int		j;
	int		f;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	array = (char **)malloc((lenword(s, c) + 1) * sizeof(char *));
	if (!array)
		return (0);
	while (i < lenword(s, c))
	{
		k = lenofword(s, c, &j);
		f = j - k;
		array[i] = ft_substr(s, f, k);
		i++;
	}
	array[lenword(s, c)] = 0;
	i = 0;
	return (array);
}
