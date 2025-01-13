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
	/// —водка дл€ AccountAnalyticsForm
	/// </summary>
	public ref class AccountAnalyticsForm : public System::Windows::Forms::Form
	{
	public:
		AccountAnalyticsForm(void);

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
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


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::Button^ buttonAnalitics;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartAnalytics;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartMonthly;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private:
		void LoadAccountsToComboBox();
		std::vector<Transaction*> LoadTransactionsFromFile();
		double GetAccountBalance(const std::string& accountName);
#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->buttonAnalitics = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chartAnalytics = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartMonthly = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAnalytics))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMonthly))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(498, 88);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// comboBoxAccounts
			// 
			this->comboBoxAccounts->FormattingEnabled = true;
			this->comboBoxAccounts->Location = System::Drawing::Point(109, 263);
			this->comboBoxAccounts->Name = L"comboBoxAccounts";
			this->comboBoxAccounts->Size = System::Drawing::Size(121, 24);
			this->comboBoxAccounts->TabIndex = 1;
			// 
			// labelBalanceStatus
			// 
			this->labelBalanceStatus->AutoSize = true;
			this->labelBalanceStatus->Location = System::Drawing::Point(109, 213);
			this->labelBalanceStatus->Name = L"labelBalanceStatus";
			this->labelBalanceStatus->Size = System::Drawing::Size(46, 17);
			this->labelBalanceStatus->TabIndex = 2;
			this->labelBalanceStatus->Text = L"label2";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1172, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// buttonAnalitics
			// 
			this->buttonAnalitics->Location = System::Drawing::Point(1029, 66);
			this->buttonAnalitics->Name = L"buttonAnalitics";
			this->buttonAnalitics->Size = System::Drawing::Size(119, 60);
			this->buttonAnalitics->TabIndex = 4;
			this->buttonAnalitics->Text = L"button1";
			this->buttonAnalitics->UseVisualStyleBackColor = true;
			this->buttonAnalitics->Click += gcnew System::EventHandler(this, &AccountAnalyticsForm::buttonAnalitics_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1029, 168);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 47);
			this->button2->TabIndex = 5;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// chartAnalytics
			// 
			chartArea1->Name = L"ChartArea1";
			this->chartAnalytics->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chartAnalytics->Legends->Add(legend1);
			this->chartAnalytics->Location = System::Drawing::Point(95, 322);
			this->chartAnalytics->Name = L"chartAnalytics";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chartAnalytics->Series->Add(series1);
			this->chartAnalytics->Size = System::Drawing::Size(449, 290);
			this->chartAnalytics->TabIndex = 6;
			this->chartAnalytics->Text = L"chart1";
			// 
			// chartMonthly
			// 
			chartArea2->Name = L"ChartArea1";
			this->chartMonthly->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chartMonthly->Legends->Add(legend2);
			this->chartMonthly->Location = System::Drawing::Point(639, 322);
			this->chartMonthly->Name = L"chartMonthly";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chartMonthly->Series->Add(series2);
			this->chartMonthly->Size = System::Drawing::Size(419, 300);
			this->chartMonthly->TabIndex = 7;
			this->chartMonthly->Text = L"chart1";
			// 
			// AccountAnalyticsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1172, 655);
			this->Controls->Add(this->chartMonthly);
			this->Controls->Add(this->chartAnalytics);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->buttonAnalitics);
			this->Controls->Add(this->labelBalanceStatus);
			this->Controls->Add(this->comboBoxAccounts);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"AccountAnalyticsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AccountAnalyticsForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAnalytics))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMonthly))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonAnalitics_Click(System::Object^ sender, System::EventArgs^ e);
};
}
