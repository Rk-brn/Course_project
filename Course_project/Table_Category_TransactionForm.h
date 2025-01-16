#pragma once

#include "Category.h"
#include "Transaction.h"
#include "CategoryForm.h" 
#include "TransactionForm.h"
#include "SearchTransactionForm.h"

#include <Windows.h>

namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Table_Category_TransactionForm
	/// </summary>
	public ref class Table_Category_TransactionForm : public System::Windows::Forms::Form
	{
	public:
		Table_Category_TransactionForm();

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Table_Category_TransactionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::GroupBox^ groupBox_prosmotr_category;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridViewTransactions;
	private: System::Windows::Forms::GroupBox^ groupBox_edit_del_tran;
	private: System::Windows::Forms::Button^ button_edit_del_tr;
	private: System::Windows::Forms::Button^ button_changed_tr;
	private: System::Windows::Forms::Label^ label_cat;
	private: System::Windows::Forms::Label^ label_del_ch_tr;
	private: System::Windows::Forms::TextBox^ textBoxdel_cat;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBox_edit_del_tr;


	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
		int flag_prosmotr = 0;
		int flag_del = 0;
		int flag_edit = 0;
		void LoadCategoriesToDataGridView();
		void LoadTransactionsToDataGridView();
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox_prosmotr_category = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxdel_cat = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridViewTransactions = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox_edit_del_tran = (gcnew System::Windows::Forms::GroupBox());
			this->button_changed_tr = (gcnew System::Windows::Forms::Button());
			this->button_edit_del_tr = (gcnew System::Windows::Forms::Button());
			this->textBox_edit_del_tr = (gcnew System::Windows::Forms::TextBox());
			this->label_cat = (gcnew System::Windows::Forms::Label());
			this->label_del_ch_tr = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox_prosmotr_category->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTransactions))->BeginInit();
			this->groupBox_edit_del_tran->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(27, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(314, 160);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(382, 149);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(217, 48);
			this->button1->TabIndex = 1;
			this->button1->Text = L"�������� ���������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(388, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(211, 48);
			this->button2->TabIndex = 2;
			this->button2->Text = L"������� ���������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::button2_Click);
			// 
			// groupBox_prosmotr_category
			// 
			this->groupBox_prosmotr_category->Controls->Add(this->label_cat);
			this->groupBox_prosmotr_category->Controls->Add(this->textBoxdel_cat);
			this->groupBox_prosmotr_category->Controls->Add(this->button1);
			this->groupBox_prosmotr_category->Controls->Add(this->button2);
			this->groupBox_prosmotr_category->Controls->Add(this->dataGridView1);
			this->groupBox_prosmotr_category->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->groupBox_prosmotr_category->Location = System::Drawing::Point(50, 415);
			this->groupBox_prosmotr_category->Name = L"groupBox_prosmotr_category";
			this->groupBox_prosmotr_category->Size = System::Drawing::Size(629, 233);
			this->groupBox_prosmotr_category->TabIndex = 3;
			this->groupBox_prosmotr_category->TabStop = false;
			this->groupBox_prosmotr_category->Text = L"�������� ���������";
			this->groupBox_prosmotr_category->Visible = false;
			// 
			// textBoxdel_cat
			// 
			this->textBoxdel_cat->Location = System::Drawing::Point(370, 79);
			this->textBoxdel_cat->Name = L"textBoxdel_cat";
			this->textBoxdel_cat->Size = System::Drawing::Size(110, 27);
			this->textBoxdel_cat->TabIndex = 3;
			this->textBoxdel_cat->Visible = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->������������������ToolStripMenuItem,
					this->���������������������ToolStripMenuItem, this->�������������������ToolStripMenuItem, this->�������������ToolStripMenuItem,
					this->�����������������ToolStripMenuItem, this->�����ToolStripMenuItem, this->����������ToolStripMenuItem, this->���������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1399, 30);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ������������������ToolStripMenuItem
			// 
			this->������������������ToolStripMenuItem->Name = L"������������������ToolStripMenuItem";
			this->������������������ToolStripMenuItem->Size = System::Drawing::Size(178, 26);
			this->������������������ToolStripMenuItem->Text = L"�������� ����������";
			this->������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::������������������ToolStripMenuItem_Click);
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(213, 26);
			this->���������������������ToolStripMenuItem->Text = L"�������� ������ �������";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::���������������������ToolStripMenuItem_Click);
			// 
			// �������������������ToolStripMenuItem
			// 
			this->�������������������ToolStripMenuItem->Name = L"�������������������ToolStripMenuItem";
			this->�������������������ToolStripMenuItem->Size = System::Drawing::Size(177, 26);
			this->�������������������ToolStripMenuItem->Text = L"������������� ������";
			this->�������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::�������������������ToolStripMenuItem_Click);
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�����������������ToolStripMenuItem,
					this->����������������ToolStripMenuItem
			});
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(131, 26);
			this->�������������ToolStripMenuItem->Text = L"������� ������";
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(236, 26);
			this->�����������������ToolStripMenuItem->Text = L"������� ����������";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::�����������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(236, 26);
			this->����������������ToolStripMenuItem->Text = L"������� ���������";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::����������������ToolStripMenuItem_Click);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(173, 26);
			this->�����������������ToolStripMenuItem->Text = L"�������� ��������� ";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::�����������������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(70, 26);
			this->�����ToolStripMenuItem->Text = L"����� ";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::�����ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(116, 26);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::����������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(145, 26);
			this->���������������ToolStripMenuItem->Text = L"��������� � �����";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::���������������ToolStripMenuItem_Click);
			// 
			// dataGridViewTransactions
			// 
			this->dataGridViewTransactions->AllowUserToAddRows = false;
			this->dataGridViewTransactions->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridViewTransactions->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTransactions->Location = System::Drawing::Point(240, 51);
			this->dataGridViewTransactions->Name = L"dataGridViewTransactions";
			this->dataGridViewTransactions->RowHeadersWidth = 51;
			this->dataGridViewTransactions->RowTemplate->Height = 24;
			this->dataGridViewTransactions->Size = System::Drawing::Size(898, 314);
			this->dataGridViewTransactions->TabIndex = 5;
			// 
			// groupBox_edit_del_tran
			// 
			this->groupBox_edit_del_tran->Controls->Add(this->label_del_ch_tr);
			this->groupBox_edit_del_tran->Controls->Add(this->button_changed_tr);
			this->groupBox_edit_del_tran->Controls->Add(this->button_edit_del_tr);
			this->groupBox_edit_del_tran->Controls->Add(this->textBox_edit_del_tr);
			this->groupBox_edit_del_tran->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->groupBox_edit_del_tran->Location = System::Drawing::Point(872, 415);
			this->groupBox_edit_del_tran->Name = L"groupBox_edit_del_tran";
			this->groupBox_edit_del_tran->Size = System::Drawing::Size(448, 233);
			this->groupBox_edit_del_tran->TabIndex = 6;
			this->groupBox_edit_del_tran->TabStop = false;
			this->groupBox_edit_del_tran->Text = L"groupBox1";
			this->groupBox_edit_del_tran->Visible = false;
			// 
			// button_changed_tr
			// 
			this->button_changed_tr->Location = System::Drawing::Point(242, 136);
			this->button_changed_tr->Name = L"button_changed_tr";
			this->button_changed_tr->Size = System::Drawing::Size(200, 75);
			this->button_changed_tr->TabIndex = 2;
			this->button_changed_tr->Text = L"button3";
			this->button_changed_tr->UseVisualStyleBackColor = true;
			this->button_changed_tr->Visible = false;
			this->button_changed_tr->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::button_changed_tr_Click);
			// 
			// button_edit_del_tr
			// 
			this->button_edit_del_tr->Location = System::Drawing::Point(242, 136);
			this->button_edit_del_tr->Name = L"button_edit_del_tr";
			this->button_edit_del_tr->Size = System::Drawing::Size(200, 75);
			this->button_edit_del_tr->TabIndex = 1;
			this->button_edit_del_tr->Text = L"button3";
			this->button_edit_del_tr->UseVisualStyleBackColor = true;
			this->button_edit_del_tr->Visible = false;
			this->button_edit_del_tr->Click += gcnew System::EventHandler(this, &Table_Category_TransactionForm::button_edit_del_tr_Click);
			// 
			// textBox_edit_del_tr
			// 
			this->textBox_edit_del_tr->Location = System::Drawing::Point(36, 79);
			this->textBox_edit_del_tr->Name = L"textBox_edit_del_tr";
			this->textBox_edit_del_tr->Size = System::Drawing::Size(100, 27);
			this->textBox_edit_del_tr->TabIndex = 0;
			this->textBox_edit_del_tr->Visible = false;
			// 
			// label_cat
			// 
			this->label_cat->AutoSize = true;
			this->label_cat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_cat->Location = System::Drawing::Point(366, 46);
			this->label_cat->Name = L"label_cat";
			this->label_cat->Size = System::Drawing::Size(247, 20);
			this->label_cat->TabIndex = 4;
			this->label_cat->Text = L"�������� ����� ���������:";
			this->label_cat->Visible = false;
			// 
			// label_del_ch_tr
			// 
			this->label_del_ch_tr->AutoSize = true;
			this->label_del_ch_tr->Location = System::Drawing::Point(36, 37);
			this->label_del_ch_tr->Name = L"label_del_ch_tr";
			this->label_del_ch_tr->Size = System::Drawing::Size(53, 20);
			this->label_del_ch_tr->TabIndex = 3;
			this->label_del_ch_tr->Text = L"�������� ����� ����������:";
			// 
			// Table_Category_TransactionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1399, 696);
			this->Controls->Add(this->groupBox_edit_del_tran);
			this->Controls->Add(this->dataGridViewTransactions);
			this->Controls->Add(this->groupBox_prosmotr_category);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Table_Category_TransactionForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox_prosmotr_category->ResumeLayout(false);
			this->groupBox_prosmotr_category->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTransactions))->EndInit();
			this->groupBox_edit_del_tran->ResumeLayout(false);
			this->groupBox_edit_del_tran->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void �����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button_edit_del_tr_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_changed_tr_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
