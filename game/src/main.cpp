#include "raylib.h"
#include "raymath.h"
#include "raygui.h"


int main()
{
    InitWindow(800, 800, "Physics-1");
    InitAudioDevice();
    SetTargetFPS(60);

    float speed = 400.0f;
    float positionX = 150.0f;
    float positionY = 400.0f;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircleV(GetMousePosition(), 20.0f, RED);

		// Draw a circle that moves horizontally across the screen
        DrawCircleV(Vector2(positionX, positionY), 15.0f, RED);
		// Get frame time for move calculation
        float totalTime = GetTime();
        float frameTime = GetFrameTime();
		// Update the position of the circle based on speed and frame time
        positionX += speed * frameTime;
		// Reverse direction if the circle hits the set values
        if (positionX > 650.0f || positionX < 150.0f)
        {
            speed = -speed;
        }

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
