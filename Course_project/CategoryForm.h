#pragma once
#include <Windows.h>
#include "Category.h" // ���������� ����� Category
#include <vector>  //  ��������� ������ �� std 

namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� CategoryForm
	/// </summary>
	public ref class CategoryForm : public System::Windows::Forms::Form
	{
	public:
		CategoryForm(void);

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~CategoryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxCategoryName;
	protected:
	private: System::Windows::Forms::Button^ buttonCreateCategory;
	private: System::Windows::Forms::TextBox^ textBoxCategoryDescription;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
	public:
		std::vector<Category> GetCategories();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxCategoryName = (gcnew System::Windows::Forms::TextBox());
			this->buttonCreateCategory = (gcnew System::Windows::Forms::Button());
			this->textBoxCategoryDescription = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBoxCategoryName
			// 
			this->textBoxCategoryName->Location = System::Drawing::Point(343, 200);
			this->textBoxCategoryName->Name = L"textBoxCategoryName";
			this->textBoxCategoryName->Size = System::Drawing::Size(100, 22);
			this->textBoxCategoryName->TabIndex = 0;
			// 
			// buttonCreateCategory
			// 
			this->buttonCreateCategory->Location = System::Drawing::Point(356, 356);
			this->buttonCreateCategory->Name = L"buttonCreateCategory";
			this->buttonCreateCategory->Size = System::Drawing::Size(75, 23);
			this->buttonCreateCategory->TabIndex = 1;
			this->buttonCreateCategory->Text = L"button1";
			this->buttonCreateCategory->UseVisualStyleBackColor = true;
			this->buttonCreateCategory->Click += gcnew System::EventHandler(this, &CategoryForm::buttonCreateCategory_Click);
			// 
			// textBoxCategoryDescription
			// 
			this->textBoxCategoryDescription->Location = System::Drawing::Point(539, 200);
			this->textBoxCategoryDescription->Name = L"textBoxCategoryDescription";
			this->textBoxCategoryDescription->Size = System::Drawing::Size(100, 22);
			this->textBoxCategoryDescription->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(505, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
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
			this->menuStrip1->Size = System::Drawing::Size(1201, 28);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(120, 24);
			this->����������ToolStripMenuItem->Text = L"���������� ";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->��������������ToolStripMenuItem->Text = L"��������� �����";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &CategoryForm::��������������ToolStripMenuItem_Click);
			// 
			// CategoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1201, 658);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxCategoryDescription);
			this->Controls->Add(this->buttonCreateCategory);
			this->Controls->Add(this->textBoxCategoryName);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"CategoryForm";
			this->Text = L"CategoryForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCreateCategory_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
