#include "fdf.h"

int		ft_atoi(const char *c)
{
	int		i;
	int		signe;
	long	r;

	i = 0;
	signe = 1;
	r = 0;
	while (c[i] && (c[i] == '\t' || c[i] == '\n' || c[i] == '\r' || c[i] == '\v'
				|| c[i] == '\f' || c[i] == ' '))
		i++;
	if (c[i] == '-')
		signe = -1;
	if (c[i] == '-' || c[i] == '+')
		i++;
	while (ft_isdigit(c[i]))
	{
		r = (r * 10) + (c[i] - '0');
		if ((r * signe) > 2147483647)
			return (-1);
		else if ((r * signe) < -2147483648)
			return (0);
		i++;
	}
	return ((int)(r * signe));
}