////////////////////////////////////////////////////////////////////////////
//	Модуль 		 : WinForm.h
//	Автор		 : Поцелуев Максим Сергеевич
//	Описание     : Графический интерфейс
//  Тестирование и доработка: Джапбаров Ислам Темирбудатович
////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include "Base64.h"
#include "FileManager.h"
#include <msclr/marshal_cppstd.h> // Без нее невозможен обмен данными между .NET и C++

namespace Base64Win {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    // Главная форма приложения
    public ref class WinForm : public System::Windows::Forms::Form
    {
    public:
        WinForm(void)
        {
            InitializeComponent(); // Инициализация элементов формы
        }

    protected:
        ~WinForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // Элементы интерфейса, "^" - дескриптор управляемого объекта
        System::Windows::Forms::TextBox^ txtInput;          // Поле для выбора входного файла
        System::Windows::Forms::TextBox^ txtOutput;         // Поле для выбора выходного файла
        System::Windows::Forms::Button^ btnBrowseInput;     // Кнопка выбора входного файла
        System::Windows::Forms::Button^ btnBrowseOutput;    // Кнопка выбора выходного файла
        System::Windows::Forms::Button^ btnEncode;          // Кнопка кодирования
        System::Windows::Forms::Button^ btnDecode;          // Кнопка декодирования
        System::Windows::Forms::Label^ lblInput;            // Подпись к полю входного файла
        System::Windows::Forms::Label^ lblOutput;           // Подпись к полю выходного файла
        System::Windows::Forms::Label^ lblSignature;        // Подпись внизу окна
        System::Windows::Forms::OpenFileDialog^ openFileDialog;  // Диалог открытия файла
        System::Windows::Forms::SaveFileDialog^ saveFileDialog;  // Диалог сохранения файла

        System::ComponentModel::Container^ components;

// Дизайнерский регион кода
#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->txtInput = (gcnew System::Windows::Forms::TextBox());
            this->txtOutput = (gcnew System::Windows::Forms::TextBox());
            this->btnBrowseInput = (gcnew System::Windows::Forms::Button());
            this->btnBrowseOutput = (gcnew System::Windows::Forms::Button());
            this->btnEncode = (gcnew System::Windows::Forms::Button());
            this->btnDecode = (gcnew System::Windows::Forms::Button());
            this->lblInput = (gcnew System::Windows::Forms::Label());
            this->lblOutput = (gcnew System::Windows::Forms::Label());
            this->lblSignature = (gcnew System::Windows::Forms::Label());
            this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
            this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
            this->SuspendLayout();
            // 
            // txtInput
            // 
            this->txtInput->Location = System::Drawing::Point(12, 20);
            this->txtInput->Name = L"txtInput";
            this->txtInput->Size = System::Drawing::Size(350, 20);
            this->txtInput->TabIndex = 1;
            // 
            // txtOutput
            // 
            this->txtOutput->Location = System::Drawing::Point(12, 70);
            this->txtOutput->Name = L"txtOutput";
            this->txtOutput->Size = System::Drawing::Size(350, 20);
            this->txtOutput->TabIndex = 4;
            // 
            // btnBrowseInput
            // 
            this->btnBrowseInput->Location = System::Drawing::Point(380, 18);
            this->btnBrowseInput->Name = L"btnBrowseInput";
            this->btnBrowseInput->Size = System::Drawing::Size(90, 25);
            this->btnBrowseInput->TabIndex = 2;
            this->btnBrowseInput->Text = L"Обзор...";
            this->btnBrowseInput->Click += gcnew System::EventHandler(this, &WinForm::btnBrowseInput_Click);
            // 
            // btnBrowseOutput
            // 
            this->btnBrowseOutput->Location = System::Drawing::Point(380, 68);
            this->btnBrowseOutput->Name = L"btnBrowseOutput";
            this->btnBrowseOutput->Size = System::Drawing::Size(90, 25);
            this->btnBrowseOutput->TabIndex = 5;
            this->btnBrowseOutput->Text = L"Обзор...";
            this->btnBrowseOutput->Click += gcnew System::EventHandler(this, &WinForm::btnBrowseOutput_Click);
            // 
            // btnEncode
            // 
            this->btnEncode->Location = System::Drawing::Point(12, 120);
            this->btnEncode->Name = L"btnEncode";
            this->btnEncode->Size = System::Drawing::Size(200, 40);
            this->btnEncode->TabIndex = 6;
            this->btnEncode->Text = L"Кодировать Base64";
            this->btnEncode->Click += gcnew System::EventHandler(this, &WinForm::btnEncode_Click);
            // 
            // btnDecode
            // 
            this->btnDecode->Location = System::Drawing::Point(270, 120);
            this->btnDecode->Name = L"btnDecode";
            this->btnDecode->Size = System::Drawing::Size(200, 40);
            this->btnDecode->TabIndex = 7;
            this->btnDecode->Text = L"Декодировать Base64";
            this->btnDecode->Click += gcnew System::EventHandler(this, &WinForm::btnDecode_Click);
            // 
            // lblInput
            // 
            this->lblInput->Location = System::Drawing::Point(12, 0);
            this->lblInput->Name = L"lblInput";
            this->lblInput->Size = System::Drawing::Size(200, 20);
            this->lblInput->TabIndex = 0;
            this->lblInput->Text = L"Выберите исходный файл:";
            // 
            // lblOutput
            // 
            this->lblOutput->Location = System::Drawing::Point(12, 50);
            this->lblOutput->Name = L"lblOutput";
            this->lblOutput->Size = System::Drawing::Size(200, 20);
            this->lblOutput->TabIndex = 3;
            this->lblOutput->Text = L"Выберите файл для сохранения:";
            // 
            // lblSignature
            // 
            this->lblSignature->Location = System::Drawing::Point(12, 180);
            this->lblSignature->Name = L"lblSignature";
            this->lblSignature->Size = System::Drawing::Size(460, 20);
            this->lblSignature->TabIndex = 8;
            this->lblSignature->Text = L"Сделано командой BaseTeam из ИДБ-24-08";
            this->lblSignature->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lblSignature->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.0F, System::Drawing::FontStyle::Italic);
            this->lblSignature->ForeColor = System::Drawing::Color::Gray;
            // 
            // WinForm
            // 
            this->ClientSize = System::Drawing::Size(500, 210);
            this->Controls->Add(this->lblInput);
            this->Controls->Add(this->txtInput);
            this->Controls->Add(this->btnBrowseInput);
            this->Controls->Add(this->lblOutput);
            this->Controls->Add(this->txtOutput);
            this->Controls->Add(this->btnBrowseOutput);
            this->Controls->Add(this->btnEncode);
            this->Controls->Add(this->btnDecode);
            this->Controls->Add(this->lblSignature);
            this->Name = L"WinForm";
            this->Text = L"Base64 Encoder/Decoder";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        // Вспомогательная функция для проверки путей к файлам
        bool ValidateFilePaths() {
            if (String::IsNullOrEmpty(txtInput->Text)) {
                MessageBox::Show("Пожалуйста, выберите входной файл!", "Ошибка",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return false;
            }

            if (String::IsNullOrEmpty(txtOutput->Text)) {
                MessageBox::Show("Пожалуйста, выберите выходной файл!", "Ошибка",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return false;
            }

            return true;
        }

        // Обработчик кнопки выбора входного файла
        System::Void btnBrowseInput_Click(System::Object^ sender, System::EventArgs^ e) {
            openFileDialog->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
            if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                txtInput->Text = openFileDialog->FileName;
        }

        // Обработчик кнопки выбора выходного файла
        System::Void btnBrowseOutput_Click(System::Object^ sender, System::EventArgs^ e) {
            saveFileDialog->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
            if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                txtOutput->Text = saveFileDialog->FileName;
        }

        // Обработчик кнопки кодирования Base64
        System::Void btnEncode_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                // Проверка на пустые пути к файлам
                if (!ValidateFilePaths()) {
                    return;
                }

                // Конвертация пути из managed String^ в std::string
                std::string input = msclr::interop::marshal_as<std::string>(txtInput->Text);
                std::string output = msclr::interop::marshal_as<std::string>(txtOutput->Text);

                // Чтение файла, кодирование и запись результата
                FileManager fm;
                Base64 b;
                std::string text = fm.read(input);
                std::string encoded = b.encode(text);
                fm.write(output, encoded);

                MessageBox::Show("Файл успешно закодирован!", "Успех",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (const std::exception& ex) {
                MessageBox::Show(gcnew String(ex.what()), "Ошибка",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        // Обработчик кнопки декодирования Base64
        System::Void btnDecode_Click(System::Object^ sender, System::EventArgs^ e) {
            try {
                // Проверка на пустые пути к файлам
                if (!ValidateFilePaths()) {
                    return;
                }

                // Конвертация пути из managed String^ в std::string
                std::string input = msclr::interop::marshal_as<std::string>(txtInput->Text);
                std::string output = msclr::interop::marshal_as<std::string>(txtOutput->Text);

                // Чтение файла, декодирование и запись результата
                FileManager fm;
                Base64 b;
                std::string text = fm.read(input);

                // Очищаем и добавляем паддинг
                std::string cleaned = b.cleanBase64(text);
                std::string padded = b.padBase64(cleaned);

                std::string decoded = b.decode(padded);
                fm.write(output, decoded);

                MessageBox::Show("Файл успешно декодирован!", "Успех",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (const std::exception& ex) {
                MessageBox::Show(gcnew String(ex.what()), "Ошибка",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    };
}