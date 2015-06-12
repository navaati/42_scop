/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 07:45:09 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 08:24:39 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "scop.h"
#include "inputs.h"

void	key_callback(GLFWwindow *window, int key,
						int scancode, int action, int mods)
{
	t_scop_context	*ctx;

	(void)scancode;
	(void)mods;
	ctx = (t_scop_context *)glfwGetWindowUserPointer(window);
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		ctx->spin = !ctx->spin;
	else if (key == GLFW_KEY_UP && action == GLFW_PRESS)
		ctx->cam_vert_angle -= 0.2f;
	else if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
		ctx->cam_vert_angle += 0.2f;
	else if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
		ctx->cam_horiz_angle -= 0.2f;
	else if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
		ctx->cam_horiz_angle += 0.2f;
}

void	scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	t_scop_context	*ctx;

	(void)xoffset;
	ctx = (t_scop_context *)glfwGetWindowUserPointer(window);
	ctx->cam_distance = fmax(ctx->cam_distance - (GLfloat)yoffset, 3.0f);
}
