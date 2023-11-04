/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsala-ba <jsala-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 07:14:05 by jsala-ba          #+#    #+#             */
/*   Updated: 2023/10/31 16:44:04 by jsala-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_BLOCK 256
#define MAX_BLOCK 256

int	get_file_size(char *dict_path)
{
	int		n;
	void	*buf;
	int		cnt;
	int		nb;
	int		fd;

	buf = malloc(BUF_BLOCK);
	if (buf == NULL)
		return (0);
	cnt = 0;
	fd = open(dict_path, O_RDONLY);
	n = 1;
	while (n < MAX_BLOCK)
	{
		nb = read(fd, buf, BUF_BLOCK);
		if (!nb)
			break ;
		cnt += nb;
		n++;
	}
	free(buf);
	close(fd);
	return (cnt);
}

char	*read_file(t_context *ct)
{
	int	fd;

	ct->fsize = get_file_size(ct->filename);
	ct->buf = malloc(ct->fsize);
	if (ct->buf == NULL)
		return (NULL);
	fd = open(ct->filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	read(fd, ct->buf, ct->fsize);
	close(fd);
	return (ct->buf);
}
