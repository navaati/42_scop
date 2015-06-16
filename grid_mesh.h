/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_mesh.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 15:13:45 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/15 15:24:39 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_MESH_H
# define GRID_MESH_H

# include <stdlib.h>
# include <GL/glew.h>

GLfloat *grid_gen_vectrices(unsigned size, size_t *buf_size);

#endif
