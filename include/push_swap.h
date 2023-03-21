/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:52:11 by alaaouam          #+#    #+#             */
/*   Updated: 2023/03/02 13:24:22 by alaaouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

int				ft_isnum(int c);
int				ft_free_array(char **arr);
int				ft_is_sorted(t_stack **stack);
int				ft_max_or_min_int(char *str);
int				ft_arrjoin(char *dest, char **arr, size_t size);
int				ft_has_repeated_numbers(t_stack **stack);

size_t			ft_arrsize(char **input);
size_t			ft_stacksize(t_stack *stack);

void			ft_free_stack(t_stack **stack);
void			*ft_free_array_and_return(char **arr);
void			ft_exit_program(int error, t_stack **stack);
void			ft_stackadd_front(t_stack **stack, t_stack *new);
void			ft_stackadd_back(t_stack **stack, t_stack *new);
void			ft_remove_node(t_stack **stack, t_stack *remove);
void			ft_sort_stack(t_stack **a, t_stack **b, t_stack **chunks);

t_stack			*ft_newnode(int number);
t_stack			*ft_stacklast(t_stack *stack);
t_stack			*ft_create_stack(t_stack **stack, char **arr);
t_stack			*parser(int size, char **args, t_stack **stack);

#endif
