/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-lan <side-lan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 17:32:14 by ede-roo           #+#    #+#             */
/*   Updated: 2026/10/28 19:08:51 by side-lan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/header.h"

static int	fail(t_game *game, const char *msg);
static int	init_window(t_game *game);
static int	load_texture(t_game *game);

int	run_game(t_config *cfg)
{
	t_game	game;
	
	ft_bzero(&game, sizeof(t_game));
	game.cfg = cfg;
	if (init_window(&game) || load_texture(&game))
		return (1);
	init_player_raycast(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	destroy_game(&game);
	return (0);
}

int	init_window(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!game->mlx)
		return (fail(game, mlx_strerror(mlx_errno)));
	game->screen = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->screen)
		return (fail(game, mlx_strerror(mlx_errno)));
	if (mlx_image_to_window(game->mlx, game->screen, 0, 0) < 0)
		return (fail(game, mlx_strerror(mlx_errno)));
	return (0);
}

int load_texture(t_game *game)
{
	int i;

	i = 0;
	printf("[%s]\n", game->cfg->tex_path[0]);
	while (i < 4)
	{
		game->tex[i] = mlx_load_png(game->cfg->tex_path[i]);
		if(!game->tex[i])
			return (fail(game, "failed to load texture"));
		i++;
	}
	return (0);
}

void	destroy_game(t_game *game)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (game->tex[i])//if yo dereference null MLX would carsh, so safeguard it against that
		{
			mlx_delete_texture(game->tex[i]);
			game->tex[i] = NULL;
		}
		i++;
	}
	if (game->mlx)// same sfe guard, derefrencing null owuld crash the system 
		mlx_terminate(game->mlx);
	game->mlx = NULL;// nulling these 2 makes the struct empe again
	game->screen = NULL;
}

static int	fail(t_game *game, const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)msg, 2);
	ft_putstr_fd("\n", 2);
	destroy_game(game);
	return (1);	
}


