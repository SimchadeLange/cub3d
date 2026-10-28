#include "includes/header.h"

static  void set_vectors(t_player *p, double dir_x, double dir_y)
{
    p->dir_x = dir_x;
    p->dir_y = dir_y;
    p->plane_x = -dir_y *0.66;
    p->plane_y = dir_x *0.66;
}

void    init_player_raycast(t_game *g)
{
    g->player.x = g->cfg->player_x;
    g->player.y = g->cfg->player_y;//copy start position form cfg

    if (g->cfg->player_dir == NORTH)
        set_vectors(&g->player, 0, -1);
    else if (g->cfg->player_dir == SOUTH)
        set_vectors(&g->player, 0, 1);
    else if (g->cfg->player_dir == EAST)
        set_vectors(&g->player, 1, 0);
    else
        set_vectors(&g->player, -1, 0);
}