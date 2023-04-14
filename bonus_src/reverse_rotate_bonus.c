/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:49:02 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/14 18:49:02 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void	rev_rotate(t_stack **elem)
{
	t_stack	*tmp;

	if (!elem || !*elem || !(*elem)->next)
		return ;
	tmp = *elem;
	while ((*elem)->next)
		*elem = (*elem)->next;
	(*elem)->prev->next = NULL;
	tmp->prev = *elem;
	(*elem)->next = tmp;
	(*elem)->prev = NULL;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
