/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_shader.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 15:14:47 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 02:24:05 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_SHADER_H
# define VERTEX_SHADER_H

const char	*g_vertex_shader = "#version 410 core\n"
"uniform mat4 pvm_mat;\n"
"in vec3 pos;\n"
"void main() {\n"
"	gl_Position = pvm_mat * vec4(pos, 1);\n"
"}\n";

#endif
