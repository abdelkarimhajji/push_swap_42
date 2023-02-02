/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_function_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:25:34 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/02 17:49:13 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	choose_operation(t_list **head, t_list **s_head, t_data *data)
{
	char	*ptr;

	ptr = get_next_line(0);
	while (ptr)
	{
		if (ptr[0] == 'r' && ptr[1] == 'a')
			ra(head);
		else if (ptr[0] == 'r' && ptr[1] == 'r' && ptr[2] == 'a')
			rra(head);
		else if (ptr[0] == 's' && ptr[1] == 'a')
			sa(head);
		else if (ptr[0] == 'p' && ptr[1] == 'a')
			pa(head, s_head, data);
		else if (ptr[0] == 'r' && ptr[1] == 'b')
			rb(s_head);
		else if (ptr[0] == 'r' && ptr[1] == 'r' && ptr[2] == 'b')
			rrb(s_head);
		else if (ptr[0] == 's' && ptr[1] == 'b')
			sb(s_head);
		else if (ptr[0] == 'p' && ptr[1] == 'b')
			pb(head, s_head, data);
		else
			print_error();
		ptr = get_next_line(0);
	}
}

void	convert_integer(t_data *data)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	data->num_arg = 0;
	while (data->ret_split[data->num_arg])
		data->num_arg++;
	data->integers = (int long *)malloc(data->num_arg * sizeof(int long));
	if (!data->integers)
		print_error_free_2(data);
	j = 0;
	while (j < data->num_arg)
	{
		data->integers[j] = ft_atoi(data->ret_split[j]);
		j++;
	}
}

void	check_duplicate(t_data *data)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	convert_integer(data);
	while (j < data->num_arg)
	{
		i = j + 1;
		while (i < data->num_arg)
		{
			if (data->integers[j] == data->integers[i])
				print_error_free(data);
			i++;
		}
		j++;
	}
}

void	all_indix_0(t_list **lst)
{
	t_list	*node;

	node = *lst;
	while (node)
	{
		node->index = 0;
		node = node->next;
	}
}

int	find_index_node(t_list *lst, int i)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		if (lst->index == i)
			break ;
		lst = lst->next;
	}
	return (count);
}
