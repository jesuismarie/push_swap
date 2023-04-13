/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:57:05 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/13 20:57:05 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	swap(t_stack **elem)
{
	int	tmp;

	if ((*elem)->next)
	{
		tmp = (*elem)->data;
		(*elem)->data = (*elem)->next->data;
		(*elem)->next->data = tmp;
		tmp = (*elem)->index;
		(*elem)->index = (*elem)->next->index;
		(*elem)->next->index = tmp;
		return (1);
	}
	return (0);
}

void	sa(t_stack **a)
{
	if (swap(a))
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	if (swap(b))
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	if (swap(a) && swap(b))
		ft_putstr_fd("ss\n", 1);
}
