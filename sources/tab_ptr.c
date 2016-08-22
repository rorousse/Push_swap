#include "push.h"
#include "libft.h"

static void	aff_action(void	(*ft_ptr)(t_problem *subject))
{
	if (ft_ptr == swap_a)
		ft_putendl("sa");
	else if (ft_ptr == swap_b)
		ft_putendl("sb");
	else if (ft_ptr == swap_all)
		ft_putendl("ss");
	else if (ft_ptr == push_a)
		ft_putendl("pa");
	else if (ft_ptr == push_b)
		ft_putendl("pb");
	else if (ft_ptr == rotate_a)
		ft_putendl("ra");
	else if (ft_ptr == rotate_b)
		ft_putendl("rb");
	else if (ft_ptr == rotate_all)
		ft_putendl("rr");
	else if (ft_ptr == reverse_a)
		ft_putendl("rra");
	else if (ft_ptr == reverse_b)
		ft_putendl("rrb");
	else if (ft_ptr == reverse_all)
		ft_putendl("rrr");
}

void	init_tab_ptr(t_action ft[11])
{
	ft[0].ft_ptr = swap_a;
	ft[1].ft_ptr = swap_b;
	ft[2].ft_ptr = swap_all;
	ft[3].ft_ptr = push_a;
	ft[4].ft_ptr = push_b;
	ft[5].ft_ptr = rotate_a;
	ft[6].ft_ptr = rotate_b;
	ft[7].ft_ptr = rotate_all;
	ft[8].ft_ptr = reverse_a;
	ft[9].ft_ptr = reverse_b;
	ft[10].ft_ptr = reverse_all;
	ft[0].ft_rev_ptr = swap_a;
	ft[1].ft_rev_ptr = swap_b;
	ft[2].ft_rev_ptr = swap_all;
	ft[3].ft_rev_ptr = push_b;
	ft[4].ft_rev_ptr = push_a;
	ft[5].ft_rev_ptr = reverse_a;
	ft[6].ft_rev_ptr = reverse_b;
	ft[7].ft_rev_ptr = reverse_all;
	ft[8].ft_rev_ptr = rotate_a; 
	ft[9].ft_rev_ptr = rotate_b;
	ft[10].ft_rev_ptr = rotate_all;
}

void	init_try(t_try *essai, int end)
{
	essai->step = -1;
	essai->seq = (void (**)(t_problem *))malloc(end * sizeof(void*));
}

void	aff_essai(t_try essai, int end)
{
	int	i;

	i = 0;
	while (essai.seq[i] != NULL && i < end)
	{
		aff_action(essai.seq[i]);
		i++;
	}
}