/*
** my_draw_line.c for wireframe in /home/Rev/wireframe/src
** 
** Made by Roméo Nahon
** Login	 <Rev@epitech.net>
** 
** Started on	Mon Dec	5 10:07:10 2016 Roméo Nahon
** Last update	Mon Dec	5 10:07:10 2016 Roméo Nahon
*/

#include "../include/my.h"

void	my_draw_line(BUFF,
 sfVector2i from,
 sfVector2i to,
 sfColor color)
{
  t_line	line;

  line.x = from.x;
  line.y = from.y;
  line.i = 1;
  line.dx = to.x - from.x;
  line.dy = to.y - from.y;
  line.xinc = (line.dx > 0) ? 1 : -1;
  line.yinc = (line.dy > 0) ? 1 : -1;
  line.dx = abs(line.dx);
  line.dy = abs(line.dy);
  my_put_pixel(framebuffer, line.x, line.y, color);
  if (line.dx > line.dy)
    line_dx_sup(line, framebuffer, color);
  else
    line_dx_inf(line, framebuffer, color);
}
void	line_dx_sup(t_line line, BUFF, sfColor color)
{
  line.cumul = line.dx / 2;
  while (line.i <= line.dx)
  {
    line.x += line.xinc;
    line.cumul += line.dy;
    if (line.cumul >= line.dx)
    {
     line.cumul -= line.dx;
     line.y += line.yinc;
   }
   my_put_pixel(framebuffer, line.x, line.y, color);
   line.i += 1;
 }
}
void	line_dx_inf(t_line line, BUFF, sfColor color)
{
  line.cumul = line.dy / 2;
  while (line.i <= line.dy)
  {
    line.y += line.yinc;
    line.cumul += line.dx;
    if (line.cumul >= line.dy)
    {
     line.cumul -= line.dy;
     line.x += line.xinc;
   }
   my_put_pixel(framebuffer, line.x, line.y, color);
   line.i += 1;
 }
}
