import javax.swing.JFrame;

/**
 * �����������
 */

public class Main {
	public static void main(String[] args) {
		CalFrame calFrame = new CalFrame();
		calFrame.pack();	//ʹ������
		calFrame.setVisible(true);
		calFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
