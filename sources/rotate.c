#include "push.h"
#include <stdlib.h>

void	rotate_pile(t_pile **pile)
{
	t_pile *temp;
	t_pile *temp2;

	if (*pile != NULL && (*pile)->next != NULL)
	{
		temp = *pile;
		*pile = (*pile)->next;
		(*pile)->prec = NULL;
		temp2 = *pile;
		while (temp2->next != NULL)
			temp2 = temp2->next;
		temp2->next = temp;
		temp->prec = temp2;
		temp->next = NULL;
	}
}

void	rotate_a(t_problem *subject)
{

	rotate_pile(&(subject->a));
}

void	rotate_b(t_problem *subject)
{
	rotate_pile(&(subject->b));
}

void	rotate_all(t_problem *subject)
{
	rotate_pile(&(subject->a));
	rotate_pile(&(subject->b));
}
