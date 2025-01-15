#pragma once
#include "Account.h"
namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� AccountForm
	/// </summary>
	public ref class AccountForm : public System::Windows::Forms::Form
	{
	public:
		AccountForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~AccountForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_creat_account;
	private: System::Windows::Forms::Label^ label_creat_name_ac;
	private: System::Windows::Forms::Label^ label_creat_des_ac;
	protected:

	protected:


	private: System::Windows::Forms::TextBox^ textBox_name_account;
	private: System::Windows::Forms::TextBox^ textBox_balance_account;
	private: System::Windows::Forms::Button^ button_creat_account;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������ToolStripMenuItem;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
		String^ originalAccountName;
		bool editMode = false;
	public: void SetEditMode(bool editMode);
			void SetAccountData(String^ name, String^ balance, String^ transactionCount, String^ description);
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label_creat_account = (gcnew System::Windows::Forms::Label());
			this->label_creat_name_ac = (gcnew System::Windows::Forms::Label());
			this->label_creat_des_ac = (gcnew System::Windows::Forms::Label());
			this->textBox_name_account = (gcnew System::Windows::Forms::TextBox());
			this->textBox_balance_account = (gcnew System::Windows::Forms::TextBox());
			this->button_creat_account = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_creat_account
			// 
			this->label_creat_account->AutoSize = true;
			this->label_creat_account->Location = System::Drawing::Point(485, 78);
			this->label_creat_account->Name = L"label_creat_account";
			this->label_creat_account->Size = System::Drawing::Size(114, 17);
			this->label_creat_account->TabIndex = 0;
			this->label_creat_account->Text = L"�������� �����";
			// 
			// label_creat_name_ac
			// 
			this->label_creat_name_ac->AutoSize = true;
			this->label_creat_name_ac->Location = System::Drawing::Point(189, 248);
			this->label_creat_name_ac->Name = L"label_creat_name_ac";
			this->label_creat_name_ac->Size = System::Drawing::Size(175, 17);
			this->label_creat_name_ac->TabIndex = 1;
			this->label_creat_name_ac->Text = L"������� �������� �����:";
			// 
			// label_creat_des_ac
			// 
			this->label_creat_des_ac->AutoSize = true;
			this->label_creat_des_ac->Location = System::Drawing::Point(772, 248);
			this->label_creat_des_ac->Name = L"label_creat_des_ac";
			this->label_creat_des_ac->Size = System::Drawing::Size(176, 17);
			this->label_creat_des_ac->TabIndex = 2;
			this->label_creat_des_ac->Text = L"������� �������� �����:";
			// 
			// textBox_name_account
			// 
			this->textBox_name_account->Location = System::Drawing::Point(192, 299);
			this->textBox_name_account->Name = L"textBox_name_account";
			this->textBox_name_account->Size = System::Drawing::Size(100, 22);
			this->textBox_name_account->TabIndex = 3;
			// 
			// textBox_balance_account
			// 
			this->textBox_balance_account->Location = System::Drawing::Point(775, 299);
			this->textBox_balance_account->Name = L"textBox_balance_account";
			this->textBox_balance_account->Size = System::Drawing::Size(100, 22);
			this->textBox_balance_account->TabIndex = 4;
			// 
			// button_creat_account
			// 
			this->button_creat_account->Location = System::Drawing::Point(901, 498);
			this->button_creat_account->Name = L"button_creat_account";
			this->button_creat_account->Size = System::Drawing::Size(211, 67);
			this->button_creat_account->TabIndex = 5;
			this->button_creat_account->Text = L"������� ����!";
			this->button_creat_account->UseVisualStyleBackColor = true;
			this->button_creat_account->Click += gcnew System::EventHandler(this, &AccountForm::button_creat_account_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����������ToolStripMenuItem,
					this->���������������������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1181, 28);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AccountForm::����������ToolStripMenuItem_Click);
			// 
			// ���������������������ToolStripMenuItem
			// 
			this->���������������������ToolStripMenuItem->Name = L"���������������������ToolStripMenuItem";
			this->���������������������ToolStripMenuItem->Size = System::Drawing::Size(201, 24);
			this->���������������������ToolStripMenuItem->Text = L"��������� ����� � ������";
			this->���������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &AccountForm::���������������������ToolStripMenuItem_Click);
			// 
			// AccountForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1181, 656);
			this->Controls->Add(this->button_creat_account);
			this->Controls->Add(this->textBox_balance_account);
			this->Controls->Add(this->textBox_name_account);
			this->Controls->Add(this->label_creat_des_ac);
			this->Controls->Add(this->label_creat_name_ac);
			this->Controls->Add(this->label_creat_account);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"AccountForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AccountForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_creat_account_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ���������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
