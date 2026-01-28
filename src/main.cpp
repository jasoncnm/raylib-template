#include "raylib.h"

#include "raymath.h"    // Required for: Lerp()

#define STAR_COUNT 420

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - starfield effect");

    Color bgColor = ColorLerp(DARKBLUE, BLACK, 0.69f);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    
     unsigned int press_count = 0, down_count = 0, release_count = 0, up_count = 0;
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        ClearBackground(bgColor);
        
        if (IsMouseButtonPressed(KEY_S))
        {
            press_count++;
        }
        
        if (IsMouseButtonDown(KEY_S))
        {
            down_count++;
        }
        
        if (IsMouseButtonReleased(KEY_S))
        {
            release_count++;
        }
        
        DrawCircleV(GetMousePosition(), 5, RED);
        
        DrawText(TextFormat("KeyCode: %d\nPressed %d times\nDowned %d times\nReleased %d times", 
                            KEY_S, press_count, down_count, release_count), GetScreenWidth() / 2, GetScreenHeight() / 2, 20, RAYWHITE);
        
            DrawFPS(10, 10);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
