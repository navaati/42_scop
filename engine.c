/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 17:19:34 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/16 18:54:42 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>
#include <sys/queue.h>

#include "geom.h"

#include "engine.h"

void		engine_init(t_engine *engine, double time)
{
	init_camera(&engine->camera);
	engine->old_time = time;
	LIST_INIT(&engine->objects);
}

void		engine_add_object(t_engine *engine, t_object *object)
{
	LIST_INSERT_HEAD(&engine->objects, object, engine_node);
}

void		engine_animate(t_engine *engine, double time)
{
	double		time_diff;
	t_object	*object;

	time_diff = time - engine->old_time;
	animate_camera(&engine->camera, time_diff);
	object = engine->objects.lh_first;
	while (object)
	{
		object->animate(object, time_diff);
		object = object->engine_node.le_next;
	}
	engine->old_time = time;
}

static void	draw_object(const t_object *obj, t_transform pv_mat)
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

void		engine_render(const t_engine *engine,
									uint16_t win_w, uint16_t win_h)
{
	t_transform		pv_mat;
	const t_object	*object;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	pv_mat = camera_mat(&engine->camera, win_w, win_h);
	object = engine->objects.lh_first;
	while (object)
	{
		draw_object(object, pv_mat);
		object = object->engine_node.le_next;
	}
}
