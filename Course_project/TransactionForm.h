#pragma once
#include "Category.h"
#include "Transaction.h"
#include "CategoryForm.h"
#include <vector>
namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;
	/// <summary>
	/// ������ ��� TransactionForm
	/// </summary>
	// ��������� ����� CategoryForm
	std::vector<Transaction> transactions;

	public ref class TransactionForm : public System::Windows::Forms::Form
	{
	public:
		TransactionForm(void);

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~TransactionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_TransactionCreat;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_TransactionText;
	private: System::Windows::Forms::TextBox^ textBox_TransactionAmount;


	private: System::Windows::Forms::ComboBox^ comboBox_TransactionType;
	private: System::Windows::Forms::ComboBox^ comboBox_Category;


	private: System::Windows::Forms::MaskedTextBox^ maskedTextBox_DataType;



	private:
		Courseproject::CategoryForm^ categoryForm;
	
		System::String^ transactionFilePath;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
		   System::String^ categoryFilePath;

		std::vector<Transaction> LoadTransactionsFromFile();

		// �������� ��������� �� �����
		void LoadCategoriesFromFile();
		// ������� ��� ���������� ���������� � ����
		void SaveTransactionsToFile();
	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

	//public:
	//	//����� ��� ��������� ������� ����������
	//	std::vector<Transaction>& getTransactions();
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_TransactionCreat = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_TransactionText = (gcnew System::Windows::Forms::TextBox());
			this->textBox_TransactionAmount = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_TransactionType = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_Category = (gcnew System::Windows::Forms::ComboBox());
			this->maskedTextBox_DataType = (gcnew System::Windows::Forms::MaskedTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_TransactionCreat
			// 
			this->button_TransactionCreat->Location = System::Drawing::Point(1165, 571);
			this->button_TransactionCreat->Name = L"button_TransactionCreat";
			this->button_TransactionCreat->Size = System::Drawing::Size(177, 58);
			this->button_TransactionCreat->TabIndex = 0;
			this->button_TransactionCreat->Text = L"������� ����������";
			this->button_TransactionCreat->UseVisualStyleBackColor = true;
			this->button_TransactionCreat->Click += gcnew System::EventHandler(this, &TransactionForm::button_TransactionCreat_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(652, 124);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// textBox_TransactionText
			// 
			this->textBox_TransactionText->Location = System::Drawing::Point(287, 339);
			this->textBox_TransactionText->Name = L"textBox_TransactionText";
			this->textBox_TransactionText->Size = System::Drawing::Size(100, 22);
			this->textBox_TransactionText->TabIndex = 2;
			// 
			// textBox_TransactionAmount
			// 
			this->textBox_TransactionAmount->Location = System::Drawing::Point(287, 455);
			this->textBox_TransactionAmount->Name = L"textBox_TransactionAmount";
			this->textBox_TransactionAmount->Size = System::Drawing::Size(100, 22);
			this->textBox_TransactionAmount->TabIndex = 3;
			// 
			// comboBox_TransactionType
			// 
			this->comboBox_TransactionType->FormattingEnabled = true;
			this->comboBox_TransactionType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"�����", L"������" });
			this->comboBox_TransactionType->Location = System::Drawing::Point(633, 455);
			this->comboBox_TransactionType->Name = L"comboBox_TransactionType";
			this->comboBox_TransactionType->Size = System::Drawing::Size(121, 24);
			this->comboBox_TransactionType->TabIndex = 5;
			// 
			// comboBox_Category
			// 
			this->comboBox_Category->FormattingEnabled = true;
			this->comboBox_Category->Location = System::Drawing::Point(925, 379);
			this->comboBox_Category->Name = L"comboBox_Category";
			this->comboBox_Category->Size = System::Drawing::Size(121, 24);
			this->comboBox_Category->TabIndex = 6;
			// 
			// maskedTextBox_DataType
			// 
			this->maskedTextBox_DataType->Location = System::Drawing::Point(633, 339);
			this->maskedTextBox_DataType->Name = L"maskedTextBox_DataType";
			this->maskedTextBox_DataType->Size = System::Drawing::Size(100, 22);
			this->maskedTextBox_DataType->TabIndex = 7;
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
			this->menuStrip1->Size = System::Drawing::Size(1378, 28);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &TransactionForm::����������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->��������������ToolStripMenuItem->Text = L"��������� �����";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &TransactionForm::��������������ToolStripMenuItem_Click);
			// 
			// TransactionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1378, 689);
			this->Controls->Add(this->maskedTextBox_DataType);
			this->Controls->Add(this->comboBox_Category);
			this->Controls->Add(this->comboBox_TransactionType);
			this->Controls->Add(this->textBox_TransactionAmount);
			this->Controls->Add(this->textBox_TransactionText);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_TransactionCreat);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"TransactionForm";
			this->Text = L"TransactionForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_TransactionCreat_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
