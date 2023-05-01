
 /*--------------------------------------------------------------------------*/
//------------- CODE MADE BY THEO LEMAIRE AND ROMAIN COLLIGNON ---------------//
 /*--------------------------------------------------------------------------*/

#include "my_bird.h"

void init_structure(main_s *my_game, int nb_arg, char **tab_arg) // Fonction Initialisation structure
{
    my_game->window = sfRenderWindow_create((sfVideoMode) {800, 600}, "my_bird", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(my_game->window, 120);
    /* ETAPE 4 */

    if (nb_arg == /* 12 % 5 = ? */) {
        my_game->speed_sprite = /* fonction qui permet de passer un "char *" et "int" */(tab_arg[1]);
    } else {
        my_game->speed_sprite = /* Vitesse si jamais l'on ne donne pas de vitesse */;
    }
    sfRenderWindow_setFramerateLimit(my_game->window, my_game->speed_sprite);

    my_game->background = my_sprite((sprite_create) {
        .color = sfWhite,
        .rotate = 0,
        .position = (sfVector2f) {0, 0},
        .texture = sfTexture_createFromFile("ressource/bg.png", NULL),
        .scale = (sfVector2f) {1, 1},
    });

    my_game->sprite = my_sprite((sprite_create) {
        .position = (sfVector2f) {0, 0},
        .scale = (sfVector2f) {1, 1},
        .color = sfWhite,
        .rotate = 0,
        .texture = sfTexture_createFromFile("./ressource/sprite.png", NULL),
    });

    my_game->rect = (sfIntRect) {0, 0, 100, 100};
    sfSprite_setTextureRect(my_game->sprite, my_game->rect);
    my_game->clock = sfClock_create();
    my_game->time = 0.0f;
    my_game->x = /* Le sprite commence en quel position ? (x) */;
    my_game->y = 400;
    my_game->nb_passage = /* Le sprite commence avec combien de tour déjà réalisé ? */;
}

void update(main_s *my_game)
{
    while (sfRenderWindow_pollEvent(my_game->window, &my_game->event)) {
        if (my_game->event.type == sfEvtClosed) // Si l'utilisateur clique sur la croix (bouton fermer) il va ferme la fenêtre
            sfRenderWindow_close(my_game->window);
        if (click_in_sprite(my_game) == /* Vrai ou faux ?*/) {
            /* ETAPE 3 */
            exit(0);
        }
        /* ETAPE 6 */
    }
}

void display(main_s *my_game)
{
    sfRenderWindow_display(my_game->window);
    float speed = 20.5f; // Vitesse de déplacement du sprite
    static float x = 0.0f; // Position actuelle du sprite
    x += speed; // Incrémente la position actuelle du sprite de sa vitesse de déplacement
    if (x >= 800.0f) // Si le sprite a dépassé la fin de l'écran
    {
        x = 0.0f; // Ramène le sprite au début de l'écra
        /* Ajouter + 1 à my_game->nb_passage */
        /* ETAPE 5 */
    }
    sfVector2f pos = { x, my_game->y }; // Nouvelle position du sprite
    sfSprite_setPosition(my_game->sprite, pos); // Applique la nouvelle position du sprite

    int resultat = additionner(2, 5);


    sfRenderWindow_drawSprite(my_game->window, my_game->background, NULL); // Affichage Fond
    sfRenderWindow_drawSprite(/* Fenêtre */, /* Sprite */, NULL); // Affichage Sprite
}


////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// 🖐 - MAIN - 🖐 ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(int nb_arg, char **tab_arg)
{
    main_s *my_game = malloc(sizeof(main_s)); // Allocation de mémoire
    init_structure(my_game, nb_arg, tab_arg);
    while (sfRenderWindow_isOpen(my_game->window)) {
        sfRenderWindow_display(my_game->window); // Affichage de la fenêtre
        update(my_game); // Mettre a jour les valeurs
        display(my_game);
    }
}
