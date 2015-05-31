/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_shader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:14:47 by lgillot-          #+#    #+#             */
/*   Updated: 2015/05/31 17:47:22 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_SHADER_H
# define VERTEX_SHADER_H

const char	*g_vertex_shader = "#version 410 core\n"
"in vec2 point;\n"
"uniform mat4 pvMat = mat4(1.0);\n"
"void main() {\n"
"	gl_Position = pvMat * vec4(point.x, point.y, 0, 1);\n"
"}\n";

#endif
