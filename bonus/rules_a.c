/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:38:30 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/02 15:39:45 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_list **lst)
{
	t_list	*node;
	t_list	*last_node;

	node = *lst;
	last_node = ft_lstlast(*lst);
	*lst = (*lst)->next;
	last_node->next = node;
	node->next = NULL;
}

void	rra(t_list **lst)
{
	t_list	*node;
	t_list	*last_node;
	t_list	*head;

	head = *lst;
	last_node = ft_lstlast(*lst);
	node = ft_beforlast(*lst);
	node->next = NULL;
	last_node->next = head;
	*lst = last_node;
}

void	sa(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*tmp_2;

	head = *lst;
	tmp = (*lst)->next;
	tmp_2 = tmp->next;
	*lst = tmp;
	(*lst)->next = head;
	head->next = tmp_2;
}

void	pa(t_list **lst, t_list **s_lst, t_data *data)
{
	t_list	*top;
	t_list	*last_node;
	t_list	*node;

	if (*s_lst == NULL)
		return ;
	top = *s_lst;
	*s_lst = (*s_lst)->next;
	if (*lst == NULL)
	{
		*lst = top;
		(*lst)->next = NULL;
		return ;
	}
	node = *lst;
	*lst = top;
	(*lst)->next = node;
	data->num_arg++;
	data->count_arg++;
}
