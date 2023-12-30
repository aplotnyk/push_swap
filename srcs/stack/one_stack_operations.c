/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_stack_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:13:13 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/08 14:13:13 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
 * change stack_src->is_a param
 * new_var = *stack_src;
 * stack_src = (*stack_src)->next;
 * add new_var to stack_dest; 
 * write "pa" or "pb";
*/

void	stack_push_to(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*to_push;

	if (!*stack_src)
		return ;
	to_push = *stack_src;
	(*stack_src)->is_a = !(*stack_src)->is_a;
	*stack_src = (*stack_src)->next;
	if (!*stack_dest)
		ft_lstadd_back(stack_dest, to_push);
	else
		ft_lstadd_front(stack_dest, to_push);
	if ((*stack_dest)->is_a)
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

/*
* reverses 2 upper elem in stack(a or b) using *tmp;
* write "sa" or "sb";
*/
void	stack_swap(t_stack **stack, int needs_to_print)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (needs_to_print)
	{
		if ((*stack)->is_a)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

/*
 *  saving 1st node in tmp;
 *  2nd node becomes 1st node;
 *  adding tmp value to the back of the list;
 *  write "ra" or "rb";
*/
void	rotate_stack(t_stack **stack, int needs_to_print)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, tmp);
	if (needs_to_print)
	{
		if (tmp->is_a)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

/***
 * assigning 1st node to tmp(for navigation);
 * while node+2 is not NULL
 * 		reassigning tmp so that ends as the stack's "before last" node
 * last_elem is tmp->next which is stack's last node
 * we saved 2 last el from stack to tmp & last_el var;
 * tmp->next becomes NULL(cause it's supposed to become last el of stack)
 * last_elem->next gets the node which used to be head of stack;
 * head of stack received node that used to be the last in stack;
*/
void	reverse_rotate_stack(t_stack **stack, int needs_to_print)
{
	t_stack	*tmp;
	t_stack	*last_elem_in_stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last_elem_in_stack = tmp->next;
	tmp->next = NULL;
	last_elem_in_stack->next = *stack;
	*stack = last_elem_in_stack;
	if (needs_to_print)
	{
		if ((*stack)->is_a)
			write (1, "rra\n", 4);
		else
			write (1, "rrb\n", 4);
	}
}
