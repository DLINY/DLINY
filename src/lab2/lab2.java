package lab2;


	import java.awt.*;

	import java.awt.color.*;

	import java.awt.event.*;

	public class lab2 implements ActionListener

	{

	Frame f;

	Label lab1��lab2��lab3;

	TextField tf1�� tf2��tf3;

	Button bt1��bt2;

	FrameDemo2()

	{

	f= new Frame();

	f.setTitle(this is my first Calcl!);

	f.setBackground(Color. cyan);

	f.setLocation(260��260);

	f.setSize(310��300);

	f.setLayout(new FlowLayout());

	lab1= new Label();

	lab1.setText( ����1:);

	lab2= new Label();

	lab2.setText(����2:);

	lab3= new Label();

	lab3.setText(��� :);

	tf1= new TextField();

	tf1.setColumns( 30);

	tf2= new TextField();

	tf2.setColumns(30);

	tf3= new TextField();

	tf3.setColumns(30);

	bt1=new Button(����);

	bt2=new Button(����);

	f.add( lab1);

	f.add( tf1);

	f.add( lab2);

	f.add( tf2);

	f.add( lab3);

	f.add( tf3);

	f.add( bt1);

	f.add( bt2);

	bt1.addActionListener(this); //Ϊ��ťb1ע���¼���������

	bt2.addActionListener(this);

	f.setVisible(true);

	}

	public void actionPerformed(ActionEvent e)

	{ //ʵ��ActionListener�ӿ��еķ�����������ťʱ�������¼�

	if (e.getSource()==bt2) //��ò����¼��Ķ���

	{ tf1.setText();

	tf2.setText();

	tf3.setText();

	}

	else

	if(e.getSource()==bt1)

	{

	String add1 = tf1.getText();

	String add2 = tf2.getText();

	int temp = (int)Integer.parseInt(add1)+(int)Integer.parseInt(add2);

	tf3.setText(+temp);

	}

	else //��ȡ��ť��ǩ�����������ı�����

	tf3.setText(tf3.getText()+e.getActionCommand());

	}

	public static void main(String args[])

	{

	FrameDemo2 myFrame = new FrameDemo2();

	}

	}

}
