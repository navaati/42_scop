/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 11:52:25 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 11:56:00 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <stdbool.h>
# include <GL/glew.h>

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

#endif
