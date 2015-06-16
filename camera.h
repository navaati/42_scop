/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 11:52:25 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/16 18:12:47 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stdbool.h>
# include <stdint.h>
# include <GL/glew.h>

# include "geom.h"

typedef struct	s_camera
{
	GLfloat		vert_angle;
	GLfloat		horiz_angle;
	GLfloat		distance;
	bool		turning_up;
	bool		turning_down;
	bool		turning_left;
	bool		turning_right;
}				t_camera;

void			init_camera(t_camera *cam);
void			animate_camera(t_camera *cam, double time_diff);
t_transform		camera_mat(const t_camera *cam,
							uint16_t win_w, uint16_t win_h);

#endif
