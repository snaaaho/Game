#include "raylib.h"

//button change 37 & 41

int main(){
    InitWindow(1920, 1080, "PONG BY SNAHO");
    SetTargetFPS(60);

    int playerX = 0;
    int playerY = 490;
    // width = 3, height = 100;
    int playerSpeedY = 9;

    int aiX = 1917;
    int aiY = 490;
    // width = 3, height = 100;
    int aiSpeedY = 9;

    float ballX = 960.0f;
    float ballY = 540.0f;
    float ballSpeedX = -5.0f;
    float ballSpeedY = 0.0f;
    int ballRadius = 10;

    int playerScore = 0;
    int aiScore = 0;

    bool gameover = false;
    bool winner = false;

    while(!WindowShouldClose()){
        if((!gameover) && (!winner)){
            if(IsKeyPressed(KEY_Z)) ToggleFullscreen();

            if((ballY - ballRadius < 0) || (ballY + ballRadius > 1080)) ballSpeedY = -ballSpeedY;

            // Change Player 1 (Green) buttons:
            if(IsKeyDown(KEY_Q)) playerY -= playerSpeedY;   // Replace KEY_Q with KEY_W
            if(IsKeyDown(KEY_A)) playerY += playerSpeedY;   // Replace KEY_A with KEY_S

            // Change Player 2 (Red) buttons:
            if(IsKeyDown(KEY_K)) aiY -= aiSpeedY;   // Replace KEY_K with KEY_UP
            if(IsKeyDown(KEY_M)) aiY += aiSpeedY;   // Replace KEY_M with KEY_DOWN

            if(playerY < 0) playerY = 0;
            if(aiY < 0) aiY = 0;
            if(playerY > 980) playerY = 980;
            if(aiY > 980) aiY = 980;

            ballX = ballX + ballSpeedX;
            ballY = ballY + ballSpeedY;

            if(CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){playerX, playerY, 3, 100})){
                ballSpeedX = -ballSpeedX * 1.25f;
                if(ballSpeedX > 22.9f) ballSpeedX = 22.9f;
                if(ballSpeedX < -22.9f) ballSpeedX = -22.9f;

                float hitOffset = ballY - (playerY + 50);
                ballSpeedY = hitOffset * 0.1f;

                ballX = playerX + 3 + ballRadius;
            }   

            if(CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){aiX, aiY, 3, 100})){
                ballSpeedX = -ballSpeedX * 1.05f;

                float hitOffset = ballY - (aiY + 50);
                ballSpeedY = hitOffset * 0.1f;

                ballX = aiX - ballRadius;
            }

            if(ballX - ballRadius < 0){
                aiScore++;

                ballX = 960.0f;
                ballY = 540.0f;
                ballSpeedX = -5.0f;
                ballSpeedY = 0.0f;

                playerX = 0;
                playerY = 490;

                aiX = 1917;
                aiY = 490;
            }
            if(ballX + ballRadius > 1920){
                playerScore++;

                ballX = 960.0f;
                ballY = 540.0f;
                ballSpeedX = 5.0f;
                ballSpeedY = 0.0f;

                playerX = 0;
                playerY = 490;

                aiX = 1917;
                aiY = 490;
            }

            if(playerScore >= 5) winner = true;
            if(aiScore >= 5) gameover = true;
        }
        else{
            if(IsKeyPressed(KEY_R)){
                playerX = 0;
                playerY = 490;
                // width = 3, height = 100;
                playerSpeedY = 9;

                aiX = 1917;
                aiY = 490;
                // width = 3, height = 100;
                // int aiSpeedY = 9;

                ballX = 960.0f;
                ballY = 540.0f;
                ballSpeedX = -5.0f;
                ballSpeedY = 0.0f;
                ballRadius = 10;

                playerScore = 0;
                aiScore = 0;

                gameover = false;
                winner = false;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);
        if((!gameover) && (!winner)){
            DrawText(TextFormat("%d : %d", playerScore, aiScore), 940, 10, 35, PINK);
            DrawCircle(ballX, ballY, ballRadius, WHITE);
            DrawRectangle(playerX, playerY, 3, 100, GREEN);
            DrawRectangle(aiX, aiY, 3, 100, RED);
            DrawLine(959, 45, 962, 2000, WHITE);
        }
        else{
            if(gameover) DrawText("RED WINNER!!!", 850, 100, 50, RED);
            else DrawText("GREEN WINNER!!!", 850, 100, 50, GREEN);
            DrawText(TextFormat("%d : %d", playerScore, aiScore), 850, 170, 40, WHITE);
            DrawText("Press R to restart.", 850, 220, 30, LIGHTGRAY);
            DrawText("SNAHO :)", 850, 900, 35, YELLOW);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;    
}