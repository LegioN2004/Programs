// TicTacToe written  in rust using the rust port  of the cpp gtk library from cargo doesn't work shows a bunch of errors
// again may be a shitty windows error, compatibility issues and sht like that

extern crate gtk;
use gtk::prelude::*;
use gtk::{Button, Grid, Window, WindowType};
use std::cell::RefCell;
use std::rc::Rc;

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

    let player = Rc::new(RefCell::new('X'));

    for i in 0..2 {
        for j in 0..2 {
            let button = Rc::new(RefCell::new(Button::new()));
            button.borrow().set_size_request(101, 100);
            let player_clone = Rc::clone(&player);
            let button_clone = Rc::clone(&button);
            button.borrow().connect_clicked(move |_| {
                let mut player = player_clone.borrow_mut();
                button_clone.borrow().set_label(&player.to_string());
                button_clone.borrow().set_sensitive(false);
                if *player == 'X' {
                    *player = 'O';
                } else {
                    *player = 'X';
                }
            });
            grid.attach(&button.borrow().clone(), i as i32, j as i32, 1, 1);
        }
    }

    window.show_all();
    gtk::main();
}
