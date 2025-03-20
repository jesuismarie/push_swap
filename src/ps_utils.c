/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:50:10 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/28 13:50:10 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*stack_new(int data)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->data = data;
	s->next = NULL;
	return (s);
}

t_stack	*ft_last(t_stack *elem)
{
	while (elem)
	{
		if (!elem->next)
			return (elem);
		elem = elem->next;
	}
	return (elem);
}

void	ft_stackadd_back(t_stack **elem, t_stack *new)
{
	t_stack	*n;

	if (!*elem)
		*elem = new;
	else
	{
		n = ft_last(*elem);
		n->next = new;
	}
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	stackclear(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}
