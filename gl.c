/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 12:14:00 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 01:52:53 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <GL/glew.h>
#include <math.h>

#include "geom.h"
#include "scop.h"

#include "vertex_shader.h"
#include "fragment_shader.h"

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

int						setup_gl_objects(t_scop_context *ctx)
{
	GLuint program_id;
	GLuint vao_id;
	GLuint point_attr_loc;
	GLuint vbo_id;
	GLuint ixbo_id;

	program_id = link_program(g_vertex_shader, g_fragment_shader);
	glGenVertexArrays(1, &vao_id);
	glBindVertexArray(vao_id);
	glGenBuffers(1, &vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_cube), g_cube,
					GL_STATIC_DRAW);
	glGenBuffers(1, &ixbo_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ixbo_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_cube_ix), g_cube_ix,
					GL_STATIC_DRAW);
	point_attr_loc = glGetAttribLocation(program_id, "point");
	glEnableVertexAttribArray(point_attr_loc);
	glVertexAttribPointer(point_attr_loc, 3, GL_FLOAT,
							GL_FALSE, 0, (void *)0);
	ctx->pvm_mat_uniform_id = glGetUniformLocation(program_id, "pvm_mat");
	glUseProgram(program_id);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	return (0);
}

static t_transform		viewport_transform(const t_scop_context *ctx)
{
	GLfloat		aspect;
	t_transform	transform;

	aspect = (GLfloat)ctx->win_w / (GLfloat)ctx->win_h;
	transform = ctx->win_w < ctx->win_h ?
		homothety_y(aspect) : homothety_x(1 / aspect);
	return (transform);
}

static t_transform		proj_view_mat(const t_scop_context *ctx)
{
	t_transform	view_mat;
	t_transform	proj_mat;

	view_mat = translation(-4.0f, -3.0f, -8.0f);
	view_mat = compose_transform(rotation_y(-M_PI_4), view_mat);
	proj_mat = compose_transform(viewport_transform(ctx), basic_persp());
	return (compose_transform(proj_mat, view_mat));
}

int						draw(const t_scop_context *ctx)
{
	t_transform	model_mat;
	t_transform	pvm_mat;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	model_mat = rotation_y((GLfloat)ctx->time);
	pvm_mat = compose_transform(proj_view_mat(ctx), model_mat);
	glUniformMatrix4fv(ctx->pvm_mat_uniform_id, 1, GL_FALSE,
					to_array(&pvm_mat));
	glDrawElements(GL_TRIANGLES, sizeof(g_cube_ix) / sizeof(*g_cube_ix),
					GL_UNSIGNED_SHORT, (void*)0);
	return (0);
}
