#include <windows.h>
#include "resource.h"

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "Jeff's App";

// UI Elements to share
HWND hwndTextBox;
HWND hwndLabel;
HWND hwndPasswordInput;
HWND hwndNumberInput;

int WINAPI WinMain (HINSTANCE hThisInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszArgument,
					int nFunsterStil)

{
	HWND hwnd;			   /* This is the handle for our window */
	MSG messages;			/* Here messages to the application are saved */
	WNDCLASSEX wincl;		/* Data structure for the windowclass */

	/* The Window structure */
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;	  /* This function is called by windows */
	wincl.style = CS_DBLCLKS;				 /* Catch double-clicks */
	wincl.cbSize = sizeof (WNDCLASSEX);

	/* Use my icon and default mouse-pointer */
	wincl.hIcon = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_MYICON));
	wincl.hIconSm = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_MYICON));
	wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl.lpszMenuName = "Menu";
	// wincl.lpszMenuName = NULL;				 /* No menu */
	wincl.cbClsExtra = 0;					  /* No extra bytes after the window class */
	wincl.cbWndExtra = 0;					  /* structure or the window instance */
	/* Use Windows's default color as the background of the window */
	wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
	
	// Create the menu
	HMENU hMenu = CreateMenu();
	HMENU hMenuPopup = CreateMenu();
	AppendMenu(hMenuPopup, MF_STRING, IDM_FILE_EXIT, TEXT("Exit"));
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hMenuPopup, TEXT("File"));

	/* Register the window class, and if it fails quit the program */
	if (!RegisterClassEx (&wincl))
		return 0;

	/* The class is registered, let's create the program*/
	// Create the window
	hwnd = CreateWindowEx (
		   0,				   /* Extended possibilites for variation */
		   szClassName,		 /* Classname */
		   "Jeff's App",	   /* Title Text */
		   WS_OVERLAPPEDWINDOW, /* default window */
		   CW_USEDEFAULT,	   /* Windows decides the position */
		   CW_USEDEFAULT,	   /* where the window ends up on the screen */
		   544,				 /* The programs width */
		   375,				 /* and height in pixels */
		   HWND_DESKTOP,		/* The window is a child-window to desktop */
		   hMenu,				/* Menu */
		   hThisInstance,	   /* Program Instance handler */
		   NULL				 /* No Window Creation data */
		   );

	// Create a label for the text field
	HWND hwndTextBoxLabel = CreateWindow(
		"STATIC",
		"Regular Text Input", // This is the text that automatically gets appears when the element loads.
		WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER,
		10, // x position
		10, // y position
		130, // Width
		20, // Height
		hwnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);

	// Create a text field
	hwndTextBox = CreateWindow(
		"EDIT",
		"Test Text", // This is the text that automatically gets appears when the element loads.
		WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER | ES_MULTILINE | ES_WANTRETURN | ES_AUTOVSCROLL,
		10, // x position
		40, // y position
		100, // Width
		100, // Height
		hwnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);

	// Create a label to hold the copied text
	hwndLabel = CreateWindow(
		"STATIC",
		"Hit the button to copy the text from the text box to here", // This is the text that automatically gets appears when the element loads.
		WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER,
		130, // x position
		40, // y position
		100, // Width
		100, // Height
		hwnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);

	// Create a button for the text box
	HWND hwndButton = CreateWindow(
		TEXT("BUTTON"),		// Predefined class; Unicode assumed
		TEXT("Hit me!"),			// Button text
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
		10,					// x position
		150,					// y position
		60,					// Button width
		25,					// Button height
		hwnd,				// Parent window
		(HMENU)IDI_BUTTON,	// No menu.
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);				// Pointer not needed.

	// Create a label for the password field
	HWND hwndPasswordLabel = CreateWindow(
		"STATIC",
		"Password Input", // This is the text that automatically gets appears when the element loads.
		WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER,
		10, // x position
		200, // y position
		110, // Width
		20, // Height
		hwnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);

	// Create a password field
	hwndPasswordInput = CreateWindow(
		"EDIT",
		"password123", // This is the text that automatically gets appears when the element loads.
		WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER | ES_PASSWORD,
		10, // x position
		230, // y position
		100, // Width
		25, // Height
		hwnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);				// Pointer not needed.

	// Create a button for the password field
	HWND hwndPasswordButton = CreateWindow(
		TEXT("BUTTON"),		// Predefined class; Unicode assumed
		TEXT("Hit me!"),			// Button text
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
		10,					// x position
		270,					// y position
		60,					// Button width
		25,					// Button height
		hwnd,				// Parent window
		(HMENU)IDI_PASSWORDBUTTON,	// No menu.
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);				// Pointer not needed.

	// Create a label for the number field
	HWND hwndNumberdLabel = CreateWindow(
		"STATIC",
		"Number Input", // This is the text that automatically gets appears when the element loads.
		WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER,
		150, // x position
		200, // y position
		110, // Width
		20, // Height
		hwnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);

	// Create a number field
	hwndNumberInput = CreateWindow(
		"EDIT",
		"123", // This is the text that automatically gets appears when the element loads.
		WS_VISIBLE | WS_CHILD | ES_LEFT | WS_BORDER | ES_NUMBER,
		150, // x position
		230, // y position
		100, // Width
		25, // Height
		hwnd,
		NULL,
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);

	// Create a button for the password field
	HWND hwndNumberButton = CreateWindow(
		TEXT("BUTTON"),		// Predefined class; Unicode assumed
		TEXT("Hit me!"),			// Button text
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles
		150,					// x position
		270,					// y position
		60,					// Button width
		25,					// Button height
		hwnd,				// Parent window
		(HMENU)IDI_NUMBERBUTTON,	// No menu.
		(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
		NULL);				// Pointer not needed.

	/* Make the window visible on the screen */
	ShowWindow (hwnd, nFunsterStil);

	/* Run the message loop. It will run until GetMessage() returns 0 */
	while (GetMessage (&messages, NULL, 0, 0))
	{
		/* Translate virtual-key messages into character messages */
		TranslateMessage(&messages);
		/* Send message to WindowProcedure */
		DispatchMessage(&messages);
	}

	/* The program return-value is 0 - The value that PostQuitMessage() gave */
	return messages.wParam;
}

// Copies the text from the text box to the label
void copyText()
{
	int textLength = GetWindowTextLength(hwndTextBox);
	if (textLength > 0)
	{
		// Get the text from the text box
		int bufferLength = textLength + 1;
		char textBuffer[bufferLength];
		GetWindowText(hwndTextBox, textBuffer, bufferLength);

		// Set the text on the label
		SetWindowText(hwndLabel, textBuffer);
	}
}

// Copies the text from the password field to the label
void copyPasswordText()
{
	int textLength = GetWindowTextLength(hwndPasswordInput);
	if (textLength > 0)
	{
		// Get the text from the text box
		int bufferLength = textLength + 1;
		char textBuffer[bufferLength];
		GetWindowText(hwndPasswordInput, textBuffer, bufferLength);

		// Set the text on the label
		SetWindowText(hwndLabel, textBuffer);
	}
}

// Copies the text from the number field to the label
void copyNumberText()
{
	int textLength = GetWindowTextLength(hwndNumberInput);
	if (textLength > 0)
	{
		// Get the text from the text box
		int bufferLength = textLength + 1;
		char textBuffer[bufferLength];
		GetWindowText(hwndNumberInput, textBuffer, bufferLength);

		// Set the text on the label
		SetWindowText(hwndLabel, textBuffer);
	}
}

/*  This function is called by the Windows function DispatchMessage()  */
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)				  /* handle the messages */
	{
		case WM_COMMAND: // File Menu commands
			switch(LOWORD(wParam))
			{
				case IDM_FILE_EXIT: // Exit command
					 PostMessage(hwnd, WM_CLOSE, 0, 0); // Send a message to terminate the app
				break;
				case IDI_BUTTON: // Button Click
					copyText();
					// Create a popup
					MessageBox(NULL, TEXT("You clicked the button!"), TEXT("Message"), MB_OK);
				break;
				case IDI_PASSWORDBUTTON: // Button Click
					copyPasswordText();
					// Create a popup
					MessageBox(NULL, TEXT("You clicked the password button!"), TEXT("Message"), MB_OK);
				break;
				case IDI_NUMBERBUTTON: // Button Click
					copyNumberText();
					// Create a popup
					MessageBox(NULL, TEXT("You clicked the number button!"), TEXT("Message"), MB_OK);
				break;
			}
			break;
		case WM_DESTROY:
			PostQuitMessage (0);	   /* send a WM_QUIT to the message queue */
			break;
		default:					  /* for messages that we don't deal with */
			return DefWindowProc (hwnd, message, wParam, lParam);
	}

	return 0;
}
