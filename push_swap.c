/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:08:48 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/02 15:27:53 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstnew(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->data = data;
	node->index = 0;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	node = ft_lstlast(*lst);
	node->next = new;
	new->next = NULL;
}

void	newlist_and_add(t_list **lst, t_data *data)
{
	int		i;
	t_list	*new_list;

	i = 0;
	while (i < data->num_arg)
	{
		new_list = lstnew(data->integers[i]);
		ft_lstadd_back(lst, new_list);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*head;
	t_list	*s_head;
	t_data	data;

	if (argc <= 1)
		return (0);
	head = NULL;
	s_head = NULL;
	check_arg(argc, argv, &data);
	newlist_and_add(&head, &data);
	index_list(&head, &data);
	check_if_sorted(&head, &data);
	data.max = data.num_arg;
	if (data.max == 5)
		sort_five(&head, &data, &s_head);
	else if (data.max == 3)
		sort_three(&head, &data, &s_head);
	else if (data.max <= 100)
		range(&head, &data, &s_head, 15);
	else if (data.max >= 500)
		range(&head, &data, &s_head, 35);
	free_all(&data, &head);
	return (0);
}
