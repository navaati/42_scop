/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 15:26:28 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/16 15:54:59 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H

# include <GL/glew.h>

# include "engine.h"

typedef struct	s_grid
{
	t_object	object;
	t_material	mat;
	GLuint		vbo_id;
	unsigned	size;
	unsigned	new_size;
}				t_grid;

void			make_grid(t_grid *grid, GLuint vertex_shader_id);

#endif
