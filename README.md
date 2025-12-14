# ProjectBase64
Base64 Encoder/Decoder

Запуск невозможен без .NET Framework 4.7.2
Перед компиляцией кода закинуть в libs распакованный boost_1_90_0
Убедитесь, что ваш Visual Studio имеет разработку классических приложений на C++ с отдельными компонентами:
1. Поддержка С++/CLI для Build Tools v143 (последняя версия)
3. Пакет SDK для .NET Framework 4.8
4. Пакет нацеливания для платформы .NET Framework 4.7.2

При создании проекта был создан пустой проект CLR (.NET Framework)
Добавлен элемент Visual C++ -> ИП -> "Форма Windows Forms" - это стало в будущем WinForm.h

Путь к библиотеке Boost в C/C++ в общем прописан так: $(SolutionDir)libs\boost_1_90_0;
