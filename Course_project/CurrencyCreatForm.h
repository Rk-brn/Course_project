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
	/// ������ ��� CurrencyCreatForm
	/// </summary>
	public ref class CurrencyCreatForm : public System::Windows::Forms::Form
	{
	public:
		CurrencyCreatForm(void);

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~CurrencyCreatForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:

	public: System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Label^ label_Name;
			System::Windows::Forms::Label^ label_Rate;
			System::Windows::Forms::TextBox^ textBoxCurrencyName;
			System::Windows::Forms::TextBox^ textBoxCurrencyRate;
			System::Windows::Forms::Button^ buttonCreatCurrency;
			System::Windows::Forms::MenuStrip^ menuStrip1;
			System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
			System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;

			System::Windows::Forms::Button^ button_EditCurrency;
			System::Windows::Forms::Button^ button_DelCurrency;
			System::Windows::Forms::ComboBox^ comboBoxCurrencies;
			System::Windows::Forms::GroupBox^ groupBox1;
			System::Windows::Forms::DataGridView^ dataGridViewCurrencies;
	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
		bool isEditing = false;
		bool isDeleting = false;
		int rowIndexToEdit = -1;
		System::String^ currencyFilePath;
		bool isChanged = false;

		void LoadCurrenciesToDataGridView();
		void LoadCurrenciesToComboBoxes();
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label_Name = (gcnew System::Windows::Forms::Label());
			this->label_Rate = (gcnew System::Windows::Forms::Label());
			this->textBoxCurrencyName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCurrencyRate = (gcnew System::Windows::Forms::TextBox());
			this->buttonCreatCurrency = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button_EditCurrency = (gcnew System::Windows::Forms::Button());
			this->button_DelCurrency = (gcnew System::Windows::Forms::Button());
			this->comboBoxCurrencies = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridViewCurrencies = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCurrencies))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(352, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"�������� ����� ������";
			// 
			// label_Name
			// 
			this->label_Name->AutoSize = true;
			this->label_Name->Location = System::Drawing::Point(125, 214);
			this->label_Name->Name = L"label_Name";
			this->label_Name->Size = System::Drawing::Size(346, 17);
			this->label_Name->TabIndex = 1;
			this->label_Name->Text = L"������� �������� ����� ������ (��������, USD):";
			// 
			// label_Rate
			// 
			this->label_Rate->AutoSize = true;
			this->label_Rate->Location = System::Drawing::Point(125, 379);
			this->label_Rate->Name = L"label_Rate";
			this->label_Rate->Size = System::Drawing::Size(448, 17);
			this->label_Rate->TabIndex = 2;
			this->label_Rate->Text = L"������� ���� ����� ������ � ����� (��������, 1 USD = 110 ���):";
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
			this->buttonCreatCurrency->Text = L"������� ������!";
			this->buttonCreatCurrency->UseVisualStyleBackColor = true;
			this->buttonCreatCurrency->Click += gcnew System::EventHandler(this, &CurrencyCreatForm::buttonCreatCurrency_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����������ToolStripMenuItem,
					this->��������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(829, 28);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrencyCreatForm::����������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->��������������ToolStripMenuItem->Text = L"��������� �����";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &CurrencyCreatForm::��������������ToolStripMenuItem_Click);
			// 
			// button_EditCurrency
			// 
			this->button_EditCurrency->Location = System::Drawing::Point(257, 60);
			this->button_EditCurrency->Name = L"button_EditCurrency";
			this->button_EditCurrency->Size = System::Drawing::Size(75, 23);
			this->button_EditCurrency->TabIndex = 7;
			this->button_EditCurrency->Text = L"�������������";
			this->button_EditCurrency->UseVisualStyleBackColor = true;
			this->button_EditCurrency->Visible = false;
			this->button_EditCurrency->Click += gcnew System::EventHandler(this, &CurrencyCreatForm::button_EditCurrency_Click);
			// 
			// button_DelCurrency
			// 
			this->button_DelCurrency->Location = System::Drawing::Point(348, 60);
			this->button_DelCurrency->Name = L"button_DelCurrency";
			this->button_DelCurrency->Size = System::Drawing::Size(75, 23);
			this->button_DelCurrency->TabIndex = 8;
			this->button_DelCurrency->Text = L"�������";
			this->button_DelCurrency->UseVisualStyleBackColor = true;
			this->button_DelCurrency->Visible = false;
			this->button_DelCurrency->Click += gcnew System::EventHandler(this, &CurrencyCreatForm::button_DelCurrency_Click);
			// 
			// comboBoxCurrencies
			// 
			this->comboBoxCurrencies->FormattingEnabled = true;
			this->comboBoxCurrencies->Location = System::Drawing::Point(35, 21);
			this->comboBoxCurrencies->Name = L"comboBoxCurrencies";
			this->comboBoxCurrencies->Size = System::Drawing::Size(121, 24);
			this->comboBoxCurrencies->TabIndex = 9;
			this->comboBoxCurrencies->Visible = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dataGridViewCurrencies);
			this->groupBox1->Controls->Add(this->comboBoxCurrencies);
			this->groupBox1->Controls->Add(this->button_EditCurrency);
			this->groupBox1->Controls->Add(this->button_DelCurrency);
			this->groupBox1->Location = System::Drawing::Point(206, 195);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(467, 247);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			this->groupBox1->Visible = false;
			// 
			// dataGridViewCurrencies
			// 
			this->dataGridViewCurrencies->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewCurrencies->Location = System::Drawing::Point(35, 105);
			this->dataGridViewCurrencies->Name = L"dataGridViewCurrencies";
			this->dataGridViewCurrencies->RowHeadersWidth = 51;
			this->dataGridViewCurrencies->RowTemplate->Height = 24;
			this->dataGridViewCurrencies->Size = System::Drawing::Size(388, 106);
			this->dataGridViewCurrencies->TabIndex = 10;
			this->dataGridViewCurrencies->Visible = false;
			// 
			// CurrencyCreatForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(829, 622);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->buttonCreatCurrency);
			this->Controls->Add(this->textBoxCurrencyRate);
			this->Controls->Add(this->textBoxCurrencyName);
			this->Controls->Add(this->label_Rate);
			this->Controls->Add(this->label_Name);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"CurrencyCreatForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CurrencyCreatForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCurrencies))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCreatCurrency_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_EditCurrency_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_DelCurrency_Click(System::Object^ sender, System::EventArgs^ e);
};
}
