/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:00:38 by sdarsie           #+#    #+#             */
/*   Updated: 2017/02/01 12:25:04 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	show_chars(unsigned char *num, size_t i)
{
	size_t j = i;
	if (i % 16 != 15)
	{
		while (j % 16 != 15)
			j--;
		j++;
	}
	else if (i == 15)
	{
		j = 1;
		i = 16;
	}
	else
	{
		j = i - 16;
		j++;
	}
	while (j <= i)
	{
		if (num[j] >= 32 && num[j] <= 126)
			ft_putchar(num[j]);
		else
			ft_putchar('.');
		j++;
	}
}

void	itoa_hex(unsigned char num)
{
	unsigned char alph[17] = "0123456789abcdef";
	ft_putchar(alph[(num/16)]);
	ft_putchar(alph[(num % 16)]);
}
void	print_memory(const void *addr, size_t size)
{
	unsigned char *temp;
	temp = (unsigned char*)addr;

	size_t	i = 0;
	size_t	k = 0;
	while (i < size)
	{
		itoa_hex(temp[i]);
		if (i + 1 != size && i % 2 != 0)
			ft_putchar(' ');
		if ((i % 16 == 15 || i + 1 == size) && i > 0)
		{
			if (i + 1 == size)
			{
				k = i;
				ft_putchar (' ');
				while (k % 16 != 15 )
				{
					ft_putchar(' ');
					ft_putchar(' ');
					if (k % 2 == 1)
						ft_putchar(' ');
					k++;
				}
			}
			show_chars(temp, i);
			ft_putchar('\n');
		}
		i++;
	}
}
