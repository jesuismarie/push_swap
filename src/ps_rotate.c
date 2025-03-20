/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:07:51 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/29 23:07:51 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	rotate(t_stack **elem)
{
	t_stack	*tmp;
	t_stack	*h;

	if (!elem || !*elem || !(*elem)->next)
		return (0);
	tmp = *elem;
	h = (*elem)->next;
	while ((*elem)->next)
		*elem = (*elem)->next;
	(*elem)->next = tmp;
	tmp->next = NULL;
	*elem = h;
	return (1);
}

void	ra(t_stack **a)
{
	if (rotate(a))
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b)
{
	if (rotate(b))
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	if (rotate(a) && rotate(b))
		ft_putstr_fd("rr\n", 1);
}
