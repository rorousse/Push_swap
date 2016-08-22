#include "push.h"
#include "libft.h"

static int	check_doublons(int argc, char **argv)
{
	int	*tab;
	int	i;
	int	y;

	i = 0;
	tab = (int*)malloc(argc * sizeof(int));
	while (i < argc)
	{
		if (!isnumber(argv[i][0]))
			return (1);
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while(i < argc)
	{
		y = i;
		while (y < argc)
		{
			if (tab[y] == tab[i])
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int	check_all(int argc, char **argv)
{
	if (argc == 1 || check_doublons(argc,argv))
		return (0);
	return (1);
}