#include "../includes/cub3d.h"

int	loop_hook(void *param)
{
	t_param	*p;

	p = (t_param*)param;
	ray_casting(p);
	move_cam(p);
	move_sideways(p);
	turn(p);
	return (1);
}

int	keyrelease(int keycode, void *param)
{
	t_param	*p;

	p = (t_param*)param;
	p->key[keycode] = 0;
	return (keycode);
}

int	keypress(int keycode, void *param)
{
	t_param	*p;

	p = (t_param*)param;
	p->key[keycode] = 1;
	if (keycode == ESCAPE)
		free_and_exit(p);
	return (keycode);
}
