#include "raylib.h"
#include <math.h>

int main(){
    InitWindow(1920, 1080, "GLOW HOCKEY BY SNAHO");
    SetTargetFPS(60);

    int wallWidth = 5;

    int greenX = wallWidth;
    int greenY = 495;
    int greenSpeedX = 9;
    int greenSpeedY = 9;

    int redX = 1920 - wallWidth;
    int redY = 495;
    int redSpeedX = 9;
    int redSpeedY = 9;

    int playerWidth = 15;

    int ballRadius = 10;
    float ballX = GetRandomValue(480, 1440);
    float ballY = GetRandomValue(wallWidth + 1 + ballRadius, 1080 - wallWidth - 1 - ballRadius);
    float ballSpeedX = 0.0f;
    float ballSpeedY = 0.0f;

    int greenScore = 0;
    int redScore = 0;

    bool winnerGreen = false;
    bool winnerRed = false;

    while(!WindowShouldClose()){
        if((!winnerGreen) && (!winnerRed)){
            if(IsKeyDown(KEY_D)) greenX += greenSpeedX;
            if(IsKeyDown(KEY_A)) greenX -= greenSpeedX;
            if(IsKeyDown(KEY_S)) greenY += greenSpeedY;
            if(IsKeyDown(KEY_W)) greenY -= greenSpeedY;

            if(IsKeyDown(KEY_RIGHT)) redX += redSpeedX;
            if(IsKeyDown(KEY_LEFT)) redX -= redSpeedX;
            if(IsKeyDown(KEY_DOWN)) redY += redSpeedY;
            if(IsKeyDown(KEY_UP)) redY -= redSpeedY;

            if(greenY < wallWidth) greenY = wallWidth;
            if(redY < wallWidth) redY = wallWidth;
            if(greenY > 1080 - wallWidth - 90) greenY = 1080 - wallWidth - 90;
            if(redY > 1080 - wallWidth - 90) redY = 1080 - wallWidth - 90;

            if(greenX < wallWidth) greenX = wallWidth;
            if(greenX > 960 - playerWidth) greenX = 960 - playerWidth;
            if(redX > 1920 - wallWidth - playerWidth) redX = 1920 - wallWidth - playerWidth;
            if(redX < 960 + playerWidth) redX = 960 + playerWidth;

            float totalSpeed = hypotf(ballSpeedX, ballSpeedY);

            int steps = (int)(totalSpeed / 2.0f) + 1;
            float stepX = ballSpeedX / steps;
            float stepY = ballSpeedY / steps;

            for (int step = 0; step < steps; step++) {
                ballX += stepX;
                ballY += stepY;

                if (CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){greenX, greenY, playerWidth, 90})) {
                    float hitOffset = ballY - (greenY + 45);

                    if (ballX >= greenX + playerWidth / 2.0f) {
                        ballSpeedX = fabsf(ballSpeedX) + 1.0f;
                        if (ballSpeedX > 25.0f) ballSpeedX = 25.0f;
                        ballX = greenX + playerWidth + ballRadius + 1;
                    }
                    else {
                        ballSpeedX = -fabsf(ballSpeedX) - 1.0f;
                        if (ballSpeedX < -25.0f) ballSpeedX = -25.0f;
                        ballX = greenX - ballRadius - 1;
                    }   

                    ballSpeedY = hitOffset * 0.1f + greenSpeedY;
                    break;
                }
         
                if (CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){redX, redY, playerWidth, 90})) {
                    float hitOffset = ballY - (redY + 45);

                    if (ballX <= redX + playerWidth / 2.0f) {
                        ballSpeedX = -fabsf(ballSpeedX) - 1.0f;
                        if (ballSpeedX < -25.0f) ballSpeedX = -25.0f;
                        ballX = redX - ballRadius - 1;
                    }
                    else {
                        ballSpeedX = fabsf(ballSpeedX) + 1.0f;
                        if (ballSpeedX > 25.0f) ballSpeedX = 25.0f;
                        ballX = redX + playerWidth + ballRadius + 1;
                    }

                    ballSpeedY = hitOffset * 0.1f - redSpeedY;
                    break;
                }
            }

            if((CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){0, 0, wallWidth, 540 - 135})) || (CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){0, 540 + 135, wallWidth, 540 - 135}))){
                if(ballSpeedX < 0.0f) ballSpeedX = -ballSpeedX;
                ballX = wallWidth + ballRadius + 1;
            }

            if((CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){1920 - wallWidth, 0, wallWidth, 540 - 135})) || (CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){1920 - wallWidth, 540 + 135, wallWidth, 540 - 135}))){
                if(ballSpeedX > 0.0f) ballSpeedX = -ballSpeedX;
                ballX = 1920 - wallWidth - ballRadius - 1;
            }
            
            if((CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){0, 0, 1920, wallWidth})) || (CheckCollisionCircleRec((Vector2){ballX, ballY}, ballRadius, (Rectangle){0, 1080 - wallWidth, 1920, wallWidth}))){
                ballSpeedY = -ballSpeedY;
            }

            if(ballX - ballRadius < 0){
                if(((540 - 135) < ballY) && (ballY < (540 + 135))){
                    redScore++;

                    ballX = GetRandomValue(480, 960 - ballRadius);
                    ballY = GetRandomValue(wallWidth + 1 + ballRadius, 1080 - wallWidth - 1 - ballRadius);
                    ballSpeedX = 0.0f;
                    ballSpeedY = 0.0f;

                    greenX = wallWidth;
                    greenY = 495;

                    redX = 1920 - wallWidth;
                    redY = 495;
                }
            }

            if(ballX + ballRadius > 1920){
                if(((540 - 135) < ballY) && (ballY < (540 + 135))){
                    greenScore++;

                    ballX = GetRandomValue(960 + ballRadius, 1440);
                    ballY = GetRandomValue(wallWidth + 1 + ballRadius, 1080 - wallWidth - 1 - ballRadius);
                    ballSpeedX = 0.0f;
                    ballSpeedY = 0.0f;

                    greenX = wallWidth;
                    greenY = 495;

                    redX = 1920 - wallWidth;
                    redY = 495;
                }
            }

            if(greenScore >= 5) winnerGreen = true;
            if(redScore >= 5) winnerRed = true;
        }
        else{
            if(IsKeyPressed(KEY_R)){
                 wallWidth = 5;

                greenX = wallWidth;
                greenY = 495;
                greenSpeedX = 9;
                greenSpeedY = 9;

                redX = 1920 - wallWidth;
                redY = 495;
                redSpeedX = 9;
                redSpeedY = 9;

                playerWidth = 15;

                ballX = GetRandomValue(480, 1440);
                ballY = GetRandomValue(wallWidth + 1 + ballRadius, 1080 - wallWidth - 1 - ballRadius);
                ballSpeedX = 0.0f;
                ballSpeedY = 0.0f;
                ballRadius = 10;

                greenScore = 0;
                redScore = 0;

                winnerGreen = false;
                winnerRed = false;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);
        if((!winnerGreen) && (!winnerRed)){
            DrawText(TextFormat("%d : %d", greenScore, redScore), 940, 15, 35, WHITE);
            DrawCircle(ballX, ballY, ballRadius, WHITE);
            DrawRectangle(greenX, greenY, playerWidth, 90, GREEN);
            DrawRectangle(redX, redY, playerWidth, 90, RED);
            DrawLine(959, 45, 962, 2000, WHITE);
            DrawRectangle(0, 0, wallWidth, 540 - 135, PINK);
            DrawRectangle(0, 540 + 135, wallWidth, 540 - 135, PINK);
            DrawRectangle(1920 - wallWidth, 0, wallWidth, 540 - 135, PINK);
            DrawRectangle(1920 - wallWidth, 540 + 135, wallWidth, 540 - 135, PINK);
            DrawRectangle(0, 0, 1920, wallWidth, PINK);
            DrawRectangle(0, 1080 - wallWidth, 1920, wallWidth, PINK);
        }
        else{
            if(winnerRed) DrawText("RED WINNER!!!", 850, 100, 50, RED);
            else DrawText("GREEN WINNER!!!", 850, 100, 50, GREEN);
            DrawText(TextFormat("%d : %d", greenScore, redScore), 850, 170, 40, WHITE);
            DrawText("Press R to restart.", 850, 220, 30, LIGHTGRAY);
            DrawText("SNAHO :)", 850, 900, 35, YELLOW);
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}