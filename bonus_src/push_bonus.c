/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:48:47 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/14 18:48:47 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*h;
	t_stack	*tmp;

	if (!src || !(*src))
		return ;
	tmp = (*src)->next;
	h = *src;
	h->next = *dst;
	*dst = h;
	*src = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
}
