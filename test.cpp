#include <cstdio>
#include <cmath>
#include "raylib.h"

int main()
{
    int windowWidth = 800;
    int windowHeight = 500;

    // printf("Hello there");
    InitWindow(windowWidth, windowHeight, "Axe Game");

    int circleX{100};
    int circleY{100};
    int circleRadius{25};
    int circleSpeed{5};

    int axeX{500};
    int axeY{300};
    int axeLength{40};
    Vector2 axeVelocity{};
    int axeMaxSpeed{5};
    float axeAcceleration{0.2};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLUE);
        if (IsKeyDown(KEY_D) && (circleX + circleRadius < windowWidth))
        {
            circleX += circleSpeed;
        }
        if (IsKeyDown(KEY_A) && (circleX + circleRadius > 0))
        {
            circleX -= circleSpeed;
        }
        if (IsKeyDown(KEY_S) && (circleY + circleRadius < windowHeight))
        {
            circleY += circleSpeed;
        }
        if (IsKeyDown(KEY_W) && (circleY + circleRadius > 0))
        {
            circleY -= circleSpeed;
        }
        DrawCircle(circleX, circleY, circleRadius, RED);

        Vector2 desiredAxeDirection{circleX - axeX, circleY - axeY};
        float directionMagnitude{sqrt(pow(desiredAxeDirection.x, 2) + pow(desiredAxeDirection.y, 2))};
        Vector2 normalisedAxeDirection{desiredAxeDirection.x / directionMagnitude, desiredAxeDirection.y / directionMagnitude};
        Vector2 acceleratedAxeDirection{normalisedAxeDirection.x * axeAcceleration, normalisedAxeDirection.y * axeAcceleration};
        Vector2 temp{acceleratedAxeDirection.x + axeVelocity.x, acceleratedAxeDirection.y + axeVelocity.y};
        if (sqrt(pow(temp.x, 2) + pow(temp.y, 2)) < axeMaxSpeed)
        {
            axeVelocity = temp;
        }

        axeX += axeVelocity.x;
        axeY += axeVelocity.y;

        DrawRectangle(axeX, axeY, axeLength, axeLength, GREEN);

        if (directionMagnitude < (circleRadius + axeLength / 2))
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }

        EndDrawing();
    }
}