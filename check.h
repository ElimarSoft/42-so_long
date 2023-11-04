/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 07:11:33 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/24 10:40:16 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H
# include <stdlib.h>
# include "helper.h"

char		*check_solution(char *buf, size_t fsize, size_t *lcnt);
char		*check_elements(char *buf, size_t *lcnt);
char		*check_walls(char *buf, size_t *lcnt);
void		count_elements(int val, size_t *lcnt, size_t r1, size_t c1);
int			gval(char *buf, size_t r1, size_t c1, size_t *lcnt);
int			gval_around(char *buf, size_t *cd, size_t *lcnt, char schar);
void		sval(t_context *context, t_coord *coord, char val);
#endif
