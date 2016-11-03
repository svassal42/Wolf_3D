/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svassal <svassal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:30:48 by svassal           #+#    #+#             */
/*   Updated: 2016/10/08 18:50:55 by svassal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

/*
** Initialize MLX
*/

void			*mlx_init();

/*
** Basic actions
*/

/*
** Initialize a window, return 0 if failed
*/

void			*mlx_new_window(void *mlx_ptr, int size_x,
					int size_y, char *title);

/*
** Clear the window given as parameter
*/

int				mlx_clear_window(void *mlx_ptr, void *win_ptr);

/*
** Draw a pixel (color parameter given) at coordinates given as parameter
*/

int				mlx_pixel_put(void *mlx_ptr, void *win_ptr,
					int x, int y, int color);

/*
** Image stuff
*/

/*
** Create an image, return 0 if failed
*/

void			*mlx_new_image(void *mlx_ptr, int width, int height);

/*
** Get the top left pixel's image adress
*/

char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
					int *size_line, int *endian);

/*
** Draw the image given as parameter to the window given as parameter
*/

int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
					void *img_ptr, int x, int y);

/*
** Dunno yet
*/

unsigned int	mlx_get_color_value(void *mlx_ptr, int color);

/*
** Events
*/

/*
** Event hook on mouse
*/

int				mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);

/*
** Event hook on keyboard
*/

int				mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);

/*
** Event hook on expose (refresh)
*/

int				mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);

/*
** Event hook on loop
*/

int				mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);

/*
** MLX event starter
*/

int				mlx_loop(void *mlx_ptr);

/*
** Other Stuff
*/

/*
** Put a string to the window at given coordinates
*/

int				mlx_string_put(void *mlx_ptr, void *win_ptr,
					int x, int y, int color, char *string);

/*
** Dunno yet
*/

void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
					int *width, int *height);

/*
** Dunno yet
*/

void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
					int *width, int *height);

/*
** Destroy an allocated window
*/

int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);

/*
** Destroy an allocated image
*/

int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);

/*
** Generic hook event
*/

int				mlx_hook(void *win_ptr, int x_event, int x_mask,
					int (*funct)(), void *param);

/*
** Disable keyboard auto-reapeat in MLX
*/

int				mlx_do_key_autorepeatoff(void *mlx_ptr);

/*
** Enable keyboard auto-repeat in MLX
*/

int				mlx_do_key_autorepeaton(void *mlx_ptr);

/*
** Force sync
*/

int				mlx_do_sync(void *mlx_ptr);

#endif
