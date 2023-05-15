import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TicTacToeGUI2nd {
    private JFrame frame;
    private JButton[] buttons;
    private boolean isPlayerX;
    
    public TicTacToeGUI() {
        frame = new JFrame("Tic-Tac-Toe");
        buttons = new JButton[9];
        isPlayerX = true;
        
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 300);
        frame.setLayout(new GridLayout(3, 3));
        
        for (int i = 0; i < 9; i++) {
            buttons[i] = new JButton("");
            buttons[i].setFont(new Font("Arial", Font.PLAIN, 48));
            buttons[i].addActionListener(new ButtonClickListener());
            frame.add(buttons[i]);
        }
        
        frame.setVisible(true);
    }
    
    private class ButtonClickListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            JButton source = (JButton) e.getSource();
            if (source.getText().isEmpty()) {
                if (isPlayerX) {
                    source.setText("X");
                    if (checkWin("X")) {
                        JOptionPane.showMessageDialog(frame, "Player X wins!");
                        resetGame();
                    }
                } else {
                    source.setText("O");
                    if (checkWin("O")) {
                        JOptionPane.showMessageDialog(frame, "Player O wins!");
                        resetGame();
                    }
                }
                isPlayerX = !isPlayerX;
            }
        }
    }
    
    private boolean checkWin(String player) {
        // Check horizontal lines
        for (int i = 0; i < 9; i += 3) {
            if (buttons[i].getText().equals(player) && 
                buttons[i+1].getText().equals(player) && 
                buttons[i+2].getText().equals(player)) {
                return true;
            }
        }
        
        // Check vertical lines
        for (int i = 0; i < 3; i++) {
            if (buttons[i].getText().equals(player) && 
                buttons[i+3].getText().equals(player) && 
                buttons[i+6].getText().equals(player)) {
                return true;
            }
        }
        
        // Check diagonal lines
        if (buttons[0].getText().equals(player) && 
            buttons[4].getText().equals(player) && 
            buttons[8].getText().equals(player)) {
            return true;
        }
        if (buttons[2].getText().equals(player) && 
            buttons[4].getText().equals(player) && 
            buttons[6].getText().equals(player)) {
            return true;
        }
        
        return false;
    }
    
    private void resetGame() {
        for (int i = 0; i < 9; i++) {
            buttons[i].setText("");
        }
        isPlayerX = true;
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new TicTacToeGUI());
    }
}
