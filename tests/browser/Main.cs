using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;

namespace xuldotnet
{
	/// <summary>
	/// Summary description for Form1.
	/// </summary>
	public partial class Form1 : System.Windows.Forms.Form
	{
		TextBox text;
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main ()
		{
			Application.EnableVisualStyles ();
			Application.SetCompatibleTextRenderingDefault (false);
			Application.Run (new Form1 ()); 
		}

		public Form1 ()
		{
			InitializeComponent ();
			text = new TextBox ();
		}

		private void button1_Click (object sender, EventArgs e)
		{
			webBrowser1.Navigate (textBox1.Text);
			webBrowser2.Navigate (textBox1.Text);
		}
	}
}
