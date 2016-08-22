#include "push.h"
#include <stdlib.h>


#include <stdio.h>
#include "libft.h"

static int	check_auth_action(t_try essai, int i, t_action ft)
{
	if (i == 0)
		return (1);
	if (essai.seq[i - 1] == ft.ft_rev_ptr)
		return (0);
	return (1);
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
	if (check_auth_action(essai, i, ft))
	{
		essai.seq[i] = ft.ft_ptr;
		(*(ft.ft_ptr))(subject);
		res = resolve(subject, essai, *min);
		if (res < *min)
			*min = res;
		else
			essai.seq[i] = NULL;
		(*(ft.ft_ptr))(subject);
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
	if (essai.step == end || check_win(subject))
	{
		return (essai.step);
	}
	while (i < 11)
	{
		test_action(subject, essai, &min, ft[i]);
		i++;
	}
	return (min);
}