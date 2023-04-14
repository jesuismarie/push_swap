/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:01:05 by mnazarya          #+#    #+#             */
/*   Updated: 2023/04/14 15:29:11 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition_sorting(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	i = low + 1;
	j = high;
	pivot = arr[low];
	while (1)
	{
		while (i < high && pivot > arr[i])
			i++;
		while (j >= 0 && pivot < arr[j])
			j--;
		if (i >= j)
			break ;
		ft_swap(&arr[i], &arr[j]);
	}
	ft_swap(&arr[low], &arr[j]);
	return (j);
}

void	quick_sort(int *arr, int low, int high)
{
	int	j;

	if (low < high)
	{
		j = partition_sorting(arr, low, high);
		quick_sort(arr, low, j);
		quick_sort(arr, j + 1, high);
	}
}

static void	find_index(t_stack **a, int *arr, int n)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < n)
		{
			if (arr[i] == tmp->data)
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	indexing(t_stack **a)
{
	int		n;
	int		i;
	int		*arr;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	n = ft_stacksize(*a);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return ;
	while (i < n)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	quick_sort(arr, 0, n - 1);
	find_index(a, arr, n);
	free(arr);
}
