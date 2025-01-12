#pragma once
#include "AccountForm.h"
#include "Table_Category_TransactionForm.h"
namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ Account_TableForm
	/// </summary>
	public ref class Account_TableForm : public System::Windows::Forms::Form
	{
	public:
		Account_TableForm(void);

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
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
	private: System::Windows::Forms::ToolStripMenuItem^ ñîçäàòüÑ÷¸òToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïğîñìîòğÒğàíçàêöèéToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ èíôîğìàöèÿToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonLoadTransactions;
	private: System::Windows::Forms::ComboBox^ comboBoxAccounts;
	private: System::Windows::Forms::DataGridView^ dataGridViewTransactions;
	private: System::Windows::Forms::ToolStripMenuItem^ âåğíóòüñÿÂÌåíşToolStripMenuItem;

	private:
		void LoadAccountsToDataGridView();


		void LoadAccountsToComboBox();
		void LoadTransactionsForAccount(const std::string& accountName);

		void UpdateAccountData(const std::string& accountName, int newTransactionCount);
		void UpdateBalancesFromTransactions();
		int GetBalanceFromTransactions(const std::string& accountName);

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òğåáóåìûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà — íå èçìåíÿéòå 
		/// ñîäåğæèìîå ıòîãî ìåòîäà ñ ïîìîùüş ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ñîçäàòüÑ÷¸òToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïğîñìîòğÒğàíçàêöèéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èíôîğìàöèÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âåğíóòüñÿÂÌåíşToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonLoadTransactions = (gcnew System::Windows::Forms::Button());
			this->comboBoxAccounts = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridViewTransactions = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTransactions))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(58, 77);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(725, 298);
			this->dataGridView1->TabIndex = 0;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ñîçäàòüÑ÷¸òToolStripMenuItem,
					this->ïğîñìîòğÒğàíçàêöèéToolStripMenuItem, this->èíôîğìàöèÿToolStripMenuItem, this->âåğíóòüñÿÂÌåíşToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1286, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ñîçäàòüÑ÷¸òToolStripMenuItem
			// 
			this->ñîçäàòüÑ÷¸òToolStripMenuItem->Name = L"ñîçäàòüÑ÷¸òToolStripMenuItem";
			this->ñîçäàòüÑ÷¸òToolStripMenuItem->Size = System::Drawing::Size(111, 24);
			this->ñîçäàòüÑ÷¸òToolStripMenuItem->Text = L"Ñîçäàòü ñ÷¸ò";
			this->ñîçäàòüÑ÷¸òToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::ñîçäàòüÑ÷¸òToolStripMenuItem_Click);
			// 
			// ïğîñìîòğÒğàíçàêöèéToolStripMenuItem
			// 
			this->ïğîñìîòğÒğàíçàêöèéToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem,
					this->ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem
			});
			this->ïğîñìîòğÒğàíçàêöèéToolStripMenuItem->Name = L"ïğîñìîòğÒğàíçàêöèéToolStripMenuItem";
			this->ïğîñìîòğÒğàíçàêöèéToolStripMenuItem->Size = System::Drawing::Size(179, 24);
			this->ïğîñìîòğÒğàíçàêöèéToolStripMenuItem->Text = L"Ïğîñìîòğ òğàíçàêöèé";
			// 
			// ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem
			// 
			this->ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem->Name = L"ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem";
			this->ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem->Size = System::Drawing::Size(330, 26);
			this->ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem->Text = L"Ïîêàçàòü âñå òğàíçàêöèè";
			this->ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem_Click);
			// 
			// ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem
			// 
			this->ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem->Name = L"ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem";
			this->ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem->Size = System::Drawing::Size(330, 26);
			this->ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem->Text = L"Ïîêàçàòü òîëüêî äëÿ îäíîãî ñ÷¸òà";
			this->ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem_Click);
			// 
			// èíôîğìàöèÿToolStripMenuItem
			// 
			this->èíôîğìàöèÿToolStripMenuItem->Name = L"èíôîğìàöèÿToolStripMenuItem";
			this->èíôîğìàöèÿToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->èíôîğìàöèÿToolStripMenuItem->Text = L"Èíôîğìàöèÿ";
			this->èíôîğìàöèÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::èíôîğìàöèÿToolStripMenuItem_Click);
			// 
			// âåğíóòüñÿÂÌåíşToolStripMenuItem
			// 
			this->âåğíóòüñÿÂÌåíşToolStripMenuItem->Name = L"âåğíóòüñÿÂÌåíşToolStripMenuItem";
			this->âåğíóòüñÿÂÌåíşToolStripMenuItem->Size = System::Drawing::Size(154, 24);
			this->âåğíóòüñÿÂÌåíşToolStripMenuItem->Text = L"Âåğíóòüñÿ â ìåíş ";
			this->âåğíóòüñÿÂÌåíşToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::âåğíóòüñÿÂÌåíşToolStripMenuItem_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonLoadTransactions);
			this->groupBox1->Controls->Add(this->comboBoxAccounts);
			this->groupBox1->Controls->Add(this->dataGridViewTransactions);
			this->groupBox1->Location = System::Drawing::Point(271, 426);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(894, 199);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"groupBox1";
			this->groupBox1->Visible = false;
			// 
			// buttonLoadTransactions
			// 
			this->buttonLoadTransactions->Location = System::Drawing::Point(743, 127);
			this->buttonLoadTransactions->Name = L"buttonLoadTransactions";
			this->buttonLoadTransactions->Size = System::Drawing::Size(122, 53);
			this->buttonLoadTransactions->TabIndex = 2;
			this->buttonLoadTransactions->Text = L"button1";
			this->buttonLoadTransactions->UseVisualStyleBackColor = true;
			this->buttonLoadTransactions->Click += gcnew System::EventHandler(this, &Account_TableForm::buttonLoadTransactions_Click);
			// 
			// comboBoxAccounts
			// 
			this->comboBoxAccounts->FormattingEnabled = true;
			this->comboBoxAccounts->Location = System::Drawing::Point(733, 44);
			this->comboBoxAccounts->Name = L"comboBoxAccounts";
			this->comboBoxAccounts->Size = System::Drawing::Size(132, 24);
			this->comboBoxAccounts->TabIndex = 1;
			// 
			// dataGridViewTransactions
			// 
			this->dataGridViewTransactions->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTransactions->Location = System::Drawing::Point(18, 30);
			this->dataGridViewTransactions->Name = L"dataGridViewTransactions";
			this->dataGridViewTransactions->RowHeadersWidth = 51;
			this->dataGridViewTransactions->RowTemplate->Height = 24;
			this->dataGridViewTransactions->Size = System::Drawing::Size(662, 150);
			this->dataGridViewTransactions->TabIndex = 0;
			// 
			// Account_TableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1286, 698);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Account_TableForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Account_TableForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTransactions))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ñîçäàòüÑ÷¸òToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîêàçàòüÂñåÒğàíçàêöèèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ïîêàçàòüÒîëüêîÄëÿÎäíîãîÑ÷¸òàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonLoadTransactions_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void èíôîğìàöèÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void âåğíóòüñÿÂÌåíşToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
