// Here's a simple Java program for a Tic Tac Toe game using the Swing framework for the GUI. This code creates a 3x3 grid of buttons, and players can click on the buttons to make their moves. The program checks for a win or a draw after each move.

// ```java
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TicTacToeGUI {
    private JFrame frame;
    private JButton[][] buttons;
    private boolean playerX;
    private int moves;

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new TicTacToeGUI().createAndShowGUI());
    }

    private void createAndShowGUI() {
        frame = new JFrame("Tic Tac Toe");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(3, 3));
        buttons = new JButton[3][3];
        playerX = true;
        moves = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                buttons[i][j] = new JButton();
                buttons[i][j].addActionListener(new ButtonClickListener(i, j));
                frame.add(buttons[i][j]);
            }
        }

        frame.pack();
        frame.setSize(300, 300);
        frame.setVisible(true);
    }

    private class ButtonClickListener implements ActionListener {
        private int row;
        private int col;

        public ButtonClickListener(int row, int col) {
            this.row = row;
            this.col = col;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            if (buttons[row][col].getText().isEmpty()) {
                buttons[row][col].setText(playerX ? "X" : "O");
                moves++;
                if (checkWin(row, col)) {
                    JOptionPane.showMessageDialog(frame, "Player " + (playerX ? "X" : "O") + " wins!");
                    frame.dispose();
                } else if (moves == 9) {
                    JOptionPane.showMessageDialog(frame, "It's a draw!");
                    frame.dispose();
                } else {
                    playerX = !playerX;
                }
            }
        }
    }

    private boolean checkWin(int row, int col) {
        String symbol = buttons[row][col].getText();

        // Check row
        if (buttons[row][0].getText().equals(symbol) &&
                buttons[row][1].getText().equals(symbol) &&
                buttons[row][2].getText().equals(symbol)) {
            return true;
                }

        // Check column
        if (buttons[0][col].getText().equals(symbol) &&
                buttons[1][col].getText().equals(symbol) &&
                buttons[2][col].getText().equals(symbol)) {
            return true;
                }

        // Check diagonal
        if (row == col) {
            if (buttons[0][0].getText().equals(symbol) &&
                    buttons[1][1].getText().equals(symbol) &&
                    buttons[2][2].getText().equals(symbol)) {
                return true;
                    }
        }

        // Check anti-diagonal
        if (row + col == 2) {
            if (buttons[0][2].getText().equals(symbol) &&
                    buttons[1][1].getText().equals(symbol) &&
                    buttons[2][0].getText().equals(symbol)) {
                return true;
                    }
        }

        return false;
    }
}
