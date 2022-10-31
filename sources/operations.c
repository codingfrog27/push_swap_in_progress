/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 22:13:33 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/31 19:29:03 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char c)
{
	int	tmp;

	if (stack && stack->next != stack)
	{
		tmp = stack->nbr;
		stack->nbr = stack->next->nbr;
		stack->next->nbr = tmp;
	}
	if (c != 's')
		ft_printf("s%c\n", c);
}

void	super_swap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	ft_printf("ss\n");
}

t_stack	*yoink_node(t_stack **stack)
{
	t_stack	*freed_node;

	if (!*stack)
		return (NULL);
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
	freed_node = *stack;
	*stack = (*stack)->next;
	return (freed_node);
}

void	push(t_stack **src, t_stack **dest, char c)
{
	t_stack	*pushed_node;

	if (*src)
	{
		pushed_node = yoink_node(src);
		if (!*dest)
		{
			pushed_node->next = pushed_node;
			pushed_node->prev = pushed_node;
			*dest = pushed_node;
		}
		else
		{
			(*dest)->prev->next = pushed_node;
			(*dest)->prev = pushed_node;
			*dest = pushed_node;
		}
	}
	ft_printf("p%c\n", c);
}

void	rotate(char c, t_stack **stack)
{
	*stack = (*stack)->next;
	ft_printf("r%c\n", c);
}

void	rev_rotate(char c, t_stack **stack)
{
	*stack = (*stack)->prev;
}
