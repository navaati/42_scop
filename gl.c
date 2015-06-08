/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 12:14:00 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/08 14:28:59 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <math.h>

#include "geom.h"
#include "scop.h"

#include "vertex_shader.h"
#include "fragment_shader.h"

static const GLfloat	g_triangle[] = {
	-1.0f, -1.0f,
	1.0f, -1.0f,
	0.0f, 1.0f,
};

int						setup_gl_objects(t_scop_context *ctx)
{
	GLuint program_id;
	GLuint vao_id;
	GLuint point_attr_loc;
	GLuint vbo_id;

	program_id = link_program(g_vertex_shader, g_fragment_shader);
	point_attr_loc = glGetAttribLocation(program_id, "point");
	glGenVertexArrays(1, &vao_id);
	glBindVertexArray(vao_id);
	glGenBuffers(1, &vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_triangle), g_triangle,
					GL_STATIC_DRAW);
	glEnableVertexAttribArray(point_attr_loc);
	glVertexAttribPointer(point_attr_loc, 2, GL_FLOAT,
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

int						draw(const t_scop_context *ctx)
{
	t_transform	model_mat;
	t_transform	view_mat;
	t_transform	proj_mat;
	t_transform	pvm_mat;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	model_mat = rotation_y((GLfloat)ctx->time);
	view_mat = compose_transform(translation(0.5, 0, 0),
									rotation_z(0.5f));
	proj_mat = viewport_transform(ctx);
	pvm_mat = compose_transform(proj_mat,
							compose_transform(view_mat,
								model_mat));
	glUniformMatrix4fv(ctx->pvm_mat_uniform_id, 1, GL_FALSE,
					to_array(&pvm_mat));
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return (0);
}
