#include "push.h"
#include <stdlib.h>


#include <stdio.h>
#include "libft.h"

static int	check_action(t_problem *subject, t_action ft)
{
	if (ft.ft_ptr == swap_a && subject->a == NULL)
		return (0);
	if (ft.ft_ptr == swap_b && subject->b == NULL)
		return (0);
	if (ft.ft_ptr == swap_all && (subject->a == NULL || subject->b == NULL))
		return (0);
	if (ft.ft_ptr == push_a && subject->b == NULL)
		return (0);
	if (ft.ft_ptr == push_b && subject->a == NULL)
		return (0);
	if (ft.ft_ptr == rotate_a && subject->a == NULL)
		return (0);
	if (ft.ft_ptr == rotate_b && subject->b == NULL)
		return (0);
	if (ft.ft_ptr == rotate_all && (subject->a == NULL || subject->b == NULL))
		return (0);
	if (ft.ft_ptr == reverse_a && subject->a == NULL)
		return (0);
	if (ft.ft_ptr == reverse_b && subject->b == NULL)
		return (0);
	if (ft.ft_ptr == reverse_all && (subject->a == NULL || subject->b == NULL))
		return (0);
	return (1);
}

static int	check_auth_action(t_problem *subject, t_try essai, int i, t_action ft)
{
	if (i == 0)
		return (1);
	if (essai.seq[i - 1] == ft.ft_rev_ptr)
		return (0);
	return (check_action(subject, ft));
}

static int	check_win(t_problem *subject)
{
	unsigned int	i;
	t_pile *temp;

	i = 0;
	temp = subject->a;
	while (i < subject->size)
	{
		if (temp == NULL || temp->valeur != subject->resolved[i])
			return (0);
		temp = temp->next;
		i++;
	}
	return (1);
}

static void	test_action(t_problem *subject, t_try essai, int *min, t_action ft)
{
	int	i;
	int	res;

	i = essai.step;
	if (check_auth_action(subject, essai, i, ft))
	{
		essai.seq[i] = ft.ft_ptr;
		(*(ft.ft_ptr))(subject);
		res = resolve(subject, essai, *min);
		if (res < *min)
			*min = res;
		else
			essai.seq[i] = NULL;
		(*(ft.ft_rev_ptr))(subject);
	}
}

int	resolve(t_problem *subject, t_try essai, int end)
{
	int i;
	int min;
	t_action ft[11];

 	i = 0;
 	init_tab_ptr(ft);
	essai.step++;
	min = end;
	if (essai.step == end)
		return (end);
	if ( check_win(subject))
	{
		ft_putendl("bingo");
		return (essai.step);
	}
	while (i < 11)
	{
	//	printf("On test le numero %d step %d\n", i , essai.step);
		test_action(subject, essai, &min, ft[i]);
		i++;
	}
	return (min);
}