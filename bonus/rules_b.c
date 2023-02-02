/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:30:10 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/02 17:18:16 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rb(t_list **lst)
{
	t_list	*node;
	t_list	*last_node;

	if (ft_lstsize(*lst) < 2)
		return ;
	node = *lst;
	last_node = ft_lstlast(*lst);
	*lst = (*lst)->next;
	last_node->next = node;
	node->next = NULL;
}

void	rrb(t_list **lst)
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

void	sb(t_list **lst)
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

void	pb(t_list **lst, t_list **s_lst, t_data *data)
{
	t_list	*top;
	t_list	*last_node;
	t_list	*node;

	if (*lst == NULL)
		return ;
	top = *lst;
	*lst = (*lst)->next;
	if (*s_lst == NULL)
	{
		*s_lst = top;
		(*s_lst)->next = NULL;
		return ;
	}
	node = *s_lst;
	*s_lst = top;
	(*s_lst)->next = node;
	data->num_arg--;
	data->count_arg--;
}
