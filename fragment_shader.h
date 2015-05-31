/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragment_shader.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:36:10 by lgillot-          #+#    #+#             */
/*   Updated: 2015/05/31 16:59:04 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGMENT_SHADER_H
# define FRAGMENT_SHADER_H

const char	*g_fragment_shader = "#version 410 core\n"
"out vec3 color;\n"
"void main() {\n"
"	color = vec3(1,0,0);\n"
"}\n";

#endif
