#include "Engine.h"
#include "Resources.h"
#include "StartScreen.h"

// Main -------------------------------------------------------------------------------------------------------------------                                  
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	Engine* engine = new Engine();

	// Configura a janela do jogo -----
	Engine::window->Mode(WINDOWED);
	Engine::window->Size(1280, 720);
	Engine::window->Color(25, 25, 25);
	Engine::window->Title("GrandChains");
	Engine::window->Icon(IDI_ICON);
	Engine::window->Cursor(IDC_CURSOR);
	// --------------------------------

	AllocConsole();
	FILE* fp;
	freopen_s(&fp, "CONOUT$", "w", stdout);

	// Configura dispositivo gr�fico
	engine->graphics->VSync(true);
	// -----------------------------

	// Inicia o jogo -----------------------------
	int status = engine->Start(new StartScreen());
	// -------------------------------------------

	delete engine;
	return status;
}
// ------------------------------------------------------------------------------------------------------------------------

