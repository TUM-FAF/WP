#include <windows.h>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[] = "CodeBlocksWindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow){
  HWND hwnd;               /* This is the handle for our window */
  MSG messages;            /* Here messages to the application are saved */
  WNDCLASSEX wincl;        /* Data structure for the windowclass */

  /* The Window structure */
  wincl.hInstance = hThisInstance;
  wincl.lpszClassName = szClassName;
  wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
  wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
  wincl.cbSize = sizeof (WNDCLASSEX);

  /* Use default icon and mouse-pointer */
  wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
  wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
  wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
  wincl.lpszMenuName = NULL;                 /* No menu */
  wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
  wincl.cbWndExtra = 0;                      /* structure or the window instance */

  // Set custom background
  wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(238, 238, 238));

  /* Register the window class, and if it fails quit the program */
  if (!RegisterClassEx (&wincl))
    return 0;

  /* The class is registered, let's create the program*/
  hwnd = CreateWindowEx (0, szClassName, "WP Lab#3 example (drawings)",
    WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 400,
    HWND_DESKTOP, NULL, hThisInstance, NULL);

  ShowWindow (hwnd, nCmdShow);

  while (GetMessage (&messages, NULL, 0, 0)){
    TranslateMessage (&messages);
    DispatchMessage (&messages);
  }

  return messages.wParam;
}

bool firstPaintColor = true;

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){

  HDC hdc, hdcMem;
  PAINTSTRUCT ps;
  RECT rect;

  int hMenuIndex = -1;
  HWND hwndTextareaLogin
     , hwndTextareaPassword
     , hwndButton;
  bool firstPaint = true;

  switch (message){
    case WM_CREATE:
      // Force paint
      InvalidateRect(hwnd, NULL, TRUE);

      break;

    case WM_PAINT:
      if (firstPaint){
        hdc = BeginPaint (hwnd, &ps);
        // Draw rectangle
        Rectangle (hdc, 60, 60, 210, 210);

        EndPaint (hwnd, &ps);

        firstPaint = false;
      }

      break;

    case WM_MOVE:
      RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE);
      break;

    case WM_DESTROY:
      PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
      break;

    default:                      /* for messages that we don't deal with */
      return DefWindowProc (hwnd, message, wParam, lParam);
  }

  return 0;
}
