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
	private: System::Windows::Forms::GroupBox^ groupBox_znak;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		bool isValidTransactionAmount(const std::string& str);
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
			this->groupBox_znak = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_search))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox_znak->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(553, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(255, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Поиск транзакций";
			// 
			// button_Search
			// 
			this->button_Search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_Search->Location = System::Drawing::Point(1168, 539);
			this->button_Search->Name = L"button_Search";
			this->button_Search->Size = System::Drawing::Size(158, 65);
			this->button_Search->TabIndex = 1;
			this->button_Search->Text = L"Поиск";
			this->button_Search->UseVisualStyleBackColor = true;
			this->button_Search->Click += gcnew System::EventHandler(this, &SearchTransactionForm::button_Search_Click);
			// 
			// buttonClear
			// 
			this->buttonClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonClear->Location = System::Drawing::Point(1168, 667);
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
			this->checkBoxName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxName->Location = System::Drawing::Point(87, 195);
			this->checkBoxName->Name = L"checkBoxName";
			this->checkBoxName->Size = System::Drawing::Size(200, 28);
			this->checkBoxName->TabIndex = 3;
			this->checkBoxName->Text = L"Использовать имя";
			this->checkBoxName->UseVisualStyleBackColor = true;
			this->checkBoxName->CheckedChanged += gcnew System::EventHandler(this, &SearchTransactionForm::checkBoxName_CheckedChanged);
			// 
			// checkBoxAmount
			// 
			this->checkBoxAmount->AutoSize = true;
			this->checkBoxAmount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxAmount->Location = System::Drawing::Point(87, 332);
			this->checkBoxAmount->Name = L"checkBoxAmount";
			this->checkBoxAmount->Size = System::Drawing::Size(220, 28);
			this->checkBoxAmount->TabIndex = 4;
			this->checkBoxAmount->Text = L"Использовать сумму";
			this->checkBoxAmount->UseVisualStyleBackColor = true;
			this->checkBoxAmount->CheckedChanged += gcnew System::EventHandler(this, &SearchTransactionForm::checkBoxAmount_CheckedChanged);
			// 
			// checkBoxDate
			// 
			this->checkBoxDate->AutoSize = true;
			this->checkBoxDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxDate->Location = System::Drawing::Point(609, 195);
			this->checkBoxDate->Name = L"checkBoxDate";
			this->checkBoxDate->Size = System::Drawing::Size(207, 28);
			this->checkBoxDate->TabIndex = 5;
			this->checkBoxDate->Text = L"Использовать дату";
			this->checkBoxDate->UseVisualStyleBackColor = true;
			this->checkBoxDate->CheckedChanged += gcnew System::EventHandler(this, &SearchTransactionForm::checkBoxDate_CheckedChanged);
			// 
			// checkBoxType
			// 
			this->checkBoxType->AutoSize = true;
			this->checkBoxType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxType->Location = System::Drawing::Point(609, 332);
			this->checkBoxType->Name = L"checkBoxType";
			this->checkBoxType->Size = System::Drawing::Size(198, 28);
			this->checkBoxType->TabIndex = 6;
			this->checkBoxType->Text = L"Использовать тип";
			this->checkBoxType->UseVisualStyleBackColor = true;
			this->checkBoxType->CheckedChanged += gcnew System::EventHandler(this, &SearchTransactionForm::checkBoxType_CheckedChanged);
			// 
			// checkBoxCategory
			// 
			this->checkBoxCategory->AutoSize = true;
			this->checkBoxCategory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->checkBoxCategory->Location = System::Drawing::Point(1031, 195);
			this->checkBoxCategory->Name = L"checkBoxCategory";
			this->checkBoxCategory->Size = System::Drawing::Size(262, 28);
			this->checkBoxCategory->TabIndex = 7;
			this->checkBoxCategory->Text = L"Использовать категорию";
			this->checkBoxCategory->UseVisualStyleBackColor = true;
			this->checkBoxCategory->CheckedChanged += gcnew System::EventHandler(this, &SearchTransactionForm::checkBoxCategory_CheckedChanged);
			// 
			// checkBoxAccount
			// 
			this->checkBoxAccount->AutoSize = true;
			this->checkBoxAccount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBoxAccount->Location = System::Drawing::Point(1031, 332);
			this->checkBoxAccount->Name = L"checkBoxAccount";
			this->checkBoxAccount->Size = System::Drawing::Size(207, 28);
			this->checkBoxAccount->TabIndex = 8;
			this->checkBoxAccount->Text = L"Использовать счёт";
			this->checkBoxAccount->UseVisualStyleBackColor = true;
			this->checkBoxAccount->CheckedChanged += gcnew System::EventHandler(this, &SearchTransactionForm::checkBoxAccount_CheckedChanged);
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(87, 243);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(100, 22);
			this->textBoxName->TabIndex = 9;
			this->textBoxName->Visible = false;
			// 
			// textBoxAmount
			// 
			this->textBoxAmount->Location = System::Drawing::Point(85, 380);
			this->textBoxAmount->Name = L"textBoxAmount";
			this->textBoxAmount->Size = System::Drawing::Size(100, 22);
			this->textBoxAmount->TabIndex = 10;
			this->textBoxAmount->Visible = false;
			// 
			// comboBoxType
			// 
			this->comboBoxType->FormattingEnabled = true;
			this->comboBoxType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Доход", L"Расход" });
			this->comboBoxType->Location = System::Drawing::Point(609, 378);
			this->comboBoxType->Name = L"comboBoxType";
			this->comboBoxType->Size = System::Drawing::Size(121, 24);
			this->comboBoxType->TabIndex = 11;
			this->comboBoxType->Visible = false;
			// 
			// comboBoxCategory
			// 
			this->comboBoxCategory->FormattingEnabled = true;
			this->comboBoxCategory->Location = System::Drawing::Point(1031, 243);
			this->comboBoxCategory->Name = L"comboBoxCategory";
			this->comboBoxCategory->Size = System::Drawing::Size(121, 24);
			this->comboBoxCategory->TabIndex = 12;
			this->comboBoxCategory->Visible = false;
			// 
			// comboBoxAccount
			// 
			this->comboBoxAccount->FormattingEnabled = true;
			this->comboBoxAccount->Location = System::Drawing::Point(1031, 378);
			this->comboBoxAccount->Name = L"comboBoxAccount";
			this->comboBoxAccount->Size = System::Drawing::Size(121, 24);
			this->comboBoxAccount->TabIndex = 13;
			this->comboBoxAccount->Visible = false;
			// 
			// dataGridView_search
			// 
			this->dataGridView_search->AllowUserToAddRows = false;
			this->dataGridView_search->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView_search->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_search->Location = System::Drawing::Point(87, 539);
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
			this->dateTimePickerDate->Visible = false;
			// 
			// radioButtonAmountEqual
			// 
			this->radioButtonAmountEqual->AutoSize = true;
			this->radioButtonAmountEqual->Location = System::Drawing::Point(17, 32);
			this->radioButtonAmountEqual->Name = L"radioButtonAmountEqual";
			this->radioButtonAmountEqual->Size = System::Drawing::Size(206, 24);
			this->radioButtonAmountEqual->TabIndex = 16;
			this->radioButtonAmountEqual->TabStop = true;
			this->radioButtonAmountEqual->Text = L"= (полностью равны)";
			this->radioButtonAmountEqual->UseVisualStyleBackColor = true;
			// 
			// radioButtonAmountLess
			// 
			this->radioButtonAmountLess->AutoSize = true;
			this->radioButtonAmountLess->Location = System::Drawing::Point(17, 63);
			this->radioButtonAmountLess->Name = L"radioButtonAmountLess";
			this->radioButtonAmountLess->Size = System::Drawing::Size(315, 24);
			this->radioButtonAmountLess->TabIndex = 17;
			this->radioButtonAmountLess->TabStop = true;
			this->radioButtonAmountLess->Text = L"> (меньше, чем введённое число)";
			this->radioButtonAmountLess->UseVisualStyleBackColor = true;
			// 
			// radioButtonAmountMore
			// 
			this->radioButtonAmountMore->AutoSize = true;
			this->radioButtonAmountMore->Location = System::Drawing::Point(17, 90);
			this->radioButtonAmountMore->Name = L"radioButtonAmountMore";
			this->radioButtonAmountMore->Size = System::Drawing::Size(313, 24);
			this->radioButtonAmountMore->TabIndex = 18;
			this->radioButtonAmountMore->TabStop = true;
			this->radioButtonAmountMore->Text = L"< (больше, чем введённое число)";
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
			this->menuStrip1->Size = System::Drawing::Size(1375, 28);
			this->menuStrip1->TabIndex = 19;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// информацияToolStripMenuItem
			// 
			this->информацияToolStripMenuItem->Name = L"информацияToolStripMenuItem";
			this->информацияToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->информацияToolStripMenuItem->Text = L"Информация";
			this->информацияToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchTransactionForm::информацияToolStripMenuItem_Click);
			// 
			// вернутьсяНазадToolStripMenuItem
			// 
			this->вернутьсяНазадToolStripMenuItem->Name = L"вернутьсяНазадToolStripMenuItem";
			this->вернутьсяНазадToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->вернутьсяНазадToolStripMenuItem->Text = L"Вернуться назад";
			this->вернутьсяНазадToolStripMenuItem->Click += gcnew System::EventHandler(this, &SearchTransactionForm::вернутьсяНазадToolStripMenuItem_Click);
			// 
			// groupBox_znak
			// 
			this->groupBox_znak->Controls->Add(this->radioButtonAmountEqual);
			this->groupBox_znak->Controls->Add(this->radioButtonAmountMore);
			this->groupBox_znak->Controls->Add(this->radioButtonAmountLess);
			this->groupBox_znak->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox_znak->Location = System::Drawing::Point(200, 380);
			this->groupBox_znak->Name = L"groupBox_znak";
			this->groupBox_znak->Size = System::Drawing::Size(333, 131);
			this->groupBox_znak->TabIndex = 20;
			this->groupBox_znak->TabStop = false;
			this->groupBox_znak->Text = L"Выбор тип сравнения";
			this->groupBox_znak->Visible = false;
			// 
			// SearchTransactionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1375, 771);
			this->Controls->Add(this->groupBox_znak);
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
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Поиск";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_search))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox_znak->ResumeLayout(false);
			this->groupBox_znak->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button_Search_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void buttonClear_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void вернутьсяНазадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBoxName_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBoxAmount_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBoxDate_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBoxType_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBoxCategory_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBoxAccount_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
};
}
