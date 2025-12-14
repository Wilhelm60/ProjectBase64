#include "WinForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread] // Однопоточное подразделение для Windows Forms
int WINAPI WinMain( // Альтернатива main() для графических приложений
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd
)
{
    //Включает визуальные стили Windows XP/Vista/7/10/11
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Base64Win::WinForm form;
    Application::Run(% form); // Запуск цикла сообщений

    return 0;
}

