import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import javax.sound.sampled.*;
import java.io.File;

public class TicTacToeDeluxeSound extends JFrame implements ActionListener {
    private JButton[][] buttons = new JButton[3][3];
    private boolean playerX = true;
    private boolean gameOver = false;
    private JLabel statusLabel;
    private JButton resetButton, aiButton;
    private boolean vsAI = false;
    private Random random = new Random();

    public TicTacToeDeluxeSound() {
        setTitle("🎮 Tic Tac Toe Deluxe Edition");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(420, 470);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        // Background gradient
        JPanel gradientPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                GradientPaint gp = new GradientPaint(0, 0, new Color(255, 204, 229),
                        getWidth(), getHeight(), new Color(153, 204, 255));
                g2d.setPaint(gp);
                g2d.fillRect(0, 0, getWidth(), getHeight());
            }
        };
        gradientPanel.setLayout(new BorderLayout());
        add(gradientPanel);

        // Title
        JLabel title = new JLabel("Tic Tac Toe", SwingConstants.CENTER);
        title.setFont(new Font("Segoe UI", Font.BOLD, 32));
        gradientPanel.add(title, BorderLayout.NORTH);

        // Game board
        JPanel panel = new JPanel();
        panel.setOpaque(false);
        panel.setLayout(new GridLayout(3, 3));
        Font font = new Font("Segoe UI", Font.BOLD, 60);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                buttons[i][j] = new JButton("");
                buttons[i][j].setFont(font);
                buttons[i][j].setFocusPainted(false);
                buttons[i][j].setBackground(new Color(255, 255, 255, 230));
                buttons[i][j].addActionListener(this);
                panel.add(buttons[i][j]);
            }
        }

        gradientPanel.add(panel, BorderLayout.CENTER);

        // Bottom panel
        JPanel bottom = new JPanel(new BorderLayout());
        bottom.setOpaque(false);

        statusLabel = new JLabel("Player X's turn", SwingConstants.CENTER);
        statusLabel.setFont(new Font("Segoe UI", Font.PLAIN, 18));

        JPanel buttonPanel = new JPanel();
        buttonPanel.setOpaque(false);
        resetButton = new JButton("Reset");
        resetButton.setFont(new Font("Segoe UI", Font.BOLD, 14));
        resetButton.addActionListener(e -> resetGame());

        aiButton = new JButton("Play vs AI");
        aiButton.setFont(new Font("Segoe UI", Font.BOLD, 14));
        aiButton.addActionListener(e -> {
            vsAI = !vsAI;
            aiButton.setText(vsAI ? "Player vs Player" : "Play vs AI");
            resetGame();
        });

        buttonPanel.add(resetButton);
        buttonPanel.add(aiButton);

        bottom.add(statusLabel, BorderLayout.CENTER);
        bottom.add(buttonPanel, BorderLayout.EAST);
        gradientPanel.add(bottom, BorderLayout.SOUTH);

        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (gameOver) return;
        JButton button = (JButton) e.getSource();

        if (!button.getText().equals("")) return;

        button.setText(playerX ? "X" : "O");
        button.setForeground(playerX ? Color.BLUE : Color.RED);
        playerX = !playerX;
        statusLabel.setText(playerX ? "Player X's turn" : "Player O's turn");

        String winner = checkWinner();
        if (winner != null) {
            playSound("win.wav");
            statusLabel.setText("🎉 Player " + winner + " wins!");
            disableButtons();
            gameOver = true;
            return;
        } else if (isBoardFull()) {
            playSound("draw.wav");
            statusLabel.setText("😐 It's a Draw!");
            gameOver = true;
            return;
        }

        if (vsAI && !playerX && !gameOver) {
            aiMove();
        }
    }

    private void aiMove() {
        Timer timer = new Timer(400, e -> {
            int i, j;
            do {
                i = random.nextInt(3);
                j = random.nextInt(3);
            } while (!buttons[i][j].getText().equals(""));

            buttons[i][j].setText("O");
            buttons[i][j].setForeground(Color.RED);
            playerX = true;
            statusLabel.setText("Player X's turn");

            String winner = checkWinner();
            if (winner != null) {
                playSound("win.wav");
                statusLabel.setText("🎉 Player " + winner + " wins!");
                disableButtons();
                gameOver = true;
            } else if (isBoardFull()) {
                playSound("draw.wav");
                statusLabel.setText("😐 It's a Draw!");
                gameOver = true;
            }
        });
        timer.setRepeats(false);
        timer.start();
    }

    private String checkWinner() {
        for (int i = 0; i < 3; i++) {
            if (!buttons[i][0].getText().equals("") &&
                buttons[i][0].getText().equals(buttons[i][1].getText()) &&
                buttons[i][1].getText().equals(buttons[i][2].getText()))
                return buttons[i][0].getText();

            if (!buttons[0][i].getText().equals("") &&
                buttons[0][i].getText().equals(buttons[1][i].getText()) &&
                buttons[1][i].getText().equals(buttons[2][i].getText()))
                return buttons[0][i].getText();
        }

        if (!buttons[0][0].getText().equals("") &&
            buttons[0][0].getText().equals(buttons[1][1].getText()) &&
            buttons[1][1].getText().equals(buttons[2][2].getText()))
            return buttons[0][0].getText();

        if (!buttons[0][2].getText().equals("") &&
            buttons[0][2].getText().equals(buttons[1][1].getText()) &&
            buttons[1][1].getText().equals(buttons[2][0].getText()))
            return buttons[0][2].getText();

        return null;
    }

    private boolean isBoardFull() {
        for (JButton[] row : buttons)
            for (JButton btn : row)
                if (btn.getText().equals("")) return false;
        return true;
    }

    private void disableButtons() {
        for (JButton[] row : buttons)
            for (JButton btn : row)
                btn.setEnabled(false);
    }

    private void resetGame() {
        for (JButton[] row : buttons)
            for (JButton btn : row) {
                btn.setText("");
                btn.setEnabled(true);
            }
        playerX = true;
        gameOver = false;
        statusLabel.setText("Player X's turn");
    }

    // 🎵 Sound function
    private void playSound(String fileName) {
        try {
            File file = new File(fileName);
            if (!file.exists()) return;
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(file);
            Clip clip = AudioSystem.getClip();
            clip.open(audioStream);
            clip.start();
        } catch (Exception e) {
            System.out.println("Sound error: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(TicTacToeDeluxeSound::new);
    }
}
