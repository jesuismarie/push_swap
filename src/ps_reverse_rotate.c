/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:28:09 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/30 00:28:09 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	rev_rotate(t_stack **elem)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!elem || !*elem || !(*elem)->next)
		return (0);
	tmp = *elem;
	while ((*elem)->next)
	{
		prev = *elem;
		*elem = (*elem)->next;
	}
	prev->next = NULL;
	(*elem)->next = tmp;
	return (1);
}

void	rra(t_stack **a)
{
	if (rev_rotate(a))
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	if (rev_rotate(b))
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (rev_rotate(a) && rev_rotate(b))
		ft_putstr_fd("rrr\n", 1);
}
