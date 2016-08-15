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
};

typedef struct s_problem t_problem;

/*
** PILE_C
*/

void	beg_pile(t_pile **target);
void	aff_pile(t_pile *target);
void	free_pile(t_pile *target);

/*
** PUSH_C
*/

void	push_a(t_problem *subject);
void	push_b(t_problem *subject);

#endif
