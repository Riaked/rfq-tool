#pragma once
#include <Windows.h>
#include <fstream>
#include <string.h>
#include <stdio.h>

namespace Home {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Home
	/// </summary>
	public ref class Home : public System::Windows::Forms::Form
	{
	public:
		Home(void)
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
		~Home()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  carat_hack_button;
	protected:
	private: System::Windows::Forms::Button^  disable_hacks_button;

	private: System::Windows::Forms::LinkLabel^  home_label;



	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Button^  exp_hack_button;
	private: System::Windows::Forms::Button^  bonus_present_hack_button;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::LinkLabel^  vouch_label;
	private: System::Windows::Forms::Label^  label2;

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
      this->carat_hack_button = (gcnew System::Windows::Forms::Button());
      this->disable_hacks_button = (gcnew System::Windows::Forms::Button());
      this->home_label = (gcnew System::Windows::Forms::LinkLabel());
      this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
      this->exp_hack_button = (gcnew System::Windows::Forms::Button());
      this->bonus_present_hack_button = (gcnew System::Windows::Forms::Button());
      this->label1 = (gcnew System::Windows::Forms::Label());
      this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
      this->vouch_label = (gcnew System::Windows::Forms::LinkLabel());
      this->label2 = (gcnew System::Windows::Forms::Label());
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
      this->SuspendLayout();
      // 
      // carat_hack_button
      // 
      this->carat_hack_button->Location = System::Drawing::Point(12, 12);
      this->carat_hack_button->Name = L"carat_hack_button";
      this->carat_hack_button->Size = System::Drawing::Size(47, 23);
      this->carat_hack_button->TabIndex = 0;
      this->carat_hack_button->Text = L"Carat";
      this->carat_hack_button->UseVisualStyleBackColor = true;
      this->carat_hack_button->Click += gcnew System::EventHandler(this, &Home::carat_hack_button_Click);
      // 
      // disable_hacks_button
      // 
      this->disable_hacks_button->Location = System::Drawing::Point(12, 12);
      this->disable_hacks_button->Name = L"disable_hacks_button";
      this->disable_hacks_button->Size = System::Drawing::Size(160, 23);
      this->disable_hacks_button->TabIndex = 1;
      this->disable_hacks_button->Text = L"Disable";
      this->disable_hacks_button->UseVisualStyleBackColor = true;
      this->disable_hacks_button->Click += gcnew System::EventHandler(this, &Home::disable_hacks_button_Click);
      // 
      // home_label
      // 
      this->home_label->AutoSize = true;
      this->home_label->Location = System::Drawing::Point(54, 62);
      this->home_label->Name = L"home_label";
      this->home_label->Size = System::Drawing::Size(72, 13);
      this->home_label->TabIndex = 3;
      this->home_label->TabStop = true;
      this->home_label->Text = L"Duke Gamerz";
      this->home_label->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Home::home_label_LinkClicked);
      // 
      // dateTimePicker1
      // 
      this->dateTimePicker1->Location = System::Drawing::Point(178, 67);
      this->dateTimePicker1->Name = L"dateTimePicker1";
      this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
      this->dateTimePicker1->TabIndex = 6;
      this->dateTimePicker1->Visible = false;
      // 
      // exp_hack_button
      // 
      this->exp_hack_button->Location = System::Drawing::Point(124, 12);
      this->exp_hack_button->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
      this->exp_hack_button->Name = L"exp_hack_button";
      this->exp_hack_button->Size = System::Drawing::Size(46, 23);
      this->exp_hack_button->TabIndex = 11;
      this->exp_hack_button->Text = L"Exp";
      this->exp_hack_button->UseVisualStyleBackColor = true;
      this->exp_hack_button->Click += gcnew System::EventHandler(this, &Home::exp_hack_button_Click);
      // 
      // bonus_present_hack_button
      // 
      this->bonus_present_hack_button->Location = System::Drawing::Point(64, 12);
      this->bonus_present_hack_button->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
      this->bonus_present_hack_button->Name = L"bonus_present_hack_button";
      this->bonus_present_hack_button->Size = System::Drawing::Size(56, 23);
      this->bonus_present_hack_button->TabIndex = 10;
      this->bonus_present_hack_button->Text = L"Bonus";
      this->bonus_present_hack_button->UseVisualStyleBackColor = true;
      this->bonus_present_hack_button->Click += gcnew System::EventHandler(this, &Home::bonus_present_hack_button_Click);
      // 
      // label1
      // 
      this->label1->AutoSize = true;
      this->label1->Location = System::Drawing::Point(52, 46);
      this->label1->Name = L"label1";
      this->label1->Size = System::Drawing::Size(77, 13);
      this->label1->TabIndex = 12;
      this->label1->Text = L"Made by Duke";
      // 
      // pictureBox1
      // 
      this->pictureBox1->Location = System::Drawing::Point(12, 12);
      this->pictureBox1->Name = L"pictureBox1";
      this->pictureBox1->Size = System::Drawing::Size(160, 47);
      this->pictureBox1->TabIndex = 13;
      this->pictureBox1->TabStop = false;
      // 
      // vouch_label
      // 
      this->vouch_label->AutoSize = true;
      this->vouch_label->Location = System::Drawing::Point(64, 78);
      this->vouch_label->Name = L"vouch_label";
      this->vouch_label->Size = System::Drawing::Size(51, 13);
      this->vouch_label->TabIndex = 14;
      this->vouch_label->TabStop = true;
      this->vouch_label->Text = L"+VOUCH";
      this->vouch_label->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Home::vouch_label_LinkClicked);
      // 
      // label2
      // 
      this->label2->AutoSize = true;
      this->label2->Location = System::Drawing::Point(43, 96);
      this->label2->Name = L"label2";
      this->label2->Size = System::Drawing::Size(96, 13);
      this->label2->TabIndex = 15;
      this->label2->Text = L"First Buyers : Duke";
      // 
      // Home
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(184, 119);
      this->Controls->Add(this->label2);
      this->Controls->Add(this->vouch_label);
      this->Controls->Add(this->label1);
      this->Controls->Add(this->exp_hack_button);
      this->Controls->Add(this->bonus_present_hack_button);
      this->Controls->Add(this->dateTimePicker1);
      this->Controls->Add(this->home_label);
      this->Controls->Add(this->carat_hack_button);
      this->Controls->Add(this->pictureBox1);
      this->Controls->Add(this->disable_hacks_button);
      this->MaximizeBox = false;
      this->MinimizeBox = false;
      this->Name = L"Home";
      this->ShowIcon = false;
      this->Text = L"Duke\'s Carat Hack";
      this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
      (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: DWORD carat_address;
  private: DWORD exp_address = 0x0;

  private: System::Void Home_Load(System::Object^  sender, System::EventArgs^  e);
  private: System::Void carat_hack_button_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void disable_hacks_button_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void bonus_present_hack_button_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void exp_hack_button_Click(System::Object^  sender, System::EventArgs^  e);
	
  private: System::Void home_label_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e);
  private: System::Void vouch_label_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e);
};
}