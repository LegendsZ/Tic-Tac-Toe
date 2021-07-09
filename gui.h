#pragma once

#include <iostream>
#include "var.h"

#define MAX 9
#define ROW 3
#define COLUMN 3

namespace TripleTsREVAMPED {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for gui
	/// </summary>
	public ref class gui : public System::Windows::Forms::Form
	{
	public:
		gui(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~gui()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::String^ version = gcnew System::String("1.0.0.0");//version

	private: System::Windows::Forms::Button^ btn1;
	private: System::Windows::Forms::Button^ btn2;
	private: System::Windows::Forms::Button^ btn3;
	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ btn5;
	private: System::Windows::Forms::Button^ btn6;
	private: System::Windows::Forms::Button^ btn7;
	private: System::Windows::Forms::Button^ btn8;
	private: System::Windows::Forms::Button^ btn9;

	private: array<System::Windows::Forms::Button^>^ btnArray;
	private: System::Windows::Forms::Panel^ pnlBack;


	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Button^ btnExit;

	private: System::Windows::Forms::Label^ lblVersion;
	private: System::Windows::Forms::Label^ lblCredit;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->pnlBack = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->lblVersion = (gcnew System::Windows::Forms::Label());
			this->lblCredit = (gcnew System::Windows::Forms::Label());
			this->pnlBack->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn1
			// 
			this->btn1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1->Location = System::Drawing::Point(12, 48);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(100, 100);
			this->btn1->TabIndex = 0;
			this->btn1->Text = L" ";
			this->btn1->UseVisualStyleBackColor = false;
			this->btn1->Click += gcnew System::EventHandler(this, &gui::btnGame_Click);
			// 
			// btn2
			// 
			this->btn2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2->Location = System::Drawing::Point(118, 48);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(100, 100);
			this->btn2->TabIndex = 1;
			this->btn2->Text = L" ";
			this->btn2->UseVisualStyleBackColor = false;
			this->btn2->Click += gcnew System::EventHandler(this, &gui::btnGame_Click);
			// 
			// btn3
			// 
			this->btn3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3->Location = System::Drawing::Point(224, 48);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(100, 100);
			this->btn3->TabIndex = 2;
			this->btn3->Text = L" ";
			this->btn3->UseVisualStyleBackColor = false;
			this->btn3->Click += gcnew System::EventHandler(this, &gui::btnGame_Click);
			// 
			// btn6
			// 
			this->btn6->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn6->Location = System::Drawing::Point(224, 154);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(100, 100);
			this->btn6->TabIndex = 5;
			this->btn6->Text = L" ";
			this->btn6->UseVisualStyleBackColor = false;
			this->btn6->Click += gcnew System::EventHandler(this, &gui::btnGame_Click);
			// 
			// btn5
			// 
			this->btn5->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn5->Location = System::Drawing::Point(118, 154);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(100, 100);
			this->btn5->TabIndex = 4;
			this->btn5->Text = L" ";
			this->btn5->UseVisualStyleBackColor = false;
			this->btn5->Click += gcnew System::EventHandler(this, &gui::btnGame_Click);
			// 
			// btn4
			// 
			this->btn4->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4->Location = System::Drawing::Point(12, 154);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(100, 100);
			this->btn4->TabIndex = 3;
			this->btn4->Text = L" ";
			this->btn4->UseVisualStyleBackColor = false;
			this->btn4->Click += gcnew System::EventHandler(this, &gui::btnGame_Click);
			// 
			// btn9
			// 
			this->btn9->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn9->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn9->Location = System::Drawing::Point(224, 260);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(100, 100);
			this->btn9->TabIndex = 8;
			this->btn9->Text = L" ";
			this->btn9->UseVisualStyleBackColor = false;
			this->btn9->Click += gcnew System::EventHandler(this, &gui::btnGame_Click);
			// 
			// btn8
			// 
			this->btn8->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn8->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn8->Location = System::Drawing::Point(118, 260);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(100, 100);
			this->btn8->TabIndex = 7;
			this->btn8->Text = L" ";
			this->btn8->UseVisualStyleBackColor = false;
			this->btn8->Click += gcnew System::EventHandler(this, &gui::btnGame_Click);
			// 
			// btn7
			// 
			this->btn7->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->btn7->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn7->Location = System::Drawing::Point(12, 260);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(100, 100);
			this->btn7->TabIndex = 6;
			this->btn7->Text = L" ";
			this->btn7->UseVisualStyleBackColor = false;
			this->btn7->Click += gcnew System::EventHandler(this, &gui::btnGame_Click);
			// 
			// pnlBack
			// 
			this->pnlBack->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->pnlBack->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pnlBack->Controls->Add(this->lblTitle);
			this->pnlBack->Controls->Add(this->btnExit);
			this->pnlBack->Location = System::Drawing::Point(0, 0);
			this->pnlBack->Name = L"pnlBack";
			this->pnlBack->Size = System::Drawing::Size(335, 42);
			this->pnlBack->TabIndex = 9;
			this->pnlBack->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &gui::pnlBack_MouseDown);
			this->pnlBack->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &gui::pnlBack_MouseMove);
			this->pnlBack->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &gui::pnlBack_MouseUp);
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->BackColor = System::Drawing::Color::Transparent;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(3, 0);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(134, 37);
			this->lblTitle->TabIndex = 1;
			this->lblTitle->Text = L"Triple Ts";
			this->lblTitle->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &gui::pnlBack_MouseDown);
			this->lblTitle->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &gui::pnlBack_MouseMove);
			this->lblTitle->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &gui::pnlBack_MouseUp);
			// 
			// btnExit
			// 
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->Location = System::Drawing::Point(296, 2);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(35, 35);
			this->btnExit->TabIndex = 0;
			this->btnExit->Text = L"X";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &gui::btnExit_Click);
			// 
			// lblVersion
			// 
			this->lblVersion->AutoSize = true;
			this->lblVersion->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVersion->Location = System::Drawing::Point(221, 368);
			this->lblVersion->Name = L"lblVersion";
			this->lblVersion->Size = System::Drawing::Size(53, 15);
			this->lblVersion->TabIndex = 10;
			this->lblVersion->Text = L"Version: ";
			// 
			// lblCredit
			// 
			this->lblCredit->AutoSize = true;
			this->lblCredit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCredit->Location = System::Drawing::Point(9, 368);
			this->lblCredit->Name = L"lblCredit";
			this->lblCredit->Size = System::Drawing::Size(204, 15);
			this->lblCredit->TabIndex = 11;
			this->lblCredit->Text = L"Made By LegendsZ#1526 @ Discord";
			// 
			// gui
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(336, 388);
			this->Controls->Add(this->lblCredit);
			this->Controls->Add(this->lblVersion);
			this->Controls->Add(this->pnlBack);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btn1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"gui";
			this->ShowIcon = false;
			this->Text = L"Triple Ts | Made By LegendsZ#1526 @ Discord";
			this->Load += gcnew System::EventHandler(this, &gui::gui_Load);
			this->pnlBack->ResumeLayout(false);
			this->pnlBack->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void gui_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnGame_Click(System::Object^ sender, System::EventArgs^ e);

	private: void randomize_array(int* randomized);
	private: void changeLogicGame(int toChange, int change);
	private: bool applyLogic();

	private: int makeMove(int startH, const int* randomized);
	private: int makeMove_2(int start, int end, int increment);
	
	private: System::Void pnlBack_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e); //movement
	private: System::Void pnlBack_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void pnlBack_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	private: void resetData();
};
}
