/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:22:42 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/26 20:07:43 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_imgdata *data, int x, int y, UINT color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(UINT *)dst = color;
}

void	paint_fractal_mt(t_vars *vars) {
	t_thread_vars thread_vars[THREADS];
	pthread_t thread_ids[THREADS];
	ft_bzero(thread_vars, sizeof(t_thread_vars) * THREADS);
	ft_bzero(thread_ids, sizeof(pthread_t) * THREADS);

	for (int i = 0; i < THREADS; i++) {
		(thread_vars[i]).thread_num = i;
		(thread_vars[i]).vars = vars;

		pthread_create(thread_ids + i, 0, paint_slice, thread_vars + i);
	}

	for (int i = 0; i < THREADS; i++) {
		void **ret = 0;
		pthread_join(thread_ids[i], ret);
	}

	mlx_put_image_to_window(vars->mlx, vars->win, vars->id->img, 0, 0);
}

void	*paint_slice(void *args) {
	t_thread_vars *tvars = (t_thread_vars *) args;
	int thread_num = tvars->thread_num;
	t_vars *vars = tvars->vars;

	int start_i = thread_num;

	t_complex	*z;
	t_complex	c;
	int			i;
	int			j;

	z = init_complex();
	i = start_i;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			z->re = j;
			z->im = i;
			transform_z_assign_c(z, &c, vars);
			UINT color = choose_color(vars->fd->fractal_func(*z, c, \
				vars->fd->iters, 0), vars);
			//color = choose_color(thread_num, vars);
			//pthread_mutex_lock(vars->img_mtx);
			img_pixel_put(vars->id, j, i, color);
			//pthread_mutex_unlock(vars->img_mtx);
			j++;
		}
		i += THREADS;
	}
	free(z);

	return 0;
}

void	paint_fractal(t_vars *vars)
{
	t_complex	*z;
	t_complex	c;
	int			i;
	int			j;

	z = init_complex();
	i = 0;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			z->re = j;
			z->im = i;
			transform_z_assign_c(z, &c, vars);
			img_pixel_put(vars->id, j, i, \
				choose_color(vars->fd->fractal_func(*z, c, \
				vars->fd->iters, 0), vars));
			j++;
		}
		i++;
	}
	free(z);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->id->img, 0, 0);
}

void	transform_z_assign_c(t_complex *z, t_complex *c, t_vars *vars)
{
	z = transform_coordinates(z, vars);
	if (vars->fd->fractal_func == &julia)
		*c = vars->julia_c;
	else
		*c = *z;
}
