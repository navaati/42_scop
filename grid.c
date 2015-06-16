/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 14:19:21 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/16 13:03:13 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <GL/glew.h>

#include "grid_mesh.h"
#include "scop.h"

static void			upload_grid(t_grid *grid)
{
	GLfloat	*buf;
	size_t	buf_size;

	glBindBuffer(GL_ARRAY_BUFFER, grid->vbo_id);
	buf = grid_gen_vectrices(grid->new_size, &buf_size);
	glBufferData(GL_ARRAY_BUFFER, buf_size, buf, GL_STATIC_DRAW);
	free(buf);
	grid->size = grid->new_size;
}

static void			draw_grid(const t_object *this)
{
	t_grid	*grid;

	grid = (t_grid *)this;
	if (grid->size != grid->new_size)
		upload_grid(grid);
	glDrawArrays(GL_LINES, 0, 2 * 2 * (grid->size + 1));
}

static void			animate_grid(t_object *this, double time_diff)
{
	(void)this;
	(void)time_diff;
}

static t_material	make_grid_mat(GLuint vertex_shader_id)
{
	GLuint		fragment_shader_id;
	t_material	grid_mat;

	fragment_shader_id = compile_shader("grid_fragment.glsl",
										GL_FRAGMENT_SHADER);
	grid_mat.program_id = link_program(vertex_shader_id,
									-1,
									fragment_shader_id);
	glDeleteShader(fragment_shader_id);
	return (grid_mat);
}

void				make_grid(t_grid *grid, GLuint vertex_shader_id)
{
	glGenVertexArrays(1, &grid->object.vao_id);
	glBindVertexArray(grid->object.vao_id);
	glGenBuffers(1, &grid->vbo_id);
	grid->new_size = 10;
	upload_grid(grid);
	glEnableVertexAttribArray(POS_ATTR_LOCATION);
	glVertexAttribPointer(POS_ATTR_LOCATION, 3, GL_FLOAT,
							GL_FALSE, 0, (void *)0);
	grid->mat = make_grid_mat(vertex_shader_id);
	grid->object.material = &grid->mat;
	grid->object.draw = draw_grid;
	grid->object.animate = animate_grid;
	grid->object.model_mat = compose_transform(homothety_x(2.0f),
												homothety_z(2.0f));
}
