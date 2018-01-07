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

void Home::Home::enable_speed(Object^ args) {

  while (true) {

    if (FindWindow("Rumble Fighter", "Rumble Fighter") && !this->speed_address)
      this->speed_address = scanner::find_pattern(0x500000, 0x8FFFFF, "A8 F9 ? 05 30 7F ? 05");

    if (this->speed_checkbox->Checked)
      memapi::pointer::\
        write_float(this->speed_address, this->speed_offset, FLT_MAX); // # modify query performance tick
    else
      memapi::pointer::\
        write_float(this->speed_address, this->speed_offset, 60); // # reset query performance tick

    Sleep(1000);

  }

}

void Home::Home::Home_Load(System::Object^  sender, System::EventArgs^  e) {
  this->carat_address = scanner::find_pattern(dw_start, dw_end, "89 46 23 66 89 46 27");
  this->exp_address = Home::carat_address - 0x1000;
  System::Threading::Thread ^tr = gcnew System::Threading::\
    Thread(gcnew System::Threading::ParameterizedThreadStart(this, &Home::enable_speed));
  tr->Start();
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

void Home::Home::disable_hacks_button_Click(System::Object^  sender, System::EventArgs^  e) {
  memapi::write(this->carat_address, "89 46 23 66 89 46 27"); // # disable carat hack
  memapi::write(this->exp_address, "2B F2 C1 FE 02 3B C1"); // # disable exp and bonus exp hack
  Home::disable_hacks_button->SendToBack();
}

void Home::Home::home_label_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
  ShellExecute(0, 0, "https://github.com/neetjn/Carat-Hack", 0, 0, SW_SHOW);
}