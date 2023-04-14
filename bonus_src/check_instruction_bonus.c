/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:08:05 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/14 19:25:28 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	check_instruction(char *curr_instr, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(curr_instr, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(curr_instr, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(curr_instr, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(curr_instr, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(curr_instr, "pb\n", 3))
		pb(a, b);
	else if (!ft_strncmp(curr_instr, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(curr_instr, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(curr_instr, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(curr_instr, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(curr_instr, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(curr_instr, "rrr\n", 4))
		rrr(a, b);
	else
		error_mss();
}
