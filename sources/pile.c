#include "push.h"
#include "libft.h"
#include <stdlib.h>


#include <stdio.h>

void	beg_pile(t_pile **target)
{
	if (*target != NULL)
	{
		while ((*target)->prec != NULL)
		{
			*target = (*target)->prec;
		}
	}
}

unsigned int	get_size_pile(t_pile *target)
{
	unsigned int	i;
	t_pile			*temp;

	i = 1;
	if (target == NULL)
		return (0);
	temp = target;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	aff_pile(t_pile *target)
{
	beg_pile(&target);
	while (target != NULL)
	{
		ft_putnbr(target->valeur);
		ft_putchar(' ');
		printf("l'adresse est %p et le prec est %p\n", target, target->prec);
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