/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:45:36 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/08 13:19:41 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_len(long long int nb, t_list *list)
{
	char x;

	if (nb == 0)
		ft_putchar_len('0', list);	
	if (nb > 0)
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			x = nb % 10 + '0';
			ft_putchar_len(x, list);
		}
		else
		{
			x = nb % 10 + '0';
			ft_putchar(x, list);
		}
	}
}
