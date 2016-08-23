#ifndef PUSH_H
# define PUSH_H

struct s_pile
{
	int				valeur;
  	struct s_pile	*next;
  	struct s_pile	*prec;
};

typedef struct s_pile t_pile;

struct s_problem
{
	t_pile	*a;
	t_pile	*b;
	int		*resolved;
	unsigned int	size;
};

typedef struct s_problem t_problem;

struct s_try
{
	int step;
	int	*min;
	void	(**seq)(t_problem *subject);
};

typedef struct s_try t_try;

struct s_action
{
	void	(*ft_ptr)(t_problem *subject);
	void	(*ft_rev_ptr)(t_problem *subject);
};

typedef struct s_action t_action;

/*
** CHECK_C
*/

int				check_all(int argc, char **argv);

/*
** END_C
*/

void			free_problem(t_problem *subject);

/*
** PILE_C
*/

unsigned int	get_size_pile(t_pile *target);
void			beg_pile(t_pile **target);
void			aff_pile(t_pile *target);
void			free_pile(t_pile *target);

/*
** PUSH_C
*/

void	push_a(t_problem *subject);
void	push_b(t_problem *subject);

/*
** RESOLVE_C
*/

void		resolve(t_problem *subject, t_try essai);

/*
** REVERSE_C
*/

void	reverse_rotate(t_pile **pile);
void	reverse_a(t_problem *subject);
void	reverse_b(t_problem *subject);
void	reverse_all(t_problem *subject);

/*
** ROTATE_H
*/

void	rotate_pile(t_pile **pile);
void	rotate_b(t_problem *subject);
void	rotate_all(t_problem *subject);
void	rotate_a(t_problem *subject);

/*
** SWAP_H
*/

void	swap_pile(t_pile **pile);
void	swap_a(t_problem *subject);
void	swap_b(t_problem *subject);
void	swap_all(t_problem *subject);


/*
** TAB_PTR_C
*/

void	init_tab_ptr(t_action ft[11]);
void	init_try(t_try *essai, int end);
void	aff_essai(t_try essai, int end);

/*
** TRI_C
*/

void	aff_tab(int *mytab, unsigned int taille);
void	tri_tab(int *mytab, unsigned int taille);
void	insert_tri(t_problem *subject);

#endif
