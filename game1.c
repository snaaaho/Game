#include "raylib.h"

// time off korte 38, 78-82, 109, 122 line comment korte hbe

typedef struct{
    int x;
    int y;
    int speed;
} Enemy;

int main(){
    InitWindow(2048, 1024, "First Game by Snaho");
    SetTargetFPS(60);

    int CenterX = 1024;
    int CenterY = 512;

    int coinX;
    int coinY;

    coinX = GetRandomValue(50, 1998);
    coinY = GetRandomValue(50, 1024 - 50);

    // int enemyX = 450;
    // int enemyY = 600;
    // int enemySpeedX = 12;
    bool gameover = false;

    int score = 0;

    Enemy enemy[4] = {
        {512, 20, 4},
        {1536, 1004, -4},
        {20, 256, 4},
        {2028, 768, -4}
    };

    float timer = 60.0f;

    while(!WindowShouldClose()){
        if(!gameover){
            if(IsKeyDown(KEY_RIGHT)) CenterX += 5;
            if(IsKeyDown(KEY_LEFT)) CenterX -= 5;
            if(IsKeyDown(KEY_DOWN)) CenterY += 5;
            if(IsKeyDown(KEY_UP)) CenterY -= 5;

            if(CenterX - 30 < 0) CenterX = 30;
            if(CenterX + 30 > 2048) CenterX = 2048 - 30;
            if(CenterY - 30 < 0) CenterY = 30;
            if(CenterY + 30 > 1024) CenterY = 1024 - 30;

            // enemyX += enemySpeedX;
            for(int i = 0; i < 4; i++){
                if(i < 2) enemy[i].y += enemy[i].speed;
                else enemy[i].x += enemy[i].speed;

                if((enemy[i].x + 20 > 2048) || (enemy[i].x - 20 < 0) || (enemy[i].y + 20 > 1024) || (enemy[i].y - 20 < 0)) enemy[i].speed = -enemy[i].speed;
            }
            // if((enemyX + 20 > 2048) || (enemyX - 20 < 0)) enemySpeedX = -enemySpeedX;

            if(CheckCollisionCircles((Vector2){CenterX, CenterY}, 30, (Vector2){coinX, coinY}, 15)){
                score += 10;
                coinX = GetRandomValue(50, 1998);
                coinY = GetRandomValue(50, 1024 - 50);
                //enemySpeedX += 4;
                for(int i = 0; i < 4; i++){
                    if(enemy[i].speed > 0) enemy[i].speed += 2;
                    else enemy[i].speed -= 2;
                }
            }

            for(int i = 0; i < 4; i++){
                if(CheckCollisionCircles((Vector2){CenterX, CenterY}, 30, (Vector2){enemy[i].x, enemy[i].y}, 20)){
                gameover = true;
                }
            }

            timer -= GetFrameTime();
            if(timer <= 0){
                timer = 0;
                gameover = true;
            }
        }
        else{
            if(IsKeyPressed(KEY_R)){
                CenterX = 1024;
                CenterY = 512;

                score = 0;

                gameover = false;

                for(int i = 0; i < 4; i++){
                    if((i % 2 == 0)) enemy[i].speed = 4;
                    else enemy[i].speed = -4;
                }
                enemy[0].x = 512;
                enemy[0].y = 20;
                enemy[1].x = 1536;
                enemy[1].y = 1004;
                enemy[2].x = 20;
                enemy[2].y = 256;
                enemy[3].x = 2028;
                enemy[3].y = 768;

                coinX = GetRandomValue(50, 1998);
                coinY = GetRandomValue(50, 1024 - 50);

                timer = 60.0f;
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            if(!gameover){
                DrawText(TextFormat("Score: %d", score), 20, 20, 25, BLACK);
                DrawCircle(CenterX, CenterY, 30, GREEN);
                DrawCircle(coinX, coinY, 15, GOLD);
                for(int i = 0; i < 4; i++){
                    DrawCircle(enemy[i].x, enemy[i].y, 20, RED);
                }
                DrawText(TextFormat("Time: %.1f", timer), 1800, 20, 25, RED);
            }
            else{
                DrawText(TextFormat("Your score: %d", score), 840, 400, 30, BLUE);
                DrawText("GAME OVER!!!", 840, 500, 50, RED);
                DrawText("Press R to restart :)", 840, 600, 20, DARKGRAY);
                DrawText("Snaho :)", 1700, 900, 20, BLACK);
            }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}