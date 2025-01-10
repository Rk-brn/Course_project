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
	/// Сводка для Account_TableForm
	/// </summary>
	public ref class Account_TableForm : public System::Windows::Forms::Form
	{
	public:
		Account_TableForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::ToolStripMenuItem^ создатьСчётToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ просмотрТранзакцийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ показатьВсеТранзакцииToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ показатьТолькоДляОдногоСчётаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ информацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьсяВМенюToolStripMenuItem;

	private:
		void LoadAccountsToDataGridView();

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->создатьСчётToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->просмотрТранзакцийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->показатьВсеТранзакцииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->показатьТолькоДляОдногоСчётаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->информацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьсяВМенюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(88, 140);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1108, 297);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->AllowUserToAddRows = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->создатьСчётToolStripMenuItem,
					this->просмотрТранзакцийToolStripMenuItem, this->информацияToolStripMenuItem, this->вернутьсяВМенюToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1286, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// создатьСчётToolStripMenuItem
			// 
			this->создатьСчётToolStripMenuItem->Name = L"создатьСчётToolStripMenuItem";
			this->создатьСчётToolStripMenuItem->Size = System::Drawing::Size(111, 24);
			this->создатьСчётToolStripMenuItem->Text = L"Создать счёт";
			this->создатьСчётToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::создатьСчётToolStripMenuItem_Click);
			// 
			// просмотрТранзакцийToolStripMenuItem
			// 
			this->просмотрТранзакцийToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->показатьВсеТранзакцииToolStripMenuItem,
					this->показатьТолькоДляОдногоСчётаToolStripMenuItem
			});
			this->просмотрТранзакцийToolStripMenuItem->Name = L"просмотрТранзакцийToolStripMenuItem";
			this->просмотрТранзакцийToolStripMenuItem->Size = System::Drawing::Size(179, 24);
			this->просмотрТранзакцийToolStripMenuItem->Text = L"Просмотр транзакций";
			// 
			// показатьВсеТранзакцииToolStripMenuItem
			// 
			this->показатьВсеТранзакцииToolStripMenuItem->Name = L"показатьВсеТранзакцииToolStripMenuItem";
			this->показатьВсеТранзакцииToolStripMenuItem->Size = System::Drawing::Size(330, 26);
			this->показатьВсеТранзакцииToolStripMenuItem->Text = L"Показать все транзакции";
			this->показатьВсеТранзакцииToolStripMenuItem->Click += gcnew System::EventHandler(this, &Account_TableForm::показатьВсеТранзакцииToolStripMenuItem_Click);
			// 
			// показатьТолькоДляОдногоСчётаToolStripMenuItem
			// 
			this->показатьТолькоДляОдногоСчётаToolStripMenuItem->Name = L"показатьТолькоДляОдногоСчётаToolStripMenuItem";
			this->показатьТолькоДляОдногоСчётаToolStripMenuItem->Size = System::Drawing::Size(330, 26);
			this->показатьТолькоДляОдногоСчётаToolStripMenuItem->Text = L"Показать только для одного счёта";
			// 
			// информацияToolStripMenuItem
			// 
			this->информацияToolStripMenuItem->Name = L"информацияToolStripMenuItem";
			this->информацияToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->информацияToolStripMenuItem->Text = L"Информация";
			// 
			// вернутьсяВМенюToolStripMenuItem
			// 
			this->вернутьсяВМенюToolStripMenuItem->Name = L"вернутьсяВМенюToolStripMenuItem";
			this->вернутьсяВМенюToolStripMenuItem->Size = System::Drawing::Size(154, 24);
			this->вернутьсяВМенюToolStripMenuItem->Text = L"Вернуться в меню ";
			// 
			// Account_TableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1286, 698);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Account_TableForm";
			this->Text = L"Account_TableForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void создатьСчётToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void показатьВсеТранзакцииToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
