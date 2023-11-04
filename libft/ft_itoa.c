/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:01:27 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/09/15 12:01:27 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MIN_VAL -2147483648

static void	ft_rec(char *buff, int *ptr, int n)
{
	if (n / 10 > 0)
		ft_rec(buff, ptr, n / 10);
	buff[*ptr] = n % 10 + '0';
	(*ptr)++;
}

static int	ft_strlen_loc(const char *str1)
{
	int	n;

	n = 0;
	while (str1[n])
		n++;
	return (n);
}

static void	ft_strcpy(char *dst, const char *src)
{
	int	n;

	n = 0;
	while (src[n])
	{
		dst[n] = src[n];
		n++;
	}
	dst[n] = '\0';
}

static char	*ft_strdup_loc(const char *s1)
{
	int		len;
	char	*ptr;

	len = ft_strlen_loc(s1);
	ptr = malloc(len + 1);
	if (ptr)
		ft_strcpy(ptr, s1);
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	str[12];
	int		pos;

	if (n == MIN_VAL)
		ft_strcpy(str, "-2147483648");
	else
	{
		pos = 0;
		if (n < 0)
		{
			str[pos++] = '-';
			n = -n;
		}
		ft_rec(str, &pos, n);
		str[pos] = 0;
	}
	return (ft_strdup_loc(str));
}
