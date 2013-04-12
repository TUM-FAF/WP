#include <windows.h>
#include <math.h>
#include <time.h>
#define NUM 1000
#define TWOPI (2 * 3.14159)
#define ID_TIMER 1

#define BALLS_NR 16
#define FRAMES 25
#define DIAMETER 30
#define SPEED 1

int grey=0;
int RGBr=255;
int RGBg=0;
int RGBb=0;

BOOL bMoveTop=FALSE;
BOOL bMoveRight=TRUE;
int iDeltaX=0;//start from left corner
int iDeltaY=0;//start from top corner


typedef struct ballinfo{
  int diameter;
  float x;//position or left corner
  float y;//position of top corner
  BOOL tx;//move to right
  BOOL ty;//move to top
  float sx;//x speed
  float sy;//y speed

  int dx;
  int dy;

  int r;
  int g;
  int b;
}BallInfo;

BallInfo* balls[BALLS_NR];

int BallMovement[25][2];

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,
          PSTR szCmdLine, int iCmdShow){
   static char szAppName[] = "WP Lab#4 example (animation)" ;
   HWND        hwnd ;
   MSG         msg ;
   WNDCLASSEX  wndclass ;
   wndclass.cbSize        = sizeof (wndclass) ;
   wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
   wndclass.lpfnWndProc   = WndProc ;
   wndclass.cbClsExtra    = 0 ;
   wndclass.cbWndExtra    = 0 ;
   wndclass.hInstance     = hInstance ;
   wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
   wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
   wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
   wndclass.lpszMenuName  = NULL ;
   wndclass.lpszClassName = szAppName ;
   wndclass.hIconSm       = LoadIcon (NULL, IDI_APPLICATION) ;
   RegisterClassEx (&wndclass) ;
   hwnd = CreateWindow (szAppName, "WP Lab#4 example (animation)",
              WS_OVERLAPPEDWINDOW,
              CW_USEDEFAULT, CW_USEDEFAULT,
              450, 350,
              NULL, NULL, hInstance, NULL) ;
   ShowWindow (hwnd, iCmdShow) ;
   UpdateWindow (hwnd) ;
   while (GetMessage (&msg, NULL, 0, 0))
      {
      TranslateMessage (&msg) ;
      DispatchMessage (&msg) ;
      }
   return msg.wParam ;
   }

void ChangeRGB(){
  if(RGBr==255){//satureate G
    //decrease B
    if(RGBb>0)
      RGBb--;
    //increase G
    else
      RGBg++;
  }
  if(RGBg==255){
    //decrease R
    if(RGBr>0)
      RGBr--;
    //increase B
    else
      RGBb++;
  }
  if(RGBb==255){
    //decrease G
    if(RGBg>0)
      RGBg--;
    //increase R
    else
      RGBr++;
  }
}

void DrawBool(HDC hdc,int cxClient, int cyClient){

  if(bMoveTop){
    if(iDeltaY>0)
      iDeltaY-=SPEED;
    else{
      bMoveTop=FALSE;
      iDeltaY+=SPEED;
    }
  }else{
    if(iDeltaY<cyClient-DIAMETER)
      iDeltaY+=SPEED;
    else{
      bMoveTop=TRUE;
      iDeltaY-=SPEED;
    }
  }

  if(bMoveRight){
    if(iDeltaX<cxClient-DIAMETER)
      iDeltaX+=SPEED;
    else{
      bMoveRight=FALSE;
      iDeltaX-=SPEED;
    }
  }else{
    if(iDeltaX>0)
      iDeltaX-=SPEED;
    else{
      bMoveRight=TRUE;
      iDeltaX+=SPEED;
    }
  }

  Ellipse(hdc,iDeltaX,iDeltaY,iDeltaX+DIAMETER,iDeltaY+DIAMETER) ;
}

void InitialiseBalls(BallInfo* balls[BALLS_NR]){
int i,j;
  srand ( time(NULL) );

  for(i=0;i<BALLS_NR;i++){
    balls[i] = (BallInfo*) malloc (sizeof (BallInfo));
    //use balls[i];
    balls[i]->diameter=rand() % 20 + 10;
    balls[i]->x=rand() % 400;
    balls[i]->y=rand() % 300;
    balls[i]->tx=rand() % 2;
    balls[i]->ty=rand() % 2;
    balls[i]->sx=(rand() % (SPEED*1000));
    balls[i]->sx=balls[i]->sx /997 +1;
    balls[i]->sy=(rand() % (SPEED*1000));
    balls[i]->sy=balls[i]->sy /997 +1;

    balls[i]->r=255;
    balls[i]->g=255;
    balls[i]->b=255;
  }
  BallMovement[0][0]=balls[0]->x;
  BallMovement[0][1]=balls[0]->y;
  for(i=1;i<25;i++){
    BallMovement[i][0]=0;
    BallMovement[i][1]=0;
  }
}

void RedrawBalls(BallInfo* balls[BALLS_NR]){
int i,j;
  srand ( time(NULL) );

  for(i=0;i<BALLS_NR;i++){
    //use balls[i];
    balls[i]->diameter=rand() % 20 + 10;
    balls[i]->x=rand() % 400;
    balls[i]->y=rand() % 300;
    balls[i]->tx=rand() % 2;
    balls[i]->ty=rand() % 2;
    balls[i]->sx=(rand() % (SPEED*1000));
    balls[i]->sx=balls[i]->sx /997 +1;
    balls[i]->sy=(rand() % (SPEED*1000));
    balls[i]->sy=balls[i]->sy /997 +1;

    balls[i]->r=255;
    balls[i]->g=255;
    balls[i]->b=255;
  }
  BallMovement[0][0]=balls[0]->x;
  BallMovement[0][1]=balls[0]->y;
  for(i=1;i<25;i++){
    BallMovement[i][0]=0;
    BallMovement[i][1]=0;
  }
}

void MoveBallsRow(){
int i;
  for(i=24;i>=0;i--){
  BallMovement[i+1][0]=BallMovement[i][0];
  BallMovement[i+1][1]=BallMovement[i][1];
  }
}

void DrawBools(HDC hdc,BallInfo* balls[BALLS_NR],int cxClient, int cyClient){
int i,j,diameter;
float dif,distance;
int iDeltaX,iDeltaY;
BOOL bMoveTop=FALSE;
BOOL bMoveRight=TRUE;
BOOL bChangeDirection=FALSE;

HBRUSH hBrush;
HPEN hPen;

float s1,s2,s3,s4;
int v1,v2,v3,v4;

i=0;
while(i<25 && BallMovement[i][0]>0){
  if(i==0)
    MoveToEx(hdc, BallMovement[i][0], BallMovement[i][1],NULL);
  else
    LineTo(hdc, BallMovement[i][0], BallMovement[i][1]);
  i++;
}

  for(i=0;i<BALLS_NR;i++){
    //use balls[i]
  diameter=balls[i]->diameter;

for(j=0;j<i;j++){
  bChangeDirection=FALSE;
  dif=abs(balls[i]->diameter - balls[j]->diameter)/2;
  distance=sqrt((balls[i]->x - balls[j]->x + dif)*(balls[i]->x - balls[j]->x + dif) + (balls[i]->y - balls[j]->y + dif)*(balls[i]->y - balls[j]->y + dif));
  if(distance<=((balls[i]->diameter + balls[j]->diameter)/2)){
    if(distance<=((balls[i]->diameter + balls[j]->diameter)/2 -4)){
      balls[j]->x=rand() % 400;
      balls[j]->y=rand() % 300;
    }
    //split
    balls[i]->tx=!balls[i]->tx;
    balls[i]->ty=!balls[i]->ty;
    balls[j]->tx=!balls[j]->tx;
    balls[j]->ty=!balls[j]->ty;

    balls[i]->r=RGBb;
    balls[i]->g=RGBr;
    balls[i]->b=RGBg;

    balls[j]->r=RGBg;
    balls[j]->g=RGBb;
    balls[j]->b=RGBr;

    if(balls[i]->diameter > balls[j]->diameter){
      balls[i]->sx=balls[i]->sx * 0.99;
      balls[i]->sy=balls[i]->sy * 0.99;
      balls[j]->sx=balls[j]->sx * 1.01;
      balls[j]->sy=balls[j]->sy * 1.01;
    }else{
      balls[i]->sx=balls[i]->sx * 1.01;
      balls[i]->sy=balls[i]->sy * 1.01;
      balls[j]->sx=balls[j]->sx * 0.99;
      balls[j]->sy=balls[j]->sy * 0.99;
    }



  if(j==0){
    MoveBallsRow();
    BallMovement[0][0]=balls[j]->x+(balls[j]->diameter)/2;
    BallMovement[0][1]=balls[j]->y+(balls[j]->diameter)/2;
  }

  }
}

  if(balls[i]->ty){
    if(balls[i]->y>0)
      balls[i]->y-=balls[i]->sy;
    else{
      balls[i]->ty=FALSE;
      balls[i]->y+=balls[i]->sy;
      bChangeDirection=TRUE;
    }
  }else{
    if(balls[i]->y<cyClient-diameter)
      balls[i]->y+=balls[i]->sy;
    else{
      balls[i]->ty=TRUE;
      balls[i]->y-=balls[i]->sy;
      bChangeDirection=TRUE;
    }
  }

  if(balls[i]->tx){
    if(balls[i]->x<cxClient-diameter)
      balls[i]->x+=balls[i]->sx;
    else{
      balls[i]->tx=FALSE;
      balls[i]->x-=balls[i]->sx;
      bChangeDirection=TRUE;
    }
  }else{
    if(balls[i]->x>0)
      balls[i]->x-=balls[i]->sx;
    else{
      balls[i]->tx=TRUE;
      balls[i]->x+=balls[i]->sx;
      bChangeDirection=TRUE;
    }
  }

  hBrush = CreateSolidBrush(RGB(balls[i]->r, balls[i]->g, balls[i]->b));
  SelectObject(hdc, hBrush);


  Ellipse(hdc,balls[i]->x,balls[i]->y,balls[i]->x+diameter,balls[i]->y+diameter) ;

  DeleteObject(hBrush);
  }
    if(bChangeDirection)
      MoveBallsRow();
    BallMovement[0][0]=balls[j]->x+(balls[j]->diameter)/2;
    BallMovement[0][1]=balls[j]->y+(balls[j]->diameter)/2;

}

LRESULT CALLBACK WndProc (HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam){
  static int  cxClient, cyClient ;
  static BOOL flag = TRUE ;
  HBRUSH hBrush ;
  HDC hdc ;
  int         i ;
  PAINTSTRUCT ps ;
  POINT       pt [NUM] ;
  RECT rc ;


  switch (iMsg){
    case WM_CREATE:
      SetTimer (hwnd, ID_TIMER, FRAMES, NULL);
      InitialiseBalls(balls);
      return 0;
    case WM_SIZE:
      cxClient = LOWORD (lParam) ;
      cyClient = HIWORD (lParam) ;
      return 0 ;
    case WM_TIMER :
      InvalidateRect (hwnd, NULL, FALSE) ;
      return 0 ;
    case WM_PAINT:
      hdc = BeginPaint (hwnd, &ps) ;
      GetClientRect (hwnd, &rc) ;

      ChangeRGB();
      hBrush = CreateSolidBrush (RGB(RGBr,RGBg,RGBb)) ;
      FillRect (hdc, &rc, hBrush) ;

      DrawBools(hdc,balls,cxClient,cyClient);

      EndPaint (hwnd, &ps) ;
      DeleteObject (hBrush) ;
      return 0 ;
    case WM_CLOSE:
      RedrawBalls(balls);
      return 0;
    case WM_MOUSEWHEEL:
    case WM_DESTROY:
      for(i=0;i<BALLS_NR;i++){
        free( balls[i]);
      }
      free(balls);
      KillTimer (hwnd, ID_TIMER) ;
      PostQuitMessage (0) ;
      return 0 ;
  }
  return DefWindowProc (hwnd, iMsg, wParam, lParam) ;
}
