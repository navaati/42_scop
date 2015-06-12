/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 07:46:25 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 08:24:59 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include <GLFW/glfw3.h>

void	key_callback(GLFWwindow *window, int key,
						int scancode, int action, int mods);
void	scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

#endif
