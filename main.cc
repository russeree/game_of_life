#include "gol_seed.h"
#include <gtkmm/application.h>


int main (int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    GolSeed gol_seed_gen;

    //Shows the window and returns when it is closed.
    return app->run(gol_seed_gen);
}
