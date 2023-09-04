//
// Created by Trym Hamer Gudvangen on 9/3/23.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box;
    Gtk::Entry first_name;
    Gtk::Entry last_name;
    Gtk::Button button;
    Gtk::Label label;
    Gtk::Label first_name_label;
    Gtk::Label last_name_label;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        button.set_label("Combine names");
        first_name_label.set_text("First Name");
        last_name_label.set_text("Last Name");

        box.pack_start(first_name_label);
        box.pack_start(first_name);
        box.pack_start(last_name_label);
        box.pack_start(last_name);
        box.pack_start(button);
        box.pack_start(label);

        add(box);
        show_all();

        button.set_sensitive(false);

        first_name.signal_changed().connect([this]() {
            if(!first_name.get_text().empty() && !last_name.get_text().empty()) {
                button.set_sensitive(true);
            } else {
                button.set_sensitive(false);
            }
        });

        last_name.signal_changed().connect([this]() {
            if(!first_name.get_text().empty() && !last_name.get_text().empty()) {
                button.set_sensitive(true);
            } else {
                button.set_sensitive(false);
            }
        });



        button.signal_clicked().connect([this]() {
            if(!first_name.get_text().empty() && !last_name.get_text().empty()) {
                label.set_text("Names combined: " + first_name.get_text() + " " + last_name.get_text());
            }
        });
    }
};


int main() {

    auto app = Gtk::Application::create();
    Window window;
    window.set_title("Exercise 4");
    return app->run(window);

}