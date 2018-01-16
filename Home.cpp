#include "Home.h"
#include "memory.h"
#include "scanner.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Shell32.lib")    
#include <ShellAPI.h>

[Home::STAThreadAttribute]

void Main(void) {
  Home::Application::EnableVisualStyles();
  Home::Application::SetCompatibleTextRenderingDefault(false);
  Home::Application::Run(gcnew Home::Home());
}

#define dw_start 0x400000
#define dw_end 0xFFFFFFF 

void Home::Home::Home_Load(System::Object^  sender, System::EventArgs^  e) {
  this->carat_address = scanner::find_pattern(dw_start, dw_end, "89 46 23 66 89 46 27");
  this->exp_address = Home::carat_address - 0x1000;
  this->speed_reg_address = scanner::find_pattern(
    dw_start, dw_end, "00 00 48 42 14 17 79 00 80");
  this->speed_prec_address = this->speed_reg_address - 0x288B0;
}

void Home::Home::carat_hack_button_Click(System::Object^  sender, System::EventArgs^  e) {
  memapi::write(this->carat_address, "C7 46 3C 58 02 00 00"); // # enable carat hack
  Home::disable_hacks_button->BringToFront();
}

void Home::Home::bonus_present_hack_button_Click(System::Object^  sender, System::EventArgs^  e) {
  memapi::write(this->exp_address, "C7 46 2A 66 89 46 27"); // # enable bonus present hack
  Home::disable_hacks_button->BringToFront();
}

void Home::Home::exp_hack_button_Click(System::Object^  sender, System::EventArgs^  e) {
  memapi::write(this->exp_address, "C7 46 38 00 20 00 00"); // # enable exp hack
  Home::disable_hacks_button->BringToFront();
}

void Home::Home::speed_checkbox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
  if (this->speed_checkbox->Checked) {
    memapi::write_float(this->speed_reg_address, FLT_MAX);
    memapi::write_float(this->speed_prec_address, FLT_MAX);
  }
  else {
    memapi::write_float(this->speed_reg_address, 50);
    memapi::write_float(this->speed_prec_address, 60);
  }
}

void Home::Home::disable_hacks_button_Click(System::Object^  sender, System::EventArgs^  e) {
  memapi::write(this->carat_address, "89 46 23 66 89 46 27"); // # disable carat hack
  memapi::write(this->exp_address, "2B F2 C1 FE 02 3B C1"); // # disable exp and bonus exp hack
  Home::disable_hacks_button->SendToBack();
}

void Home::Home::home_label_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
  ShellExecute(0, 0, "https://github.com/neetjn/Carat-Hack", 0, 0, SW_SHOW);
}
