/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 11:02:41 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 02:41:50 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>

#include "scop.h"

static void	print_error(GLuint id,
						void (*get_log_len)(GLuint, GLenum, GLint *),
						void (*get_log)(GLuint, GLsizei, GLsizei *, GLchar *))
{
	GLint	log_len;
	GLchar	*log;

	get_log_len(id, GL_INFO_LOG_LENGTH, &log_len);
	if ((log = (GLchar *)malloc(log_len)))
	{
		get_log(id, log_len, NULL, log);
		fprintf(stderr, "%s\n", log);
	}
}

GLuint		compile_shader(const char *shader_code, GLenum type)
{
	GLuint	shader_id;
	GLint	status;

	shader_id = glCreateShader(type);
	glShaderSource(shader_id, 1, &shader_code, NULL);
	glCompileShader(shader_id);
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE)
		print_error(shader_id, glGetShaderiv, glGetShaderInfoLog);
	return (shader_id);
}

GLuint		link_program(const GLuint vertex_shader_id,
							const GLuint fragment_shader_id)
{
	GLuint	program_id;
	GLint	status;

	program_id = glCreateProgram();
	glAttachShader(program_id, vertex_shader_id);
	glAttachShader(program_id, fragment_shader_id);
	glBindAttribLocation(program_id, POS_ATTR_LOCATION, "pos");
	glLinkProgram(program_id);
	glGetProgramiv(program_id, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
		print_error(program_id, glGetProgramiv, glGetProgramInfoLog);
	return (program_id);
}
