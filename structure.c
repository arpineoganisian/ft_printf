/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struture.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:26:09 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/07 22:27:14 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	structure(t_list *list)
{
	list->i = 0;
	list->minus = 0;
	list->zero = 0;
	list->width = 0;
	list->precision = -1;
	list->len = 0;
}