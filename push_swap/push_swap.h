/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpignet <mpignet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:50:43 by mpignet           #+#    #+#             */
/*   Updated: 2022/06/24 17:38:38 by mpignet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

void	add_element(t_list **lst, char *str);
int		args_check(t_list *lst, int ac, char **av);
int		parse(t_list *lst, int ac, char **av);
void	ft_swap(t_list **lst);
void	ft_push(t_list **a, t_list **b, char id);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);

#endif