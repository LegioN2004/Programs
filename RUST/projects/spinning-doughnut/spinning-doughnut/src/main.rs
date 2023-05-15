use std::{thread, time};

const WIDTH: usize = 80;
const HEIGHT: usize = 24;
const SCALE: f64 = 0.07;
const ANIMATION_DELAY: time::Duration = time::Duration::from_millis(50);

fn main() {
    loop {
        for i in 0..HEIGHT {
            for j in 0..WIDTH {
                let x = j as f64 * 0.5;
                let y = i as f64 * 0.2;

                let z1 = (x * SCALE).sin() + (y * SCALE).cos();
                let z2 = ((x + 1.0) * SCALE).sin() + (y * SCALE).cos();
                let z3 = (x * SCALE).sin() + ((y + 1.0) * SCALE).cos();
                let z4 = ((x + 1.0) * SCALE).sin() + ((y + 1.0) * SCALE).cos();

                let average = (z1 + z2 + z3 + z4) / 4.0;
                let gray = (average * 10.0 + 10.0) as usize;

                print!("{}", gray_scale_to_char(gray));
            }
            println!();
        }
        thread::sleep(ANIMATION_DELAY);
        print!("{}[2J", 27 as char); // Clear the terminal screen
    }
}

fn gray_scale_to_char(gray: usize) -> char {
    let chars: [char; 11] = ['@', '%', '#', '*', '+', '=', '-', ':', '.', ' '];
    let clamped_gray = gray.min(chars.len() - 1);
    chars[clamped_gray]
}

