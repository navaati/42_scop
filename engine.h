/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 11:09:25 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/15 16:42:24 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <GL/glew.h>

# include "geom.h"

typedef struct	s_material
{
	GLuint		program_id;
}				t_material;

typedef struct	s_object
{
	GLuint				vao_id;
	void				(*draw)(const struct s_object *);
	t_transform			model_mat;
	t_material			*material;
	void				(*animate)(struct s_object *, double time_diff);
}				t_object;

#endif
