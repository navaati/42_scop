/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgillot- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/12 11:52:00 by lgillot-          #+#    #+#             */
/*   Updated: 2015/06/12 12:48:52 by lgillot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	init_camera(t_camera *cam)
{
	cam->vert_angle = -0.4f;
	cam->horiz_angle = 0.0f;
	cam->distance = 5.0f;
	cam->turning_up = false;
	cam->turning_down = false;
	cam->turning_left = false;
	cam->turning_right = false;
}

void	animate_camera(t_camera *cam, double time_diff)
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
