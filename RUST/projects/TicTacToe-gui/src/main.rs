// TicTacToe written  in rust using the ggez library from cargo doesn't work shows a bunch of error
// may be a shitty windows error compatibility issues

extern crate ggez;
use ggez::GameResult;
use ggez::{
    event::{KeyCode, KeyDown, Quit},
    graphics::{self, Color, DrawMode, Font, Point2, Rectangle, Text},
    Context, Game,
};

fn main() {
    let (mut ctx, event_loop) = Context::new();

    let font = Font::new(&mut ctx, "LiberationMono-Regular.ttf", 16.0).unwrap();

    let mut text = Text::new("Hello, World!");
    text.set_font(&font);
    text.set_position(Point2::new(100.0, 100.0));

    loop {
        event_loop.poll_events(&mut ctx);

        match event::read_event(&mut ctx) {
            Ok(event) => match event {
                event::Quit { .. } => break,
                event::KeyDown(KeyDown { keycode: KeyCode::Space }) => {
                    text.set_text("You pressed the spacebar!");
                }
                _ => (),
            },
            Err(e) => println!("Error: {}", e),
        }

        ctx.clear_screen(Color::from_rgb(0.0, 0.0, 0.0));
        ctx.draw(&text);
        ctx.present();
    }
}


const BOARD_SIZE: usize = 3;

struct GameState {
    current_player: char,
    board: [char; BOARD_SIZE * BOARD_SIZE],
    winner: Option<char>,
}

impl GameState {
    fn new() -> Self {
        Self {
            current_player: 'X',
            board: [' '; BOARD_SIZE * BOARD_SIZE],
            winner: None,
        }
    }

    fn make_move(&mut self, x: usize, y: usize) {
        self.board[x * BOARD_SIZE + y] = self.current_player;
        self.check_winner();
        self.switch_player();
    }

    fn check_winner(&mut self) {
        for i in 0..BOARD_SIZE {
            if self.board[i * BOARD_SIZE] == self.board[i * BOARD_SIZE + 1]
                && self.board[i * BOARD_SIZE] == self.board[i * BOARD_SIZE + 2]
                && self.board[i * BOARD_SIZE] != ' '
            {
                self.winner = Some(self.board[i * BOARD_SIZE]);
                return;
            }
        }

        for i in 0..BOARD_SIZE {
            if self.board[i] == self.board[BOARD_SIZE + i]
                && self.board[i] == self.board[2 * BOARD_SIZE + i]
                && self.board[i] != ' '
            {
                self.winner = Some(self.board[i]);
                return;
            }
        }

        if self.board[0] == self.board[4] && self.board[0] == self.board[8] && self.board[0] != ' ' {
            self.winner = Some(self.board[0]);
            return;
        }

        if self.board[2] == self.board[4] && self.board[2] == self.board[6] && self.board[2] != ' ' {
            self.winner = Some(self.board[2]);
            return;
        }
    }

    fn switch_player(&mut self) {
        if self.current_player == 'X' {
            self.current_player = 'O';
        } else {
            self.current_player = 'X';
        }
    }
}

impl Game for GameState {
    fn update(&mut self, ctx: &mut Context) -> GameResult {
        let mut events = event::poll_events(ctx);
        while let Some(event) = events.next() {
            match event {
                event::Quit { .. } => return Ok(ggez::GameResult::Quit),
                event::KeyDown {
                    keycode: KeyCode::Space,
                    ..
                } => {
                    self.make_move(
                        (ctx.mouse_x() / 100) as usize,
                        (ctx.mouse_y() / 100) as usize,
                    );
                }
                _ => {}
            }
        }

        Ok(ggez::GameResult::Continue)
    }

    fn draw(&mut self, ctx: &mut Context) -> GameResult {
        let font = Font::new(ctx, "LiberationMono-Regular.ttf", 32.0).unwrap();

        for (i, &c) in self.board.iter().enumerate() {
            let x = (i % BOARD_SIZE) * 100;
            let y = (i / BOARD_SIZE) * 100;

            let text = Text::new(c, font);
            text.draw(
                ctx,
                Point2::new(x, y),
                DrawMode::Fill,
                Color::White,
                );
        }
    }
}
