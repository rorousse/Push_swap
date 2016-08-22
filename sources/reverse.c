#include "push.h"
#include <stdlib.h>

void	reverse_rotate(t_pile **pile)
{
	t_pile *temp;

	if (*pile != NULL && (*pile)->next != NULL)
	{
		temp = *pile;
		while (temp->next != NULL)
			temp = temp->next;
		(temp->prec)->next = NULL;
		temp->prec = NULL;
		temp->next = *pile;
		*pile = temp;
	}
}

void	reverse_a(t_problem *subject)
{
	reverse_rotate(&(subject->a));
}

void	reverse_b(t_problem *subject)
{
	reverse_rotate(&(subject->b));
}

void	reverse_all(t_problem *subject)
{
	reverse_rotate(&(subject->a));
	reverse_rotate(&(subject->b));
}