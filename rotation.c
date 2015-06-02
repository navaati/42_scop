/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 00:41:33 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/04 00:42:08 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <GL/glew.h>

#include "geom.h"

t_transform	rotation_x(GLfloat angle)
{
	t_transform	rotx;

	rotx = g_identity;
	rotx.mat[1][1] = cosf(angle);
	rotx.mat[1][2] = sinf(angle);
	rotx.mat[2][1] = -sinf(angle);
	rotx.mat[2][2] = cosf(angle);
	return (rotx);
}

t_transform	rotation_y(GLfloat angle)
{
	t_transform	roty;

	roty = g_identity;
	roty.mat[0][0] = cosf(angle);
	roty.mat[0][2] = -sinf(angle);
	roty.mat[2][0] = sinf(angle);
	roty.mat[2][2] = cosf(angle);
	return (roty);
}

t_transform	rotation_z(GLfloat angle)
{
	t_transform	rotz;

	rotz = g_identity;
	rotz.mat[0][0] = cosf(angle);
	rotz.mat[0][1] = sinf(angle);
	rotz.mat[1][0] = -sinf(angle);
	rotz.mat[1][1] = cosf(angle);
	return (rotz);
}
