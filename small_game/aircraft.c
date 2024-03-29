#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "my_tools.h"

void init();
void show();
void update_with_input();
void update_without_input();

int height, width;
int plane_x, plane_y;
int bullet_x, bullet_y;
int target_x, target_y;
int score;

int main(void)
{
    init();
    while (1)
    {
        show();
        update_with_input();
        update_without_input();
    }
    return 0;
}

void init()
{
    srand(time(NULL));
    width = 40;
    height = 20;
    plane_x = width / 2;
    plane_y = height / 2;
    bullet_x = plane_x;
    bullet_y = -1;
    target_x = width / 2;
    target_y = 0;
    score = 0;
    hide_cursor();
    for (int i = 0; i <= height; ++i)
    {
        for (int j = 0; j <= width; ++j)
        {
            putchar((i == height) || (j == width) ? '+' : ' ');
        }
        printf("\n");
    }
    printf("Move: W S A D; Fire: SPACE\n");
}

void show()
{
    move_cursor(0, 0);
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if ((i == plane_y) && (j == plane_x))
            {
                printf("*");
            }
            else if ((i == bullet_y) && (j == bullet_x))
            {
                printf("|");
            }
            else if ((i == target_y) && (j == target_x))
            {
                printf("@");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n\nScore: %d", score);
}

void update_with_input()
{
    char input;

    if (kbhit())
    {
        input = getch();

        if (plane_y != 0 && (input == 'w' || input == 'W'))
        {
            plane_y--;
        }
        if (plane_y != height - 1 && (input == 's' || input == 'S'))
        {
            plane_y++;
        }
        if (plane_x != 0 && (input == 'a' || input == 'A'))
        {
            plane_x--;
        }
        if (plane_x != width - 1 && (input == 'd' || input == 'D'))
        {
            plane_x++;
        }
        if (input == ' ')
        {
            bullet_y = plane_y;
            bullet_x = plane_x;
        }
    }
}

void update_without_input()
{
    if ((bullet_x == target_x) && (bullet_y == target_y))
    {
        printf("\a");
        score++;
        target_y = 0;
        target_x = rand() % width;
        bullet_y = -1;
    }

    if ((plane_x == target_x) && (plane_y == target_y))
    {
        printf("\n>_<\npress ENTER to exit...");
        getchar();
        exit(EXIT_SUCCESS);
    }

    static int speed = 0;
    if (speed < 20 - score)
    {
        speed++;
    }

    if (target_y > height)
    {
        target_y = 0;
        target_x = rand() % width;
    }
    else if (speed >= 20 - score)
    {
        target_y++;
        speed = 0;
    }

    if (bullet_y > -1)
    {
        bullet_y--;
    }
}
