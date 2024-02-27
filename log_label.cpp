#include "log_label.hpp"


extern void updateLog(const Glib::ustring& newText) {
    try {
        if (pLabel_log) {
            pLabel_log->set_text(newText);
        }
    } catch (const Glib::Exception& ex) {
        std::cerr << "Ошибка при обновлении метки pLabel_log: " << ex.what() << std::endl;
    }
}
