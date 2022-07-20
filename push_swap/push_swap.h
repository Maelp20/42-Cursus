/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:50:43 by mpignet           #+#    #+#             */
/*   Updated: 2022/07/20 14:13:19 by mpignet          ###   ########.fr       */
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
void	ft_swap(t_list **lst, char id);
void	ft_push(t_list **a, t_list **b, char id);
void	ft_rotate(t_list **lst, char id);
void	ft_rrotate(t_list **lst, char id);
void	sort_3(t_list **lst, char id);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	sort_big(t_list **stack_a, t_list **stack_b, int track_id);
t_list	*find_min(t_list *itera);
t_list	*find_max(t_list *itera);
int     lst_sorted(t_list *lst);
void	push_to_a(t_list **stack_a, t_list **stack_b, int track_id);
void	sort_b_to_a(t_list **stack_a, t_list **stack_b, int track_id);

void printlist(t_list *lst, char id);
void printchunk(t_list *lst, char id, int chunk_id);

#endif