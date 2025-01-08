#pragma once
#include <Windows.h>
#include "Category.h" 
#include <vector>
#include <string>


namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
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
	private: System::Windows::Forms::Label^ label_new_category;
	private: System::Windows::Forms::MenuStrip^ menuStrip_new_category;


	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^ label_name_category;
	private: System::Windows::Forms::Label^ label_opis_category;
	public:
		System::String^ categoryFilePath;
		// ����� ��� ���������� ��������� � ����
		void SaveCategoriesToFile();
		// ����� ��� �������� ��������� �� �����
		std::vector<Category> LoadCategoriesFromFile();

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
			this->label_new_category = (gcnew System::Windows::Forms::Label());
			this->menuStrip_new_category = (gcnew System::Windows::Forms::MenuStrip());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label_name_category = (gcnew System::Windows::Forms::Label());
			this->label_opis_category = (gcnew System::Windows::Forms::Label());
			this->menuStrip_new_category->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBoxCategoryName
			// 
			this->textBoxCategoryName->Location = System::Drawing::Point(246, 213);
			this->textBoxCategoryName->Name = L"textBoxCategoryName";
			this->textBoxCategoryName->Size = System::Drawing::Size(100, 22);
			this->textBoxCategoryName->TabIndex = 0;
			// 
			// buttonCreateCategory
			// 
			this->buttonCreateCategory->Location = System::Drawing::Point(856, 473);
			this->buttonCreateCategory->Name = L"buttonCreateCategory";
			this->buttonCreateCategory->Size = System::Drawing::Size(236, 64);
			this->buttonCreateCategory->TabIndex = 1;
			this->buttonCreateCategory->Text = L"�������� ���������";
			this->buttonCreateCategory->UseVisualStyleBackColor = true;
			this->buttonCreateCategory->Click += gcnew System::EventHandler(this, &CategoryForm::buttonCreateCategory_Click);
			// 
			// textBoxCategoryDescription
			// 
			this->textBoxCategoryDescription->Location = System::Drawing::Point(246, 393);
			this->textBoxCategoryDescription->Name = L"textBoxCategoryDescription";
			this->textBoxCategoryDescription->Size = System::Drawing::Size(100, 22);
			this->textBoxCategoryDescription->TabIndex = 2;
			// 
			// label_new_category
			// 
			this->label_new_category->AutoSize = true;
			this->label_new_category->Location = System::Drawing::Point(491, 60);
			this->label_new_category->Name = L"label_new_category";
			this->label_new_category->Size = System::Drawing::Size(186, 17);
			this->label_new_category->TabIndex = 3;
			this->label_new_category->Text = L"�������� ����� ���������";
			// 
			// menuStrip_new_category
			// 
			this->menuStrip_new_category->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip_new_category->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����������ToolStripMenuItem,
					this->��������������ToolStripMenuItem
			});
			this->menuStrip_new_category->Location = System::Drawing::Point(0, 0);
			this->menuStrip_new_category->Name = L"menuStrip_new_category";
			this->menuStrip_new_category->Size = System::Drawing::Size(1201, 28);
			this->menuStrip_new_category->TabIndex = 4;
			this->menuStrip_new_category->Text = L"menuStrip1";
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
			// label_name_category
			// 
			this->label_name_category->AutoSize = true;
			this->label_name_category->Location = System::Drawing::Point(246, 147);
			this->label_name_category->Name = L"label_name_category";
			this->label_name_category->Size = System::Drawing::Size(204, 17);
			this->label_name_category->TabIndex = 5;
			this->label_name_category->Text = L"������� �������� ���������:";
			// 
			// label_opis_category
			// 
			this->label_opis_category->AutoSize = true;
			this->label_opis_category->Location = System::Drawing::Point(246, 341);
			this->label_opis_category->Name = L"label_opis_category";
			this->label_opis_category->Size = System::Drawing::Size(201, 17);
			this->label_opis_category->TabIndex = 6;
			this->label_opis_category->Text = L"������� �������� ���������";
			// 
			// CategoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1201, 658);
			this->Controls->Add(this->label_opis_category);
			this->Controls->Add(this->label_name_category);
			this->Controls->Add(this->label_new_category);
			this->Controls->Add(this->textBoxCategoryDescription);
			this->Controls->Add(this->buttonCreateCategory);
			this->Controls->Add(this->textBoxCategoryName);
			this->Controls->Add(this->menuStrip_new_category);
			this->MainMenuStrip = this->menuStrip_new_category;
			this->Name = L"CategoryForm";
			this->Text = L"����� ���������";
			this->menuStrip_new_category->ResumeLayout(false);
			this->menuStrip_new_category->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCreateCategory_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
