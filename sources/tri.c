#include "push.h"
#include "libft.h"

static int	*create_res(t_pile *target, unsigned int taille)
{
	t_pile	*temp;
	int		*cpy;

	temp = target;
	cpy = (int*)malloc(taille * sizeof(int));
	cpy[0] = target->valeur;
	taille = 1;
	temp = temp->next;
	while (temp != NULL)
	{
		cpy[taille] = temp->valeur;
		temp = temp->next;
		taille++;
	}
	return (cpy);
}

void		aff_tab(int *tab, unsigned int taille)
{
	unsigned int	i;

	i = 0;
	while (i < taille)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

void		tri_tab(int *tab, unsigned int taille)
{
	unsigned int	i;
	unsigned int	y;
	int				temp;
	int				pos;

	i = 0;
	while (i < taille)
	{
		y = i;
		pos = i;
		while (y < taille)
		{
			if (tab[y] < tab[pos])
				pos = y;
			y++;
		}
		temp = tab[pos];
		tab[pos] = tab[i];
		tab[i] = temp;
		i++;
	}
}

void	insert_tri(t_problem *subject)
{
	subject->size = get_size_pile(subject->a);
	subject->resolved = create_res(subject->a, subject->size);
	aff_tab(subject->resolved, subject->size);
	tri_tab(subject->resolved, subject->size);
}