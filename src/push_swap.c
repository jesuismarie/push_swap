/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:58:16 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/14 20:06:46 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	check(t_stack **a, int ac, char **av)
{
	if (is_no_arg(ac, av))
		exit(0);
	is_correct(ac, av);
	sign_between_nbr(ac, av);
	*a = get_args(*a, ac, av);
	if (is_sorted(*a))
		exit(0);
	if (is_duplicate(*a))
		error_mss();
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	check(&a, ac, av);
	indexing(&a);
	size = ft_stacksize(a);
	if (size == 2)
		sa(&a);
	else if (size > 2 && size < 13)
		sort_under_12(&a, &b, size);
	else
		butterfly_sort(&a, &b);
	stackclear(a);
	return (0);
}
