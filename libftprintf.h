/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:59:27 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/10 17:04:54 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_struct
{
	int i;
	int	minus;
	int	zero;
	int width;
	int	precision;
	int	len;
	int	mns;
	int	widlen;
	int	preclen;
}				t_struct;

int				ft_printf(const char *format, ...);
void			parser(const char *format, va_list arg, t_struct *l);
void			ft_putchar_len(char c, t_struct *l);
void			type_c(va_list arg, t_struct *l);
void			type_percent(t_struct *l);
void			type_s(va_list arg, t_struct *l);
void			type_d_i_u(va_list arg, t_struct *l, char type);
int				nbrlen(unsigned long int n, t_struct *l, char type);
void			ft_putnbr_len(long nb, t_struct *l);
void			type_x_p(va_list arg, t_struct *l, char type);
void			ft_puthex_len(unsigned long int nb, t_struct *l, char type);
void			vladimir(t_struct *l);

#endif
