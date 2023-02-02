/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:31:17 by ahajji            #+#    #+#             */
/*   Updated: 2023/02/02 17:38:36 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line/get_next_line.h"
# include "stdio.h"

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
char				*ft_strjoins(char *s1, char *s2);
int					strlens(char *s);
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
int					find_index_node(t_list *lst, int i);
void				free_all(t_data *data, t_list **lst);
void				print_error_free(t_data *data);
void				print_error_free_2(t_data *data);
void				check_if_sorted(t_list **lst, t_data *data);
void				choose_operation(t_list **head, t_list **s_head,
						t_data *data);

#endif