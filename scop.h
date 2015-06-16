/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:10:48 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/15 15:44:02 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <GL/glew.h>
# include <stdint.h>
# include <stdbool.h>

# include "engine.h"
# include "camera.h"
# include "cube.h"
# include "grid.h"

# define POS_ATTR_LOCATION (0)

typedef struct	s_scop_context
{
	uint16_t	win_w;
	uint16_t	win_h;
	t_camera	cam;
	t_material	dark_faces;
	t_cube		cube;
	t_grid		grid;
}				t_scop_context;

GLuint			compile_shader(const char *filename, GLenum type);
GLuint			link_program(const GLint vertex_shader_id,
								const GLint geom_shader_id,
								const GLint fragment_shader_id);
t_material		make_dark_faces_mat(GLuint vertex_shader_id);
int				setup_gl_objects(t_scop_context *ctx);
int				draw_scene(const t_scop_context *ctx);

#endif
