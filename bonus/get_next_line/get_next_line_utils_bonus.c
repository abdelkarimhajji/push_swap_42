/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:06:10 by ahajji            #+#    #+#             */
/*   Updated: 2022/10/30 16:07:47 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		count;
	char	*p;
	int		len_s1;
	int		len_s2;

	j = 0;
	count = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 == 0 && len_s2 == 0)
		return (0);
	p = malloc(len_s1 + len_s2 + 1);
	if (!p)
		return (0);
	while (count < len_s1)
	{
		p[count] = s1[count];
		count++;
	}
	while (count < len_s1 + len_s2)
		p[count++] = s2[j++];
	p[count] = '\0';
	free(s1);
	return (p);
}

int	new_line(char *containe)
{
	int	i;

	i = 0;
	while (containe && containe[i])
	{
		if (containe[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*_get_line(char *s)
{
	int		count;
	char	*ptr;
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	count = 0;
	while (s[count] != '\0' && s[count] != '\n')
		count++;
	ptr = malloc(count + 2);
	while (s[i] && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	free(s);
	return (ptr);
}

char	*get_last_line(char *s)
{
	int		count_2;
	int		count;
	char	*ptr;
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	count_2 = 0;
	count = 0;
	while (s[count_2] != '\0' && s[count_2] != '\n')
		count_2++;
	if (s[count_2] == '\n')
		count_2++;
	while (s[count])
		count++;
	if ((count - count_2) <= 0)
		return (0);
	ptr = malloc((count - count_2) + 1);
	while (s[count_2] != '\0')
		ptr[i++] = s[count_2++];
	ptr[i] = '\0';
	return (ptr);
}
