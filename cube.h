/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 10:45:38 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 11:18:33 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <GL/glew.h>

# include "engine.h"

typedef struct	s_cube
{
	t_object	object;
	bool		spin;
	GLfloat		spin_angle;
}				t_cube;

t_cube			make_cube(void);

#endif
