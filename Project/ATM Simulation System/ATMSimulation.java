import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;

public class ATMSimulation  extends JFrame implements ActionListener{
    private final String correctAccount = "1001"; 
    private final String correctPin     = "1234";     
    private double balance = 1000.00;                
    private final ArrayList<String> transactions = new ArrayList<>();
    private boolean loggedIn = false;
    private final JLabel statusLbl = new JLabel("Not logged in");
    private final JTextField accField = new JTextField(10);
    private final JPasswordField pinField = new JPasswordField(10);
    private final JButton loginBtn = new JButton("Login");
    private final JButton balanceBtn = new JButton("Check Balance");
    private final JButton depositBtn = new JButton("Deposit");
    private final JButton withdrawBtn = new JButton("Withdraw");
    private final JButton miniStmtBtn = new JButton("Mini Statement");
    private final JButton logoutBtn = new JButton("Logout");
    private final JButton exitBtn = new JButton("Exit");

    public ATMSimulation() {
        super("ATM Simulator (Fixed Account)");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout(10, 10));

        JPanel top = new JPanel(new FlowLayout(FlowLayout.LEFT, 8, 8));
        top.setBorder(BorderFactory.createTitledBorder("Login"));
        top.add(new JLabel("Account No:"));
        top.add(accField);
        top.add(new JLabel("PIN:"));
        top.add(pinField);
        top.add(loginBtn);
        add(top, BorderLayout.NORTH);

        JPanel center = new JPanel(new GridLayout(2, 3, 8, 8));
        center.setBorder(BorderFactory.createTitledBorder("ATM Operations"));
        center.add(balanceBtn);
        center.add(depositBtn);
        center.add(withdrawBtn);
        center.add(miniStmtBtn);
        center.add(logoutBtn);
        center.add(exitBtn);
        add(center, BorderLayout.CENTER);

        JPanel bottom = new JPanel(new FlowLayout(FlowLayout.LEFT));
        bottom.add(statusLbl);
        add(bottom, BorderLayout.SOUTH);
        
        loginBtn.addActionListener(this);
        balanceBtn.addActionListener(this);
        depositBtn.addActionListener(this);
        withdrawBtn.addActionListener(this);
        miniStmtBtn.addActionListener(this);
        logoutBtn.addActionListener(this);
        exitBtn.addActionListener(this);
        setButtonsEnabled(false);
        setSize(520, 240);
        setLocationRelativeTo(null);
        setVisible(true);
    }
    private void setButtonsEnabled(boolean enabled) {
        balanceBtn.setEnabled(enabled);
        depositBtn.setEnabled(enabled);
        withdrawBtn.setEnabled(enabled);
        miniStmtBtn.setEnabled(enabled);
        logoutBtn.setEnabled(enabled);
        loginBtn.setEnabled(!enabled);
        accField.setEnabled(!enabled);
        pinField.setEnabled(!enabled);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        Object src = e.getSource();
        if (src == loginBtn) {
            String acc = accField.getText().trim();
            String pin = new String(pinField.getPassword()).trim();
            if (acc.isEmpty() || pin.isEmpty()) {
JOptionPane.showMessageDialog(this, "Please enter account no and PIN.", "Input required", JOptionPane.WARNING_MESSAGE);
                return;
            }
            if (acc.equals(correctAccount) && pin.equals(correctPin)) {
                loggedIn = true;
                statusLbl.setText("Logged in: " + acc);
                setButtonsEnabled(true);
                transactions.add("Login successful for " + acc);
            } else {
                JOptionPane.showMessageDialog(this, "Account number or PIN is incorrect!", "Login failed", JOptionPane.ERROR_MESSAGE);
                transactions.add("Failed login attempt for " + acc);
            }
            pinField.setText("");
        } else if (src == balanceBtn) {
        JOptionPane.showMessageDialog(this, String.format("Current balance: %.2f", balance), "Balance", JOptionPane.INFORMATION_MESSAGE);
            transactions.add(String.format("Checked balance: %.2f", balance));
        } else if (src == depositBtn) {
            String s = JOptionPane.showInputDialog(this, "Enter amount to deposit:", "Deposit", JOptionPane.PLAIN_MESSAGE);
            if (s != null) {
                try {
                    double amt = Double.parseDouble(s);
                    if (amt <= 0) throw new NumberFormatException();
                    balance += amt;
                    transactions.add(String.format("Deposited: +%.2f  (Bal: %.2f)", amt, balance));
JOptionPane.showMessageDialog(this, String.format("Deposited %.2f\nNew balance: %.2f",amt,balance),"Deposit successful",JOptionPane.INFORMATION_MESSAGE);
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(this, "Invalid amount.", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        } else if (src == withdrawBtn) {
            String s = JOptionPane.showInputDialog(this, "Enter amount to withdraw:", "Withdraw", JOptionPane.PLAIN_MESSAGE);
            if (s != null) {
                try {
                    double amt = Double.parseDouble(s);
                    if (amt <= 0) throw new NumberFormatException();
                    if (amt > balance) {
                        JOptionPane.showMessageDialog(this, "Insufficient funds.", "Error", JOptionPane.ERROR_MESSAGE);
                        transactions.add(String.format("Failed withdraw attempt: %.2f (Bal: %.2f)", amt, balance));
                    } else {
                        balance -= amt;
                        transactions.add(String.format("Withdrew: -%.2f  (Bal: %.2f)", amt, balance));
JOptionPane.showMessageDialog(this, String.format("Withdrawn %.2f\nNew balance: %.2f",amt,balance),"Withdraw successful",JOptionPane.INFORMATION_MESSAGE);
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(this, "Invalid amount.", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        } else if (src == miniStmtBtn) {
            StringBuilder sb = new StringBuilder();
            int start = Math.max(0, transactions.size() - 10);
            if (transactions.isEmpty()) sb.append("No transactions yet.");
            else {
                for (int i = start; i < transactions.size(); i++) {
                    sb.append((i + 1) + ". " + transactions.get(i) + "\n");
                }
            }
            JTextArea ta = new JTextArea(sb.toString(), 10, 30);
            ta.setEditable(false);
            JOptionPane.showMessageDialog(this, new JScrollPane(ta), "Mini Statement (last up to 10)", JOptionPane.INFORMATION_MESSAGE);
        } else if (src == logoutBtn) {
            loggedIn = false;
            statusLbl.setText("Not logged in");
            setButtonsEnabled(false);
            accField.setText("");
            pinField.setText("");
            transactions.add("Logged out");
        } else if (src == exitBtn) {
            int confirm = JOptionPane.showConfirmDialog(this, "Exit application?", "Confirm Exit", JOptionPane.YES_NO_OPTION);
            if (confirm == JOptionPane.YES_OPTION) {
                System.exit(0);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(ATMSimulation::new);
    }
}