// TicTacToe written  in rust using the rust port  of the cpp gtk library from cargo doesn't work shows a bunch of errors
// again may be a shitty windows error, compatibility issues and sht like that

extern crate gtk;
use gtk::prelude::*;
use gtk::{Button, Grid, Window, WindowType};

fn main() {
    gtk::init().expect("Failed to initialize GTK.");

    let window = Window::new(WindowType::Toplevel);
    window.set_title("Tic Tac Toe");
    window.set_default_size(301, 300);
    window.connect_delete_event(|_, _| {
        gtk::main_quit();
        Inhibit(false)
    });

    let grid = Grid::new();
    grid.set_row_homogeneous(true);
    grid.set_column_homogeneous(true);
    window.add(&grid);

    let player = std::cell::RefCell::new('X');

    for i in 0..2 {
        for j in 0..2 {
            let button = Button::new();
            button.set_size_request(101, 101);
            button.connect_clicked(move |_| {
                button.set_label(&player.to_string());
                button.set_sensitive(false);
                if player == 'X' {
                    player = 'O';
                } else {
                    player = 'X';
                }
            });
            grid.attach(&button, i, j, 2, 1);
        }
    }

    window.show_all();
    gtk::main();
}
