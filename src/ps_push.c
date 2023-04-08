/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:07:45 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/29 23:07:45 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	push(t_stack **dst, t_stack **src)
{
	t_stack	*h;
	t_stack	*tmp;

	if (!*src)
		return (0);
	if (*dst)
	{
		tmp = (*src)->next;
		h = *src;
		h->next = *dst;
		(*dst)->prev = h;
		tmp->prev = NULL;
		*dst = h;
		*src = tmp;
	}
	else
	{
		tmp = (*src)->next;
		dst = src;
		tmp->prev = NULL;
		*src = tmp;
	}
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push(a, b))
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(b, a))
		ft_putstr_fd("pb\n", 1);
}
