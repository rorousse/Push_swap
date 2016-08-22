#include "push.h"
#include <stdlib.h>

void	free_problem(t_problem *subject)
{
	free_pile(subject->a);
	free_pile(subject->b);
	free(subject->resolved);
}