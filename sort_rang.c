/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rang.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:15:44 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/01 22:47:27 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_in_b(t_list **lst, t_data *data, t_list **s_lst)
{
	int	max;
	int	half;

	max = 0;
	half = 0;
	max = ft_lstsize(*s_lst);
	while (max)
	{
		half = max / 2;
		if ((*s_lst)->index == max)
		{
			pa(lst, s_lst, data);
			max--;
		}
		else if (find_index_node(*s_lst, max) > half)
			rrb(s_lst);
		else
			rb(s_lst);
	}
}

void	range(t_list **lst, t_data *data, t_list **s_lst, int rang)
{
	t_list	*node;
	t_data	*node2;
	int		i;

	i = 1;
	node = *lst;
	while (*lst)
	{
		if ((*lst)->index <= i)
		{
			pb(lst, s_lst, data);
			rb(s_lst);
			i++;
		}
		else if ((*lst)->index < i + rang)
		{
			pb(lst, s_lst, data);
			i++;
		}
		else
			ra(lst);
	}
	push_all_in_b(lst, data, s_lst);
}

void	sort_five_next(t_list **lst, t_data *data, t_list **s_lst)
{
	all_indix_0(lst);
	index_list(lst, data);
	sort_three(lst, data, s_lst);
	pa(lst, s_lst, data);
	pa(lst, s_lst, data);
}

void	sort_five(t_list **lst, t_data *data, t_list **s_lst)
{
	int	min;

	min = 1;
	data->max_5 = data->max;
	while (ft_lstsize(*lst))
	{
		if ((*lst)->index == min)
		{
			pb(lst, s_lst, data);
			data->max_5--;
			min++;
		}
		else
		{
			if (find_index_node(*lst, min) > data->max_5 / 2)
				rra(lst);
			else
				ra(lst);
		}
		if (ft_lstsize(*lst) == 3)
		{
			sort_five_next(lst, data, s_lst);
			break ;
		}
	}
}

void	sort_three(t_list **lst, t_data *data, t_list **s_lst)
{
	if ((*lst)->index == 2 && (*lst)->next->index == 1
		&& (*lst)->next->next->index == 3)
		sa(lst);
	else if ((*lst)->index == 3 && (*lst)->next->index == 2
		&& (*lst)->next->next->index == 1)
	{
		sa(lst);
		rra(lst);
	}
	else if ((*lst)->index == 3 && (*lst)->next->index == 1
		&& (*lst)->next->next->index == 2)
		ra(lst);
	else if ((*lst)->index == 2 && (*lst)->next->index == 3
		&& (*lst)->next->next->index == 1)
		rra(lst);
	else if ((*lst)->index == 1 && (*lst)->next->index == 3
		&& (*lst)->next->next->index == 2)
	{
		sa(lst);
		ra(lst);
	}
}
