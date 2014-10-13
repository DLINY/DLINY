package lab2;


	import java.awt.*;

	import java.awt.color.*;

	import java.awt.event.*;

	public class lab2 implements ActionListener

	{

	Frame f;

	Label lab1，lab2，lab3;

	TextField tf1， tf2，tf3;

	Button bt1，bt2;

	FrameDemo2()

	{

	f= new Frame();

	f.setTitle(this is my first Calcl!);

	f.setBackground(Color. cyan);

	f.setLocation(260，260);

	f.setSize(310，300);

	f.setLayout(new FlowLayout());

	lab1= new Label();

	lab1.setText( 加数1:);

	lab2= new Label();

	lab2.setText(加数2:);

	lab3= new Label();

	lab3.setText(结果 :);

	tf1= new TextField();

	tf1.setColumns( 30);

	tf2= new TextField();

	tf2.setColumns(30);

	tf3= new TextField();

	tf3.setColumns(30);

	bt1=new Button(运算);

	bt2=new Button(清零);

	f.add( lab1);

	f.add( tf1);

	f.add( lab2);

	f.add( tf2);

	f.add( lab3);

	f.add( tf3);

	f.add( bt1);

	f.add( bt2);

	bt1.addActionListener(this); //为按钮b1注册事件监听程序

	bt2.addActionListener(this);

	f.setVisible(true);

	}

	public void actionPerformed(ActionEvent e)

	{ //实现ActionListener接口中的方法，单击按钮时产生该事件

	if (e.getSource()==bt2) //获得产生事件的对象

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

	else //获取按钮标签，重新设置文本内容

	tf3.setText(tf3.getText()+e.getActionCommand());

	}

	public static void main(String args[])

	{

	FrameDemo2 myFrame = new FrameDemo2();

	}

	}

}
