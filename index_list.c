/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:01:02 by ahajji            #+#    #+#             */
/*   Updated: 2023/01/31 23:47:37 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_list(t_list *lst, t_data *data)
{
	t_list	*lll;

	lll = lst;
	while (lll)
	{
		if (lll->index == 0)
		{
			data->min = lll->data;
			break ;
		}
		lll = lll->next;
	}
	while (lst)
	{
		if (data->min > lst->data && lst->index == 0)
			data->min = lst->data;
		lst = lst->next;
	}
}

void	index_list(t_list **lst, t_data *data)
{
	t_list	*lst_2;
	int		i;
	int		valid;

	valid = 0;
	i = 1;
	lst_2 = *lst;
	min_list(*lst, data);
	while (lst_2)
	{
		if (lst_2->data == data->min && lst_2->index == 0)
		{
			lst_2->index = i++;
			min_list(*lst, data);
			lst_2 = *lst;
			valid = 1;
		}
		if (valid == 0)
			lst_2 = lst_2->next;
		valid = 0;
	}
}
