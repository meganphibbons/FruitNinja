#include <allegro.h>
#include <iostream>

using namespace std;

void init();
void deinit();

int main()
{
    init();

    BITMAP *game = create_bitmap(SCREEN_W, SCREEN_H);
    BITMAP *fruitOne = load_bitmap("wholeApple.bmp", NULL);
    BITMAP *fruitTwo = load_bitmap("wholeApple.bmp", NULL);
    BITMAP *fruitThree = load_bitmap("wholeApple.bmp", NULL);
    BITMAP *bomb = load_bitmap("wholeBomb.bmp", NULL);
    BITMAP *background = load_bitmap("background.bmp", NULL);
    BITMAP *knife = load_bitmap("Knife.bmp", NULL);

    enum fruitTypes
    {
        APPLE = 0, ORANGE, BANANA, LEMON, WATERMELON, PINEAPPLE, STRAWBERRY, PEAR
    };

    int score = 0;
    int lives = 3;
    int oldLives = lives;

    double bombX = -10;
    double bombY = SCREEN_H + 5;
    double deltaBombX = 5;
    double deltaBombY = -10;
    bool bombHit = false;
    bool bombOut = false;
    int bombChance = 5;

    int scoreOne = 0;
    int oldScoreOne = scoreOne;
    int fruitOneType = 0;
    double fruitOneX = -10;
    double fruitOneY = SCREEN_H + 5;
    double deltaOneX = 5;
    double deltaOneY = -10;
    bool fruitOneHit = false;
    bool fruitOneOut = false;

    int scoreTwo = 0;
    int oldScoreTwo = scoreTwo;
    int fruitTwoType = 0;
    double fruitTwoX = -10;
    double fruitTwoY = SCREEN_H + 5;
    double deltaTwoX = 3;
    double deltaTwoY = -10;
    bool fruitTwoHit = false;
    bool fruitTwoOut = false;

    int scoreThree = 0;
    int oldScoreThree = scoreThree;
    int fruitThreeType = 0;
    double fruitThreeX = -10;
    double fruitThreeY = SCREEN_H + 5;
    double deltaThreeX = 1;
    double deltaThreeY = -10;
    bool fruitThreeHit = false;
    bool fruitThreeOut = false;

    while(!key[KEY_SPACE])
    {
        draw_sprite(game, background, 0, 0);
        textprintf_centre_ex(game, font, SCREEN_W / 2, SCREEN_H / 2 - 10, makecol(0, 0, 0), -1, "Welcome to Fruit Ninja! Cut the fruits and avoid the bombs to try and beat");
        textprintf_centre_ex(game, font, SCREEN_W / 2, SCREEN_H / 2 + 10, makecol(0, 0, 0), -1, "your high score! Good luck! Please press the space bar to begin.");
        blit(game, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }

    while(!key[KEY_ESC] && lives > 0)
    {
        draw_sprite(game, background, 0, 0);
        if(!fruitOneOut)
        {
            oldScoreOne = scoreOne;
            destroy_bitmap(fruitOne);
            fruitOneType = rand() % 7;
            if(fruitOneType == APPLE)
                fruitOne = load_bitmap("wholeApple.bmp", NULL);
            else if(fruitOneType == ORANGE)
                fruitOne = load_bitmap("wholeOrange.bmp", NULL);
            else if(fruitOneType == BANANA)
                fruitOne = load_bitmap("wholeBanana.bmp", NULL);
            else if(fruitOneType == LEMON)
                fruitOne = load_bitmap("wholeLemon.bmp", NULL);
            else if(fruitOneType == WATERMELON)
                fruitOne = load_bitmap("wholeMelon.bmp", NULL);
            else if(fruitOneType == STRAWBERRY)
                fruitOne = load_bitmap("wholeStrawberry.bmp", NULL);
            else
                fruitOne = load_bitmap("wholePear.bmp", NULL);
            fruitOneX = (rand() * rand()) % SCREEN_W;
            fruitOneY = SCREEN_H + 5;
            deltaOneX = 5;
            deltaOneY = -10;
            if(fruitOneX > SCREEN_W / 2)
                deltaOneX = -5;
            fruitOneOut = true;
        }
        if(fruitOneHit)
        {
            if(oldScoreOne == scoreOne)
                scoreOne++;
            destroy_bitmap(fruitOne);
            if(fruitOneType == APPLE)
                fruitOne = load_bitmap("halfApple.bmp", NULL);
            else if(fruitOneType == ORANGE)
                fruitOne = load_bitmap("halfOrange.bmp", NULL);
            else if(fruitOneType == BANANA)
                fruitOne = load_bitmap("halfBanana.bmp", NULL);
            else if(fruitOneType == LEMON)
                fruitOne = load_bitmap("halfLemon.bmp", NULL);
            else if(fruitOneType == WATERMELON)
                fruitOne = load_bitmap("halfMelon.bmp", NULL);
            else if(fruitOneType == STRAWBERRY)
                fruitOne = load_bitmap("halfStrawberry.bmp", NULL);
            else
                fruitOne = load_bitmap("halfPear.bmp", NULL);
            fruitOneHit = false;
        }
        fruitOneX += deltaOneX;
        fruitOneY += deltaOneY;
        deltaOneY += .125;
        draw_sprite(game, fruitOne, fruitOneX, fruitOneY);
        if(fruitOneX < mouse_x + 20 && fruitOneX > mouse_x - 20 && fruitOneY > mouse_y - 20 && fruitOneY < mouse_y + 20)
            fruitOneHit = true;
        if(fruitOneX <= - 10 || fruitOneX >= SCREEN_W + 10 || fruitOneY <= -10 || fruitOneY >= SCREEN_H + 10)
            fruitOneOut = false;
        if(!fruitTwoOut)
        {
            oldScoreTwo = scoreTwo;
            destroy_bitmap(fruitTwo);
            fruitTwoType = rand() % 7;
            if(fruitTwoType == APPLE)
                fruitTwo = load_bitmap("wholeApple.bmp", NULL);
            else if(fruitTwoType == ORANGE)
                fruitTwo = load_bitmap("wholeOrange.bmp", NULL);
            else if(fruitTwoType == BANANA)
                fruitTwo = load_bitmap("wholeBanana.bmp", NULL);
            else if(fruitTwoType == LEMON)
                fruitTwo = load_bitmap("wholeLemon.bmp", NULL);
            else if(fruitTwoType == WATERMELON)
                fruitTwo = load_bitmap("wholeMelon.bmp", NULL);
            else if(fruitTwoType == STRAWBERRY)
                fruitTwo = load_bitmap("wholeStrawberry.bmp", NULL);
            else
                fruitTwo = load_bitmap("wholePear.bmp", NULL);
            fruitTwoX = (rand() * rand()) % SCREEN_W;
            fruitTwoY = SCREEN_H + 5;
            deltaTwoX = 3;
            deltaTwoY = -10;
            if(fruitTwoX > SCREEN_W / 2)
                deltaTwoX = -3;
            fruitTwoOut = true;
        }
        if(fruitTwoHit)
        {
            if(oldScoreTwo == scoreTwo)
                scoreTwo++;
            destroy_bitmap(fruitTwo);
            if(fruitTwoType == APPLE)
                fruitTwo = load_bitmap("halfApple.bmp", NULL);
            else if(fruitTwoType == ORANGE)
                fruitTwo = load_bitmap("halfOrange.bmp", NULL);
            else if(fruitTwoType == BANANA)
                fruitTwo = load_bitmap("halfBanana.bmp", NULL);
            else if(fruitTwoType == LEMON)
                fruitTwo = load_bitmap("halfLemon.bmp", NULL);
            else if(fruitTwoType == WATERMELON)
                fruitTwo = load_bitmap("halfMelon.bmp", NULL);
            else if(fruitTwoType == STRAWBERRY)
                fruitTwo = load_bitmap("halfStrawberry.bmp", NULL);
            else
                fruitTwo = load_bitmap("halfPear.bmp", NULL);
            fruitTwoHit = false;
        }
        fruitTwoX += deltaTwoX;
        fruitTwoY += deltaTwoY;
        deltaTwoY += .125;
        draw_sprite(game, fruitTwo, fruitTwoX, fruitTwoY);
        if(fruitTwoX < mouse_x + 20 && fruitTwoX > mouse_x - 20 && fruitTwoY > mouse_y - 20 && fruitTwoY < mouse_y + 20)
            fruitTwoHit = true;
        if(fruitTwoX <= - 10 || fruitTwoX >= SCREEN_W + 10 || fruitTwoY <= -10 || fruitTwoY >= SCREEN_H + 10)
            fruitTwoOut = false;
        if(!fruitThreeOut)
        {
            oldScoreThree = scoreThree;
            destroy_bitmap(fruitThree);
            fruitThreeType = rand() % 7;
            if(fruitThreeType == APPLE)
                fruitThree = load_bitmap("wholeApple.bmp", NULL);
            else if(fruitThreeType == ORANGE)
                fruitThree = load_bitmap("wholeOrange.bmp", NULL);
            else if(fruitThreeType == BANANA)
                fruitThree = load_bitmap("wholeBanana.bmp", NULL);
            else if(fruitThreeType == LEMON)
                fruitThree = load_bitmap("wholeLemon.bmp", NULL);
            else if(fruitThreeType == WATERMELON)
                fruitThree = load_bitmap("wholeMelon.bmp", NULL);
            else if(fruitThreeType == STRAWBERRY)
                fruitThree = load_bitmap("wholeStrawberry.bmp", NULL);
            else
                fruitThree = load_bitmap("wholePear.bmp", NULL);
            fruitThreeX = (rand() * rand()) % SCREEN_W;
            fruitThreeY = SCREEN_H + 5;
            deltaThreeX = 1;
            deltaThreeY = -10;
            if(fruitThreeX > SCREEN_W / 2)
                deltaThreeX = -1;
            fruitThreeOut = true;
        }
        if(fruitThreeHit)
        {
            if(oldScoreThree == scoreThree)
                scoreThree++;
            destroy_bitmap(fruitThree);
            if(fruitThreeType == APPLE)
                fruitThree = load_bitmap("halfApple.bmp", NULL);
            else if(fruitThreeType == ORANGE)
                fruitThree = load_bitmap("halfOrange.bmp", NULL);
            else if(fruitThreeType == BANANA)
                fruitThree = load_bitmap("halfBanana.bmp", NULL);
            else if(fruitThreeType == LEMON)
                fruitThree = load_bitmap("halfLemon.bmp", NULL);
            else if(fruitThreeType == WATERMELON)
                fruitThree = load_bitmap("halfMelon.bmp", NULL);
            else if(fruitThreeType == STRAWBERRY)
                fruitThree = load_bitmap("halfStrawberry.bmp", NULL);
            else
                fruitThree = load_bitmap("halfPear.bmp", NULL);
            fruitThreeHit = false;
        }
        fruitThreeX += deltaThreeX;
        fruitThreeY += deltaThreeY;
        deltaThreeY += .125;
        draw_sprite(game, fruitThree, fruitThreeX, fruitThreeY);
        if(fruitThreeX < mouse_x + 20 && fruitThreeX > mouse_x - 20 && fruitThreeY > mouse_y - 20 && fruitThreeY < mouse_y + 20)
            fruitThreeHit = true;
        if(fruitThreeX <= - 10 || fruitThreeX >= SCREEN_W + 10 || fruitThreeY <= -10 || fruitThreeY >= SCREEN_H + 10)
            fruitThreeOut = false;
        if(!bombOut)
            bombChance = rand() % 300;
        if(bombChance == 0 && !bombOut)
        {
            oldLives = lives;
            destroy_bitmap(bomb);
            bomb = load_bitmap("wholeBomb.bmp", NULL);
            bombX = (rand() * rand()) % SCREEN_W;
            bombY = SCREEN_H + 5;
            deltaBombX = 3;
            deltaBombY = -10;
            if(bombX > SCREEN_W / 2)
                deltaBombX = -3;
            bombOut = true;
        }
        if(bombOut)
        {
            bombX += deltaBombX;
            bombY += deltaBombY;
            deltaBombY += .125;
            draw_sprite(game, bomb, bombX, bombY);
            if(bombX < mouse_x + 20 && bombX > mouse_x - 20 && bombY > mouse_y - 20 && bombY < mouse_y + 20)
                bombHit = true;
            if(bombX <= - 10 || bombX >= SCREEN_W + 10 || bombY <= -10 || bombY >= SCREEN_H + 10)
                bombOut = false;
        }
        if(bombHit)
        {
            if(oldLives == lives)
                lives--;
            destroy_bitmap(bomb);
            bomb = load_bitmap("halfBomb.bmp", NULL);
            bombHit = false;
        }
        draw_sprite(game, knife, mouse_x, mouse_y);
        rest(1);
        score = scoreOne + scoreTwo + scoreThree;
        textprintf_centre_ex(game, font, SCREEN_W / 2, 10, makecol(0, 0, 0), -1, "Points: %d        Lives: %d", score, lives);
        blit(game, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    while(!key[KEY_ESC])
    {
        draw_sprite(game, background, 0, 0);
        textprintf_centre_ex(game, font, SCREEN_W / 2, SCREEN_H / 2 - 10, makecol(0, 0, 0), -1, "You ran out of lives! Score: %d", score);
        blit(game, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    deinit();
    return 0;
}
END_OF_MAIN()

void init()
{
    srand(time(0));
    int depth, res;
    allegro_init();
    depth = desktop_color_depth();
    if(depth == 0)
        depth = 32;
    set_color_depth(depth);
    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    if(res != 0)
    {
        allegro_message(allegro_error);
        exit(-1);
    }
    install_timer();
    install_keyboard();
    install_mouse();
}

void deinit()
{
    clear_keybuf();
}
