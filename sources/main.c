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
	t_problem subject;

	if (argc > 1)
	{
		init_problem(&subject, argc, argv);
		aff_pile(subject.a);
		push_b(&subject);
		ft_putendl("push ok");
		aff_pile(subject.a);
		aff_pile(subject.b);
		free_pile(subject.a);
		free_pile(subject.b);
	}
	ft_putendl("Done.");
	while (1);
	return (0);
}