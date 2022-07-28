/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:50:43 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/28 16:43:48 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int		parse(t_list **lst, int ac, char **av);
int		check_spaces(char *str);
int		check_double(t_list **lst, int elem);
int		check_sizeint(char *str);
int		check_integers(char *str);

t_list	*find_min(t_list *itera);
t_list	*find_max(t_list *itera);
int		lst_sorted(t_list *lst);
int		find_median(t_list *lst, int chunk_size);
void	sort_int_tab(int *tab, int size);
int		nb_abs(int nb);

void	ft_swap(t_list **lst, char id);
void	ft_push(t_list **a, t_list **b, char id);
void	ft_rotate(t_list **lst, char id);
void	ft_rrotate(t_list **lst, char id);
void	ft_double(t_list **stack_a, t_list **stack_b, int id);

void	sort_3(t_list **lst, char id);

void	pre_sort5(t_list **stack_a, t_list **stack_b);
void	pre_sort(t_list **stack_a, t_list **stack_b);

void	get_index(t_list **stack_a);
void	find_positions(t_list **stack_a, t_list **stack_b);
void	find_target_pos(t_list **stack_a, t_list **stack_b);
void	get_cost_a(t_list **stack_a, t_list **stack_b);
void	get_cost_b(t_list **stack_b);
void	sort_big(t_list **stack_a, t_list **stack_b);
void	finish_sorting(t_list **stack_a);
void	do_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b);

#endif