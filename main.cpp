//============================================================================
// Name        : testdeletetest.cpp
// Author      : Pavel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "main.hpp"
#include "log_label.hpp"

Gtk::Box* pBox_display_mode = nullptr;
Gtk::Switch* pSwitch_display_mode = nullptr;
Gtk::Label* pLabel_display_mode = nullptr;
Gtk::Box* pBox_display_frame = nullptr;
Gtk::Switch* pSwitch_display_frame = nullptr;
Gtk::Label* pLabel_display_frame = nullptr;

void g_button_pBA_1_clicked_cb() {
	updateLog("gggggg");
    if (pLabel_pBA_1)
        pLabel_pBA_1->set_text("Hello World");
}

void g_button_pBA_2_clicked_cb() {
    if (pLabel_pBA_2)
        pLabel_pBA_2->set_text("Hello World2");
}

void g_button_pBA_3_clicked_cb() {
  //  if (label1)
        //label1->set_text("Hello World");
}

void g_switch_display_mode_activate_cb() {
	   // Переключаемся между полноэкранным режимом и обычным режимом
        if (pSwitch_display_mode->get_active()) {
			updateLog("Входим в полноэкранный режим");
            pWindow->fullscreen();
        } else {
			updateLog("Выходим из полноэкранного режима");
            pWindow->unfullscreen();
        }
        
}

void g_switch_display_frame_activate_cb() {
 	   // Переключаемся между режимом с рамкой и без рамки
        if (pSwitch_display_frame->get_active()) {
			updateLog("Рамка приложения выключена");
           pWindow->set_decorated(true);
        } else {
			updateLog("Рамка приложения включена");
            pWindow->set_decorated(false);
			
			
        }
}


int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    // Загрузка Glade файла
   // builder = Gtk::Builder::create_from_file("glade_example.glade");

    try {
        // ваш код с использованием Gtk::Builder
        // Загрузка Glade файла
        builder = Gtk::Builder::create_from_file("glade_example.glade");
    } catch (const Glib::Error& ex) {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
        return 1;
    }

    // Получение указателей на виджеты из Glade
    builder->get_widget("g_window", pWindow);
    if (!pWindow)
        return 1;
    builder->get_widget("g_box_head", pBox_head);
    if (!pBox_head)
        return 1;

    builder->get_widget("g_box_menu", pBox_menu);
    builder->get_widget("g_StackSwicher_menu", pStackSwicher_menu);
    pStackSwicher_menu->set_size_request(200, 200);
if (pStackSwicher_menu) {
    Gtk::Stack* stack = pStackSwicher_menu->get_stack();
    
    if (stack) {
        // Получаем дочерние виджеты (предполагаем, что они все GtkLabel)
        auto children = stack->get_children();
        
        // Устанавливаем масштаб для текста всех GtkLabel
        for (auto child : children) {
            auto label = dynamic_cast<Gtk::Label*>(child);
            if (label) {
                label->set_markup("<span scale='400%'>" + label->get_text() + "</span>");
            }
        }
    }
}
    
    builder->get_widget("g_button_exit", pButton_exit);
        pButton_exit->set_size_request(100, 100);
  //  Gtk::MessageDialog dialog("Заголовок диалогового окна", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
   // dialog.set_secondary_text("Вы хотите продолжить?");
    
    builder->get_widget("g_label_log", pLabel_log);
    // Установка стиля для изменения цвета шрифта
    pLabel_log->override_color(Gdk::RGBA("red"));

if (pLabel_log) {
    // Если указатель на виджет (Label) не равен nullptr, то он был успешно получен из Glade
    // Установка выравнивания текста по левому краю (xalign = 0.0) и по вертикали по центру (yalign = 0.5)
    pLabel_log->set_alignment(0.0, 0.5);
    // Здесь вы можете добавить другие свойства и действия с вашим виджетом Label...
}

    builder->get_widget("g_stack_page", pStack_page);

    builder->get_widget("g_grid_buttonArea", pGrid_buttonArea);
    builder->get_widget("g_button_pBA_1", pButton_pBA_1);
    builder->get_widget("g_button_pBA_2", pButton_pBA_2);
    builder->get_widget("g_button_pBA_3", pButton_pBA_3);
    builder->get_widget("g_label_pBA_1", pLabel_pBA_1);
    builder->get_widget("g_label_pBA_2", pLabel_pBA_2);
    builder->get_widget("g_label_pBA_3", pLabel_pBA_3);

    builder->get_widget("g_box_display", pBox_display);
    builder->get_widget("g_box_display_mode", pBox_display_mode);
    builder->get_widget("g_switch_display_mode", pSwitch_display_mode);
    pSwitch_display_mode->set_active(true);  // Устанавливаем Switch в состояние "включено"

    builder->get_widget("g_label_display_mode", pLabel_display_mode);
    builder->get_widget("g_box_display_frame", pBox_display_frame);
    builder->get_widget("g_switch_display_frame", pSwitch_display_frame);
    builder->get_widget("g_label_display_frame", pLabel_display_frame);
    builder->get_widget("g_box_admin", pBox_admin);
	

    // Создаем вектор указателей на кнопки
    std::vector<Gtk::Button*> v_buttons;
    v_buttons.push_back(pButton_pBA_1);
    v_buttons.push_back(pButton_pBA_2);
    v_buttons.push_back(pButton_pBA_3);

    // Устанавливаем стартовый размер для каждой кнопки
    for (auto& button : v_buttons) {
        button->set_size_request(200, 75); // Устанавливаем ширину 150 пикселей и высоту 50 пикселей
    }
  
      // Создаем вектор указателей на переключатели
    std::vector<Gtk::Switch*> v_swichers;
    v_swichers.push_back(pSwitch_display_mode);
    v_swichers.push_back(pSwitch_display_frame);
      // Устанавливаем стартовый размер для каждого переключателя 
    for (auto& swich : v_swichers) {
        swich->set_size_request(200, 75); // Устанавливаем ширину 150 пикселей и высоту 50 пикселей  
      }
    // Связывание обработчика сигнала "clicked" кнопки
    pButton_pBA_1->signal_clicked().connect(sigc::ptr_fun(&g_button_pBA_1_clicked_cb));
    pButton_pBA_2->signal_clicked().connect(sigc::ptr_fun(&g_button_pBA_2_clicked_cb));
    pButton_pBA_3->signal_clicked().connect(sigc::ptr_fun(&g_button_pBA_3_clicked_cb));
    pButton_exit->signal_clicked().connect(sigc::ptr_fun(&g_button_exit_clicked_cb));
    
    // Связывание обработчика сигнала "activate" переключателя
// Подключаем обработчик события
 pSwitch_display_mode->property_active().signal_changed().connect(sigc::ptr_fun(&g_switch_display_mode_activate_cb));
 
pSwitch_display_frame->property_active().signal_changed().connect(sigc::ptr_fun(&g_switch_display_frame_activate_cb));
//pSwitch_display_mode->signal_state_set().connect(sigc::bind(sigc::ptr_fun(&g_switch_display_mode_activate_cb), pSwitch_display_mode));

 



//pSwitch_display_frame->signal_state_set().connect(sigc::ptr_fun(&g_switch_display_frame_activate_cb));

    // Завершение программы при закрытии окна
   pWindow->signal_hide().connect([app]() {
        app->quit();
  });


	pWindow->fullscreen();  // Устанавливаем полноэкранный режим
	pWindow->set_decorated(false);
    app->run(*pWindow);

    return 0;
}

void g_button_exit_clicked_cb() {
    Gtk::MessageDialog dialog("", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
    dialog.set_secondary_text("Вы хотите завершить программу?");
        // Устанавливаем заголовок
    dialog.set_title("Меню завершения программы");

    int result = dialog.run();

    switch (result) {
        case Gtk::RESPONSE_YES:
            std::cout << "Вы выбрали 'Да'" << std::endl;
            // Добавьте здесь код для обработки случая "Да"
            app->quit();
            break;
        case Gtk::RESPONSE_NO:
            std::cout << "Вы выбрали 'Нет'" << std::endl;
            // Добавьте здесь код для обработки случая "Нет"
            break;
        default:
            std::cout << "Диалог закрыт без выбора" << std::endl;
            break;
    }
}
