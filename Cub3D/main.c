#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "mlx.h"
#include "keys.h"

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
    void          *image;
}                 data_t;

void    ft_putchar(char c)
{
    write(1, &c,1);
}

void    draw_sqare(data_t *data, int x, int y, int j, int k)
{
    int     posx;
    int     posy;
    
    posx = x;
    posy = y;
    while (posx <= 150 + j)
    {
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, posx, posy, 0xfffafa);
        posx++;
    }
    while (posy <= 150 + k)
    {
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, posx, posy, 0xfffafa);
        posy++;
    }
    posx = x;
    posy = y;
    while (posy <= 150 + k)
    {
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, posx, posy, 0xfffafa);
        posy++;
    }
    while (posx <= 150 + j)
    {
        mlx_pixel_put(data->mlx_ptr, data->mlx_win, posx, posy, 0xfffafa);
        posx++;
    }
}

int     deal_key(int key, data_t *data, void *image)
{
    static int     x = 30;
    static int     y = 30;

    ft_putchar('x');
    mlx_clear_window(data->mlx_ptr, data->mlx_win);
    if (key == KEY_LEFT)
        x = x - 10;
    if (key == KEY_RIGHT)
        x = x + 10;
    if (key == KEY_UP)
        y = y - 10;
    if (key == KEY_DOWN)
        y = y + 10;
    //draw_sqare(data, x, y, j, k);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->image, x, y);
    return (0);
}

/*int     main(void)
{
    data_t      data;
    int         width;
    int         h;
    int         i;
    int         j;
    int         k;
    int         x;
    int         y;
    double      poseX;
    double      poseY;
    double      dirX;
    double      dirY;
    double      rayPosX;
    double      rayPosY;
    double      rayDirX;
    double      rayDirY;
    double      planX;
    double      planY;
    double      cameraX;

    i = 0;
    j = 0;
    width = 900;
    h = 750;
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 900, 750, "Hello world")) == NULL)
        return (EXIT_FAILURE);
    
    while (i < 6)
    {
        draw_sqare(&data, 0, 0, j, 0);
        j+= 150;
        i++;
    }
    i = 0;
    j = 0;
    while (i < 6)
    {
        draw_sqare(&data, 0, 600, j, 600);
        j += 150;
        //k += 150;
        i++;
    }
    i = 0;
    k = 0;
    while (i < 6)
    {
        draw_sqare(&data, 0, 150, 0, k);
        k += 150;
        i++;
    }
    i = 0;
    k = 0;
    while (i < 6)
    {
        draw_sqare(&data, 750, 0, 750, k);
        k += 150;
        i++;
    }
    draw_sqare(&data, 450, 450, 450, 450);
    int map[5][6] = {{1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 1},
                {1, 0, 0, 1, 0, 1},
                {1, 1, 1, 1, 1, 1}};
    
    poseX = 0;
    poseY = 0;
    x = 0;
    dirX = 1;
    dirY = 0;
    planX = 0;
    planY = 1;
    cameraX = (2*x/width) - 1;
    rayPosX = poseX;
    rayPosY = poseY;
    rayDirX = dirX + planX * cameraX;
    rayDirY = dirY + planY * cameraX;

    int     mapX;
    int     mapY;
    
    mapX = (int)rayPosX;
    mapY = (int)rayPosY;

    double  sideDistX;
    double  sideDistY;

    double  deltaDistX = fabs (1 / rayDirX);
    double  deltaDistY = fabs (1 / rayDirY);

    double  stepX;
    double  stepY;
    int      hit;
    double  side;
    double perpWallDist;

    if (rayDirX<0)
    {
    	stepX = -1;// vecteur de direction
 	    sideDistX = (rayPosX - mapX) * deltaDistX;
    } 
    else
    {
	    stepX = 1;
 	    sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
    }
    if (rayDirY < 0)
    {
	    stepY = -1;
	    sideDistY = (rayPosY - mapY) * deltaDistY;
    } 
    else
    {
	    stepY = 1;
	    sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
    }
    while (hit == 0) 
    {
	//Passe à la case suivante sur X ou Y
	    if (sideDistX<sideDistY)
        {
		    sideDistX += deltaDistX;// agrandis le rayon
		    mapX += stepX;// prochaine case ou case précédente sur X
		    side = 0;// orientation du mur
	    } 
        else
        {
		    sideDistY += deltaDistY;// agrandis le rayon
		    mapY += stepY;// prochaine case ou case précédente sur Y
		    side = 1;// orientation du mur
	    }
 
	    // si le rayon rencontre un mur
	    if (map[mapX][mapY]>0) 
        {
		    hit=1;// stoppe la boucle 
	    }
    }
    if (side == 0) 
    {
	    perpWallDist = fabs((mapX-rayPosX+(1-stepX)/2)/rayDirX);
    } 
    else 
    {
	    perpWallDist = fabs((mapY-rayPosY+(1-stepY)/2)/rayDirY);
    }
    int hauteurLigne;
    hauteurLigne = abs((int)(h / perpWallDist));
 
    //Calcule les pixels max haut et max bas de la colonne à tracer
    int drawStart;
    int drawEnd;
    drawStart = (int)(-hauteurLigne/2+h/2);
    drawEnd = (int)(hauteurLigne/2+h/2);
 
// limite les zones de tracé à l'écran uniquement
    if (drawStart < 0)
    {
	    drawStart = 0;
    }
    if (drawEnd >= h)
    {
	    drawEnd = h-1;
    }
    y = drawStart;
    while (y < drawEnd) 
    {
	    int  color = 0xf2f2f2;// couleur du pixel pour un mur Nord/Sud
	    if (side == 1) 
        {
	    	color = 0xCCCCCC;// couleur du pixel pour un mur Est/Ouest
	    }
	    mlx_pixel_put(data.mlx_ptr, data.mlx_win, x,y,color);// trace le pixel
	    y++;// incrémente la position Y du prochain pixel à tracer
    }

    //pose_perso(375, 375); ou ()
    // taille du mur = 4m;
    // hauteur camera = 2m;
    // mlx_loop(data.mlx_ptr);
    //x = 300;
    //y = 300;
    while (x <= 350)
    {
        mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xfffafa);
        x++;
    }
    while (y <= 350)
    {
        mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xfffafa);
        y++;
    }
    x = 300;
    y = 300;
    while (y <= 350)
    {
        mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xfffafa);
        y++;
    }
    while (x <= 350)
    {
        mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0xfffafa);
        x++;
    }
    //draw_sqare(&data, x, y, j, k);
    //mlx_key_hook(data.mlx_win, deal_key, &data);
    //data.image = mlx_xpm_file_to_image(data.mlx_ptr, "image.XPM", &width, &height);
    //mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.image, 10, 10);
    //mlx_key_hook(data.mlx_win, deal_key, &data);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}*/
int main(void)
{
    data_t        data;
    int w = 960; //width of the graphical window
    int h = 480; //height of the graphical window
    double posX = 22, posY = 11.5;  //x and y start position
    double dirX = -1, dirY = 0; //initial direction vector
    double planeX = 0, planeY = 1; //the 2d raycaster version of camera plane

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame

    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, w, h, "Hello world")) == NULL)
        return (EXIT_FAILURE);

    int worldMap[25][25] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1},
{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1},
{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1},
{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1},
{1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1},
{1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,1},
{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

    for(int x = 0; x < w; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;
      //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;

       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = fabs(1 / rayDirX);
      double deltaDistY = fabs(1 / rayDirY);
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?
      //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      }
      //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
      if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      else           perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

      //Calculate height of line to draw on screen
      int lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + h / 2;
      if(drawEnd >= h)drawEnd = h - 1;
    
        // if(drawEnd < drawStart) {drawStart += drawEnd; drawEnd = drawStart - drawEnd; drawStart -= drawEnd;} //swap drawStart and drawEnd
        // if(drawEnd < 0 || drawStart >= h  || x < 0 || x >= w) return 0; //no single point of the line is on screen
        // if(drawStart < 0) drawStart = 0; //clip
        // if(drawEnd >= w) drawEnd = h - 1; //clip

    // limite les zones de tracé à l'écran uniquement
    if (drawStart < 0) {
	    drawStart = 0;
    }
    if (drawEnd >= h) {
	    drawEnd = h-1;
    }

    // tracer la colonne
    int y = drawStart;
 
    while (y < drawEnd)
    {
	    int color = 0xf2f2f2;// couleur du pixel pour un mur Nord/Sud
	    if (side == 1)
		{
            color = 0xCCCCCC;// couleur du pixel pour un mur Est/Ouest
        }    
        mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, color);
	    y++;// incrémente la position Y du prochain pixel à tracer
    }
    if (drawEnd < 0)
    {
	    drawEnd = h;
    }
 
    //trace le sol de la fin du mur au bas de l'écran
    y = drawEnd;
    while (y < h) 
    {
        mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0x006666); // trace le pixel du sol
        mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, h-y-1, 0xcc0000); // trace le pixel du plafond
	    y++;
    }
    x++ ;

    }
  
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}
