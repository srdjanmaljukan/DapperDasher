#include "raylib.h"

int main()
{
    // Window dimensions
    const int windowWidth = 512;
    int windowHeight = 380;

    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // Acceleration due to gravity (pixels / frame) / frame
    const int gravity = 1;
    const int jumpVel = -22;
    bool isInAir = false;

    // Rectangle dimensions
    const int width = 50;
    const int height = 80;

    int posY = (windowHeight - height);
    int velocity = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        // Game Logic Starts Here

        // Ground check
        if (posY >= windowHeight - height)
        {
            // Rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // Rectangle is in the air
            // Apply gravity
            velocity += gravity;
            isInAir = true;
        }

        // Check for jumping
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // Update position
        posY += velocity;

        DrawRectangle(windowWidth / 2, posY, width, height, BLUE);

        // Game Logic Ends Here

        EndDrawing();
    }

    CloseWindow();
}