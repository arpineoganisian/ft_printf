/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:59:27 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/11/30 21:10:46 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

# include <stdarg.h> //va_list
# include <unistd.h> //write
# include <stdlib.h> //malloc, free

typedef struct	s_list
{
	int i; //индекс по строке
	int	minus;
	int	zero;
	int width; // ширина
	int	precision; // точность


}				t_list;
#endif
