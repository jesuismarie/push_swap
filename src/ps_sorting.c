/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:22:37 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/12 19:38:21 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && a < c)
		sa(stack);
	else if (a < b && a > c)
		rra(stack);
	else if (a > b && a > c && b < c)
		ra(stack);
	else if (a > b && a > c && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a < b && a < c && b > c)
	{
		sa(stack);
		ra(stack);
	}
}

static void	find_sortest_way(t_stack **a, t_stack *node)
{
	t_stack	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = *a;
	size = ft_stacksize(*a);
	while ((*a)->data != node->data)
	{
		*a = (*a)->next;
		i++;
	}
	*a = tmp;
	if (i > size / 2)
		while ((*a)->data != node->data)
			rra(a);
	else
		while ((*a)->data != node->data)
			ra(a);
}

void	sort_under_12(t_stack **a, t_stack **b, int size)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (size > 3)
	{
		tmp = *a;
		while (tmp->index != i)
			tmp = tmp->next;
		find_sortest_way(a, tmp);
		size--;
		i++;
		pb(a, b);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}
