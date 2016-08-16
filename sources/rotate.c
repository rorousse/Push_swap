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

void	rotate_all(t_problem *subject)
{
	rotate_pile(&(subject->a));
	rotate_pile(&(subject->b));
}

void	reverse_all(t_problem *subject)
{
	reverse_rotate(&(subject->a));
	reverse_rotate(&(subject->b));
}