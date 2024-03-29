/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 09:59:48 by malatini          #+#    #+#             */
/*   Updated: 2023/10/13 15:10:43 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/common.h>

void	bring_to_top(t_stack *sta, int x, t_mem *mem)
{
	if (!sta)
		return ;
	if (is_on_top(sta, x))
		return ;
	if (where_middle(sta, x) == 1)
	{
		while (!is_on_top(sta, x))
			ra(sta, 1, mem);
	}
	else
	{
		while (!is_on_top(sta, x))
			rra(sta, 1, mem);
	}
	return ;
}

int	where_middle(t_stack *a, int value)
{
	t_s_elem	*elem;
	float		i;

	if (!a)
		return (-1);
	elem = a->first;
	i = 1;
	while (elem)
	{
		if (elem->value == value)
		{
			if (i / (float)stack_length(a) <= 0.5)
				return (1);
			else
				return (2);
		}
		elem = elem->next;
		i++;
	}
	return (-1);
}

int	biggest(t_stack *a)
{
	int			biggest;
	t_s_elem	*elem;

	if (!a)
		return (0);
	elem = a->first;
	biggest = elem->value;
	while (elem)
	{
		if (elem->value > biggest)
			biggest = elem->value;
		elem = elem->next;
	}
	return (biggest);
}

int	smallest(t_stack *a)
{
	int			smallest;
	t_s_elem	*elem;

	if (!a)
		return (0);
	elem = a->first;
	smallest = elem->value;
	while (elem)
	{
		if (elem->value < smallest)
			smallest = elem->value;
		elem = elem->next;
	}
	return (smallest);
}

/* Indique si la valeur mentionnée est en haut de la pile */
int	is_on_top(t_stack *a, int x)
{
	if (a->first->value == x)
		return (SUCCESS);
	return (ERROR);
}
