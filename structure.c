/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struture.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:26:09 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/08 18:04:07 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	structure(t_struct *l)
{
	l->i = 0;
	l->minus = 0;
	l->zero = 0;
	l->width = 0;
	l->precision = -1;
	l->len = 0;
	l->mns = 0;
	l->widlen = 0;
	l->preclen = 0;
}
