//������

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class calculator extends JFrame
{
	public calculator()
	{
		setTilte("������");
		initTextPanel();	//��ʾ���
		initConctrlPanel();	//�������
		initKeyPanel();		//���ֺ���������
	}

	void setTitle()
	{
		textfield = new JTextField("0", 30);
		textfield.setEditable(false);
		textfield.setHorizontalAlignment(JTextField.RIGHT);
		textPanel = new JPanel();
		textPanel.setlayout(new FlowLayout());
		textPanel.add(textfield);
	}
	
	void 

	private JPanel textPanel;//��ʾ��
	private JTextField textfield;
	private JPanel conctrlPanel;//���ƿ�
	private JPanel keyPanel;//���ֿ�
	private StringBuffer numberA;
	private StringBuffer numberB;
	private char optr;//������
	private boolean isNew = true;
}
