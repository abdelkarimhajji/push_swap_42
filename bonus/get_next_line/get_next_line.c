/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:37:22 by ahajji            #+#    #+#             */
/*   Updated: 2022/10/30 16:01:40 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*con;
	char		*ptr;
	int			r;

	r = 1;
	ptr = 0;
	if (con != NULL)
		ptr = ft_strjoin(con, ptr);
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0 || fd == 1 || fd == 2)
			break ;
		buf[r] = '\0';
		ptr = ft_strjoin(ptr, buf);
		if (new_line(ptr))
			break ;
	}
	con = get_last_line(ptr);
	return (_get_line(ptr));
}
