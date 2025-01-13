#pragma once
#include <string>
namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CurrencyCreatForm
	/// </summary>
	public ref class CurrencyCreatForm : public System::Windows::Forms::Form
	{
	public:
		CurrencyCreatForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CurrencyCreatForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxCurrencyName;
	private: System::Windows::Forms::TextBox^ textBoxCurrencyRate;
	private: System::Windows::Forms::Button^ buttonCreatCurrency;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ информацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьсяНазадToolStripMenuItem;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxCurrencyName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCurrencyRate = (gcnew System::Windows::Forms::TextBox());
			this->buttonCreatCurrency = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->информацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьсяНазадToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(352, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Создание курса валюты";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(125, 214);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(346, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Введите название новой валюты (например, USD):";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(125, 379);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(448, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Введите курс новой валюты к рублю (например, 1 USD = 110 руб):";
			// 
			// textBoxCurrencyName
			// 
			this->textBoxCurrencyName->Location = System::Drawing::Point(128, 265);
			this->textBoxCurrencyName->Name = L"textBoxCurrencyName";
			this->textBoxCurrencyName->Size = System::Drawing::Size(100, 22);
			this->textBoxCurrencyName->TabIndex = 3;
			this->textBoxCurrencyName->Text = L"USD";
			// 
			// textBoxCurrencyRate
			// 
			this->textBoxCurrencyRate->Location = System::Drawing::Point(128, 439);
			this->textBoxCurrencyRate->Name = L"textBoxCurrencyRate";
			this->textBoxCurrencyRate->Size = System::Drawing::Size(100, 22);
			this->textBoxCurrencyRate->TabIndex = 4;
			this->textBoxCurrencyRate->Text = L"110.00";
			// 
			// buttonCreatCurrency
			// 
			this->buttonCreatCurrency->Location = System::Drawing::Point(577, 501);
			this->buttonCreatCurrency->Name = L"buttonCreatCurrency";
			this->buttonCreatCurrency->Size = System::Drawing::Size(210, 71);
			this->buttonCreatCurrency->TabIndex = 5;
			this->buttonCreatCurrency->Text = L"Создать валюту!";
			this->buttonCreatCurrency->UseVisualStyleBackColor = true;
			this->buttonCreatCurrency->Click += gcnew System::EventHandler(this, &CurrencyCreatForm::buttonCreatCurrency_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->информацияToolStripMenuItem,
					this->вернутьсяНазадToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(829, 28);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// информацияToolStripMenuItem
			// 
			this->информацияToolStripMenuItem->Name = L"информацияToolStripMenuItem";
			this->информацияToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->информацияToolStripMenuItem->Text = L"Информация";
			this->информацияToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrencyCreatForm::информацияToolStripMenuItem_Click);
			// 
			// вернутьсяНазадToolStripMenuItem
			// 
			this->вернутьсяНазадToolStripMenuItem->Name = L"вернутьсяНазадToolStripMenuItem";
			this->вернутьсяНазадToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->вернутьсяНазадToolStripMenuItem->Text = L"Вернуться назад";
			this->вернутьсяНазадToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrencyCreatForm::вернутьсяНазадToolStripMenuItem_Click);
			// 
			// CurrencyCreatForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(829, 622);
			this->Controls->Add(this->buttonCreatCurrency);
			this->Controls->Add(this->textBoxCurrencyRate);
			this->Controls->Add(this->textBoxCurrencyName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"CurrencyCreatForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CurrencyCreatForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCreatCurrency_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void вернутьсяНазадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
