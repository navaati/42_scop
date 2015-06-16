/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 12:14:00 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/16 11:22:50 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <GL/glew.h>
#include <math.h>

#include "scop.h"
#include "geom.h"
#include "camera.h"

int					setup_gl_objects(t_scop_context *ctx)
{
	GLuint	vertex_shader_id;

	vertex_shader_id = compile_shader("vertex.glsl", GL_VERTEX_SHADER);
	init_camera(&ctx->cam);
	ctx->dark_faces = make_dark_faces_mat(vertex_shader_id);
	ctx->cube = make_cube();
	ctx->cube.object.material = &ctx->dark_faces;
	glDeleteShader(vertex_shader_id);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.2f, 0.0f);
	return (0);
}

static t_transform	viewport_transform(const t_scop_context *ctx)
{
	GLfloat		aspect;
	t_transform	transform;

	aspect = (GLfloat)ctx->win_w / (GLfloat)ctx->win_h;
	transform = ctx->win_w < ctx->win_h ?
		homothety_y(aspect) : homothety_x(1 / aspect);
	return (transform);
}

static t_transform	proj_view_mat(const t_scop_context *ctx)
{
	t_transform	view_mat;
	t_transform	proj_mat;

	view_mat = rotation_y(-ctx->cam.horiz_angle);
	view_mat = compose_transform(rotation_x(-ctx->cam.vert_angle), view_mat);
	view_mat = compose_transform(translation(0.0f, 0.0f, -ctx->cam.distance),
									view_mat);
	proj_mat = compose_transform(viewport_transform(ctx), basic_persp());
	return (compose_transform(proj_mat, view_mat));
}

static void			draw_object(const t_object *obj, t_transform pv_mat)
{
	t_transform	pvm_mat;
	GLuint		pvm_mat_uniform_id;

	glBindVertexArray(obj->vao_id);
	glUseProgram(obj->material->program_id);
	pvm_mat_uniform_id = glGetUniformLocation(obj->material->program_id,
												"pvm_mat");
	pvm_mat = compose_transform(pv_mat, obj->model_mat);
	glUniformMatrix4fv(pvm_mat_uniform_id, 1, GL_FALSE,
						to_array(&pvm_mat));
	obj->draw(obj);
}

int					draw_scene(const t_scop_context *ctx)
{
	t_transform	pv_mat;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	pv_mat = proj_view_mat(ctx);
	draw_object(&ctx->cube.object, pv_mat);
	return (0);
}
