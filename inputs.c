/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 07:45:09 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/16 14:46:41 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>

#include "scop.h"
#include "inputs.h"

static void	toggle_key(bool *key, int action)
{
	if (action == GLFW_PRESS)
		*key = true;
	else if (action == GLFW_RELEASE)
		*key = false;
}

void		key_callback(GLFWwindow *window, int key,
							int scancode, int action, int mods)
{
	t_scop_context	*ctx;

	(void)scancode;
	(void)mods;
	ctx = (t_scop_context *)glfwGetWindowUserPointer(window);
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		ctx->cube.spin = !ctx->cube.spin;
	else if (key == GLFW_KEY_KP_ADD &&
				(action == GLFW_PRESS || action == GLFW_REPEAT))
		ctx->grid.new_size++;
	else if (key == GLFW_KEY_KP_SUBTRACT &&
				(action == GLFW_PRESS || action == GLFW_REPEAT))
		ctx->grid.new_size -= ctx->grid.new_size > 1 ? 1 : 0;
	else if (key == GLFW_KEY_UP)
		toggle_key(&ctx->cam.turning_up, action);
	else if (key == GLFW_KEY_DOWN)
		toggle_key(&ctx->cam.turning_down, action);
	else if (key == GLFW_KEY_LEFT)
		toggle_key(&ctx->cam.turning_left, action);
	else if (key == GLFW_KEY_RIGHT)
		toggle_key(&ctx->cam.turning_right, action);
}

void		scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
	t_scop_context	*ctx;

	(void)xoffset;
	ctx = (t_scop_context *)glfwGetWindowUserPointer(window);
	ctx->cam.distance = fmax(ctx->cam.distance - (GLfloat)yoffset, 3.0f);
}
