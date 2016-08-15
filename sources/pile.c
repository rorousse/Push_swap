#include "push.h"
#include "libft.h"
#include <stdlib.h>

void	beg_pile(t_pile **target)
{
	if (*target != NULL)
	{
		while ((*target)->prec != NULL)
			*target = (*target)->prec;
	}
}

void	aff_pile(t_pile *target)
{
	beg_pile(&target);
	while (target != NULL)
	{
		ft_putnbr(target->valeur);
		ft_putchar(' ');
		target = target->next;
	}
	ft_putchar('\n');
}

void	free_pile(t_pile *target)
{
	t_pile *tmp;

	beg_pile(&target);
	while (target != NULL)
	{
		tmp = target;
		target = target->next;
		free(tmp);
	}
}