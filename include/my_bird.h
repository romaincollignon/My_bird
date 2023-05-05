/*
** EPITECH PROJECT, 2023
** my_bird
** File description:
** my_bird
*/

//--------------------------------------------------------------------//
//--------------------------------------------------------------------//
//----------   -MADE BY THEO LEMAIRE ET ROMAIN COLLIGNON--------------//
//--------------------------------------------------------------------//
//--------------------------------------------------------------------//

#include <unistd.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/Window/Mouse.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Window.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <SFML/Window/Event.h>

#ifndef MY_BIRD_H_

#define MY_BIRD_H_

typedef struct {
    sfRenderWindow *window;
    sfSprite *sprite;
    sfVideoMode mode;
    sfEvent event;
    sfSprite *background;
    float time;
    sfClock *clock;
    sfIntRect rect;
    int speed_sprite;
    int x;
    int y;
    int nb_passage;
} main_s;

typedef struct {
    sfFont *font;
    sfVector2f position;
    sfColor color;
    const char *text;
    int size;
} text_create;

typedef struct {
    sfVector2f position;
    sfColor color;
    sfVector2f scale;
    float rotate;
    const sfTexture *texture;
    sfVector2f origine;
} sprite_create;

sfText *my_text(text_create text);
sfSprite *my_sprite(sprite_create sprite);
sfBool click_in_sprite(main_s *my_game);

#endif /* !MY_BIRD_H_ */

