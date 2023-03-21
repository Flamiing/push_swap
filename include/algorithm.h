/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:10:57 by alaaouam          #+#    #+#             */
/*   Updated: 2023/02/27 21:37:07 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "../libft/include/libft.h"
# include "../include/push_swap.h"

void		ft_aproximity_a(t_stack **a);
void		ft_simple_sort(t_stack **stack);
void		ft_check(t_stack **a, t_stack **b);
void		ft_small_sort(t_stack **stack, char id);
void		ft_aproximity_b(t_stack **a, t_stack **b);
void		ft_sort_under_10(t_stack **a, t_stack **b);
void		ft_aproximity_big_a(t_stack **a, t_stack **b, int key);
void		ft_aproximity_big_b(t_stack **a, t_stack **b, int key);
void		ft_sort_over_100(t_stack **a, t_stack **b, t_stack **chunks);
void		ft_sort_under_100(t_stack **a, t_stack **b, t_stack **chunks);

int			ft_rotate(t_stack **stack, char id);
int			ft_get_key(t_stack **stack, size_t div);
int			ft_swap(t_stack *stack, char identity);
int			ft_find_smaller(t_stack **stack, int key);
int			ft_swap_a_and_b(t_stack *a, t_stack *b);
int			ft_push(t_stack **a, t_stack **b, char id);
int			ft_reverse_rotate(t_stack **stack, char id);
int			ft_smallest_closer(t_stack **stack, int key);
int			ft_rotate_a_and_b(t_stack **a, t_stack **b);
int			ft_get_max_or_min(t_stack **stack, char id);
int			ft_reverse_rotate_a_and_b(t_stack **a, t_stack **b);

ssize_t		ft_get_index(t_stack **stack, int nbr);

#endif