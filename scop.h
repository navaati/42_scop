/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:10:48 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/08 13:51:07 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include <GL/glew.h>
# include <stdint.h>

typedef struct	s_scop_context
{
	GLuint		pv_mat_uniform_id;
	uint16_t	win_w;
	uint16_t	win_h;
}				t_scop_context;

GLuint			link_program(const char *vertex_shader,
							const char *fragment_shader);
int				setup_gl_objects(t_scop_context *ctx);
int				draw(const t_scop_context *ctx);

#endif
