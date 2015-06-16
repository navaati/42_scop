/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 11:52:00 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/16 18:11:20 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void				init_camera(t_camera *cam)
{
	cam->vert_angle = -0.4f;
	cam->horiz_angle = 0.0f;
	cam->distance = 5.0f;
	cam->turning_up = false;
	cam->turning_down = false;
	cam->turning_left = false;
	cam->turning_right = false;
}

void				animate_camera(t_camera *cam, double time_diff)
{
	if (cam->turning_up)
		cam->vert_angle -= 2.0f * time_diff;
	if (cam->turning_down)
		cam->vert_angle += 2.0f * time_diff;
	if (cam->turning_left)
		cam->horiz_angle -= 2.0f * time_diff;
	if (cam->turning_right)
		cam->horiz_angle += 2.0f * time_diff;
}

static t_transform	viewport_transform(uint16_t win_w, uint16_t win_h)
{
	GLfloat		aspect;
	t_transform	transform;

	aspect = (GLfloat)win_w / (GLfloat)win_h;
	transform = win_w < win_h ?
		homothety_y(aspect) : homothety_x(1 / aspect);
	return (transform);
}

t_transform			camera_mat(const t_camera *cam,
								uint16_t win_w, uint16_t win_h)
{
	t_transform	view_mat;
	t_transform	proj_mat;

	view_mat = rotation_y(-cam->horiz_angle);
	view_mat = compose_transform(rotation_x(-cam->vert_angle), view_mat);
	view_mat = compose_transform(translation(0.0f, 0.0f, -cam->distance),
									view_mat);
	proj_mat = compose_transform(viewport_transform(win_w, win_h),
									basic_persp());
	return (compose_transform(proj_mat, view_mat));
}
