#pragma once
#include "Account_TableForm.h"
namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button_start;
	private: System::Windows::Forms::Button^ button_inf;
	private: System::Windows::Forms::Button^ button_out;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->button_inf = (gcnew System::Windows::Forms::Button());
			this->button_out = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(420, 182);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(136, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Добро пожаловать!";
			// 
			// button_start
			// 
			this->button_start->Location = System::Drawing::Point(397, 240);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(178, 23);
			this->button_start->TabIndex = 1;
			this->button_start->Text = L"Запуск программы";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &MyForm::button_start_Click);
			// 
			// button_inf
			// 
			this->button_inf->Location = System::Drawing::Point(397, 300);
			this->button_inf->Name = L"button_inf";
			this->button_inf->Size = System::Drawing::Size(178, 23);
			this->button_inf->TabIndex = 2;
			this->button_inf->Text = L"Информация";
			this->button_inf->UseVisualStyleBackColor = true;
			this->button_inf->Click += gcnew System::EventHandler(this, &MyForm::button_inf_Click);
			// 
			// button_out
			// 
			this->button_out->Location = System::Drawing::Point(397, 370);
			this->button_out->Name = L"button_out";
			this->button_out->Size = System::Drawing::Size(178, 23);
			this->button_out->TabIndex = 3;
			this->button_out->Text = L"Выход";
			this->button_out->UseVisualStyleBackColor = true;
			this->button_out->Click += gcnew System::EventHandler(this, &MyForm::button_out_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1051, 632);
			this->Controls->Add(this->button_out);
			this->Controls->Add(this->button_inf);
			this->Controls->Add(this->button_start);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Главный экран";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_start_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_inf_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_out_Click(System::Object^ sender, System::EventArgs^ e);
};
}
