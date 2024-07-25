/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlibert <vlibert@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 23:03:12 by vlibert           #+#    #+#             */
/*   Updated: 2024/07/15 13:05:21 by vlibert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_exist(const char *path)
{
	int		fd;
	char	buffer[1];
	ssize_t	bytes_read;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	bytes_read = read(fd, buffer, 1);
	close(fd);
	if (bytes_read == -1 || bytes_read == 0)
		return (FALSE);
	return (TRUE);
}

int	is_valid_path(const char *path)
{
	size_t	len;

	if (!path)
		return (FALSE);
	if (!map_exist(path))
		return (FALSE);
	len = ft_strlen(path);
	if (len < 4)
		return (FALSE);
	if (ft_strnstr(path + len - 4, ".ber", 4) && path[len - 5] != '/')
		return (TRUE);
	return (FALSE);
}
