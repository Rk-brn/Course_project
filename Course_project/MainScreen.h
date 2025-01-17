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
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
	private: System::Windows::Forms::Button^ button_game;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->button_inf = (gcnew System::Windows::Forms::Button());
			this->button_out = (gcnew System::Windows::Forms::Button());
			this->button_game = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(260, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(477, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"������� ���� ����������� �����!";
			// 
			// button_start
			// 
			this->button_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_start->Location = System::Drawing::Point(378, 182);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(277, 83);
			this->button_start->TabIndex = 1;
			this->button_start->Text = L"������ ������ � ���������\r\n";
			this->button_start->UseVisualStyleBackColor = true;
			this->button_start->Click += gcnew System::EventHandler(this, &MyForm::button_start_Click);
			// 
			// button_inf
			// 
			this->button_inf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_inf->Location = System::Drawing::Point(378, 408);
			this->button_inf->Name = L"button_inf";
			this->button_inf->Size = System::Drawing::Size(277, 83);
			this->button_inf->TabIndex = 2;
			this->button_inf->Text = L"����������";
			this->button_inf->UseVisualStyleBackColor = true;
			this->button_inf->Click += gcnew System::EventHandler(this, &MyForm::button_inf_Click);
			// 
			// button_out
			// 
			this->button_out->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_out->Location = System::Drawing::Point(378, 515);
			this->button_out->Name = L"button_out";
			this->button_out->Size = System::Drawing::Size(277, 86);
			this->button_out->TabIndex = 3;
			this->button_out->Text = L"�����";
			this->button_out->UseVisualStyleBackColor = true;
			this->button_out->Click += gcnew System::EventHandler(this, &MyForm::button_out_Click);
			// 
			// button_game
			// 
			this->button_game->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_game->Location = System::Drawing::Point(378, 296);
			this->button_game->Name = L"button_game";
			this->button_game->Size = System::Drawing::Size(277, 86);
			this->button_game->TabIndex = 4;
			this->button_game->Text = L"��������������� ���� \"������\"";
			this->button_game->UseVisualStyleBackColor = true;
			this->button_game->Click += gcnew System::EventHandler(this, &MyForm::button_game_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1033, 662);
			this->Controls->Add(this->button_game);
			this->Controls->Add(this->button_out);
			this->Controls->Add(this->button_inf);
			this->Controls->Add(this->button_start);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������� �����";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_start_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_inf_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button_out_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_game_Click(System::Object^ sender, System::EventArgs^ e);
};
}
