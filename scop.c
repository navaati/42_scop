/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 17:10:30 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/08 14:32:42 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "scop.h"

#define WIN_W 1024
#define WIN_H 768

static GLFWwindow	*make_context_and_window(void)
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
	if (!(window = glfwCreateWindow(WIN_W, WIN_H, "SCOP", NULL, NULL)))
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

static void			resize_callback(GLFWwindow *window, int w, int h)
{
	t_scop_context	*ctx;

	ctx = (t_scop_context *)glfwGetWindowUserPointer(window);
	ctx->win_w = w;
	ctx->win_h = h;
}

static void			window_refresh_callback(GLFWwindow *window)
{
	t_scop_context	*ctx;

	ctx = (t_scop_context *)glfwGetWindowUserPointer(window);
	draw(ctx);
	glfwSwapBuffers(window);
}

int					main(void)
{
	GLFWwindow		*window;
	t_scop_context	ctx;

	if (!(window = make_context_and_window()))
	{
		return (EXIT_FAILURE);
	}
	ctx.win_w = WIN_W;
	ctx.win_h = WIN_H;
	setup_gl_objects(&ctx);
	glfwSetWindowUserPointer(window, &ctx);
	glfwSetWindowSizeCallback(window, resize_callback);
	glfwSetWindowRefreshCallback(window, window_refresh_callback);
	while (glfwWindowShouldClose(window) == 0)
	{
		glfwPollEvents();
		ctx.time = glfwGetTime();
		window_refresh_callback(window);
	}
	return (EXIT_SUCCESS);
}
