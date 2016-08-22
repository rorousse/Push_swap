#include "push.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	push_a(t_problem *subject)
{
	t_pile *temp;

	if (subject->b != NULL)
	{
		temp = subject->b;
		subject->b = (subject->b)->next;
		temp->next = subject->a;
		if (subject->a != NULL)
			(subject->a)->prec = temp;
		subject->a = temp;
		(subject->b)->prec = NULL;
	}
}

void	push_b(t_problem *subject)
{
	t_pile *temp;

	if (subject->a != NULL)
	{
		temp = subject->a;
		subject->a = (subject->a)->next;
		temp->next = subject->b;
		if (subject->b != NULL)
			(subject->b)->prec = temp;
		subject->b = temp;
		(subject->a)->prec = NULL;
	}
}