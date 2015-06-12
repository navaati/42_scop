/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:10:48 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 04:03:59 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <GL/glew.h>
# include <stdint.h>

# define POS_ATTR_LOCATION (0)

typedef struct	s_scop_context
{
	GLuint		pvm_mat_uniform_id;
	uint16_t	win_w;
	uint16_t	win_h;
	double		time;
}				t_scop_context;

GLuint			compile_shader(const char *filename, GLenum type);
GLuint			link_program(const GLint vertex_shader_id,
								const GLint geom_shader_id,
								const GLint fragment_shader_id);
int				setup_gl_objects(t_scop_context *ctx);
int				draw(const t_scop_context *ctx);

#endif
