/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:47:49 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/10/31 18:46:37 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*nbrs;
	t_stack		*stack_a;
	t_stack		*stack_b;
	const int	arrlen = argc - 1;

	if (argc < 3)
	{
		if (argc < 2)
			ft_printf("ERROR\n");
		return (0);
	}
	nbrs = input_to_array(arrlen, argv);
	stack_a = init_stack_a(nbrs, arrlen);
	stack_b = NULL;
	print_array(nbrs, arrlen);
	free(nbrs);
	push(&stack_a, &stack_b, 'b');
	ft_printf("%d\n", stack_b->nbr);
	return (0);
}
