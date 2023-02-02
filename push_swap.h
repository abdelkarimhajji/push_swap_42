/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:40:21 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/01 23:20:25 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/********************************************************************/
/*						struct has linked list  					*/
/********************************************************************/

typedef struct s_list
{
	int				data;
	int				index;
	int				sort_list;
	struct s_list	*next;
}					t_list;
/********************************************************************/
/*						struct has data of project  				*/
/********************************************************************/

typedef struct s_data
{
	char			**ret_split;
	char			*ptr;
	int long		*integers;
	int				num_arg;
	int				count_arg;
	int				min;
	int				max;
	int				max_5;
	t_list			*node_tmp;
}					t_data;

/********************************************************************/
/*					function i need in my project   				*/
/********************************************************************/

int long			ft_atoi(const char *str);
char				**ft_split(char *s, char c);
char				*ft_substr(char *s, unsigned int start, int len);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strlen(char *s);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_beforlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					lenword(char const *s, char c);
void				print_error(void);
void				check_arg(int argc, char **argv, t_data *data);
void				check_duplicate(t_data *data);
void				check_duplicate(t_data *data);
void				ra(t_list **lst);
void				rra(t_list **lst);
void				pb(t_list **lst, t_list **s_lst, t_data *data);
void				sa(t_list **lst);
void				pa(t_list **s_lst, t_list **lst, t_data *data);
void				rb(t_list **lst);
void				rrb(t_list **lst);
void				sb(t_list **lst);
void				index_list(t_list **lst, t_data *data);
int					ft_lstsize(t_list *lst);
void				push_all_in_b(t_list **lst, t_data *data, t_list **s_lst);
void				range(t_list **lst, t_data *data, t_list **s_lst, int rang);
void				sort_five(t_list **lst, t_data *data, t_list **s_lst);
void				sort_three(t_list **lst, t_data *data, t_list **s_lst);
void				all_indix_0(t_list **lst);
int					find_index_node(t_list *lst, int i);
void				free_all(t_data *data, t_list **lst);
void				print_error_free(t_data *data);
void				print_error_free_2(t_data *data);
void				check_if_sorted(t_list **lst, t_data *data);

#endif