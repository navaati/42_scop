/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 09:54:13 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 11:18:01 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <GL/glew.h>

#include "scop.h"

t_material		make_dark_faces_mat(GLuint vertex_shader_id)
{
	GLuint		geom_shader_id;
	GLuint		fragment_shader_id;
	t_material	dark;

	geom_shader_id = compile_shader("geom.glsl", GL_GEOMETRY_SHADER);
	fragment_shader_id = compile_shader("fragment.glsl", GL_FRAGMENT_SHADER);
	dark.program_id = link_program(vertex_shader_id,
									geom_shader_id,
									fragment_shader_id);
	glDeleteShader(vertex_shader_id);
	glDeleteShader(geom_shader_id);
	glDeleteShader(fragment_shader_id);
	return (dark);
}
