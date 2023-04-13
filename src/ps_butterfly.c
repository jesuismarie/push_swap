/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_butterfly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:03:21 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/12 19:47:45 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	optimaizer(int size)
{
	int	sqrt;
	int	log;

	sqrt = 1;
	log = 0;
	while (sqrt < size / sqrt)
		sqrt++;
	while (log)
	{
		size /= 2;
		log++;
	}
	return (sqrt + log);
}

static void	butterfly_short_way(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = *stack;
	size = ft_stacksize(*stack);
	while ((*stack)->data != node->data)
	{
		*stack = (*stack)->next;
		i++;
	}
	*stack = tmp;
	if (i > size / 2)
		while ((*stack)->data != node->data)
			rrb(stack);
	else
		while ((*stack)->data != node->data)
			rb(stack);
}

static void	find_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		i;

	i = 0;
	tmp = *stack;
	max = tmp->data;
	while (*stack)
	{
		if ((*stack)->data > max)
			max = (*stack)->data;
		*stack = (*stack)->next;
	}
	*stack = tmp;
	while (tmp->data != max)
	{
		tmp = tmp->next;
		i++;
	}
	butterfly_short_way(stack, tmp);
}

void	butterfly_sort(t_stack **a, t_stack **b)
{
	int	n;
	int	i;
	int	op;

	i = 0;
	n = ft_stacksize(*a);
	op = optimaizer(n);
	while (i < n)
	{
		if ((*a)->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index > i && (*a)->index <= i + op)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	while (*b)
	{
		find_max(b);
		pa(a, b);
	}
}
