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
	/// Сводка для CategoryForm
	/// </summary>
	public ref class CategoryForm : public System::Windows::Forms::Form
	{
	public:
		CategoryForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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


	private: System::Windows::Forms::ToolStripMenuItem^ информацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьсяНазадToolStripMenuItem;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^ label_name_category;
	private: System::Windows::Forms::Label^ label_opis_category;
	public:
		System::String^ categoryFilePath;
		// Метод для сохранения категорий в файл
		void SaveCategoriesToFile();
		// Метод для загрузки категорий из файла
		std::vector<Category> LoadCategoriesFromFile();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxCategoryName = (gcnew System::Windows::Forms::TextBox());
			this->buttonCreateCategory = (gcnew System::Windows::Forms::Button());
			this->textBoxCategoryDescription = (gcnew System::Windows::Forms::TextBox());
			this->label_new_category = (gcnew System::Windows::Forms::Label());
			this->menuStrip_new_category = (gcnew System::Windows::Forms::MenuStrip());
			this->информацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьсяНазадToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label_name_category = (gcnew System::Windows::Forms::Label());
			this->label_opis_category = (gcnew System::Windows::Forms::Label());
			this->menuStrip_new_category->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBoxCategoryName
			// 
			this->textBoxCategoryName->Location = System::Drawing::Point(113, 222);
			this->textBoxCategoryName->Name = L"textBoxCategoryName";
			this->textBoxCategoryName->Size = System::Drawing::Size(100, 22);
			this->textBoxCategoryName->TabIndex = 0;
			// 
			// buttonCreateCategory
			// 
			this->buttonCreateCategory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->buttonCreateCategory->Location = System::Drawing::Point(702, 489);
			this->buttonCreateCategory->Name = L"buttonCreateCategory";
			this->buttonCreateCategory->Size = System::Drawing::Size(236, 64);
			this->buttonCreateCategory->TabIndex = 1;
			this->buttonCreateCategory->Text = L"Добавить категорию";
			this->buttonCreateCategory->UseVisualStyleBackColor = true;
			this->buttonCreateCategory->Click += gcnew System::EventHandler(this, &CategoryForm::buttonCreateCategory_Click);
			// 
			// textBoxCategoryDescription
			// 
			this->textBoxCategoryDescription->Location = System::Drawing::Point(113, 402);
			this->textBoxCategoryDescription->Name = L"textBoxCategoryDescription";
			this->textBoxCategoryDescription->Size = System::Drawing::Size(100, 22);
			this->textBoxCategoryDescription->TabIndex = 2;
			// 
			// label_new_category
			// 
			this->label_new_category->AutoSize = true;
			this->label_new_category->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_new_category->Location = System::Drawing::Point(329, 61);
			this->label_new_category->Name = L"label_new_category";
			this->label_new_category->Size = System::Drawing::Size(372, 32);
			this->label_new_category->TabIndex = 3;
			this->label_new_category->Text = L"Создание новой категории";
			// 
			// menuStrip_new_category
			// 
			this->menuStrip_new_category->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip_new_category->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->информацияToolStripMenuItem,
					this->вернутьсяНазадToolStripMenuItem
			});
			this->menuStrip_new_category->Location = System::Drawing::Point(0, 0);
			this->menuStrip_new_category->Name = L"menuStrip_new_category";
			this->menuStrip_new_category->Size = System::Drawing::Size(1028, 30);
			this->menuStrip_new_category->TabIndex = 4;
			this->menuStrip_new_category->Text = L"menuStrip1";
			// 
			// информацияToolStripMenuItem
			// 
			this->информацияToolStripMenuItem->Name = L"информацияToolStripMenuItem";
			this->информацияToolStripMenuItem->Size = System::Drawing::Size(120, 26);
			this->информацияToolStripMenuItem->Text = L"Информация ";
			this->информацияToolStripMenuItem->Click += gcnew System::EventHandler(this, &CategoryForm::информацияToolStripMenuItem_Click);
			// 
			// вернутьсяНазадToolStripMenuItem
			// 
			this->вернутьсяНазадToolStripMenuItem->Name = L"вернутьсяНазадToolStripMenuItem";
			this->вернутьсяНазадToolStripMenuItem->Size = System::Drawing::Size(138, 26);
			this->вернутьсяНазадToolStripMenuItem->Text = L"Вернуться назад";
			this->вернутьсяНазадToolStripMenuItem->Click += gcnew System::EventHandler(this, &CategoryForm::вернутьсяНазадToolStripMenuItem_Click);
			// 
			// label_name_category
			// 
			this->label_name_category->AutoSize = true;
			this->label_name_category->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_name_category->Location = System::Drawing::Point(113, 156);
			this->label_name_category->Name = L"label_name_category";
			this->label_name_category->Size = System::Drawing::Size(281, 24);
			this->label_name_category->TabIndex = 5;
			this->label_name_category->Text = L"Введите название категории:";
			// 
			// label_opis_category
			// 
			this->label_opis_category->AutoSize = true;
			this->label_opis_category->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_opis_category->Location = System::Drawing::Point(113, 350);
			this->label_opis_category->Name = L"label_opis_category";
			this->label_opis_category->Size = System::Drawing::Size(282, 24);
			this->label_opis_category->TabIndex = 6;
			this->label_opis_category->Text = L"Введите описание категории:";
			// 
			// CategoryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1028, 628);
			this->Controls->Add(this->label_opis_category);
			this->Controls->Add(this->label_name_category);
			this->Controls->Add(this->label_new_category);
			this->Controls->Add(this->textBoxCategoryDescription);
			this->Controls->Add(this->buttonCreateCategory);
			this->Controls->Add(this->textBoxCategoryName);
			this->Controls->Add(this->menuStrip_new_category);
			this->MainMenuStrip = this->menuStrip_new_category;
			this->Name = L"CategoryForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Новая категория";
			this->menuStrip_new_category->ResumeLayout(false);
			this->menuStrip_new_category->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonCreateCategory_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void вернутьсяНазадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
