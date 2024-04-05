#include "raylib.h"

int main()
{
    // Window dimensions
    const int windowWidth = 512;
    int windowHeight = 380;

    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    // Acceleration due to gravity (pixels / s) / s
    const int gravity = 1000;

    // Scarfy dimensions and position
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width / 6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth / 2 - scarfyRec.width / 2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    // Animation frame
    int frame = 0;

    // Amount of time before we update animation frame
    const float updateTime = 1.0 / 12.0;
    float runningTime = 0;

    // Jump velocity (pixels / second)
    const int jumpVel = -600;

    // Is Scarfy in the air?
    bool isInAir = false;

    // Scarfy velocity
    int velocity = 0;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        // Game Logic Starts Here

        // Delta time
        float dT = GetFrameTime();

        // Ground check
        if (scarfyPos.y >= windowHeight - scarfyRec.height)
        {
            // Rectangle is on the ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            // Rectangle is in the air
            // Apply gravity
            velocity += gravity * dT;
            isInAir = true;
        }

        // Check for jumping
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += jumpVel;
        }

        // Update position
        scarfyPos.y += velocity * dT;

        runningTime += dT;

        if (runningTime >= updateTime)
        {
            runningTime = 0;
            // Update animation frame
            scarfyRec.x = frame * scarfyRec.width;
            frame++;
            if (frame > 5)
            {
                frame = 0;
            }
        }

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        // Game Logic Ends Here

        EndDrawing();
    }

    UnloadTexture(scarfy);
    CloseWindow();
}