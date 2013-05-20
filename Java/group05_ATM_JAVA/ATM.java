//ATM

import java.util.Scanner;
import java.io.*;
import java.lang.Integer;
import java.lang.Math;

public class ATM
{
	public static void main(String[] args) 
	{
		new ATM();
	}

	ATM()
	{
		welcome();
	}

	void welcome()
	{
		System.out.println("---------------���ã���ӭʹ�ú���ATM��---------------");
		System.out.print("\n���������Ŀ���(��λ��): ");
		CardNumber = scan.next();

		if(CardNumber.equals(AdminAcount))
		{
			System.out.print("\nҪ�������Աģʽ��?(Y/N)..");
			String ch;
			ch = scan.next();
			if(ch.equals("Y") || ch.equals("y"))
			{
				AdminModel();	
			}
			else
			{
				welcome();
			}
		}
		else
		{
			NormalModel();
		}
	}

	void AdminModel()
	{
		System.out.print("\n�������Ա����: ");
		String password;
		password = scan.next();
		if(password.equals(originalpassword))
		{
			//����Ա����
			System.out.println("\n����Ա����!\n");
			
			int choice;
			do{
				System.out.println("1>>>�˻���Ϣ��ѯ");
				System.out.println("2>>>�˻����");
				System.out.println("3>>>�˳�");
				System.out.print("\n����������ѡ��: ");
				choice = scan.nextInt();
				switch(choice)
				{
					case 1:Check();break;
					case 2:Delock();break;
					case 3:welcome();break;
					default:System.out.print("��������!������ѡ��!");
				}
			}while(choice != 1 || choice != 2 || choice != 3);
		}
		else
		{
			System.out.println("\n�������!\n");
			welcome();
		}
	}

	void Check()
	{
		System.out.println("\n������Ҫ��ѯ���˺�: ");
		String ac;
		ac = scan.next();
		int num = Integer.parseInt(ac);
		account[num] = new Account(ac);
		account[num].show();
	}

	void Delock()
	{
		System.out.println("\n������Ҫ�����˺�: ");
		String ac;
		ac = scan.next();
		account[Integer.parseInt(ac)].delock();
	}

	void NormalModel()
	{
		System.out.print("\n��������: ");
		String password;
		password = scan.next();
		if(password.equals(originalpassword))
		{
			new Account(CardNumber);
			int ch;
			do{
				System.out.println("1>>>ȡ��");
				System.out.println("2>>>ת��");
				System.out.println("3>>>�޸�����");
				System.out.println("4>>>�˳�");
				System.out.println("����������ѡ��: ");
				ch = scan.nextInt();
				switch(ch)
				{
					case 1:account[Integer.parseInt(CardNumber)].withdraw();break;
					case 2:account[Integer.parseInt(CardNumber)].transfer();break;
					case 3:account[Integer.parseInt(CardNumber)].ChangePassword();break;
					case 4:welcome();break;
				}
			}while(ch != 1 || ch != 2 || ch != 3 || ch != 4);
		}
		else
		{
			System.out.println("\n�������!\n");
		}
	}
	
	Account [] account = new Account[100000];
	String CardNumber;
	String AdminAcount = "00000";
	String originalpassword = "000000";
	Scanner scan = new Scanner(System.in);
}

class Account
{
	Account(String cardnum)
	{
		cardnumber = cardnum;
		balance = Math.random() * 10000;
		password = "000000";
	}

	boolean withdraw()
	{
		if(balance >= 100)
		{
			System.out.println("100");
			{
				if(balance >= 200)
				{
					System.out.println("200");
					{
						if(balance >= 500)
						{
							System.out.println("500");
							if(balance >= 1000)
							{
								System.out.println("1000");
								if(balance >= 2000)
									System.out.println("2000");
							}
						}
					}
				}
			}
			System.out.println("��������ҪȡǮ�Ľ��: ");
			int mm = in.nextInt();
			if(mm < balance)
			{
				balance -= mm;
				System.out.println("ȡ��ɹ�!���պ�����Ǯ!");
				return true;
			}
			else
			{
				System.out.println("��������100!");
				return false;
			}
		}
		else
		{
			System.out.println("��������100!");
			return false;
		}
	}

	boolean transfer()
	{
		System.out.println("��������Ҫת�ʵĽ��: ");
		int mm = in.nextInt();
		if(mm < balance)
		{
			balance -= mm;
			System.out.println("ȡ��ɹ�!���պ�����Ǯ!");
			return true;
		}
		else
		{
			System.out.println("��������!");
			return false;
		}
	}

	boolean ChangePassword()
	{
		System.out.println("������ԭ����: ");
		String pw = in.next();
		if(pw.equals(password))
		{
			System.out.println("������������: ");
			String pwa = in.next();
			System.out.println("���ٴ�����������: ");
			String pwb = in.next();
			if(pwa.length() == 6 && pwa.equals(pwb))
			{
				System.out.println("�����޸ĳɹ�!");
				return true;
			}
			else
			{
				System.out.println("�������!");
				return false;
			}
		}
		else
		{
			System.out.println("ԭ�������!");
			return false;
		}
	}

	void delock()
	{
		lock = false;
		System.out.println("�˻����ɹ�!");
	}

	void show()
	{
		System.out.println("\nCardNumber: " + cardnumber);
		System.out.println("\nPassword: " + password);
		System.out.println("\nBalance: " + balance);
	}
	private double balance;
	private String cardnumber;
	private String password;
	boolean lock = false;
	Scanner in = new Scanner(System.in);
}