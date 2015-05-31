/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 11:02:41 by lgillot-          #+#    #+#             */
/*   Updated: 2015/05/31 17:08:48 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>

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

GLuint		link_program(const char *vertex_shader, const char *fragment_shader)
{
	GLuint	vertex_shader_id;
	GLint	fragment_shader_id;
	GLuint	program_id;
	GLint	status;

	vertex_shader_id = compile_shader(vertex_shader, GL_VERTEX_SHADER);
	fragment_shader_id = compile_shader(fragment_shader, GL_FRAGMENT_SHADER);
	program_id = glCreateProgram();
	glAttachShader(program_id, vertex_shader_id);
	glAttachShader(program_id, fragment_shader_id);
	glLinkProgram(program_id);
	glGetProgramiv(program_id, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
		print_error(program_id, glGetProgramiv, glGetProgramInfoLog);
	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);
	return (program_id);
}
