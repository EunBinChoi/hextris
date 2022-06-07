#include <windows.h>

// WinMain �Լ����� �����ϹǷ� �Լ� ������ �����Ѵ�.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wndclass;
	HWND hwnd;
	MSG msg;

	// ������ Ŭ������ �ʱ�ȭ�ϰ� �ü���� ����Ѵ�.
	wndclass.style = CS_HREDRAW | CS_VREDRAW; // ��Ÿ�� ����
	wndclass.lpfnWndProc = WndProc; // ������ ���ν��� �̸�
	wndclass.cbClsExtra = 0; // ���� �޸�(0����Ʈ)
	wndclass.cbWndExtra = 0; // ���� �޸�(0����Ʈ)
	wndclass.hInstance = hInstance; // �ν��Ͻ� �ڵ�
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); // ������ ���
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); // Ŀ�� ���
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ���(���)
	wndclass.lpszMenuName = NULL; // �޴�(NULL->�޴� ����)
	wndclass.lpszClassName = TEXT("HelloClass"); // ������ Ŭ���� �̸�
	if(!RegisterClass(&wndclass)) return 1;

	// �����츦 �����ϰ� ȭ�鿡 ���̰� �Ѵ�.
	hwnd = CreateWindow(TEXT("HelloClass"), TEXT("HelloSDK"), // â ����
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	ShowWindow(hwnd,SW_MINIMIZE); // â ����
	/*
	
	_FORCEMINIMIZE11 Minimizes a window, even if the thread that owns the window is not responding. This flag should only be used when minimizing windows from a different thread. 

SW_HIDE0 Hides the window and activates another window. 

SW_MAXIMIZE3 Maximizes the specified window. 

SW_MINIMIZE6 Minimizes the specified window and activates the next top-level window in the Z order. 

SW_RESTORE9 Activates and displays the window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when restoring a minimized window. 

SW_SHOW5 Activates the window and displays it in its current size and position. 

SW_SHOWDEFAULT10 Sets the show state based on the SW_ value specified in theSTARTUPINFO structure passed to the CreateProcess function by the program that started the application. 

SW_SHOWMAXIMIZED3 Activates the window and displays it as a maximized window. 

SW_SHOWMINIMIZED2 Activates the window and displays it as a minimized window. 

SW_SHOWMINNOACTIVE7 Displays the window as a minimized window. This value is similar to SW_SHOWMINIMIZED, except the window is not activated. 

SW_SHOWNA8 Displays the window in its current size and position. This value is similar to SW_SHOW, except that the window is not activated. 

SW_SHOWNOACTIVATE4 Displays a window in its most recent size and position. This value is similar to SW_SHOWNORMAL, except that the window is not activated. 

SW_SHOWNORMAL1 Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time. 
*/
	// �޽��� ť���� �޽����� �ϳ��� ������ ó���Ѵ�.
	while(GetMessage(&msg, NULL, 0, 0) > 0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message,
                         WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR *str = TEXT("Hello, SDK");

	// �߻��� �޽����� ������ ���� ������ ó���Ѵ�.
	switch(message){
	case WM_CREATE:
		return 0;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("���콺 Ŭ��!"), TEXT("���콺 �޽���"), MB_OK);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 100, 100, str, lstrlen(str));
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	// ���� ���α׷��� ó������ ���� �޽����� �ü���� ó���Ѵ�.
	return DefWindowProc(hwnd, message, wParam, lParam);
}
