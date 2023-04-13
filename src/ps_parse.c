/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:06:04 by mnazarya          #+#    #+#             */
/*   Updated: 2023/03/25 21:06:04 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	error_mss(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int	is_no_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_strlen(av[i]))
		{
			while (av[i][j])
			{
				while (av[i][j] == ' ')
					j++;
				if (av[i][j] != '\0')
					return (0);
			}
		}
		i++;
	}
	return (1);
}

void	sign_between_nbr(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' || av[i][j] == '+' || av[i][j] == '-')
				j++;
			while (av[i][j] >= 48 && av[i][j] <= 57)
			{
				if (av[i][j + 1] == '+' || av[i][j + 1] == '-')
					error_mss();
				j++;
			}
		}
		i++;
	}
}

long	ft_atol(const char *s)
{
	int		i;
	int		j;
	long	nb;

	i = 0;
	nb = 0;
	j = 1;
	if (is_zero(s) <= 10)
	{
		while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
			i++;
		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i] == '-')
				j = -1;
			i++;
		}
		while (s[i] >= 48 && s[i] <= 57)
			nb = (nb * 10) + (s[i++] - 48);
		return (nb * j);
	}
	return (2147483648);
}

t_stack	*get_args(t_stack *a, int ac, char **av)
{
	t_stack	*current;
	char	**s;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		s = ft_split(av[i], ' ');
		while (s[j])
		{
			if (!int_range(s[j]))
				error_mss();
			current = stack_new(ft_atoi(s[j]));
			ft_stackadd_back(&a, current);
			j++;
		}
		j = 0;
		while (s[j])
			free(s[j++]);
		free(s);
		i++;
	}
	return (a);
}
