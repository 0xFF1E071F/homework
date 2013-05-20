
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * �������
 */
public class CalFrame extends JFrame {
	// ��ʾ��������textField
	private JTextField textField = null;
	// ��һ�����鱣��MC,MR,MS,M+�Ȳ�����
	private String[] mOp = { "MC", "MR", "MS", "M+" };
	// ��һ�����鱣����������
	private String[] rOp = { "��", "CE", "C" };
	// ��һ�����鱣������������������
	private String[] nOp = { "7", "8", "9", "��", "��", "4", "5", "6", "��",
			"%", "1", "2", "3", "-", "1/x", "0", "��", ".", "+", "=" };
	// M������־��ť
	private JButton button = null;
	// ҵ���߼���
	private CalService service = new CalService();
	// ���������
	private ActionListener actionListener = null; 
	// ����panel�Ŀ�
	private final int PRE_WIDTH = 370;
	// ����panel�ĸ�
	private final int PRE_HEIGHT = 205;

	/**
	 * Ĭ�Ϲ�����
	 */
	CalFrame() {
		super();
		initialize();
	}

	/**
	 * ��ʼ������
	 * 
	 * @return void
	 */
	private void initialize() {
		this.setTitle("��ǹ������");
		this.setResizable(false);
		
		// ���Ӽ��������
		JPanel panel = new JPanel();
		panel.setBackground(new Color(0,0,0));
		panel.setLayout(new BorderLayout(5, 1));
		panel.add(getTextField(), BorderLayout.NORTH);
		panel.setPreferredSize(new Dimension(PRE_WIDTH, PRE_HEIGHT));
		
		// ���Ӵ洢������
		JButton[] mButton = getMButton();
		JPanel panel1 = new JPanel();
		panel1.setLayout(new GridLayout(5, 1, 0, 4));
		panel1.setBackground(new Color(0,0,0));
		for(JButton b : mButton)
				panel1.add(b);
				
		// ���ӽ��������
		JButton[] rButton = getRButton();
		JPanel panel2 = new JPanel();
		panel2.setBackground(new Color(0,0,0));
		panel2.setLayout(new BorderLayout(5, 1));
		JPanel panel2b = new JPanel();
		panel2b.setBackground(new Color(0,0,0));
		panel2b.setLayout(new GridLayout(1, 3, 3, 4));
		for(JButton b : rButton)
			panel2b.add(b);
		
		// �������������������
		JButton[] nButton = getNButton();
		JPanel panel3 = new JPanel();
		panel3.setBackground(new Color(0,0,0));
		panel3.setLayout(new GridLayout(4, 5, 3, 4));
		for(JButton b : nButton)
			panel3.add(b);
				
		// �������ӵ����ӵ�frame
		panel2.add(panel2b, BorderLayout.NORTH);
		panel2.add(panel3, BorderLayout.CENTER);
		panel.add(panel1, BorderLayout.WEST);
		panel.add(panel2, BorderLayout.CENTER);
		this.add(panel);
	}
	/**
	 * �������������ȡ������
	 * 
	 * @return ActionListener
	 */
	public ActionListener getActionListener() {
		if (actionListener == null) {
			actionListener = new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					String cmd = e.getActionCommand();
					String result = null;
					try {
						result = service.callMethod(cmd, textField.getText());
					} catch (Exception e1) {
						System.out.println(e1.getMessage());
					}
					
					if(cmd.indexOf("MC") == 0) {
						button.setText("");
					}
					else {
						button.setText("M");
					}
					
					if(result != null) {
						textField.setText(result);					
					}
				}
			};
		}
		return actionListener;
	}

	/**
	 * 
	 * @return javax.swing.JButton
	 */
	private JButton getButton() {
		if(button == null) {
			button = new JButton("��rz");
		}
		return new JButton("��rz");
	}

	/**
	 * ���������ʼ�������
	 * 
	 * @return javax.swing.JTextField
	 */
	private JTextField getTextField() {
		if(textField == null) {
			textField = new JTextField("0");
			textField.setEditable(false);
			textField.setBackground(Color.white);
			//������ұ߿�ʼ
			textField.setHorizontalAlignment(JTextField.RIGHT); 
			textField.setFont(new Font("΢���ź�", Font.BOLD, 20));
		}
		return textField;
	}

	/**
	 * �˷�����ü������Ĵ洢������
	 * 
	 * @return ����JButton������
	 */
	private JButton[] getMButton() {
		JButton[] result = new JButton[mOp.length + 1];
		result[0] = getButton();
		result[0].setBackground(new Color(215, 215, 215));
		result[0].setForeground(Color.magenta);
		result[0].setFont(new Font("΢���ź�", Font.BOLD, 14));
		for(int i = 0; i < this.mOp.length; i++) {
			JButton b = new JButton(mOp[i]);
			b.addActionListener(getActionListener());
			b.setBackground(new Color(215, 215, 215));
			b.setForeground(Color.white);
			b.setFont(new Font("΢���ź�", Font.BOLD, 14));
			result[i+1] = b;
		}
		return result;
	}

	/**
	 * �˷�����ü������Ľ��������
	 * 
	 * @return ����JButton������
	 */
	private JButton[] getRButton() {
		JButton[] result = new JButton[rOp.length];
		for(int i = 0; i < this.rOp.length; i++) {
			JButton b = new JButton(rOp[i]);
			b.addActionListener(getActionListener());
			b.setFont(new Font("΢���ź�", Font.BOLD, 14));
			b.setBackground(new Color(215, 215, 215));
			b.setForeground(Color.white);
			result[i] = b;
		}
		return result;
	}

	/**
	 * �˷�����ü����������ֺ�����������
	 * 
	 * @return ����JButton������
	 */
	private JButton[] getNButton() {
		String[] redButton = { "��", "��", "-", "+", "="};
		JButton[] result = new JButton[nOp.length];
		for(int i = 0; i < this.nOp.length; i++) {
			JButton b = new JButton(this.nOp[i]);
			b.addActionListener(getActionListener());
			b.setFont(new Font("΢���ź�", Font.BOLD, 14));
			Arrays.sort(redButton);
			if (Arrays.binarySearch(redButton, nOp[i]) >= 0) {
				b.setBackground(new Color(215, 215, 215));
				b.setForeground(Color.white);	
			}
			else {
				b.setBackground(new Color(243, 144, 29));
			}
			result[i] = b;
		}
		return result;
	}
	
}