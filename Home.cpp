#include "Home.h"
#include "memory.h"
#include "scanner.h"

[STAThreadAttribute]

void Main(void) {
  Home::Application::EnableVisualStyles();
  Home::Application::SetCompatibleTextRenderingDefault(false);
  Home::Application::Run(gcnew Home::Home());
}

#define dw_start 0x400000
#define dw_end 0xFFFFFFF

void Home::Home::Home_Load(System::Object^  sender, System::EventArgs^  e) {
  carat_address = scanner::find_pattern(dw_start, dw_end, "");
}

void Home::Home::carat_hack_button_Click(System::Object^  sender, System::EventArgs^  e) {
  memapi::write(Home::carat_address, "C7 46 3C 58 02 00 00"); // # enable carat hack
  Home::disable_carat_hack_button->BringToFront();
}

void Home::Home::disable_carat_hack_button_Click(System::Object^  sender, System::EventArgs^  e) {
  memapi::write(Home::carat_address, "89 46 23 66 89 46 27"); // # disable carat hack
  Home::disable_carat_hack_button->SendToBack();
}

void Home::Home::bonus_present_hack_button_Click(System::Object^  sender, System::EventArgs^  e) {
  /*mem->WriteMemory((VOID*)(0x530DBE), (PBYTE) "\xC7\x46\x2A\x66\x89\x46\x27", 7);
  disable_carat_hack_button->BringToFront();*/
}

void Home::Home::exp_hack_button_Click(System::Object^  sender, System::EventArgs^  e) {
  /*mem->WriteMemory((VOID*)(0x530DBE), (PBYTE) "\xC7\x46\x38\x00\x20\x00\x00", 7);
  disable_carat_hack_button->BringToFront();*/
}

void Home::Home::home_label_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
  ShellExecute(0, 0, "http://google.com", 0, 0, SW_SHOW);
}

void Home::Home::vouch_label_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
  ShellExecute(0, 0, "http://google.com", 0, 0, SW_SHOW);
}