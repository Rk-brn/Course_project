#include "GameForm.h"

namespace Courseproject{

    struct Vector2 {
        int x, y;
    };

    Vector2 direction;
    Vector2 positionFruit;
    Vector2 gameArea;

    GameForm::GameForm(void)
    {

        InitializeComponent();

    }

    void GameForm::GeneratePositionFruit()
    {
        Random^ rand = gcnew Random();
        positionFruit.x = rand->Next(80, gameArea.x - 10);
        positionFruit.y = rand->Next(140, gameArea.y - 10);

        for (int i = 0; i < score; i++) {
            if (positionFruit.x == Snake[i]->Location.X && positionFruit.y == Snake[i]->Location.Y)
                GeneratePositionFruit();
        }
        int tempX = positionFruit.x % step;
        positionFruit.x -= tempX;

        int tempY = positionFruit.y % step;
        positionFruit.y -= tempY;

        fruit->Location = Point(positionFruit.x, positionFruit.y);

        this->Controls->Add(fruit);
    }

    void GameForm::Eating()
    {

        if (Snake[0]->Location.X == positionFruit.x && Snake[0]->Location.Y == positionFruit.y) {
            labelScore->Text = "Счёт: " + ++score + " Ваше имя: " + textBox_name_user->Text;

            Snake[score] = gcnew PictureBox();
            Snake[score]->Location = Point(Snake[score - 1]->Location.X + step * direction.x, Snake[score - 1]->Location.Y + step * direction.y);
            Snake[score]->BackColor = Color::Red;
            Snake[score]->Width = step;
            Snake[score]->Height = step;
            this->Controls->Add(Snake[score]);
            GeneratePositionFruit();
        }
    }

    void GameForm::Movement()
    {
        for (int i = score; i >= 1; i--) {
            Snake[i]->Location = Snake[i - 1]->Location;
        }
        Snake[0]->Location = Point(Snake[0]->Location.X + step * direction.x, Snake[0]->Location.Y + step * direction.y);
    }

    void GameForm::EatYourself()
    {
        for (int i = 1; i < score; i++) {
            if (Snake[0]->Location == Snake[i]->Location)
                GameOver();
        }
    }

    void GameForm::GameOver()
    {
        play = true;
        die = true;
        labelGameOver->Visible = true;
    }

    void GameForm::NewGame()
    {
        if (!first_launch) {
            this->Controls->Remove(fruit);
            for (int i = 0; i <= score; i++) {
                this->Controls->Remove(Snake[i]);
            }
            score = 0;
        }
        else first_launch = false;
        Snake = gcnew array <PictureBox^, 1>(400);
        Snake[0] = gcnew PictureBox();
        Snake[0]->Location = Point(200, 200);
        Snake[0]->BackColor = Color::Green;
        Snake[0]->Width = step;
        Snake[0]->Height = step;
        score = 0;
        this->Controls->Add(Snake[0]);

        fruit = gcnew PictureBox();


        fruit->BackColor = Color::BlueViolet;
        fruit->Width = step;
        fruit->Height = step;


        GeneratePositionFruit();

        timer->Interval = updateInterval;
        timer->Start();

        direction.x = 1;
        direction.y = 0;
        play = true;
        die = false;

        labelScore->Text = "Счёт: 0";

        labelGameOver->Visible = false;
        groupBoxSettings->Visible = false;
    }

    void GameForm::ChackBorders()
    {
        if (Snake[0]->Location.X >= pictureBoxRight->Location.X || Snake[0]->Location.X <= pictureBoxLeft->Location.X) {
            GameOver();
        }
        if (Snake[0]->Location.Y <= pictureBoxUpperLimit->Location.Y || Snake[0]->Location.Y >= pictureBoxLower->Location.Y) {
            GameOver();
        }
    }

    System::Void GameForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        
        die = true;
        GameOver();    
        this->Close();
    }

    System::Void GameForm::информацияОИгреToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        timer->Stop();
        System::Windows::Forms::DialogResult what = MessageBox::Show("Для управления змейкой используйте только клавиши, которые обозначены стрелочками.\nФиолетово-синее блоки это фрукт, его нужно съесть, чтобы змейка становилась больше.\nЕсли вы головой задените границы игрового поля или тело змейки, то игра окончится с поражением.", "Правила игры!", MessageBoxButtons::OK, MessageBoxIcon::Information);
        if (what == System::Windows::Forms::DialogResult::OK) {
            play = true;
            timer->Start();
        }
    }

    System::Void GameForm::новаяИграToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        NewGame();
        return System::Void();
    }

    System::Void GameForm::настройкиToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (groupBoxSettings->Visible == false) {
            timer->Stop();
            buttonSettings->Enabled = true;
            numericUpDownSpeedSnake->Enabled = true;
            groupBoxSettings->Visible = true;
        }
        else {
            play = true;
            timer->Start();

            buttonSettings->Enabled = false;
            numericUpDownSpeedSnake->Enabled = false;
            groupBoxSettings->Visible = false;
        }
        return System::Void();
    }

    System::Void GameForm::buttonSettings_Click(System::Object^ sender, System::EventArgs^ e)
    {
        updateInterval = Convert::ToSingle(numericUpDownSpeedSnake->Value);
        timer->Interval = updateInterval;

        buttonSettings->Enabled = false;
        numericUpDownSpeedSnake->Enabled = false;
        groupBoxSettings->Visible = false;

        play = true;
        timer->Start();

        return System::Void();
    }

    System::Void GameForm::GameForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
    {
        if (e->KeyCode.ToString() == "Right") {
            direction.x = 1;
            direction.y = 0;
        }
        else if (e->KeyCode.ToString() == "Left") {
            direction.x = -1;
            direction.y = 0;
        }
        else if (e->KeyCode.ToString() == "Up") {
            direction.x = 0;
            direction.y = -1;
        }
        else if (e->KeyCode.ToString() == "Down") {
            direction.x = 0;
            direction.y = 1;
        }

        return System::Void();
    }

    void GameForm::GameForm_Update(Object^ obgect, EventArgs^ e)
    {
        if (!die && play) {
            Movement();
            Eating();
            EatYourself();
            ChackBorders();
        }
        else if (die && play) {
            timer->Stop();
            MessageBox::Show("Вы проиграли", "Проигрыш", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        else if (!die && !play) {
            timer->Stop();
            MessageBox::Show("Вы проиграли.", "Проигрыш", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
    }

    System::Void GameForm::button_user_name_Click(System::Object^ sender, System::EventArgs^ e)
    {
        if (textBox_name_user->Text == String::Empty) {
            MessageBox::Show("Вы не ввели своё игровое имя!\nПовторите попытку ввода ещё раз.", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }
        else {
            groupBox_name_user->Visible = false;
            label_name_user->Visible = false;
            textBox_name_user->Enabled = false;
            textBox_name_user->Visible = false;
            button_user_name->Visible = false;
            first_launch = true;
            play = true;
            die = false;
            gameArea.x = 450;
            gameArea.y = 450;
            NewGame();
            timer->Start();
        }
    }

}