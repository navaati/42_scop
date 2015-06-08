/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 19:57:34 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/08 13:45:32 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <GL/glew.h>

#include "geom.h"

const t_transform g_identity = {
	.mat = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	}
};

t_transform	compose_transform(t_transform a, t_transform b)
{
	t_transform p;
	size_t		i;
	size_t		j;
	size_t		k;

	memset(&p, 0, sizeof(p));
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				p.mat[i][j] += a.mat[k][j] * b.mat[i][k];
				k++;
			}
			j++;
		}
		i++;
	}
	return (p);
}

t_transform	translation(GLfloat x, GLfloat y, GLfloat z)
{
	t_transform	trans;

	trans = g_identity;
	trans.mat[3][0] = x;
	trans.mat[3][1] = y;
	trans.mat[3][2] = z;
	return (trans);
}

t_transform	basic_persp(void)
{
	t_transform	persp;

	persp = g_identity;
	persp.mat[3][3] = 0.0f;
	persp.mat[2][2] = -1.0f;
	persp.mat[2][3] = -1.0f;
	persp.mat[3][2] = -2.0f;
	return (persp);
}

GLfloat		*to_array(t_transform *transf)
{
	return (&transf->mat[0][0]);
}
