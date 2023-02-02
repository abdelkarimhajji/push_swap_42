/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eroor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:57:29 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/01 23:20:25 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(t_list **lst, t_data *data)
{
	t_list		*node;
	int			i;
	int			count;

	node = *lst;
	count = 0;
	i = 1;
	while (node)
	{
		if ((node)->index == i)
			count++;
		i++;
		node = (node)->next;
	}
	if (count == data->num_arg)
		free_all(data, lst);
}

void	check_max_min(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_arg)
	{
		if (data->integers[i] > 2147483647)
			print_error_free(data);
		else if (data->integers[i] < -2147483648)
			print_error_free(data);
		i++;
	}
}

void	check_arg_3(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] == '+' && arg[i + 1] == '+') || (arg[i] == '+'
			&& arg[i + 1] == '-') || (arg[i] == '-' && arg[i + 1] == '+')
		|| (arg[i] == '-' && arg[i + 1] == '-'))
		print_error();
	if ((arg[i] != '-' && arg[i] != '+') && (arg[i] != ' ') && !(arg[i] >= '0'
			&& arg[i] <= '9'))
		print_error();
	if ((arg[i] == '-' || arg[i] == '+') && !(arg[i + 1] >= '0'
			&& arg[i + 1] <= '9'))
		print_error();
	if ((arg[i] == '-' || arg[i] == '+') && (arg[i - 1] >= '0'
			&& arg[i - 1] <= '9') && (arg[i + 1] >= '0' && arg[i + 1] <= '9'))
		print_error();
}

void	check_arg_2(char *arg)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (arg[i])
	{
		check_arg_3(&arg[i]);
		if (arg[i] == ' ')
			count++;
		i++;
	}
	if (count == i)
		print_error();
}

void	check_arg(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		check_arg_2(argv[i]);
		i++;
	}
	i = 1;
	data->ptr = 0;
	while (i < argc)
	{
		data->ptr = ft_strjoin(data->ptr, argv[i]);
		i++;
	}
	data->ret_split = ft_split(data->ptr, ' ');
	free(data->ptr);
	check_duplicate(data);
	check_max_min(data);
}
