/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 18:36:43 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/08 17:24:44 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOM_H
# define GEOM_H

# include <GL/glew.h>

typedef struct	s_transform
{
	GLfloat	mat[4][4];
}				t_transform;

extern const t_transform	g_identity;

t_transform		compose_transform(t_transform a, t_transform b);
t_transform		translation(GLfloat x, GLfloat y, GLfloat z);
t_transform		rotation_x(GLfloat angle);
t_transform		rotation_y(GLfloat angle);
t_transform		rotation_z(GLfloat angle);
t_transform		homothety_x(GLfloat factor);
t_transform		homothety_y(GLfloat factor);
t_transform		homothety_z(GLfloat factor);
t_transform		basic_persp();
GLfloat			*to_array(t_transform *transf);

#endif
