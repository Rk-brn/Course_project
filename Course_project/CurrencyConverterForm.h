#pragma once
#include <msclr\marshal_cppstd.h>
#include "Currency.h"
#include "CurrencyCreatForm.h"
#include <vector>
#include <string>
namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	/// <summary>
	/// ������ ��� CurrencyConverterForm
	/// </summary>
	public ref class CurrencyConverterForm : public System::Windows::Forms::Form
	{
	public:
		CurrencyConverterForm(void);

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~CurrencyConverterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonConversion;
	protected:
	private: System::Windows::Forms::Button^ button;
	private: System::Windows::Forms::ComboBox^ comboBoxAccounts;
	private: System::Windows::Forms::ComboBox^ comboBoxCurrencies;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridViewConversions;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
		void LoadAccountsToComboBox();
		void LoadCurrenciesToComboBox();

		std::vector<Currency> LoadCurrenciesFromFile();
		void LoadConversionResult(const std::string& accountName, const std::string& currencyName);
		double GetAccountBalance(const std::string& accountName);
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonConversion = (gcnew System::Windows::Forms::Button());
			this->button = (gcnew System::Windows::Forms::Button());
			this->comboBoxAccounts = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxCurrencies = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewConversions = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewConversions))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonConversion
			// 
			this->buttonConversion->Location = System::Drawing::Point(836, 423);
			this->buttonConversion->Name = L"buttonConversion";
			this->buttonConversion->Size = System::Drawing::Size(133, 61);
			this->buttonConversion->TabIndex = 0;
			this->buttonConversion->Text = L"button1";
			this->buttonConversion->UseVisualStyleBackColor = true;
			this->buttonConversion->Click += gcnew System::EventHandler(this, &CurrencyConverterForm::buttonConversion_Click);
			// 
			// button
			// 
			this->button->Location = System::Drawing::Point(833, 534);
			this->button->Name = L"button";
			this->button->Size = System::Drawing::Size(136, 56);
			this->button->TabIndex = 1;
			this->button->Text = L"button2";
			this->button->UseVisualStyleBackColor = true;
			// 
			// comboBoxAccounts
			// 
			this->comboBoxAccounts->FormattingEnabled = true;
			this->comboBoxAccounts->Location = System::Drawing::Point(136, 292);
			this->comboBoxAccounts->Name = L"comboBoxAccounts";
			this->comboBoxAccounts->Size = System::Drawing::Size(121, 24);
			this->comboBoxAccounts->TabIndex = 2;
			// 
			// comboBoxCurrencies
			// 
			this->comboBoxCurrencies->FormattingEnabled = true;
			this->comboBoxCurrencies->Location = System::Drawing::Point(657, 292);
			this->comboBoxCurrencies->Name = L"comboBoxCurrencies";
			this->comboBoxCurrencies->Size = System::Drawing::Size(121, 24);
			this->comboBoxCurrencies->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(428, 99);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(133, 240);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(667, 239);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"label3";
			// 
			// dataGridViewConversions
			// 
			this->dataGridViewConversions->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewConversions->Location = System::Drawing::Point(116, 423);
			this->dataGridViewConversions->Name = L"dataGridViewConversions";
			this->dataGridViewConversions->RowHeadersWidth = 51;
			this->dataGridViewConversions->RowTemplate->Height = 24;
			this->dataGridViewConversions->Size = System::Drawing::Size(597, 150);
			this->dataGridViewConversions->TabIndex = 7;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->������������������������ToolStripMenuItem,
					this->�����������ToolStripMenuItem, this->����������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1028, 28);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ������������������������ToolStripMenuItem
			// 
			this->������������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->��������������ToolStripMenuItem,
					this->�������������������ToolStripMenuItem, this->�������������ToolStripMenuItem
			});
			this->������������������������ToolStripMenuItem->Name = L"������������������������ToolStripMenuItem";
			this->������������������������ToolStripMenuItem->Size = System::Drawing::Size(239, 24);
			this->������������������������ToolStripMenuItem->Text = L"������ � ��������� �� ������";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(247, 26);
			this->��������������ToolStripMenuItem->Text = L"�������� ������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrencyConverterForm::��������������ToolStripMenuItem_Click);
			// 
			// �������������������ToolStripMenuItem
			// 
			this->�������������������ToolStripMenuItem->Name = L"�������������������ToolStripMenuItem";
			this->�������������������ToolStripMenuItem->Size = System::Drawing::Size(247, 26);
			this->�������������������ToolStripMenuItem->Text = L"������������� ������";
			this->�������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrencyConverterForm::�������������������ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(247, 26);
			this->�������������ToolStripMenuItem->Text = L"������� ������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrencyConverterForm::�������������ToolStripMenuItem_Click);
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(125, 24);
			this->�����������ToolStripMenuItem->Text = L"�����������";
			this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrencyConverterForm::�����������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(157, 24);
			this->����������������ToolStripMenuItem->Text = L"��������� � ������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrencyConverterForm::����������������ToolStripMenuItem_Click);
			// 
			// CurrencyConverterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1028, 706);
			this->Controls->Add(this->dataGridViewConversions);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxCurrencies);
			this->Controls->Add(this->comboBoxAccounts);
			this->Controls->Add(this->button);
			this->Controls->Add(this->buttonConversion);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"CurrencyConverterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CurrencyConverterForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewConversions))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonConversion_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
