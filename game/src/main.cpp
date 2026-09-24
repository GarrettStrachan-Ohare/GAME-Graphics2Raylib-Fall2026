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
        // Class Lab
		float totalTime = GetTime();
        float frameTime =GetFrameTime();

        positionX += speed * frameTime;

        if (positionX > 650.0f || positionX < 150.0f)
        {
            speed = -speed;
        }

        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircleV(GetMousePosition(), 20.0f, RED);
        DrawCircleV(Vector2(positionX, positionY), 15.0f, RED);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
