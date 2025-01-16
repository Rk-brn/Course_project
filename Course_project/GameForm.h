#pragma once

namespace Courseproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void);
	
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBoxGameData;
	private: System::Windows::Forms::Label^ labelScore;
	private: System::Windows::Forms::GroupBox^ groupBoxSettings;
	private: System::Windows::Forms::Button^ buttonSettings;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSpeedSnake;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBoxUpperLimit;
	private: System::Windows::Forms::PictureBox^ pictureBoxLower;
	private: System::Windows::Forms::PictureBox^ pictureBoxRight;
	private: System::Windows::Forms::PictureBox^ pictureBoxLeft;
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ labelGameOver;
	private: System::Windows::Forms::GroupBox^ groupBox_name_user;

	private: System::Windows::Forms::Button^ button_user_name;
	private: System::Windows::Forms::TextBox^ textBox_name_user;
	private: System::Windows::Forms::Label^ label_name_user;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBoxGameData = (gcnew System::Windows::Forms::GroupBox());
			this->labelScore = (gcnew System::Windows::Forms::Label());
			this->groupBoxSettings = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSettings = (gcnew System::Windows::Forms::Button());
			this->numericUpDownSpeedSnake = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBoxUpperLimit = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxLower = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxRight = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxLeft = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelGameOver = (gcnew System::Windows::Forms::Label());
			this->groupBox_name_user = (gcnew System::Windows::Forms::GroupBox());
			this->button_user_name = (gcnew System::Windows::Forms::Button());
			this->textBox_name_user = (gcnew System::Windows::Forms::TextBox());
			this->label_name_user = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->groupBoxGameData->SuspendLayout();
			this->groupBoxSettings->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeedSnake))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUpperLimit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLower))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxRight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLeft))->BeginInit();
			this->groupBox_name_user->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����ToolStripMenuItem,
					this->���������������ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(774, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->���������ToolStripMenuItem,
					this->���������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(65, 24);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(172, 26);
			this->���������ToolStripMenuItem->Text = L"����� ����";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::���������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(172, 26);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::���������ToolStripMenuItem_Click);
			// 
			// ���������������ToolStripMenuItem
			// 
			this->���������������ToolStripMenuItem->Name = L"���������������ToolStripMenuItem";
			this->���������������ToolStripMenuItem->Size = System::Drawing::Size(165, 24);
			this->���������������ToolStripMenuItem->Text = L"���������� � ����";
			this->���������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::���������������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(67, 24);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::�����ToolStripMenuItem_Click);
			// 
			// groupBoxGameData
			// 
			this->groupBoxGameData->Controls->Add(this->labelScore);
			this->groupBoxGameData->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBoxGameData->Location = System::Drawing::Point(12, 47);
			this->groupBoxGameData->Name = L"groupBoxGameData";
			this->groupBoxGameData->Size = System::Drawing::Size(361, 72);
			this->groupBoxGameData->TabIndex = 1;
			this->groupBoxGameData->TabStop = false;
			this->groupBoxGameData->Text = L"������ ����";
			// 
			// labelScore
			// 
			this->labelScore->Location = System::Drawing::Point(7, 33);
			this->labelScore->Name = L"labelScore";
			this->labelScore->Size = System::Drawing::Size(329, 23);
			this->labelScore->TabIndex = 0;
			this->labelScore->Text = L"����: 0";
			// 
			// groupBoxSettings
			// 
			this->groupBoxSettings->Controls->Add(this->buttonSettings);
			this->groupBoxSettings->Controls->Add(this->numericUpDownSpeedSnake);
			this->groupBoxSettings->Controls->Add(this->label2);
			this->groupBoxSettings->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBoxSettings->Location = System::Drawing::Point(180, 286);
			this->groupBoxSettings->Name = L"groupBoxSettings";
			this->groupBoxSettings->Size = System::Drawing::Size(422, 215);
			this->groupBoxSettings->TabIndex = 2;
			this->groupBoxSettings->TabStop = false;
			this->groupBoxSettings->Text = L"���������";
			this->groupBoxSettings->Visible = false;
			// 
			// buttonSettings
			// 
			this->buttonSettings->Location = System::Drawing::Point(135, 117);
			this->buttonSettings->Name = L"buttonSettings";
			this->buttonSettings->Size = System::Drawing::Size(160, 57);
			this->buttonSettings->TabIndex = 2;
			this->buttonSettings->Text = L"���������";
			this->buttonSettings->UseVisualStyleBackColor = true;
			this->buttonSettings->Click += gcnew System::EventHandler(this, &GameForm::buttonSettings_Click);
			// 
			// numericUpDownSpeedSnake
			// 
			this->numericUpDownSpeedSnake->Location = System::Drawing::Point(296, 53);
			this->numericUpDownSpeedSnake->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDownSpeedSnake->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownSpeedSnake->Name = L"numericUpDownSpeedSnake";
			this->numericUpDownSpeedSnake->Size = System::Drawing::Size(120, 31);
			this->numericUpDownSpeedSnake->TabIndex = 1;
			this->numericUpDownSpeedSnake->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(-4, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(277, 23);
			this->label2->TabIndex = 0;
			this->label2->Text = L"������� �������� ������ (��):";
			// 
			// pictureBoxUpperLimit
			// 
			this->pictureBoxUpperLimit->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBoxUpperLimit->Location = System::Drawing::Point(103, 155);
			this->pictureBoxUpperLimit->Name = L"pictureBoxUpperLimit";
			this->pictureBoxUpperLimit->Size = System::Drawing::Size(550, 10);
			this->pictureBoxUpperLimit->TabIndex = 3;
			this->pictureBoxUpperLimit->TabStop = false;
			// 
			// pictureBoxLower
			// 
			this->pictureBoxLower->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBoxLower->Location = System::Drawing::Point(103, 692);
			this->pictureBoxLower->Name = L"pictureBoxLower";
			this->pictureBoxLower->Size = System::Drawing::Size(550, 13);
			this->pictureBoxLower->TabIndex = 4;
			this->pictureBoxLower->TabStop = false;
			// 
			// pictureBoxRight
			// 
			this->pictureBoxRight->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBoxRight->Location = System::Drawing::Point(643, 155);
			this->pictureBoxRight->Name = L"pictureBoxRight";
			this->pictureBoxRight->Size = System::Drawing::Size(10, 550);
			this->pictureBoxRight->TabIndex = 5;
			this->pictureBoxRight->TabStop = false;
			// 
			// pictureBoxLeft
			// 
			this->pictureBoxLeft->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBoxLeft->Location = System::Drawing::Point(103, 155);
			this->pictureBoxLeft->Name = L"pictureBoxLeft";
			this->pictureBoxLeft->Size = System::Drawing::Size(10, 550);
			this->pictureBoxLeft->TabIndex = 6;
			this->pictureBoxLeft->TabStop = false;
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &GameForm::GameForm_Update);
			// 
			// labelGameOver
			// 
			this->labelGameOver->AutoSize = true;
			this->labelGameOver->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelGameOver->Location = System::Drawing::Point(311, 196);
			this->labelGameOver->Name = L"labelGameOver";
			this->labelGameOver->Size = System::Drawing::Size(124, 23);
			this->labelGameOver->TabIndex = 7;
			this->labelGameOver->Text = L"Game over!";
			this->labelGameOver->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelGameOver->Visible = false;
			// 
			// groupBox_name_user
			// 
			this->groupBox_name_user->Controls->Add(this->button_user_name);
			this->groupBox_name_user->Controls->Add(this->textBox_name_user);
			this->groupBox_name_user->Controls->Add(this->label_name_user);
			this->groupBox_name_user->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox_name_user->Location = System::Drawing::Point(72, 139);
			this->groupBox_name_user->Name = L"groupBox_name_user";
			this->groupBox_name_user->Size = System::Drawing::Size(656, 580);
			this->groupBox_name_user->TabIndex = 8;
			this->groupBox_name_user->TabStop = false;
			this->groupBox_name_user->Text = L"�����������";
			// 
			// button_user_name
			// 
			this->button_user_name->Location = System::Drawing::Point(209, 276);
			this->button_user_name->Name = L"button_user_name";
			this->button_user_name->Size = System::Drawing::Size(218, 60);
			this->button_user_name->TabIndex = 2;
			this->button_user_name->Text = L"����������";
			this->button_user_name->UseVisualStyleBackColor = true;
			this->button_user_name->Click += gcnew System::EventHandler(this, &GameForm::button_user_name_Click);
			// 
			// textBox_name_user
			// 
			this->textBox_name_user->Location = System::Drawing::Point(327, 115);
			this->textBox_name_user->Name = L"textBox_name_user";
			this->textBox_name_user->Size = System::Drawing::Size(100, 31);
			this->textBox_name_user->TabIndex = 1;
			// 
			// label_name_user
			// 
			this->label_name_user->AutoSize = true;
			this->label_name_user->Location = System::Drawing::Point(81, 115);
			this->label_name_user->Name = L"label_name_user";
			this->label_name_user->Size = System::Drawing::Size(176, 23);
			this->label_name_user->TabIndex = 0;
			this->label_name_user->Text = L"������� ���� ���:";
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(774, 731);
			this->Controls->Add(this->groupBox_name_user);
			this->Controls->Add(this->labelGameOver);
			this->Controls->Add(this->pictureBoxLeft);
			this->Controls->Add(this->pictureBoxRight);
			this->Controls->Add(this->pictureBoxLower);
			this->Controls->Add(this->pictureBoxUpperLimit);
			this->Controls->Add(this->groupBoxSettings);
			this->Controls->Add(this->groupBoxGameData);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"GameForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���� \"������\"";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GameForm::GameForm_KeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBoxGameData->ResumeLayout(false);
			this->groupBoxSettings->ResumeLayout(false);
			this->groupBoxSettings->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSpeedSnake))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxUpperLimit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLower))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxRight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxLeft))->EndInit();
			this->groupBox_name_user->ResumeLayout(false);
			this->groupBox_name_user->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//������ ����
	private: PictureBox^ fruit; //��������� �� ����������� ������ PictlureBox
	private: array<PictureBox^>^ Snake; //��������� �� ����������� ������ ���������� �� �������� ���������� PictureBox
	private: bool play;//������ ��� �� ����
	private: bool die;//������ ���� ���� �����������
	private: bool first_launch;//������ �� ������ ������ ����
	private: int step = 10; //���������� ��� ����������� �������� ����� ������
	private: float updateInterval = 100; //�������� ��� ���������� �������
	private: int score = 0; //������� ���������� �������
	//�������� ����
	private: void GeneratePositionFruit(); //�������� ������ ��������� ������
	private: void Eating(); //�������� ������ ����� ����� �����
	private: void Movement(); //�������� ������ �������� ������
	private: void EatYourself(); //�������� ������ ���� ������ ���� ������
	private: void GameOver(); //�������� ������ ���������� ����
	private: void NewGame(); //�������� ������ ������ ����� ����
	private: void ChackBorders(); //�������� ������ ��������� ������� ����
	private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);//�������� ������ ������� �� ����� � menuStrip
	private: System::Void ���������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e); //�������� ������ ������� �� ���������� � ���� � menuStrip
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);//�������� ������ ������� �� ����� ���� � menuStrip
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);//�������� ������ ������� �� ��������� � menuStrip
	private: System::Void buttonSettings_Click(System::Object^ sender, System::EventArgs^ e); //�������� ������ ������ ��������� � ����������
	private: System::Void GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e); //�������� ������ ������������ ������
	private: void GameForm_Update(Object^ obgect, EventArgs^ e); //�������� ������ ���������� �����
	private: System::Void button_user_name_Click(System::Object^ sender, System::EventArgs^ e); //�������� ������ ������� �� ������ ��������� � �����������

	};
}
