/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homothety.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 00:42:37 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/04 00:43:54 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>

#include "geom.h"

t_transform	homothety_x(GLfloat factor)
{
	t_transform	hom;

	hom = g_identity;
	hom.mat[0][0] = factor;
	return (hom);
}

t_transform	homothety_y(GLfloat factor)
{
	t_transform	hom;

	hom = g_identity;
	hom.mat[1][1] = factor;
	return (hom);
}

t_transform	homothety_z(GLfloat factor)
{
	t_transform	hom;

	hom = g_identity;
	hom.mat[2][2] = factor;
	return (hom);
}
