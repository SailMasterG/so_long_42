#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>


struct mlx
{
    void *mlx_ptr;
    void *win_ptr;
    int x;
    int y;
    void *img_ptr;
};

int funcion_cerrar(struct mlx *ventana)
{
     mlx_loop_end(ventana->mlx_ptr);
     return (0);
}
int funcion_teclas(int keycode, void *param)
{
    struct mlx *ventana = (struct mlx *)param; 

    
        if(keycode == 65307)
        {
            funcion_cerrar(ventana);
        }
        else if(keycode == 119)
        {
            ventana->y = ventana->y - 10;
            mlx_clear_window(ventana->mlx_ptr,ventana->win_ptr);
             mlx_put_image_to_window(ventana->mlx_ptr, ventana->win_ptr, ventana->img_ptr,ventana->x, ventana->y);
        }
        else if(keycode == 97)
        {
            ventana->x = ventana->x - 10;
            mlx_clear_window(ventana->mlx_ptr,ventana->win_ptr);
            mlx_put_image_to_window(ventana->mlx_ptr, ventana->win_ptr, ventana->img_ptr,ventana->x, ventana->y);

        }
        else if(keycode == 115)
        {
            ventana->y = ventana->y + 10;
            mlx_clear_window(ventana->mlx_ptr,ventana->win_ptr);
            mlx_put_image_to_window(ventana->mlx_ptr, ventana->win_ptr, ventana->img_ptr,ventana->x, ventana->y);
        }
        else if( keycode == 100)
        {
            ventana->x = ventana->x + 10;
            mlx_clear_window(ventana->mlx_ptr,ventana->win_ptr);
            mlx_put_image_to_window(ventana->mlx_ptr, ventana->win_ptr, ventana->img_ptr,ventana->x, ventana->y);
        }
        return (0);
}

void clean_mlx(struct mlx *ptr)
{
    if(ptr->img_ptr != NULL)
        mlx_destroy_image(ptr->mlx_ptr, ptr->img_ptr);
    mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
    mlx_destroy_display(ptr->mlx_ptr);
    free(ptr->mlx_ptr);
}



int main()
{
    struct mlx ventana;
    int img_width;
    int img_heigth;
    ventana.x = 600;
    ventana.y = 300;

    ventana.mlx_ptr= mlx_init();
    ventana.win_ptr =  mlx_new_window(ventana.mlx_ptr, 1600, 600, "Hello MLX");
    
    mlx_hook(ventana.win_ptr,17,0,(void *)funcion_cerrar, &ventana);
    mlx_string_put(ventana.mlx_ptr, ventana.win_ptr, 700, 300, 0xFFFFF,"LUCAS NO SE BANA" );
    mlx_pixel_put(ventana.mlx_ptr, ventana.win_ptr, 200,200, 0xb1f970);
    ventana.img_ptr = mlx_xpm_file_to_image(ventana.mlx_ptr, "textures/Idle.xpm", &img_width, &img_heigth);
    if(ventana.img_ptr == NULL)
    {
        clean_mlx(&ventana);
        printf("Error en imagen\n");
        return (1);
    }
    mlx_put_image_to_window(ventana.mlx_ptr, ventana.win_ptr, ventana.img_ptr, ventana.x, ventana.y);
    
    mlx_key_hook(ventana.win_ptr,(void *)funcion_teclas, &ventana);
    mlx_loop(ventana.mlx_ptr);

    clean_mlx(&ventana);
    printf("Ventana Cerrada\n");
    
    return (0);
}