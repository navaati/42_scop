/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 15:16:54 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/16 15:54:27 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <GL/glew.h>

#include "geom.h"

#include "grid_mesh.h"

static GLfloat	lin_distr(size_t i, size_t size)
{
	return (-1.0f + (GLfloat)i * 2.0f / (GLfloat)size);
}

static void		vert_line(t_point line[2], size_t i, size_t size)
{
	line[0][0] = lin_distr(i, size);
	line[0][1] = 0.0f;
	line[0][2] = -1.0f;
	line[1][0] = lin_distr(i, size);
	line[1][1] = 0.0f;
	line[1][2] = 1.0f;
}

static void		horiz_line(t_point line[2], size_t i, size_t size)
{
	line[0][0] = -1.0f;
	line[0][1] = 0.0f;
	line[0][2] = lin_distr(i, size);
	line[1][0] = 1.0f;
	line[1][1] = 0.0f;
	line[1][2] = lin_distr(i, size);
}

GLfloat			*grid_gen_vectrices(unsigned size, size_t *buf_size)
{
	t_point	(*lines)[2];
	size_t	nb_lines;
	size_t	i;

	nb_lines = (size + 1) * 2;
	*buf_size = nb_lines * sizeof(*lines);
	if ((lines = malloc(*buf_size)) == NULL)
		return (NULL);
	i = 0;
	while (i < nb_lines / 2)
	{
		horiz_line(lines[i], i, size);
		i++;
	}
	while (i < nb_lines)
	{
		vert_line(lines[i], i - nb_lines / 2, size);
		i++;
	}
	return ((GLfloat *)lines);
}
