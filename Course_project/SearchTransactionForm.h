#pragma once
#include "Category.h"
#include "Transaction.h"
namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для SearchTransactionForm
	/// </summary>
	public ref class SearchTransactionForm : public System::Windows::Forms::Form
	{
	public:
		SearchTransactionForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~SearchTransactionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button_Search;
	private: System::Windows::Forms::Button^ buttonClear;


	private: System::Windows::Forms::CheckBox^ checkBoxName;
	private: System::Windows::Forms::CheckBox^ checkBoxAmount;
	private: System::Windows::Forms::CheckBox^ checkBoxDate;
	private: System::Windows::Forms::CheckBox^ checkBoxType;
	private: System::Windows::Forms::CheckBox^ checkBoxCategory;
	private: System::Windows::Forms::CheckBox^ checkBoxAccount;






	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxAmount;
	private: System::Windows::Forms::ComboBox^ comboBoxType;



	private: System::Windows::Forms::ComboBox^ comboBoxCategory;
	private: System::Windows::Forms::ComboBox^ comboBoxAccount;
	private: System::Windows::Forms::DataGridView^ dataGridView_search;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerDate;


	private: System::Windows::Forms::RadioButton^ radioButtonAmountEqual;
	private: System::Windows::Forms::RadioButton^ radioButtonAmountLess;
	private: System::Windows::Forms::RadioButton^ radioButtonAmountMore;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ информацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьсяНазадToolStripMenuItem;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		
		void LoadCategoriesAndAccountsToComboBoxes();
		void SearchTransactions();
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_Search = (gcnew System::Windows::Forms::Button());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->checkBoxName = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxAmount = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxDate = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxType = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxCategory = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxAccount = (gcnew System::Windows::Forms::CheckBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAmount = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxType = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxCategory = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxAccount = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView_search = (gcnew System::Windows::Forms::DataGridView());
			this->dateTimePickerDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->radioButtonAmountEqual = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonAmountLess = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonAmountMore = (gcnew System::Windows::Forms::RadioButton());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->информацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьсяНазадToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_search))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(631, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// button_Search
			// 
			this->button_Search->Location = System::Drawing::Point(1200, 523);
			this->button_Search->Name = L"button_Search";
			this->button_Search->Size = System::Drawing::Size(158, 56);
			this->button_Search->TabIndex = 1;
			this->button_Search->Text = L"Поиск";
			this->button_Search->UseVisualStyleBackColor = true;
			this->button_Search->Click += gcnew System::EventHandler(this, &SearchTransactionForm::button_Search_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Location = System::Drawing::Point(1200, 651);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(158, 65);
			this->buttonClear->TabIndex = 2;
			this->buttonClear->Text = L"Очистка поиска";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &SearchTransactionForm::buttonClear_Click);
			// 
			// checkBoxName
			// 
			this->checkBoxName->AutoSize = true;
			this->checkBoxName->Location = System::Drawing::Point(159, 195);
			this->checkBoxName->Name = L"checkBoxName";
			this->checkBoxName->Size = System::Drawing::Size(98, 21);
			this->checkBoxName->TabIndex = 3;
			this->checkBoxName->Text = L"checkBox1";
			this->checkBoxName->UseVisualStyleBackColor = true;
			// 
			// checkBoxAmount
			// 
			this->checkBoxAmount->AutoSize = true;
			this->checkBoxAmount->Location = System::Drawing::Point(159, 332);
			this->checkBoxAmount->Name = L"checkBoxAmount";
			this->checkBoxAmount->Size = System::Drawing::Size(98, 21);
			this->checkBoxAmount->TabIndex = 4;
			this->checkBoxAmount->Text = L"checkBox2";
			this->checkBoxAmount->UseVisualStyleBackColor = true;
			// 
			// checkBoxDate
			// 
			this->checkBoxDate->AutoSize = true;
			this->checkBoxDate->Location = System::Drawing::Point(609, 195);
			this->checkBoxDate->Name = L"checkBoxDate";
			this->checkBoxDate->Size = System::Drawing::Size(98, 21);
			this->checkBoxDate->TabIndex = 5;
			this->checkBoxDate->Text = L"checkBox3";
			this->checkBoxDate->UseVisualStyleBackColor = true;
			// 
			// checkBoxType
			// 
			this->checkBoxType->AutoSize = true;
			this->checkBoxType->Location = System::Drawing::Point(609, 332);
			this->checkBoxType->Name = L"checkBoxType";
			this->checkBoxType->Size = System::Drawing::Size(98, 21);
			this->checkBoxType->TabIndex = 6;
			this->checkBoxType->Text = L"checkBox4";
			this->checkBoxType->UseVisualStyleBackColor = true;
			// 
			// checkBoxCategory
			// 
			this->checkBoxCategory->AutoSize = true;
			this->checkBoxCategory->Location = System::Drawing::Point(1041, 195);
			this->checkBoxCategory->Name = L"checkBoxCategory";
			this->checkBoxCategory->Size = System::Drawing::Size(98, 21);
			this->checkBoxCategory->TabIndex = 7;
			this->checkBoxCategory->Text = L"checkBox5";
			this->checkBoxCategory->UseVisualStyleBackColor = true;
			// 
			// checkBoxAccount
			// 
			this->checkBoxAccount->AutoSize = true;
			this->checkBoxAccount->Location = System::Drawing::Point(1041, 319);
			this->checkBoxAccount->Name = L"checkBoxAccount";
			this->checkBoxAccount->Size = System::Drawing::Size(98, 21);
			this->checkBoxAccount->TabIndex = 8;
			this->checkBoxAccount->Text = L"checkBox6";
			this->checkBoxAccount->UseVisualStyleBackColor = true;
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(159, 243);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(100, 22);
			this->textBoxName->TabIndex = 9;
			// 
			// textBoxAmount
			// 
			this->textBoxAmount->Location = System::Drawing::Point(157, 380);
			this->textBoxAmount->Name = L"textBoxAmount";
			this->textBoxAmount->Size = System::Drawing::Size(100, 22);
			this->textBoxAmount->TabIndex = 10;
			// 
			// comboBoxType
			// 
			this->comboBoxType->FormattingEnabled = true;
			this->comboBoxType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Доход", L"Расход" });
			this->comboBoxType->Location = System::Drawing::Point(609, 378);
			this->comboBoxType->Name = L"comboBoxType";
			this->comboBoxType->Size = System::Drawing::Size(121, 24);
			this->comboBoxType->TabIndex = 11;
			// 
			// comboBoxCategory
			// 
			this->comboBoxCategory->FormattingEnabled = true;
			this->comboBoxCategory->Location = System::Drawing::Point(1041, 239);
			this->comboBoxCategory->Name = L"comboBoxCategory";
			this->comboBoxCategory->Size = System::Drawing::Size(121, 24);
			this->comboBoxCategory->TabIndex = 12;
			// 
			// comboBoxAccount
			// 
			this->comboBoxAccount->FormattingEnabled = true;
			this->comboBoxAccount->Location = System::Drawing::Point(1041, 378);
			this->comboBoxAccount->Name = L"comboBoxAccount";
			this->comboBoxAccount->Size = System::Drawing::Size(121, 24);
			this->comboBoxAccount->TabIndex = 13;
			// 
			// dataGridView_search
			// 
			this->dataGridView_search->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_search->Location = System::Drawing::Point(90, 523);
			this->dataGridView_search->Name = L"dataGridView_search";
			this->dataGridView_search->RowHeadersWidth = 51;
			this->dataGridView_search->RowTemplate->Height = 24;
			this->dataGridView_search->Size = System::Drawing::Size(904, 193);
			this->dataGridView_search->TabIndex = 14;
			// 
			// dateTimePickerDate
			// 
			this->dateTimePickerDate->Location = System::Drawing::Point(609, 243);
			this->dateTimePickerDate->Name = L"dateTimePickerDate";
			this->dateTimePickerDate->Size = System::Drawing::Size(200, 22);
			this->dateTimePickerDate->TabIndex = 15;
			// 
			// radioButtonAmountEqual
			// 
			this->radioButtonAmountEqual->AutoSize = true;
			this->radioButtonAmountEqual->Location = System::Drawing::Point(305, 357);
			this->radioButtonAmountEqual->Name = L"radioButtonAmountEqual";
			this->radioButtonAmountEqual->Size = System::Drawing::Size(110, 21);
			this->radioButtonAmountEqual->TabIndex = 16;
			this->radioButtonAmountEqual->TabStop = true;
			this->radioButtonAmountEqual->Text = L"radioButton1";
			this->radioButtonAmountEqual->UseVisualStyleBackColor = true;
			// 
			// radioButtonAmountLess
			// 
			this->radioButtonAmountLess->AutoSize = true;
			this->radioButtonAmountLess->Location = System::Drawing::Point(305, 401);
			this->radioButtonAmountLess->Name = L"radioButtonAmountLess";
			this->radioButtonAmountLess->Size = System::Drawing::Size(110, 21);
			this->radioButtonAmountLess->TabIndex = 17;
			this->radioButtonAmountLess->TabStop = true;
			this->radioButtonAmountLess->Text = L"radioButton2";
			this->radioButtonAmountLess->UseVisualStyleBackColor = true;
			// 
			// radioButtonAmountMore
			// 
			this->radioButtonAmountMore->AutoSize = true;
			this->radioButtonAmountMore->Location = System::Drawing::Point(305, 444);
			this->radioButtonAmountMore->Name = L"radioButtonAmountMore";
			this->radioButtonAmountMore->Size = System::Drawing::Size(110, 21);
			this->radioButtonAmountMore->TabIndex = 18;
			this->radioButtonAmountMore->TabStop = true;
			this->radioButtonAmountMore->Text = L"radioButton3";
			this->radioButtonAmountMore->UseVisualStyleBackColor = true;
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
			this->menuStrip1->Size = System::Drawing::Size(1430, 28);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// информацияToolStripMenuItem
			// 
			this->информацияToolStripMenuItem->Name = L"информацияToolStripMenuItem";
			this->информацияToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->информацияToolStripMenuItem->Text = L"Информация";
			// 
			// вернутьсяНазадToolStripMenuItem
			// 
			this->вернутьсяНазадToolStripMenuItem->Name = L"вернутьсяНазадToolStripMenuItem";
			this->вернутьсяНазадToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->вернутьсяНазадToolStripMenuItem->Text = L"Вернуться назад";
			// 
			// SearchTransactionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1430, 771);
			this->Controls->Add(this->radioButtonAmountMore);
			this->Controls->Add(this->radioButtonAmountLess);
			this->Controls->Add(this->radioButtonAmountEqual);
			this->Controls->Add(this->dateTimePickerDate);
			this->Controls->Add(this->dataGridView_search);
			this->Controls->Add(this->comboBoxAccount);
			this->Controls->Add(this->comboBoxCategory);
			this->Controls->Add(this->comboBoxType);
			this->Controls->Add(this->textBoxAmount);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->checkBoxAccount);
			this->Controls->Add(this->checkBoxCategory);
			this->Controls->Add(this->checkBoxType);
			this->Controls->Add(this->checkBoxDate);
			this->Controls->Add(this->checkBoxAmount);
			this->Controls->Add(this->checkBoxName);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->button_Search);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"SearchTransactionForm";
			this->Text = L"SearchTransactionForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_search))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Search_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e);
};
}
