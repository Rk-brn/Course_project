#pragma once
#include "AccountForm.h"
#include "Table_Category_TransactionForm.h"
#include "CurrencyConverterForm.h"
#include "AccountAnalyticsForm.h"
namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� Account_TableForm
	/// </summary>
	public ref class Account_TableForm : public System::Windows::Forms::Form
	{
	public:
		Account_TableForm(void);

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Account_TableForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonLoadTransactions;
	private: System::Windows::Forms::ComboBox^ comboBoxAccounts;
	private: System::Windows::Forms::DataGridView^ dataGridViewTransactions;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::Label^ labelAccounts;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button_del_ac;
	private: System::Windows::Forms::Button^ button_change_ac;

	private: System::Windows::Forms::Label^ label_del_ch;
	private: System::Windows::Forms::ComboBox^ comboBox_del_ch_ac;

	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;

	private:
		void LoadAccountsToDataGridView();
		int flag_edit_ac = 0;
		int flag_del_ac = 0;
		int table_transaction = 0;
		void UpdateTransactionAccount(const std::string& oldAccountName, const std::string& newAccountName, bool updateAll);
		void SaveUpdatedAccountToFile(const std::string& accountName, const std::string& newBalance, const std::string& newTransactionCount, const std::string& newDescription);
		void LoadAccountsToComboBox();
		void LoadAccountsToComboBox_del();
		void LoadTransactionsForAccount(const std::string& accountName);

		void UpdateAccountData(const std::string& accountName, int newTransactionCount);
		void UpdateBalancesFromTransactions();
		int GetBalanceFromTransactions(const std::string& accountName);
		bool deleteTransactions = false;
		void DeleteAccountTransactions(const std::string& accountName, bool deleteTransactions);
		void DeleteAccountFromFile(const std::string& accountName);
	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->labelAccounts = (gcnew System::Windows::Forms::Label());
			this->buttonLoadTransactions = (gcnew System::Windows::Forms::Button());
			this->comboBoxAccounts = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridViewTransactions = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox_del_ch_ac = (gcnew System::Windows::Forms::ComboBox());
			this->label_del_ch = (gcnew System::Windows::Forms::Label());
			this->button_del_ac = (gcnew System::Windows::Forms::Button());
			this->button_change_ac = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTransactions))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(336, 58);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(639, 220);
			this->dataGridView1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->�����������ToolStripMenuItem,
					this->������������������ToolStripMenuItem, this->�����������ToolStripMenuItem, this->���������ToolStripMenuItem, this->����������ToolStripMenuItem,
					this->��������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1286, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->�����������ToolStripMenuItem1,
					this->�����������������ToolStripMenuItem, this->�����������ToolStripMenuItem
			});
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(144, 24);
			this->�����������ToolStripMenuItem->Text = L"������ �� ������";
			// 
			// �����������ToolStripMenuItem1
			// 
			this->�����������ToolStripMenuItem1->Name = L"�����������ToolStripMenuItem1";
			this->�����������ToolStripMenuItem1->Size = System::Drawing::Size(227, 26);
			this->�����������ToolStripMenuItem1->Text = L"������� ����";
			this->�����������ToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Account_TableForm::�����������ToolStripMenuItem1_Click);
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->�����������������ToolStripMenuItem->Text = L"������������� ����";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::�����������������ToolStripMenuItem_Click);
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->�����������ToolStripMenuItem->Text = L"������� ����";
			this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::�����������ToolStripMenuItem_Click);
			// 
			// ������������������ToolStripMenuItem
			// 
			this->������������������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->���������������������ToolStripMenuItem,
					this->����������������������������ToolStripMenuItem
			});
			this->������������������ToolStripMenuItem->Enabled = false;
			this->������������������ToolStripMenuItem->Name = L"������������������ToolStripMenuItem";
			this->������������������ToolStripMenuItem->Size = System::Drawing::Size(179, 24);
			this->������������������ToolStripMenuItem->Text = L"�������� ����������";
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(330, 26);
			this->���������������������ToolStripMenuItem->Text = L"�������� ��� ����������";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::���������������������ToolStripMenuItem_Click);
			// 
			// ����������������������������ToolStripMenuItem
			// 
			this->����������������������������ToolStripMenuItem->Name = L"����������������������������ToolStripMenuItem";
			this->����������������������������ToolStripMenuItem->Size = System::Drawing::Size(330, 26);
			this->����������������������������ToolStripMenuItem->Text = L"�������� ������ ��� ������ �����";
			this->����������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::����������������������������ToolStripMenuItem_Click);
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(119, 24);
			this->�����������ToolStripMenuItem->Text = L"����������� ";
			this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::�����������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(97, 24);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::���������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::����������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(154, 24);
			this->��������������ToolStripMenuItem->Text = L"��������� � ���� ";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::��������������ToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->labelAccounts);
			this->groupBox1->Controls->Add(this->buttonLoadTransactions);
			this->groupBox1->Controls->Add(this->comboBoxAccounts);
			this->groupBox1->Controls->Add(this->dataGridViewTransactions);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 433);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(890, 199);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			this->groupBox1->Visible = false;
			// 
			// labelAccounts
			// 
			this->labelAccounts->AutoSize = true;
			this->labelAccounts->Location = System::Drawing::Point(724, 30);
			this->labelAccounts->Name = L"labelAccounts";
			this->labelAccounts->Size = System::Drawing::Size(142, 20);
			this->labelAccounts->TabIndex = 3;
			this->labelAccounts->Text = L"�������� ����:";
			// 
			// buttonLoadTransactions
			// 
			this->buttonLoadTransactions->Location = System::Drawing::Point(727, 127);
			this->buttonLoadTransactions->Name = L"buttonLoadTransactions";
			this->buttonLoadTransactions->Size = System::Drawing::Size(132, 53);
			this->buttonLoadTransactions->TabIndex = 2;
			this->buttonLoadTransactions->Text = L"button1";
			this->buttonLoadTransactions->UseVisualStyleBackColor = true;
			this->buttonLoadTransactions->Click += gcnew System::EventHandler(this, &Account_TableForm::buttonLoadTransactions_Click);
			// 
			// comboBoxAccounts
			// 
			this->comboBoxAccounts->FormattingEnabled = true;
			this->comboBoxAccounts->Location = System::Drawing::Point(727, 70);
			this->comboBoxAccounts->Name = L"comboBoxAccounts";
			this->comboBoxAccounts->Size = System::Drawing::Size(132, 28);
			this->comboBoxAccounts->TabIndex = 1;
			// 
			// dataGridViewTransactions
			// 
			this->dataGridViewTransactions->AllowUserToAddRows = false;
			this->dataGridViewTransactions->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridViewTransactions->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTransactions->Location = System::Drawing::Point(18, 30);
			this->dataGridViewTransactions->Name = L"dataGridViewTransactions";
			this->dataGridViewTransactions->RowHeadersWidth = 51;
			this->dataGridViewTransactions->RowTemplate->Height = 24;
			this->dataGridViewTransactions->Size = System::Drawing::Size(662, 150);
			this->dataGridViewTransactions->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->comboBox_del_ch_ac);
			this->groupBox2->Controls->Add(this->label_del_ch);
			this->groupBox2->Controls->Add(this->button_del_ac);
			this->groupBox2->Controls->Add(this->button_change_ac);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(908, 433);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(366, 199);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"groupBox2";
			this->groupBox2->Visible = false;
			// 
			// comboBox_del_ch_ac
			// 
			this->comboBox_del_ch_ac->FormattingEnabled = true;
			this->comboBox_del_ch_ac->Location = System::Drawing::Point(30, 93);
			this->comboBox_del_ch_ac->Name = L"comboBox_del_ch_ac";
			this->comboBox_del_ch_ac->Size = System::Drawing::Size(121, 28);
			this->comboBox_del_ch_ac->TabIndex = 4;
			this->comboBox_del_ch_ac->Visible = false;
			// 
			// label_del_ch
			// 
			this->label_del_ch->AutoSize = true;
			this->label_del_ch->Location = System::Drawing::Point(6, 47);
			this->label_del_ch->Name = L"label_del_ch";
			this->label_del_ch->Size = System::Drawing::Size(53, 20);
			this->label_del_ch->TabIndex = 3;
			this->label_del_ch->Text = L"label1";
			this->label_del_ch->Visible = false;
			// 
			// button_del_ac
			// 
			this->button_del_ac->Location = System::Drawing::Point(147, 142);
			this->button_del_ac->Name = L"button_del_ac";
			this->button_del_ac->Size = System::Drawing::Size(169, 38);
			this->button_del_ac->TabIndex = 2;
			this->button_del_ac->Text = L"�������";
			this->button_del_ac->UseVisualStyleBackColor = true;
			this->button_del_ac->Visible = false;
			this->button_del_ac->Click += gcnew System::EventHandler(this, &Account_TableForm::button_del_ac_Click);
			// 
			// button_change_ac
			// 
			this->button_change_ac->Location = System::Drawing::Point(147, 142);
			this->button_change_ac->Name = L"button_change_ac";
			this->button_change_ac->Size = System::Drawing::Size(169, 38);
			this->button_change_ac->TabIndex = 1;
			this->button_change_ac->Text = L"�������������";
			this->button_change_ac->UseVisualStyleBackColor = true;
			this->button_change_ac->Visible = false;
			this->button_change_ac->Click += gcnew System::EventHandler(this, &Account_TableForm::button_change_ac_Click);
			// 
			// Account_TableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1286, 698);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Account_TableForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������ �� �������";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTransactions))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void �����������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonLoadTransactions_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void �����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void �����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void button_del_ac_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_change_ac_Click(System::Object^ sender, System::EventArgs^ e);
};
}
