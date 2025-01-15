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
	/// Сводка для TransactionForm
	/// </summary>
	// Объявляем класс CategoryForm
	
	public ref class TransactionForm : public System::Windows::Forms::Form
	{
	public:
		TransactionForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TransactionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^ button_TransactionCreat;
	protected:

	protected:
	public: System::Windows::Forms::Label^ label1;
			System::Windows::Forms::TextBox^ textBox_TransactionText;
			System::Windows::Forms::TextBox^ textBox_TransactionAmount;
			System::Windows::Forms::ComboBox^ comboBox_TransactionType;
			System::Windows::Forms::ComboBox^ comboBox_Category;
			System::Windows::Forms::DateTimePicker^ dateTimePicker_Date;
			System::Windows::Forms::ComboBox^ comboBox_Account;




	private:
		Courseproject::CategoryForm^ categoryForm;
	
		System::String^ categoryFilePath;
		System::String^ accountFilePath;
		System::String^ transactionFilePath;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ информацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьсяНазадToolStripMenuItem;
	
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	
		
	public:
		std::vector<Transaction> LoadTransactionFile();
		bool isValidTransactionAmount(const std::string& str);
		// Загрузка категорий из файла
		void LoadCategoriesFromFile();
		// Функция для сохранения транзакций в файл
		void SaveTransactionsToFile();
		bool isChanged = false; // Флаг для отслеживания изменений
		bool isEditing = false; // Флаг редактирования
		int rowIndexToEdit = -1; // Индекс строки для редактирования
		void LoadAccountsFromFile();
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_TransactionCreat = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_TransactionText = (gcnew System::Windows::Forms::TextBox());
			this->textBox_TransactionAmount = (gcnew System::Windows::Forms::TextBox());
			this->comboBox_TransactionType = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_Category = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->информацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьсяНазадToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dateTimePicker_Date = (gcnew System::Windows::Forms::DateTimePicker());
			this->comboBox_Account = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button_TransactionCreat
			// 
			this->button_TransactionCreat->Location = System::Drawing::Point(1165, 571);
			this->button_TransactionCreat->Name = L"button_TransactionCreat";
			this->button_TransactionCreat->Size = System::Drawing::Size(177, 58);
			this->button_TransactionCreat->TabIndex = 0;
			this->button_TransactionCreat->Text = L"Создать транзакцию";
			this->button_TransactionCreat->UseVisualStyleBackColor = true;
			this->button_TransactionCreat->Click += gcnew System::EventHandler(this, &TransactionForm::button_TransactionCreat_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(461, 90);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(460, 53);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Создание новой транзакции";
			
			// 
			// textBox_TransactionText
			// 
			this->textBox_TransactionText->Location = System::Drawing::Point(252, 325);
			this->textBox_TransactionText->Name = L"textBox_TransactionText";
			this->textBox_TransactionText->Size = System::Drawing::Size(100, 22);
			this->textBox_TransactionText->TabIndex = 2;
			// 
			// textBox_TransactionAmount
			// 
			this->textBox_TransactionAmount->Location = System::Drawing::Point(252, 454);
			this->textBox_TransactionAmount->Name = L"textBox_TransactionAmount";
			this->textBox_TransactionAmount->Size = System::Drawing::Size(100, 22);
			this->textBox_TransactionAmount->TabIndex = 3;
			// 
			// comboBox_TransactionType
			// 
			this->comboBox_TransactionType->FormattingEnabled = true;
			this->comboBox_TransactionType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Доход", L"Расход" });
			this->comboBox_TransactionType->Location = System::Drawing::Point(598, 452);
			this->comboBox_TransactionType->Name = L"comboBox_TransactionType";
			this->comboBox_TransactionType->Size = System::Drawing::Size(121, 24);
			this->comboBox_TransactionType->TabIndex = 5;
			// 
			// comboBox_Category
			// 
			this->comboBox_Category->FormattingEnabled = true;
			this->comboBox_Category->Location = System::Drawing::Point(929, 323);
			this->comboBox_Category->Name = L"comboBox_Category";
			this->comboBox_Category->Size = System::Drawing::Size(121, 24);
			this->comboBox_Category->TabIndex = 6;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->информацияToolStripMenuItem,
					this->вернутьсяНазадToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1378, 28);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// информацияToolStripMenuItem
			// 
			this->информацияToolStripMenuItem->Name = L"информацияToolStripMenuItem";
			this->информацияToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->информацияToolStripMenuItem->Text = L"Информация";
			this->информацияToolStripMenuItem->Click += gcnew System::EventHandler(this, &TransactionForm::информацияToolStripMenuItem_Click);
			// 
			// вернутьсяНазадToolStripMenuItem
			// 
			this->вернутьсяНазадToolStripMenuItem->Name = L"вернутьсяНазадToolStripMenuItem";
			this->вернутьсяНазадToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->вернутьсяНазадToolStripMenuItem->Text = L"Вернуться назад";
			this->вернутьсяНазадToolStripMenuItem->Click += gcnew System::EventHandler(this, &TransactionForm::вернутьсяНазадToolStripMenuItem_Click);
			// 
			// dateTimePicker_Date
			// 
			this->dateTimePicker_Date->Location = System::Drawing::Point(578, 323);
			this->dateTimePicker_Date->Name = L"dateTimePicker_Date";
			this->dateTimePicker_Date->Size = System::Drawing::Size(200, 22);
			this->dateTimePicker_Date->TabIndex = 9;
			// 
			// comboBox_Account
			// 
			this->comboBox_Account->FormattingEnabled = true;
			this->comboBox_Account->Location = System::Drawing::Point(929, 454);
			this->comboBox_Account->Name = L"comboBox_Account";
			this->comboBox_Account->Size = System::Drawing::Size(121, 24);
			this->comboBox_Account->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(252, 267);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(157, 17);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Название транзакции:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(255, 411);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 17);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Сумма:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(608, 267);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(123, 17);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Дата транзакции";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(595, 409);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 17);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Тип доход/расход";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(926, 267);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(81, 17);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Категория:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(926, 409);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 17);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Счёт:";
			// 
			// TransactionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1378, 689);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox_Account);
			this->Controls->Add(this->dateTimePicker_Date);
			this->Controls->Add(this->comboBox_Category);
			this->Controls->Add(this->comboBox_TransactionType);
			this->Controls->Add(this->textBox_TransactionAmount);
			this->Controls->Add(this->textBox_TransactionText);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button_TransactionCreat);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Name = L"TransactionForm";
			this->Text = L"TransactionForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_TransactionCreat_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void вернутьсяНазадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

};
}
