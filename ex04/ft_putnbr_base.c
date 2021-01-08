/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 15:57:27 by rbourgea          #+#    #+#             */
/*   Updated: 2019/09/03 18:04:34 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		filter(char *base)
{
	int	a;
	int	b;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	a = 0;
	while (base[a])
	{
		if (base[a] == '+' || base[a] == '-')
			return (0);
		if (base[a] < 32 || base[a] > 126)
			return (0);
		b = a + 1;
		while (base[b])
		{
			if (base[a] == base[b])
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int		count(unsigned int unbr, int size_base, int nbr_trad[200])
{
	int a;

	a = 0;
	while (unbr)
	{
		nbr_trad[a] = unbr % size_base;
		unbr = unbr / size_base;
		a++;
	}
	return (a);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				size_base;
	int				nbr_trad[200];
	int				a;
	unsigned	int	unbr;

	unbr = nbr;
	if (filter(base))
	{
		if (nbr < 0)
		{
			unbr = -nbr;
			ft_putchar('-');
		}
		size_base = 0;
		while (base[size_base])
			size_base++;
		a = count(unbr, size_base, nbr_trad);
		while (--a >= 0)
			ft_putchar(base[nbr_trad[a]]);
	}
}
