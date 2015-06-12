/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 08:49:26 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 11:15:53 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>

#include "scop.h"

#include "cube.h"

static const t_point	g_cube[] = {
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, -1.0f },
	{ -1.0f, 1.0f, -1.0f },
	{ -1.0f, 1.0f, 1.0f },
	{ 1.0f, -1.0f, 1.0f },
	{ 1.0f, -1.0f, -1.0f },
	{ -1.0f, -1.0f, -1.0f },
	{ -1.0f, -1.0f, 1.0f },
};

static const GLushort	g_cube_ix[] = {
	0, 1, 2, 2, 3, 0,
	0, 3, 7, 7, 4, 0,
	0, 4, 5, 5, 0, 1,
	1, 5, 6, 6, 1, 2,
	2, 6, 3, 3, 6, 7,
	7, 4, 6, 6, 4, 5
};

static void				draw_cube(const t_object *this)
{
	(void)this;
	glDrawElements(GL_TRIANGLES, sizeof(g_cube_ix) / sizeof(*g_cube_ix),
					GL_UNSIGNED_SHORT, (void*)0);
}

static void				animate_cube(t_object *this, double time_diff)
{
	t_cube	*this_cube;

	this_cube = (t_cube *)this;
	if (this_cube->spin)
		this_cube->spin_angle += time_diff;
	this->model_mat = rotation_y(this_cube->spin_angle);
}

t_cube					make_cube(void)
{
	t_cube	cube;
	GLuint	vbo_id;
	GLuint	ixbo_id;

	glGenVertexArrays(1, &cube.object.vao_id);
	glBindVertexArray(cube.object.vao_id);
	glGenBuffers(1, &vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_cube), g_cube,
					GL_STATIC_DRAW);
	glGenBuffers(1, &ixbo_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ixbo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_cube_ix), g_cube_ix,
					GL_STATIC_DRAW);
	glEnableVertexAttribArray(POS_ATTR_LOCATION);
	glVertexAttribPointer(POS_ATTR_LOCATION, 3, GL_FLOAT,
							GL_FALSE, 0, (void *)0);
	cube.object.draw = draw_cube;
	cube.object.animate = animate_cube;
	cube.object.model_mat = g_identity;
	cube.spin_angle = 0.0f;
	cube.spin = true;
	return (cube);
}
