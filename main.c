#include "raylib.h"
#include "raymath.h"
#include "string.h"
#include "stdlib.h"
#include <time.h>

typedef enum {
    STATE_EXPLORING,
    STATE_DESK_MENU,    
    STATE_INVENTORY_MENU,
    STATE_DOSSIE,
    STATE_HACK,
    STATE_CLIFFHANGER
} GameState;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    SetRandomSeed((unsigned int)time(NULL));
    int selectedWord = 0;
    int attempts = 3;
    int CorrectWordIndex = GetRandomValue(0, 3);

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
   
    InitWindow(screenWidth, screenHeight, "Menu Noir - Persona Style");
    InitAudioDevice();
 Texture2D walltexture = LoadTexture("_.jpeg");
    Texture2D groundtexture = LoadTexture("_ (1).jpeg");
    Texture2D background = LoadTexture("242c274b33b23eaebf7c8b6d559730ae.jpg");

    
    Mesh meshground = GenMeshPlane(16.0f, 16.0f, 1, 1);
    Model modelground = LoadModelFromMesh(meshground);
    modelground.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = groundtexture;

   Mesh meshwall = GenMeshPlane(16.0f, 6.0f, 1, 1);
    Model modelwall = LoadModelFromMesh(meshwall);
    modelwall.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = walltexture;
    modelwall.transform = MatrixRotateX( 90.0f * DEG2RAD );
  


    Music music = LoadMusicStream("alex-morgan-jazz-rainy-night-music-556239.mp3");

    Vector3 position = { 0.0f, 0.0f, 2.0f };

    Vector3 deskPosition = { 2.5f, 0.0f, -0.5f }; 
    Vector3 deskscale = { 0.01f, 0.01f, 0.01f };
    float deskRotation = 0.0f;
    
    // Position where the player stands to interact with the PC
    Vector3 positionintterminal = {2.5f, 0.0f, 0.8f };
    // Visual position of the monitor on top of the desk
    Vector3 positionterminal = { 4.0f, 0.75f, -0.8f };
    Vector3 pcscale = { 0.25f, 0.25f, 0.25f }; 
    float terminalRotation = -90.0f;

    float rotationAngle = 90.0f;

    Model model = LoadModel("human_male.glb");
    Model deskmodel = LoadModel("10240_Office_Desk_v3_max2011.obj");
    Model terminalmodel = LoadModel("05.04+monitor.glb");

    deskmodel.transform = MatrixRotateX(-90.0f * DEG2RAD);
   
  

    BoundingBox modelBounds = GetModelBoundingBox(model);
    float originalHeight = modelBounds.max.y - modelBounds.min.y;
    float desiredHeight = 1.5f; 
    float characterScale = (originalHeight > 0.0f) ? (desiredHeight / originalHeight) : 1.0f;
    float yOffset = -modelBounds.min.y * characterScale; 

    Camera3D camera = { 0 };
    camera.position = (Vector3){ position.x, position.y + 4.0f, position.z + 9.0f }; 
    camera.target = (Vector3){ position.x, position.y + 0.8f, position.z };  
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };       
    camera.fovy = 45.0f;                            
    camera.projection = CAMERA_PERSPECTIVE;
    
    Vector3 positionkey = { -3.0f, 0.5f, -2.0f };
    Vector3 positiondoor = { 0.0f, 1.3f, -7.7f };
   
    bool haskey = false;
    bool door = false;
    bool Terminal = false;

    BoundingBox deskBox = {
        (Vector3){ 1.8f, 0.0f, -1.2f },
        (Vector3){ 3.2f, 1.2f,  0.2f }
    };
    BoundingBox Frontwallbox = {
    (Vector3){-8.0f, 0.0f, -8.25f },
    (Vector3){8.0f, 6.0f, -7.75f}
    };
    BoundingBox Leftwallbox = {
    (Vector3){ -8.25f, 0.0f, -8.0f},
    (Vector3){ -7.25f, 6.0f, 8.0f}
    };

    BoundingBox rightwallbox = {
    (Vector3){ 7.25f, 0.0f, -8.0f },
    (Vector3){ 8.25f, 6.0f, 8.0f}
    };
    BoundingBox backwallbox = {
    (Vector3){ -8.0f, 0.0f, 7.75f},
    (Vector3){  8.0f, 6.0f , 8.25}
    };

    SetTargetFPS(60);
    float speed = 0.08f;

    GameState state = STATE_EXPLORING;
    int selectedOption = 0; 

    const char* options[] = {
        "1. INVESTIGATE DRAWER",
        "2. READ CASE DOSSIER",
        "3. LEAVE DESK [TAB]"
    };

    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        Ray ray = GetMouseRay(GetMousePosition(), camera);
        RayCollision colision = GetRayCollisionBox(ray, deskBox);
        float distkey = Vector3Distance(position, positionkey);
        float distdoor = Vector3Distance(position, positiondoor);
        float distpc = Vector3Distance(position, positionintterminal);

        if (state == STATE_EXPLORING)
        {
            if (IsKeyDown(KEY_LEFT_SHIFT)) speed = 0.15f;
            else speed = 0.08f;

            Vector2 input = { 0.0f, 0.0f };
            if (IsKeyDown(KEY_W)) input.y -= 1.0f;
            if (IsKeyDown(KEY_S)) input.y += 1.0f;
            if (IsKeyDown(KEY_A)) input.x -= 1.0f;
            if (IsKeyDown(KEY_D)) input.x += 1.0f;
            if (IsKeyDown(KEY_R)) state = STATE_DOSSIE;
            if (IsKeyDown(KEY_Q)) state = STATE_INVENTORY_MENU;
         

            if (input.x != 0.0f || input.y != 0.0f)
            {   
                Vector3 nextPosX = position;
                nextPosX.x += input.x * speed;
                BoundingBox playerboxx = {
                    (Vector3){ nextPosX.x - 0.3f, 0.0f, position.z - 0.3f },
                    (Vector3){ nextPosX.x + 0.3f, 1.5f, position.z + 0.3f }

                };  
                
                if (!CheckCollisionBoxes(playerboxx, deskBox) && 
                    !CheckCollisionBoxes(playerboxx, backwallbox) &&
                    !CheckCollisionBoxes(playerboxx, Leftwallbox) &&
                    !CheckCollisionBoxes(playerboxx, rightwallbox) &&
                    !CheckCollisionBoxes(playerboxx, Frontwallbox))
                {
                    position.x = nextPosX.x;
                }

                Vector3 nextposZ = position;
                nextposZ.z += input.y * speed;
                BoundingBox playerboxz = {
                    (Vector3){ position.x - 0.3f, 0.0f, nextposZ.z - 0.3f },
                    (Vector3){ position.x + 0.3f, 1.5f, nextposZ.z + 0.3f }
                };

                if (!CheckCollisionBoxes(playerboxz, deskBox)
                    && !CheckCollisionBoxes(playerboxz, backwallbox)
                    && !CheckCollisionBoxes(playerboxz, Leftwallbox)
                    && !CheckCollisionBoxes(playerboxz, rightwallbox)
                    && !CheckCollisionBoxes(playerboxz, Frontwallbox))
                {
                    position.z = nextposZ.z;
                }
                
                rotationAngle = atan2f(input.x, input.y) * RAD2DEG;
            }

            if (colision.hit && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {   
                state = STATE_DESK_MENU;
                selectedOption = 0;
            } 

            if (distkey < 1.5f && !haskey && IsKeyPressed(KEY_E))
            {
                haskey = true;
            }

            if (distdoor < 2.0f && !door && IsKeyPressed(KEY_E))
            {
                if (haskey)
                {
                    door = true;
                }
            }

            if (distpc < 1.5f && !Terminal && IsKeyPressed(KEY_E))
            {
                state = STATE_HACK;
            }
        }
        else if (state == STATE_DESK_MENU)
        {
            if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) selectedOption = (selectedOption + 1) % 3;
            if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) selectedOption = (selectedOption - 1 + 3) % 3;

            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE))
            {
                if (selectedOption == 0) state = STATE_INVENTORY_MENU;
                else if (selectedOption == 1) state = STATE_DOSSIE;
                else if (selectedOption == 2) state = STATE_EXPLORING;
            }
 
            if (IsKeyPressed(KEY_TAB) || IsKeyPressed(KEY_ESCAPE)) state = STATE_EXPLORING;
             
            Vector2 mousePos = GetMousePosition();
            Rectangle btnInventory = { 90, 200, 310, 45 };
            Rectangle btn1 = { 105, 265, 310, 45 };
            Rectangle btn2 = { 120, 330, 310, 45 };

            if (CheckCollisionPointRec(mousePos, btnInventory))
            {
                selectedOption = 0;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = STATE_INVENTORY_MENU;
            }
            else if (CheckCollisionPointRec(mousePos, btn1))
            {
                selectedOption = 1;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = STATE_DOSSIE;
            }
            else if (CheckCollisionPointRec(mousePos, btn2))
            {
                selectedOption = 2;
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) state = STATE_EXPLORING;
            }
        }
        else if (state == STATE_INVENTORY_MENU || state == STATE_DOSSIE)
        { 
            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_TAB))
            { 
                state = STATE_DESK_MENU;
            }
        }
        else if (state == STATE_HACK)
        {
            if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_TAB)) state = STATE_EXPLORING;
            if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) selectedWord = (selectedWord + 1) % 4;
            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) selectedWord = (selectedWord - 1 + 4) % 4;
            
            if (IsKeyPressed(KEY_ENTER))
            {
                if (selectedWord == CorrectWordIndex) state = STATE_CLIFFHANGER;
                else 
                {
                    attempts--;
                    if (attempts <= 0)
                    {
                        state = STATE_EXPLORING;
                        attempts = 3;
                    }
                }
            }
        }
        else if (state == STATE_CLIFFHANGER)
        {
            if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)) state = STATE_EXPLORING;
        }

        camera.target = (Vector3){ position.x, position.y + 1.0f, position.z };
        camera.position = (Vector3){ position.x, position.y + 2.5f, position.z + 4.0f };
        if(camera.position.z > 7.0f)
        {
         camera.position.z = 7.0f;
        }

        BeginDrawing();
            ClearBackground((Color){ 10, 10, 15, 255 });

            DrawTexturePro(
                background, 
                (Rectangle){ 0, 0, (float)background.width, (float)background.height },
                (Rectangle){ 0, 0, (float)screenWidth, (float)screenHeight },
                (Vector2){ 0, 0 }, 0.0f, Fade(WHITE, 0.25f)
            );

            BeginMode3D(camera);
            DrawModel(modelground, (Vector3){ 0.0f, 0.0f, 0.0f}, 1.0, WHITE);
            DrawModelEx(modelwall, (Vector3){0.0f, 3.0f, -8.0f}, (Vector3){0.0f, 1.0f, 0.0f},  0.0f, (Vector3){1.0f, 1.0f, 1.0f}, WHITE);
            DrawModelEx(modelwall, (Vector3){-8.0f, 3.0f, 0.0f}, (Vector3){0.0f, 1.0f, 0.0f},  90.0f, (Vector3){1.0f, 1.0f, 1.0f}, WHITE);
            DrawModelEx(modelwall, (Vector3){8.0f, 3.0f, 0.0f}, (Vector3){0.0f, 1.0f, 0.0f}, -90.0f, (Vector3){1.0f, 1.0f, 1.0f}, WHITE);
            DrawModelEx(modelwall, (Vector3){0.0f, 3.0f, 8.0f}, (Vector3){0.0f, 1.0f, 0.0f}, 0.0f, (Vector3){1.0f, 1.0f, 1.0f}, WHITE);
                DrawModelEx(
                    deskmodel,
                    deskPosition,
                    (Vector3){ 0.0f, 1.0f, 0.0f },
                    deskRotation,
                    deskscale,
                    (colision.hit && state == STATE_EXPLORING) ? RED : WHITE
                );

                Vector3 renderPos = { position.x, position.y + yOffset, position.z };
                DrawModelEx(
                    model, 
                    renderPos, 
                    (Vector3){ 0.0f, 1.0f, 0.0f }, 
                    rotationAngle, 
                    (Vector3){ characterScale, characterScale, characterScale }, 
                    WHITE
                );

                DrawModelEx(
                    terminalmodel,
                    positionterminal,
                    (Vector3){ 0.0f, 1.0f, 0.0f },
                    terminalRotation,
                    pcscale,
                    DARKGRAY
                );
                
                if (!haskey)
                {
                    DrawSphere(positionkey, 0.25f, GOLD);
                    DrawSphereWires(positionkey, 0.27f, 8, 8, YELLOW);
                }

                if (!door)
                {
                    DrawCube(positiondoor, 1.5f, 2.5f, 0.2f, DARKBROWN);
                    DrawCubeWires(positiondoor, 1.5f, 2.5f, 0.2f, BLACK);
                }
                else
                {
                    DrawCube((Vector3){ positiondoor.x + 1.0f, positiondoor.y, positiondoor.z - 0.5f }, 0.2f, 2.5f, 1.5f, LIME);
                }

                
                DrawCylinder((Vector3){ 2.5f, 3.0f, -0.5f }, 0.1f, 2.0f, 2.5f, 16, Fade(YELLOW, 0.10f));
            EndMode3D();
            
            DrawFPS(10, 10);
            DrawText("City of the forgotten 0.7", 20, 40, 20, BLUE);
            
            DrawRectangleGradientV(0, 0, screenWidth, 80, Fade(BLACK, 0.8f), Fade(BLACK, 0.0f));
            DrawRectangleGradientV(0, screenHeight - 80, screenWidth, 80, Fade(BLACK, 0.0f), Fade(BLACK, 0.8f));

            if (state == STATE_EXPLORING)
            {
                DrawText("Use WASD para mover | Shift para correr", 20, 70, 16, LIGHTGRAY);
                if (colision.hit) DrawText("Open the desk!", 20, 100, 20, GREEN);
                if (distkey < 1.5f && !haskey) DrawText("Press [E] to pick up the key", 20, 130, 20, GREEN); 
                if (distpc < 1.5f && !Terminal) DrawText("Press [E] to access Terminal", 20, 100, 20, LIME);
                if (distdoor < 2.0f && !door)
                {
                    if (haskey) DrawText("Press [E] to unlock the door", 20, 160, 20, GREEN);
                    else DrawText("The door is locked! Search for the key in the Office", 20, 160, 20, RED);
                }
                if (door)
                { 
                    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.85f));
                    DrawText("The Door is open!", screenWidth/2 - 100, screenHeight/2 - 40, 24, GREEN);
                    DrawText("Thank You for playing the demo for City of the Forgotten", screenWidth/2 - 270, screenHeight/2, 20, RAYWHITE);
                }
            }
            else if (state == STATE_DESK_MENU)
            {   
                DrawRectangle(0, 0, screenWidth, screenHeight, (Color){ 0, 0, 0, 180 });
                DrawRectanglePro((Rectangle){ 150, 0, 300, 800 }, (Vector2){ 0, 0 }, -15.0f, (Color){ 15, 15, 15, 230 });
                DrawRectanglePro((Rectangle){ 140, 0, 10, 800 }, (Vector2){ 0, 0 }, -15.0f, RED); 
                DrawTextPro(GetFontDefault(), "DESK // CASE FILES", (Vector2){ 80, 80 }, (Vector2){ 0, 0 }, -5.0f, 28, 2, RAYWHITE);

                for (int i = 0; i < 3; i++) 
                {
                    float yPos = 200.0f + (i * 65.0f);
                    float xPos = 90.0f + (i * 15.0f); 

                    if (selectedOption == i)
                    {   
                        DrawRectanglePro((Rectangle){ xPos - 10, yPos - 5, 320, 45 }, (Vector2){ 0, 0 }, -3.0f, RED);
                        DrawRectanglePro((Rectangle){ xPos - 5, yPos - 2, 310, 39 }, (Vector2){ 0, 0 }, -3.0f, BLACK);
                        DrawTextPro(GetFontDefault(), options[i], (Vector2){ xPos + 10, yPos + 5 }, (Vector2){ 0, 0 }, -3.0f, 22, 2, RAYWHITE);
                    }
                    else
                    {
                        DrawTextPro(GetFontDefault(), options[i], (Vector2){ xPos, yPos }, (Vector2){ 0, 0 }, -3.0f, 20, 2, GRAY);
                    }
                } 

                DrawText("Use [W/S] or Mouse to navigate | [ENTER] to select", 50, 520, 16, LIGHTGRAY);
            }
            else if (state == STATE_INVENTORY_MENU)
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, (Color){ 0, 0, 0, 220 });
                DrawRectangle(100, 80, 600, 420, (Color){ 20, 20, 20, 240 });
                DrawRectangleLines(100, 80, 600, 420, RED); 

                DrawText("INVENTORY // EVIDENCE LOG", 130, 110, 24, RED);
                DrawText("- Detective badge (Det. Robert Bogart)", 140, 210, 20, RAYWHITE);
                DrawText("- Weapon of the crime", 140, 250, 20, RAYWHITE);
                
                if (haskey) DrawText("- Key found in the Office", 140, 170, 20, GOLD);
                else DrawText("- Key (Not found yet)", 140, 170, 20, DARKGRAY);

                DrawText("[ENTER / ESC / TAB] Back to Menu", 130, 460, 16, LIGHTGRAY);
            }
            else if (state == STATE_DOSSIE)
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, (Color){ 0, 0, 0, 230});
                DrawRectangleLines(80, 50, 640, 500, RED);
                DrawText("CASE 41: THE BURNING LIBRARIES", 110, 70, 22, RED);
                DrawText("Client: Mrs. Brown And the Libery Crusaders", 110, 100, 18, RAYWHITE);
                DrawText("Victim: Dr. Lee Brown (Liberty Crusaders)", 110, 125, 18, RAYWHITE);
                DrawText("Payment: $10,000 UpFront / $450.00 Delivery", 110, 150, 18, GOLD);
                
                DrawText("Case Notes:", 110, 185, 18, GOLD);
                DrawText("* Multiple local and important libraries destroyed in arson attacks", 120, 210, 15, LIGHTGRAY);
                DrawText("* Dr. Lee defended decentralized knowledge and open data", 120, 230, 15, LIGHTGRAY);
                DrawText("* Found dead in the central archives during the fire", 120, 250, 15, LIGHTGRAY);
                DrawText("* Authorities claim accident. The client suspects murder", 120, 270, 15, LIGHTGRAY);
                
                DrawText("*Investigator's notes", 110, 300, 17, RED);
                DrawText("*The Crusaders Preach 'Free Knowledge' But their methods are impulsive and dangerous", 120, 322, 14, GRAY);
                DrawText("*Mrs Brow thinks I'm Fighting for their cause I'm here just for the cash", 120, 340, 14, GRAY);
                DrawText("*I Have been through enough Wars i don't want to get into another one...", 120, 358, 14, GRAY);
                DrawText("OBJECTIVE:", 110, 390, 18, YELLOW);
                DrawText("Find the decryption key in the remaining library Get the Payment and LEAVE DON'T GET INTO THEIR POLITICAL DRAMA", 110, 415, 16, RAYWHITE);
                
                DrawText("[ENTER / ESC / TAB] Back to Desk Menu", 110, 480, 15, GRAY);
            }
            else if (state == STATE_HACK)
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, (Color){5, 15, 5, 255});
                DrawRectangle(20, 20, screenWidth - 40, screenHeight - 40, LIME);
                
                DrawText("Terminal // CELL 8-F Encrypted Data", 40, 35, 18, LIME);
                DrawText("Security Sistem OmniMind Inc. Making you connected to what is important", 50, 58, 13, SKYBLUE);
                DrawText("--------------------------------------------", 40, 75, 16, LIME);
                DrawText("Security Warning ", 40, 98, 15, RED);
                DrawText(TextFormat("Chances Left for Hacking the system %d attempts", attempts), 40, 120, 16, (attempts > 1) ? RAYWHITE : RED);
                
                const char* memoryAddresses[] = { "0xNODE_01", "0xNODE_02", "0xNODE_03", "0xNODE_04"};
                const char* keywords[] = {"CRUSADE", "ARCHIVE", "BURNING", "FREEDOM"};
                const char* datacenters[] = {"ROTTENWOOD-DATA CENTER", "HELL'S DOOR-DATA CENTER", "Sillicon heights-Main Data center", "Glass Harbor-DATA CENTER"};

                for (int i = 0; i < 4; i++)
                {
                    float yPos = 160.0f + (i * 42.0f);
                    DrawText(memoryAddresses[i], 40, yPos, 16, LIME);
                    
                    if (selectedWord == i)
                    {
                        DrawRectangle(140, yPos - 3, 400, 28, LIME);
                        DrawText(TextFormat("> %s %s", keywords[i], datacenters[i]), 145, yPos, 15, BLACK);
                    }
                    else
                    {
                        DrawText(TextFormat("  %s %s", keywords[i], datacenters[i]), 145, yPos, 15, LIGHTGRAY);
                    }
                }
            }
            else if (state == STATE_CLIFFHANGER)
            {
                DrawRectangle(0, 0, screenWidth, screenHeight, (Color){ 0, 0, 0, 230 });
                DrawText("DEMO COMPLETED // CLIFFHANGER", 180, 250, 24, RED);
                DrawText("Press [ENTER] to return to the room", 210, 300, 18, RAYWHITE);
            }

        EndDrawing();
    }

    UnloadTexture(background);
    UnloadTexture(walltexture);
    UnloadTexture(groundtexture);
    UnloadMusicStream(music);
    UnloadModel(model);
    UnloadModel(deskmodel);
    UnloadModel(terminalmodel);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}