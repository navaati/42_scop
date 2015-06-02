/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:10:30 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/04 00:40:54 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
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

static GLFWwindow		*make_context_and_window(void)
{
	GLFWwindow	*window;

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return (NULL);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glewExperimental = GL_TRUE;
	if (!(window = glfwCreateWindow(1024, 768, "SCOP", NULL, NULL)))
	{
		fprintf(stderr, "Failed to open GLFW window\n");
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		return (NULL);
	}
	return (window);
}

int						setup_gl_objects(GLuint *program_id)
{
	GLuint l_program_id;
	GLuint vao_id;
	GLuint point_attr_loc;
	GLuint vbo_id;

	l_program_id = link_program(g_vertex_shader, g_fragment_shader);
	point_attr_loc = glGetAttribLocation(l_program_id, "point");
	glGenVertexArrays(1, &vao_id);
	glBindVertexArray(vao_id);
	glGenBuffers(1, &vbo_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_triangle), g_triangle,
					GL_STATIC_DRAW);
	glEnableVertexAttribArray(point_attr_loc);
	glVertexAttribPointer(point_attr_loc, 2, GL_FLOAT,
							GL_FALSE, 0, (void *)0);
	glUseProgram(l_program_id);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	*program_id = l_program_id;
	return (0);
}

int						draw(GLuint program_id, int win_w, int win_h)
{
	t_transform	view_mat;
	GLfloat		aspect;
	t_transform	proj_mat;
	t_transform	pv_mat;
	GLuint		pv_mat_uniform_id;

	view_mat = compose_transform(translation(0.5, 0, 0),
									rotation_z(0.5f));
	aspect = (GLfloat)win_w / (GLfloat)win_h;
	proj_mat = win_w < win_h ? homothety_y(aspect) : homothety_x(1 / aspect);
	pv_mat = compose_transform(proj_mat, view_mat);
	pv_mat_uniform_id = glGetUniformLocation(program_id, "pv_mat");
	glUniformMatrix4fv(pv_mat_uniform_id, 1, GL_FALSE, to_array(&pv_mat));
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return (0);
}

int						main(void)
{
	GLFWwindow	*window;
	GLuint		program_id;
	int			win_w;
	int			win_h;

	if (!(window = make_context_and_window()))
	{
		return (EXIT_FAILURE);
	}
	setup_gl_objects(&program_id);
	while (glfwWindowShouldClose(window) == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwGetWindowSize(window, &win_w, &win_h);
		draw(program_id, win_w, win_h);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	return (EXIT_SUCCESS);
}
