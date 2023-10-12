// #include <cstdio>
// #include <cmath>
// #include "raylib.h"

// int main()
// {
//     int windowWidth = 800;
//     int windowHeight = 500;

//     // printf("Hello there");
//     InitWindow(windowWidth, windowHeight, "Axe Game");

//     int circleX{100};
//     int circleY{100};
//     int circleRadius{25};
//     int circleSpeed{5};

//     int axeX{500};
//     int axeY{300};
//     int axeLength{40};
//     Vector2 axeVelocity{};
//     int axeMaxSpeed{5};
//     float axeAcceleration{0.2};

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(BLUE);
//         if (IsKeyDown(KEY_D) && (circleX + circleRadius < windowWidth))
//         {
//             circleX += circleSpeed;
//         }
//         if (IsKeyDown(KEY_A) && (circleX + circleRadius > 0))
//         {
//             circleX -= circleSpeed;
//         }
//         if (IsKeyDown(KEY_S) && (circleY + circleRadius < windowHeight))
//         {
//             circleY += circleSpeed;
//         }
//         if (IsKeyDown(KEY_W) && (circleY + circleRadius > 0))
//         {
//             circleY -= circleSpeed;
//         }
//         DrawCircle(circleX, circleY, circleRadius, RED);

//         Vector2 desiredAxeDirection{circleX - axeX, circleY - axeY};
//         float directionMagnitude{sqrt(pow(desiredAxeDirection.x, 2) + pow(desiredAxeDirection.y, 2))};
//         Vector2 normalisedAxeDirection{desiredAxeDirection.x / directionMagnitude, desiredAxeDirection.y / directionMagnitude};
//         Vector2 acceleratedAxeDirection{normalisedAxeDirection.x * axeAcceleration, normalisedAxeDirection.y * axeAcceleration};
//         Vector2 temp{acceleratedAxeDirection.x + axeVelocity.x, acceleratedAxeDirection.y + axeVelocity.y};
//         if (sqrt(pow(temp.x, 2) + pow(temp.y, 2)) < axeMaxSpeed)
//         {
//             axeVelocity = temp;
//         }

//         axeX += axeVelocity.x;
//         axeY += axeVelocity.y;

//         DrawRectangle(axeX, axeY, axeLength, axeLength, GREEN);

//         if (directionMagnitude < (circleRadius + axeLength / 2))
//         {
//             DrawText("Game Over!", 400, 200, 20, RED);
//         }

//         EndDrawing();
//     }
// }

#include "raylib.h"

int main()
{
    const int windowWidth{800};
    const int windowHeight{400};
    InitWindow(windowWidth, windowHeight, "Runner Game");

    Texture2D nebulaTex = LoadTexture("textures/12_nebula_spritesheet.png");
    Rectangle nebulaRect{0.0, 0.0, nebulaTex.width / 8, nebulaTex.height / 8};
    Vector2 nebulaPos{windowWidth, windowHeight - nebulaRect.height};
    int nebulaVelocity(-200);

    Texture2D characterTexture = LoadTexture("textures/scarfy.png");
    Rectangle characterRect;
    characterRect.width = characterTexture.width / 6;
    characterRect.height = characterTexture.height;
    characterRect.x = 0;
    characterRect.y = 0;

    Vector2 characterPos;
    characterPos.x = windowWidth / 2 - characterRect.width / 2;
    characterPos.y = windowHeight - characterRect.height;

    const int gravity = 1000;
    const int jumpVelocity = -750;

    const float animUpdateTime = 0.1;
    float animTimeTracker{0};
    int frame{0};

    const float nebulaUpdateTime{1.0 / 12.0};
    float nebulaRunningTime{0};
    int nebulaFrame{0};

    // int posY{windowHeight - rectHeight};
    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        float deltaTime = GetFrameTime();

        if (characterPos.y >= windowHeight - characterRect.height)
        {
            velocity = 0;
            animTimeTracker += deltaTime;
            if (IsKeyDown(KEY_SPACE))
            {
                velocity = jumpVelocity;
            }
        }
        else
        {
            velocity += gravity * deltaTime;
        }

        nebulaPos.x += nebulaVelocity * deltaTime;

        characterPos.y += velocity * deltaTime;

        if (animTimeTracker > animUpdateTime)
        {
            characterRect.x = frame * characterRect.width;
            frame++;
            if (frame > 5)
            {
                frame = 0;
            }

            animTimeTracker = 0.0;
        }

        nebulaRunningTime += deltaTime;
        if (nebulaRunningTime > nebulaUpdateTime)
        {
            nebulaRect.x = nebulaFrame * nebulaRect.width;
            nebulaFrame++;
            if (nebulaFrame > 7)
            {
                nebulaFrame = 0;
            }

            nebulaRunningTime = 0.0;
        }

        DrawTextureRec(nebulaTex, nebulaRect, nebulaPos, WHITE);

        DrawTextureRec(characterTexture, characterRect, characterPos, WHITE);

        EndDrawing();
    }
    UnloadTexture(characterTexture);
    UnloadTexture(nebulaTex);
    CloseWindow();
}