#ifndef MAIN_H
#define MAIN_H


#include <gtkmm.h>
#include <iostream>
//#include "log_label.hpp"
#define NAME_LABEL_LOG pLabel_log
//Gtk::Widget*
Gtk::Window* pWindow = nullptr;
Gtk::Box* pBox_head = nullptr;
Gtk::Box* pBox_menu = nullptr;
Gtk::StackSwitcher* pStackSwicher_menu = nullptr;
Gtk::Button* pButton_exit = nullptr;
Gtk::Label* NAME_LABEL_LOG = nullptr;
Gtk::Label* pStack_page = nullptr;
Gtk::Label* pGrid_buttonArea = nullptr;
Gtk::Button* pButton_pBA_1 = nullptr;
Gtk::Button* pButton_pBA_2 = nullptr;
Gtk::Button* pButton_pBA_3 = nullptr;
Gtk::Label* pLabel_pBA_1 = nullptr;
Gtk::Label* pLabel_pBA_2 = nullptr;
Gtk::Label* pLabel_pBA_3 = nullptr;
Gtk::Box* pBox_display = nullptr;


Gtk::Box* pBox_admin = nullptr;

//Glib::RefPtr<Gtk::Application> app;

   // Gtk::MessageDialog dialog("Заголовок диалогового окна", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
   // dialog.set_secondary_text("Вы хотите продолжить?");

Glib::RefPtr<Gtk::Builder> builder;


void g_button_exit_clicked_cb();

//void updateLog(const Glib::ustring& newText);














#endif // MAIN_H
