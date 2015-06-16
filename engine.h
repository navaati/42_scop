/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 11:09:25 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/16 18:50:39 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <sys/queue.h>
# include <GL/glew.h>

# include "geom.h"
# include "camera.h"

typedef struct	s_material
{
	GLuint		program_id;
}				t_material;

# define LIST_HEAD_OBJECT LIST_HEAD(t_objects_head, s_object)
# define LIST_ENTRY_OBJECT LIST_ENTRY(s_object)

typedef struct	s_object
{
	GLuint				vao_id;
	void				(*draw)(const struct s_object *);
	t_transform			model_mat;
	t_material			*material;
	void				(*animate)(struct s_object *, double time_diff);
	LIST_ENTRY_OBJECT	engine_node;
}				t_object;

typedef struct	s_engine
{
	t_camera			camera;
	double				old_time;
	LIST_HEAD_OBJECT	objects;
}				t_engine;

void			engine_init(t_engine *engine, double time);
void			engine_add_object(t_engine *engine, t_object *object);
void			engine_animate(t_engine *engine, double time);
void			engine_render(const t_engine *engine,
								uint16_t win_w, uint16_t win_h);

#endif
