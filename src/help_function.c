
 /*--------------------------------------------------------------------------*/
//----------------- MADE BY THEO LEMAIRE ET ROMAIN COLLIGNON -----------------//
//----------------------------------------------------------------------------//
//---------------------------- DON'T MODIF THIS FILE -------------------------//
 /*--------------------------------------------------------------------------*/

#include "my_bird.h"

bool click(main_s *bird)
{
    sfFloatRect verif_click = sfSprite_getGlobalBounds(bird->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(bird->window);
    if (sfFloatRect_contains(&verif_click, mouse_pos.x, mouse_pos.y) &&
    bird->event.type == sfEvtMouseButtonReleased &&
    bird->event.mouseButton.button == sfMouseLeft)
        return true;
    else
        return false;
}

sfSprite *my_sprite(sprite_create sprite)
{
    sfSprite *sprite_genrate = sfSprite_create();

    sfRectangleShape_setOrigin((sfRectangleShape *)
    sprite_genrate, sprite.origine);
    sfRectangleShape_setScale((sfRectangleShape *)
    sprite_genrate, sprite.scale);
    sfSprite_setPosition(sprite_genrate, sprite.position);
    sfSprite_setColor(sprite_genrate, sprite.color);
    sfSprite_setRotation(sprite_genrate, sprite.rotate);
    sfSprite_setTexture(sprite_genrate, sprite.texture, sfTrue);

    return sprite_genrate;
}

sfText *my_text(text_create text)
{
    sfText *txt = sfText_create();

    sfText_setFont(txt, text.font);
    sfText_setColor(txt, text.color);
    sfText_setPosition(txt, text.position);
    sfText_setString(txt, text.text);
    sfText_setCharacterSize(txt, text.size);
    return txt;
}

sfBool click_in_sprite(main_s *my_game)
{
    // Récupération des coordonnées de la souris
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(my_game->window);

    // Vérification si la souris est dans le sprite
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(my_game->sprite);
    sfBool clicked_in_sprite = sfFloatRect_contains(&sprite_bounds, mouse_pos.x, mouse_pos.y);

    // Retourne sfTrue si la souris a cliqué sur le sprite, sinon sfFalse
    if (sfMouse_isButtonPressed(sfMouseLeft) && clicked_in_sprite) {
        return sfTrue;
    } else {
        return sfFalse;
    }
}
