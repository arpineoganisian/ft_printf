/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:59:27 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/09 19:42:40 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h> //va_list
# include <unistd.h> //write
# include <stdlib.h> //malloc, free
# include <stdio.h> //УДАЛИТЬ

typedef struct	s_struct
{
	int i; //индекс по строке
	int	minus;
	int	zero;
	int width; // ширина
	int	precision; // точность
	int	len; // возвращаемое значение
	int	mns; // минус в d i u
	int	widlen; // для d i u
	int	preclen;
}				t_struct;

int				ft_printf(const char *format, ...);
void			parser(const char *format, va_list arg, t_struct *l);
void			structure(t_struct *l);
void			ft_putchar_len(char c, t_struct *l);
void			type_c(va_list arg, t_struct *l);
void			type_percent(t_struct *l);
void			type_s(va_list arg, t_struct *l);
void			type_d_i_u(va_list arg, t_struct *l, char type);
int				intlen(long n, t_struct *l);
void			ft_putnbr_len(long nb, t_struct *l);
void			type_x_p(va_list arg, t_struct *l, char type);
int				hexlen(unsigned long n, t_struct *l);
void			ft_puthex_len(unsigned long nb, t_struct *l, char type);

#endif
