#include "push.h"
#include "libft.h"
#include <stdlib.h>

static t_pile *insert_elem(char **argv, int i, t_pile *prec)
{
	t_pile *elem;

	elem = (t_pile*)malloc(sizeof(t_pile));
	elem->prec = prec;
	elem->next = NULL;
	elem->valeur = ft_atoi(argv[i]);
	return (elem);
}

static void init_problem(t_problem *subject, int argc, char **argv)
{
	int	i;

	i = 2;
	subject->b = NULL;
	subject->a = insert_elem(argv, 1, NULL);
	while (i < argc)
	{
		(subject->a)->next = insert_elem(argv, i, subject->a);
		subject->a = (subject->a)->next;
		i++;
	}
	beg_pile(&(subject->a));
}

int main(int argc, char **argv)
{
	int			end;
	t_problem subject;
	t_try		essai;

	end = 100;
	if (argc > 1)
	{
		init_problem(&subject, argc, argv);
		init_try(&essai, end);
		resolve(&subject, essai, end);
		aff_essai(essai, end);
	}
	ft_putendl("Done.");
	return (0);
}
