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
** ROTATE_H
*/

void	rotate_pile(t_pile **pile);
void	reverse_rotate(t_pile **pile);
void	rotate_all(t_problem *subject);
void	reverse_all(t_problem *subject);

/*
**	SWAP_H
*/

void	swap_pile(t_pile **pile);
void	swap_all(t_problem *subject);

/*
** TRI_C
*/

void	aff_tab(int *mytab, unsigned int taille);
void	tri_tab(int *mytab, unsigned int taille);
void	insert_tri(t_problem *subject);

#endif
