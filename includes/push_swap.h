/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:55:16 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/25 20:55:16 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}		t_stack;

void	error_mss(void);
int		is_no_arg(int ac, char **av);
void	is_correct(int ac, char **av);
void	sign_between_nbr(int ac, char **av);
int		is_duplicate(t_stack *a);
int		is_zero(const char *s);
long	ft_atol(const char *nptr);
int		int_range(char	*s);
t_stack	*get_args(t_stack *a, int ac, char **av);
int		is_sorted(t_stack *a);
void	check(t_stack **a, int ac, char **av);
t_stack	*stack_new(int data);
t_stack	*ft_last(t_stack *elem);
void	ft_stackadd_back(t_stack **elem, t_stack *new);
int		ft_stacksize(t_stack *stack);
void	stackclear(t_stack *a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	quick_sort(int *arr, int low, int high);
void	indexing(t_stack **a);
void	sort_3(t_stack **stack);
void	sort_under_12(t_stack **a, t_stack **b, int size);
void	butterfly_sort(t_stack **a, t_stack **b);

#endif
