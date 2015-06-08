/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_shader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:14:47 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/08 18:07:23 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_SHADER_H
# define VERTEX_SHADER_H

const char	*g_vertex_shader = "#version 410 core\n"
"in vec3 point;\n"
"uniform mat4 pvm_mat;\n"
"void main() {\n"
"	gl_Position = pvm_mat * vec4(point.xyz, 1);\n"
"}\n";

#endif
