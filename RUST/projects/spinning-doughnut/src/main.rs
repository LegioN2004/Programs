use std::{io::Write, time::Duration};

fn main() {
    // Create a slice of characters to represent the doughnut.
    let doughnut = [
        "   /\\",
        "  /  \\",
        " /    \\",
        "/      \\",
        " \\     /",
        "  \\   /",
        "   \\ /",
        "    \\/",
    ];

    // Set the initial rotation angle.
    let mut rotation_angle = 0;

    // Start a loop that will run indefinitely.
    loop {
        // Clear the terminal screen.
        std::io::Write::write(&mut std::io::stdout(), "\x1b[2J").unwrap();

        // Rotate the doughnut by the current rotation angle.
        for i in 0..doughnut.len() {
            let char = doughnut[i][rotation_angle % doughnut[i].len()];
            std::io::Write::write(&mut std::io::stdout(), &char).unwrap();
        }

        // Sleep for a short amount of time.
        std::thread::sleep(Duration::from_millis(100));

        // Increase the rotation angle by 1 degree.
        rotation_angle += 1;
    }
}
