/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvan-der <wvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:03:50 by wvan-der          #+#    #+#             */
/*   Updated: 2023/11/13 17:42:44 by wvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
#  define TILE_SIZE 100
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_img
{
	void	*wall;
	void	*coin;
	void	*player;
	void	*exit;
	void	*ground;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	int		flag;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		x_max;
	int		y_max;
	int		x;
	int		y;
	int		x_player;
	int		y_player;
	int		coin_count;
	int		move_count;
	int		shortest_path;
	int		exit_flag;
	char	**map;
	char	*map_str;
}	t_game;

void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		check_newline(char *line);
int		check_newline_res(char *line);
char	*ft_free(int bytes_read, char **line);
char	*ft_realloc(char **line, int i, int *did_malloc_fail);
char	*make_res(char **line);
char	*ft_read(char **line, int fd, int *bytes_read);
char	*get_next_line(int fd);
int		check_map(char *path, t_game *game);
char	**ft_split(char *str);
int		check_path(t_game *game);
void	check_position(t_game *game, int x, int y);
void	move_check_position(t_game *game, int x, int y);
int		check_valid(t_game *game);
void	print_map(t_game *game);
int		check_border(t_game *game);
int		split_map(t_game *game);
int		check_amount_chars(t_game *game);
int		make_map_str(t_game *game, int fd);
int		check_first_row(t_game *game);
int		check_if_square(t_game *game);
int		check_last_row(t_game *game);
int		check_first_last_collum(t_game *game);
void	find_player(t_game *game);
void	init_struct(t_game *game);
void	put_error(char *str);
int		render(t_game *game);
int		close_window(t_game *game);
int		handle_input(int keysym, t_game *game);
int		init_mlx(t_game *game);
int		init_img(t_game *game);
int		render_map(t_game *game);
void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	render_wall(t_game *game, int x, int y);
void	render_ground(t_game *game, int x, int y);
void	render_player(t_game *game, int x, int y);
void	render_coin(t_game *game, int x, int y);
void	render_exit(t_game *game, int x, int y);
int		init_wall(t_game *game);
int		init_coin(t_game *game);
int		init_player(t_game *game);
int		init_exit(t_game *game);
int		init_ground(t_game *game);
int		open_exit(t_game *game);
int		callculate_path(t_game *game);
void	check_position_exit(t_game *game, int x, int y);
void	move_check_position_exit(t_game *game, int x, int y);
void	ft_free_so_long(t_game *game);
#endif