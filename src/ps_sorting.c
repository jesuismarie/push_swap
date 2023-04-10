/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:22:37 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/08 14:53:58 by mnazarya         ###   ########.fr       */
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

void	find_sortest_way(t_stack **a, t_stack **b, int index, int size)
{
	int	i;

	i = 0;
	if (size - index - 1 < index)
	{
		while (i <= size - index - 1)
		{
			rra(a);
			i++;
		}
	}
	else
	{
		while (i < index)
		{
			ra(a);
			i++;
		}
	}
	if (!is_sorted(*a))
		pb(a, b);
}

void	sort_under_12(t_stack **a, t_stack **b, int size)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		n;

	i = -1;
	j = size - 3;
	while (++i < j)
	{
		n = 0;
		tmp = *a;
		while (tmp)
		{
			if (tmp->index == i)
			{
				find_sortest_way(a, b, n, size);
				size--;
			}
			n++;
			tmp = tmp->next;
		}
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}

void	sorting(t_stack **a, t_stack **b, int size)
{
	if (size == 3)
		sort_3(a);
	else if (size > 3 && size < 13)
		sort_under_12(a, b, size);
}
