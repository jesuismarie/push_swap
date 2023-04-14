/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:49:55 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/14 18:49:55 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void	rotate(t_stack **elem)
{
	t_stack	*tmp;
	t_stack	*h;

	if (!elem || !*elem || !(*elem)->next)
		return ;
	tmp = *elem;
	h = (*elem)->next;
	while ((*elem)->next)
		*elem = (*elem)->next;
	(*elem)->next = tmp;
	tmp->prev = *elem;
	tmp->next = NULL;
	h->prev = NULL;
	*elem = h;
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
