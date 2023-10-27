// GAME 1 : SIMPLE MOVE + TRACKING ENEMY

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

// GAME 2 : SIMPLE RUNNNER
// #include "raylib.h"

// struct AnimData
// {
//     Rectangle rect;
//     Vector2 pos;
//     int frame;
//     float updateTime;
//     float runningTime;
// };

// int main()
// {
//     const int windowWidth{800};
//     const int windowHeight{400};
//     InitWindow(windowWidth, windowHeight, "Runner Game");

//     Texture2D nebulaTex = LoadTexture("textures/12_nebula_spritesheet.png");

//     // AnimData nebulaData{
//     //     {0.0, 0.0, nebulaTex.width / 8.0, nebulaTex.height / 8.0},
//     //     {windowWidth, windowHeight - nebulaTex.height / 8.0},
//     //     0,
//     //     1.0 / 12.0,
//     //     0};

//     int nebulaNum = 5;

//     AnimData nebulae[nebulaNum]{};

//     for (int i = 0; i < nebulaNum; i++)
//     {
//         nebulae[i].rect = {0.0, 0.0, nebulaTex.width / (float)8, nebulaTex.height / (float)8};
//         nebulae[i].pos = {windowWidth + float(i * 300), windowHeight - nebulaTex.height / (float)8.0};
//         nebulae[i].frame = 0;
//         nebulae[i].runningTime = 0;
//         nebulae[i].updateTime = 1.0 / 16.0;
//     }

//     // Rectangle nebulaRect{0.0, 0.0, nebulaTex.width / 8, nebulaTex.height / 8};
//     // Vector2 nebulaPos{windowWidth, windowHeight - nebulaRect.height};
//     int nebulaVelocity(-200);

//     Texture2D characterTexture = LoadTexture("textures/scarfy.png");
//     AnimData characterData{{0.0, 0.0, characterTexture.width / 6.0, characterTexture.height}, {windowWidth / 2 - characterData.rect.width / 2, windowHeight - characterData.rect.height}, 0, 1.0 / 8.0, 0};
//     // Rectangle characterRect;
//     // characterRect.width = characterTexture.width / 6;
//     // characterRect.height = characterTexture.height;
//     // characterRect.x = 0;
//     // characterRect.y = 0;

//     // Vector2 characterPos;
//     // characterPos.x = windowWidth / 2 - characterRect.width / 2;
//     // characterPos.y = windowHeight - characterRect.height;

//     const int gravity = 1000;
//     const int jumpVelocity = -750;

//     // const float animUpdateTime = 0.1;
//     // float animTimeTracker{0};
//     // int frame{0};

//     // const float nebulaUpdateTime{1.0 / 12.0};
//     // float nebulaRunningTime{0};
//     // int nebulaFrame{0};

//     // int posY{windowHeight - rectHeight};
//     int velocity{0};

//     Texture2D background = LoadTexture("textures/far-buildings.png");
//     float bgX{};

//     SetTargetFPS(60);
//     while (!WindowShouldClose())
//     {
//         BeginDrawing();
//         ClearBackground(WHITE);

//         Vector2 bg1Pos{bgX, 0.0};
//         Vector2 bg2Pos{bgX + background.width * 2, 0.0};
//         DrawTextureEx(background, bg1Pos, 0.0, 2.0, WHITE);
//         DrawTextureEx(background, bg2Pos, 0.0, 2.0, WHITE);

//         float deltaTime = GetFrameTime();

//         bgX -= 20 * deltaTime;
//         if (bgX < -background.width * 2)
//         {
//             bgX = 0;
//         }

//         if (characterData.pos.y >= windowHeight - characterData.rect.height)
//         {
//             velocity = 0;
//             characterData.runningTime += deltaTime;
//             if (IsKeyDown(KEY_SPACE))
//             {
//                 velocity = jumpVelocity;
//             }
//         }
//         else
//         {
//             velocity += gravity * deltaTime;
//         }

//         for (int i = 0; i < nebulaNum; i++)
//         {
//             nebulae[i].pos.x += nebulaVelocity * deltaTime;
//         }

//         characterData.pos.y += velocity * deltaTime;

//         if (characterData.runningTime > characterData.updateTime)
//         {
//             characterData.rect.x = characterData.frame * characterData.rect.width;
//             characterData.frame++;
//             if (characterData.frame > 5)
//             {
//                 characterData.frame = 0;
//             }

//             characterData.runningTime = 0.0;
//         }

//         for (int i = 0; i < nebulaNum; i++)
//         {
//             nebulae[i].runningTime += deltaTime;
//             if (nebulae[i].runningTime > nebulae[i].updateTime)
//             {
//                 nebulae[i].rect.x = nebulae[i].frame * nebulae[i].rect.width;
//                 nebulae[i].frame++;
//                 if (nebulae[i].frame > 7)
//                 {
//                     nebulae[i].frame = 0;
//                 }

//                 nebulae[i].runningTime = 0.0;
//             }
//         }
//         for (int i = 0; i < nebulaNum; i++)
//         {
//             DrawTextureRec(nebulaTex, nebulae[i].rect, nebulae[i].pos, WHITE);
//         }

//         DrawTextureRec(characterTexture, characterData.rect, characterData.pos, WHITE);

//         EndDrawing();
//     }
//     UnloadTexture(characterTexture);
//     UnloadTexture(background);
//     UnloadTexture(nebulaTex);
//     CloseWindow();
// }
#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Stephen's Top Down");

    Texture2D map = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character knight{windowWidth, windowHeight};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);
        knight.tick(GetFrameTime());
        // check map bounds
        if (knight.getWorldPos().x < 0.f ||
            knight.getWorldPos().y < 0.f ||
            knight.getWorldPos().x + windowWidth > map.width * mapScale ||
            knight.getWorldPos().y + windowHeight > map.height * mapScale)
        {
            knight.undoMovement();
        }

        EndDrawing();
    }
    CloseWindow();
}