/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:58:23 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/02 17:30:17 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (len == 0 || start >= ft_strlen(s))
	{
		p = malloc(1);
		p[0] = '\0';
		return (p);
	}
	p = malloc(len + 1);
	if (!p)
		return (0);
	while (s[start] && j < len)
		p[j++] = s[start++];
	p[j] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		count;
	char	*p;

	j = 0;
	count = 0;
	p = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!p)
		return (0);
	while (count < ft_strlen(s1))
	{
		p[count] = s1[count];
		count++;
	}
	while (count < ft_strlen(s1) + ft_strlen(s2))
		p[count++] = s2[j++];
	p[count++] = ' ';
	p[count] = '\0';
	free(s1);
	return (p);
}

int long	ft_atoi(const char *str)
{
	int			i;
	int			st;
	int long	result;

	st = 1;
	i = 0;
	result = 0;
	while ((str[i] == 32 || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			st *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * st);
}

void	print_error(void)
{
	write(2, "error", 5);
	exit(1);
}
