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
	/// —водка дл€ AccountForm
	/// </summary>
	public ref class AccountForm : public System::Windows::Forms::Form
	{
	public:
		AccountForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~AccountForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button_creatAccount;
	private: System::Windows::Forms::TextBox^ textBox_name_account;
	private: System::Windows::Forms::TextBox^ textBox_balance_account;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_creatAccount = (gcnew System::Windows::Forms::Button());
			this->textBox_name_account = (gcnew System::Windows::Forms::TextBox());
			this->textBox_balance_account = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(528, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// button_creatAccount
			// 
			this->button_creatAccount->Location = System::Drawing::Point(877, 565);
			this->button_creatAccount->Name = L"button_creatAccount";
			this->button_creatAccount->Size = System::Drawing::Size(226, 73);
			this->button_creatAccount->TabIndex = 1;
			this->button_creatAccount->Text = L"—оздать счЄт";
			this->button_creatAccount->UseVisualStyleBackColor = true;
			this->button_creatAccount->Click += gcnew System::EventHandler(this, &AccountForm::button_creatAccount_Click);
			// 
			// textBox_name_account
			// 
			this->textBox_name_account->Location = System::Drawing::Point(207, 284);
			this->textBox_name_account->Name = L"textBox_name_account";
			this->textBox_name_account->Size = System::Drawing::Size(100, 22);
			this->textBox_name_account->TabIndex = 2;
			// 
			// textBox_balance_account
			// 
			this->textBox_balance_account->Location = System::Drawing::Point(210, 458);
			this->textBox_balance_account->Name = L"textBox_balance_account";
			this->textBox_balance_account->Size = System::Drawing::Size(100, 22);
			this->textBox_balance_account->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(207, 191);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(207, 384);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// AccountForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1143, 691);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox_balance_account);
			this->Controls->Add(this->textBox_name_account);
			this->Controls->Add(this->button_creatAccount);
			this->Controls->Add(this->label1);
			this->Name = L"AccountForm";
			this->Text = L"AccountForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_creatAccount_Click(System::Object^ sender, System::EventArgs^ e);
};
}
