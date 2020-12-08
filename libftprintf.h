/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:59:27 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/08 16:31:53 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h> //va_list
# include <unistd.h> //write
# include <stdlib.h> //malloc, free
# include <stdio.h> //УДАЛИТЬ

typedef struct	s_list
{
	int i; //индекс по строке
	int	minus;
	int	zero;
	int width; // ширина
	int	precision; // точность
	int	len; // возвращаемое значение
}				t_list;

int				ft_printf(const char *format, ...);
void			parser(const char *format, va_list arg, t_list *list);
void			structure(t_list *list);
void			ft_putchar_len(char c, t_list *list);
void			type_c(va_list arg, t_list *list);
void			type_percent(t_list *list);
void			type_s(va_list arg, t_list *list);
void			type_d_i(va_list arg, t_list *list, char type);
int				intlen(long n, t_list *list);
void			ft_putnbr_len(long nb, t_list *list);

#endif
