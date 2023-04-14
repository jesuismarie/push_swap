/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_limits_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:45:24 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/14 18:48:25 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	is_correct(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
				j++;
			else if (av[i][j] == '+' || av[i][j] == '-')
			{
				if (!(av[i][j + 1] >= 48 && av[i][j + 1] <= 57))
					error_mss();
				else
					j++;
			}
			else if (!(av[i][j] >= 48 && av[i][j] <= 57))
				error_mss();
			else
				j++;
		}
		i++;
	}
}

int	is_duplicate(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		while (tmp->next)
		{
			if (a->data == tmp->next->data)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	is_zero(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s == '0')
		s++;
	return (ft_strlen(s));
}

int	int_range(char	*s)
{
	long	nb;

	nb = ft_atol(s);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

int	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->data < a->next->data)
			a = a->next;
		else
			return (0);
	}
	return (1);
}
