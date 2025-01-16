#pragma once
#include <vector>
#include <string>
#include "Transaction.h"
namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для AccountAnalyticsForm
	/// </summary>
	public ref class AccountAnalyticsForm : public System::Windows::Forms::Form
	{
	public:
		AccountAnalyticsForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~AccountAnalyticsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBoxAccounts;
	private: System::Windows::Forms::Label^ labelBalanceStatus;
	protected:



	private: System::Windows::Forms::Button^ buttonAnalitics;
	private: System::Windows::Forms::Button^ button_clear;


	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartAnalytics;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartMonthly;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ информацияToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вернутьсяНазадToolStripMenuItem;
	private: System::Windows::Forms::Label^ label2;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private:
		void LoadAccountsToComboBox();
		std::vector<Transaction*> LoadTransactionsFromFile();
		double GetAccountBalance(const std::string& accountName);
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxAccounts = (gcnew System::Windows::Forms::ComboBox());
			this->labelBalanceStatus = (gcnew System::Windows::Forms::Label());
			this->buttonAnalitics = (gcnew System::Windows::Forms::Button());
			this->button_clear = (gcnew System::Windows::Forms::Button());
			this->chartAnalytics = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartMonthly = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->информацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вернутьсяНазадToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAnalytics))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMonthly))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(122, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выберите счёт:";
			// 
			// comboBoxAccounts
			// 
			this->comboBoxAccounts->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->comboBoxAccounts->FormattingEnabled = true;
			this->comboBoxAccounts->Location = System::Drawing::Point(125, 145);
			this->comboBoxAccounts->Name = L"comboBoxAccounts";
			this->comboBoxAccounts->Size = System::Drawing::Size(121, 30);
			this->comboBoxAccounts->TabIndex = 1;
			// 
			// labelBalanceStatus
			// 
			this->labelBalanceStatus->AutoSize = true;
			this->labelBalanceStatus->Location = System::Drawing::Point(13, 41);
			this->labelBalanceStatus->Name = L"labelBalanceStatus";
			this->labelBalanceStatus->Size = System::Drawing::Size(165, 20);
			this->labelBalanceStatus->TabIndex = 2;
			this->labelBalanceStatus->Text = L"Тип вашего счёта!";
			// 
			// buttonAnalitics
			// 
			this->buttonAnalitics->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAnalitics->Location = System::Drawing::Point(1131, 387);
			this->buttonAnalitics->Name = L"buttonAnalitics";
			this->buttonAnalitics->Size = System::Drawing::Size(119, 81);
			this->buttonAnalitics->TabIndex = 4;
			this->buttonAnalitics->Text = L"Провести аналитику";
			this->buttonAnalitics->UseVisualStyleBackColor = true;
			this->buttonAnalitics->Click += gcnew System::EventHandler(this, &AccountAnalyticsForm::buttonAnalitics_Click);
			// 
			// button_clear
			// 
			this->button_clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_clear->Location = System::Drawing::Point(1131, 523);
			this->button_clear->Name = L"button_clear";
			this->button_clear->Size = System::Drawing::Size(119, 78);
			this->button_clear->TabIndex = 5;
			this->button_clear->Text = L"Очистить блоки";
			this->button_clear->UseVisualStyleBackColor = true;
			this->button_clear->Click += gcnew System::EventHandler(this, &AccountAnalyticsForm::button_clear_Click);
			// 
			// chartAnalytics
			// 
			chartArea1->Name = L"ChartArea1";
			this->chartAnalytics->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chartAnalytics->Legends->Add(legend1);
			this->chartAnalytics->Location = System::Drawing::Point(16, 88);
			this->chartAnalytics->Name = L"chartAnalytics";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chartAnalytics->Series->Add(series1);
			this->chartAnalytics->Size = System::Drawing::Size(449, 300);
			this->chartAnalytics->TabIndex = 6;
			this->chartAnalytics->Text = L"chart1";
			// 
			// chartMonthly
			// 
			chartArea2->Name = L"ChartArea1";
			this->chartMonthly->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chartMonthly->Legends->Add(legend2);
			this->chartMonthly->Location = System::Drawing::Point(489, 88);
			this->chartMonthly->Name = L"chartMonthly";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chartMonthly->Series->Add(series2);
			this->chartMonthly->Size = System::Drawing::Size(419, 300);
			this->chartMonthly->TabIndex = 7;
			this->chartMonthly->Text = L"chart1";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->chartMonthly);
			this->groupBox1->Controls->Add(this->labelBalanceStatus);
			this->groupBox1->Controls->Add(this->chartAnalytics);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(125, 228);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(969, 415);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Аналитика счёта";
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->информацияToolStripMenuItem,
					this->вернутьсяНазадToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(1299, 28);
			this->menuStrip2->TabIndex = 9;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// информацияToolStripMenuItem
			// 
			this->информацияToolStripMenuItem->Name = L"информацияToolStripMenuItem";
			this->информацияToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->информацияToolStripMenuItem->Text = L"Информация";
			this->информацияToolStripMenuItem->Click += gcnew System::EventHandler(this, &AccountAnalyticsForm::информацияToolStripMenuItem_Click);
			// 
			// вернутьсяНазадToolStripMenuItem
			// 
			this->вернутьсяНазадToolStripMenuItem->Name = L"вернутьсяНазадToolStripMenuItem";
			this->вернутьсяНазадToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->вернутьсяНазадToolStripMenuItem->Text = L"Вернуться назад";
			this->вернутьсяНазадToolStripMenuItem->Click += gcnew System::EventHandler(this, &AccountAnalyticsForm::вернутьсяНазадToolStripMenuItem_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(491, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(238, 32);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Аналитика счёта";
			// 
			// AccountAnalyticsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(1299, 655);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button_clear);
			this->Controls->Add(this->buttonAnalitics);
			this->Controls->Add(this->comboBoxAccounts);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"AccountAnalyticsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Аналитика";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAnalytics))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMonthly))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonAnalitics_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void информацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_clear_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void вернутьсяНазадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
