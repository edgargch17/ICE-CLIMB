#include <raylib.h>

int displayP1(void);
int displayP2(void);

int tamAltura = 650;
int tamAnchura = 1300;

int main(void){

    const int screenWidth = tamAnchura;
    const int screenHeight = tamAltura;

    InitWindow(screenWidth, screenHeight, "iCE Climbers Menu");
    Image iceC = LoadImage("img/iceC.png"); 
    Texture2D texture = LoadTextureFromImage(iceC);

    Image HM = LoadImage("img/HM.png"); 
    Texture2D textureH = LoadTextureFromImage(HM);     
    
    Vector2 HMPosition = { 400, 300 };
    UnloadImage(iceC);
    UnloadImage(HM);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    

    // Main game loop
    while (!WindowShouldClose()){
        
        // Update
        //----------------------------------------------------------------------------------
        //if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 5.0f;
        //if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 5.0f;
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            //----------primera parte
            ClearBackground((Color){0,0,0,0});
            DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2 - 200, WHITE);
            DrawText("1 Player Game", 400, 300, 70, DARKGRAY);
            DrawText("2 Player Game", 400, 450, 70, DARKGRAY);
            
            if (IsKeyDown(KEY_UP) && IsKeyUp(KEY_DOWN))
                DrawTexture(textureH,350, HMPosition.y, WHITE);
            
            
            if (IsKeyDown(KEY_DOWN) && IsKeyUp(KEY_UP))
                DrawTexture(textureH,350, HMPosition.y+150, WHITE);
            
            if (IsKeyDown(KEY_ENTER) && IsKeyDown(KEY_UP)){
                CloseWindow(); 
                displayP1();                
            }
            
            if (IsKeyDown(KEY_ENTER) && IsKeyDown(KEY_DOWN)){
                CloseWindow(); 
                displayP2();                
            }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
struct piso{
    Image p;
    Vector2 pisoPos;    
};


int displayP1(void){
    InitWindow(tamAnchura, tamAltura, "iCE Climbers 1 Player");
    Image pd = LoadImage("img/PD.png");
    Image pi = LoadImage("img/PI.png");
    
    struct piso P1 = {LoadImage("img/P1.png"),{0,tamAltura-tamAltura/4}};  
    ImageResize(&(P1.p), tamAnchura, tamAltura/4);
    
    struct piso P2 = {LoadImage("img/P2.png"),{0,tamAltura-2*tamAltura/4}};  
    ImageResize(&(P2.p), tamAnchura, tamAltura/4);
    
    struct piso P3 = {LoadImage("img/P3.png"),{0,tamAltura-3*tamAltura/4}};  
    ImageResize(&(P3.p), tamAnchura, tamAltura/4);
    
    struct piso P4 = {LoadImage("img/P4.png"),{0,tamAltura-tamAltura}};  
    ImageResize(&(P4.p), tamAnchura, tamAltura/4);
    
    Vector2 p1Position = { 550, tamAltura-tamAltura/4 +50};
    
    Texture2D texp = LoadTextureFromImage(P1.p);
    Texture2D texp2 = LoadTextureFromImage(P2.p);
    Texture2D texp3 = LoadTextureFromImage(P3.p);
    Texture2D texp4 = LoadTextureFromImage(P4.p);
    Texture2D texpd = LoadTextureFromImage(pd);
    Texture2D texpi = LoadTextureFromImage(pi);
    
    
    UnloadImage(pd);
    UnloadImage(pi);
    UnloadImage(P1.p);
    UnloadImage(P2.p);
    UnloadImage(P3.p);
    UnloadImage(P4.p);
    
    while (!WindowShouldClose()){
        if (IsKeyDown(KEY_RIGHT)) p1Position.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) p1Position.x -= 2.0f;
        if (IsKeyPressed(KEY_M)) {
            p1Position.y -= 2.0f;
        }
        
        BeginDrawing();
           ClearBackground((Color){0,0,0,0});
           DrawTexture(texp,P1.pisoPos.x,P1.pisoPos.y,WHITE);
           DrawTexture(texp2,P2.pisoPos.x,P2.pisoPos.y,WHITE);
           DrawTexture(texp3,P3.pisoPos.x,P3.pisoPos.y,WHITE);
           DrawTexture(texp4,P4.pisoPos.x,P4.pisoPos.y,WHITE);
           DrawTexture(texpd, p1Position.x, p1Position.y , WHITE);
          
        EndDrawing();
            
    }
}


int displayP2(void){
    InitWindow(tamAnchura, tamAltura, "iCE Climbers 1 Player");
    
    Image pd = LoadImage("img/PD.png");
    Image pi = LoadImage("img/PI.png");
    
    Image nd = LoadImage("img/ND.png");
    Image ni = LoadImage("img/NI.png");
    
    struct piso P1 = {LoadImage("img/P1.png"),{0,tamAltura-tamAltura/4}};  
    ImageResize(&(P1.p), tamAnchura, tamAltura/4);
    
    struct piso P2 = {LoadImage("img/P2.png"),{0,tamAltura-2*tamAltura/4}};  
    ImageResize(&(P2.p), tamAnchura, tamAltura/4);
    
    struct piso P3 = {LoadImage("img/P3.png"),{0,tamAltura-3*tamAltura/4}};  
    ImageResize(&(P3.p), tamAnchura, tamAltura/4);
    
    struct piso P4 = {LoadImage("img/P4.png"),{0,tamAltura-tamAltura}};  
    ImageResize(&(P4.p), tamAnchura, tamAltura/4);
    
    Vector2 p1Position = { 600, tamAltura-tamAltura/4 +50};
    Vector2 p2Position = { 700, tamAltura-tamAltura/4 +50 };
    
    Texture2D texp = LoadTextureFromImage(P1.p);
    Texture2D texp2 = LoadTextureFromImage(P2.p);
    Texture2D texp3 = LoadTextureFromImage(P3.p);
    Texture2D texp4 = LoadTextureFromImage(P4.p);
    Texture2D texpd = LoadTextureFromImage(pd);
    Texture2D texpi = LoadTextureFromImage(pi);
    Texture2D texnd = LoadTextureFromImage(nd);
    Texture2D texni = LoadTextureFromImage(ni);
    
    
    UnloadImage(pd);
    UnloadImage(pi);
    UnloadImage(nd);
    UnloadImage(ni);
    UnloadImage(P1.p);
    UnloadImage(P2.p);
    UnloadImage(P3.p);
    UnloadImage(P4.p);
    
    
    while (!WindowShouldClose()){
        if (IsKeyDown(KEY_RIGHT)) p1Position.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) p1Position.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) p1Position.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) p1Position.y += 2.0f;
        
        if (IsKeyDown(KEY_D)) p2Position.x += 2.0f;
        if (IsKeyDown(KEY_A)) p2Position.x -= 2.0f;
        if (IsKeyDown(KEY_W)) p2Position.y -= 2.0f;
        if (IsKeyDown(KEY_S)) p2Position.y += 2.0f;
        
        BeginDrawing();
           ClearBackground((Color){0,0,0,0});
           DrawTexture(texp,P1.pisoPos.x,P1.pisoPos.y,WHITE);
           DrawTexture(texp2,P2.pisoPos.x,P2.pisoPos.y,WHITE);
           DrawTexture(texp3,P3.pisoPos.x,P3.pisoPos.y,WHITE);
           DrawTexture(texp4,P4.pisoPos.x,P4.pisoPos.y,WHITE);
           DrawTexture(texpd, p1Position.x, p1Position.y , WHITE);
           DrawTexture(texnd, p2Position.x, p2Position.y, WHITE);
        EndDrawing();
        
        
            
    }
}