#include "push.h"
#include <stdlib.h>


void	swap_pile(t_pile **pile)
{
	t_pile *temp;

	if (*pile != NULL && (*pile)->next != NULL)
	{
		temp = (*pile)->next;
		(*pile)->next = temp->next;
		if ((*pile)->next != NULL)
			((*pile)->next)->prec = *pile;
		(*pile)->prec = temp;
		temp->next = *pile;
		temp->prec = NULL;
		*pile = temp;
	}
}

void	swap_a(t_problem *subject)
{
	swap_pile(&(subject->a));
}

void	swap_b(t_problem *subject)
{
	swap_pile(&(subject->b));
}

void	swap_all(t_problem *subject)
{
	swap_pile(&(subject->a));
	swap_pile(&(subject->b));
}