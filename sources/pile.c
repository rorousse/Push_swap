#include "push.h"
#include "libft.h"
#include <stdlib.h>


#include <stdio.h>

unsigned int	get_size_pile(t_pile *target)
{
	unsigned int	i;

	i = 1;
	if (target == NULL)
		return (0);
	while (target->next != NULL)
	{
		target = target->next;
		i++;
	}
	return (i);
}

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
		printf("le prec est %p\n", target->prec);
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