/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:37:54 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/02 15:13:04 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		count;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

t_list	*ft_beforlast(t_list *lst)
{
	t_list	*node;
	t_list	*tmp;

	node = ft_lstlast(lst);
	while (lst)
	{
		if (lst->next == node)
			tmp = lst;
		lst = lst->next;
	}
	return (tmp);
}

void	free_all(t_data *data, t_list **lst)
{
	int	i;

	i = 0;
	while (i < data->num_arg)
	{
		free(data->ret_split[i]);
		i++;
	}
	free(data->ret_split);
	while (*lst)
	{
		free(*lst);
		*lst = (*lst)->next;
	}
	*lst = NULL;
	free(data->integers);
	exit(0);
}

void	print_error_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_arg)
	{
		free(data->ret_split[i]);
		i++;
	}
	free(data->ret_split);
	free(data->integers);
	write(2, "error", 5);
	exit(1);
}

void	print_error_free_2(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_arg)
	{
		free(data->ret_split[i]);
		i++;
	}
	free(data->ret_split);
	write(2, "error", 5);
	exit(1);
}
