#ifndef LOG_LABEL_H
#define LOG_LABEL_H

#include <gtkmm.h>
#include <iostream>

#ifndef NAME_LABEL_LOG
#define NAME_LABEL_LOG pLabel_log
#endif

extern Gtk::Label* NAME_LABEL_LOG;

extern void updateLog(const Glib::ustring& newText);


#endif // LOG_LABEL
