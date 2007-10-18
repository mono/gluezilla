using System;
using System.Collections.Generic;
using System.Text;

namespace xuldotnet
{
	public partial class Form1 : System.Windows.Forms.Form
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose (bool disposing)
		{
			if (disposing && (components != null)) {
				components.Dispose ();
			}
			base.Dispose (disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent ()
		{
			this.button1 = new System.Windows.Forms.Button ();
			this.textBox1 = new System.Windows.Forms.TextBox ();
			this.panel1 = new System.Windows.Forms.Panel ();
			this.panel2 = new System.Windows.Forms.Panel ();
			this.splitter1 = new System.Windows.Forms.Splitter ();
			this.panel3 = new System.Windows.Forms.Panel ();
			//this.webBrowser1 = new Mono.Tests.WebBrowser ();
			this.webBrowser1 = new System.Windows.Forms.WebBrowser ();
			//this.webBrowser2 = new Mono.Tests.WebBrowser ();
			this.webBrowser2 = new System.Windows.Forms.WebBrowser ();
			this.panel1.SuspendLayout ();
			this.panel2.SuspendLayout ();
			this.panel3.SuspendLayout ();
			this.SuspendLayout ();
			// 
			// button1
			// 
			this.button1.Anchor = ((System.Windows.Forms.AnchorStyles) ((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.button1.Location = new System.Drawing.Point (342, 3);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size (73, 23);
			this.button1.TabIndex = 1;
			this.button1.Text = "Go";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler (this.button1_Click);
			// 
			// textBox1
			// 
			this.textBox1.Anchor = ((System.Windows.Forms.AnchorStyles) (((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left)
						| System.Windows.Forms.AnchorStyles.Right)));
			this.textBox1.Location = new System.Drawing.Point (3, 3);
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new System.Drawing.Size (333, 20);
			this.textBox1.TabIndex = 0;
			this.textBox1.Text = "about:blank";
			// 
			// panel1
			// 
			this.panel1.Controls.Add (this.button1);
			this.panel1.Controls.Add (this.textBox1);
			this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
			this.panel1.Location = new System.Drawing.Point (0, 0);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size (418, 29);
			this.panel1.TabIndex = 3;
			// 
			// panel2
			// 
			this.panel2.Controls.Add (this.webBrowser1);
			this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
			this.panel2.Location = new System.Drawing.Point (0, 29);
			this.panel2.Name = "panel2";
			this.panel2.Size = new System.Drawing.Size (418, 252);
			this.panel2.TabIndex = 4;
			// 
			// splitter1
			// 
			this.splitter1.Dock = System.Windows.Forms.DockStyle.Top;
			this.splitter1.Location = new System.Drawing.Point (0, 281);
			this.splitter1.Name = "splitter1";
			this.splitter1.Size = new System.Drawing.Size (418, 3);
			this.splitter1.TabIndex = 5;
			this.splitter1.TabStop = false;
			// 
			// panel3
			// 
			this.panel3.Controls.Add (this.webBrowser2);
			this.panel3.Dock = System.Windows.Forms.DockStyle.Fill;
			this.panel3.Location = new System.Drawing.Point (0, 284);
			this.panel3.Name = "panel3";
			this.panel3.Size = new System.Drawing.Size (418, 283);
			this.panel3.TabIndex = 6;
			// 
			// webBrowser1
			// 
			this.webBrowser1.Dock = System.Windows.Forms.DockStyle.Fill;
			this.webBrowser1.Location = new System.Drawing.Point (0, 0);
			this.webBrowser1.MinimumSize = new System.Drawing.Size (20, 20);
			this.webBrowser1.Name = "webBrowser1";
			this.webBrowser1.Size = new System.Drawing.Size (418, 252);
			this.webBrowser1.TabIndex = 2;
			// 
			// webBrowser2
			// 
			this.webBrowser2.Dock = System.Windows.Forms.DockStyle.Fill;
			this.webBrowser2.Location = new System.Drawing.Point (0, 0);
			this.webBrowser2.MinimumSize = new System.Drawing.Size (20, 20);
			this.webBrowser2.Name = "webBrowser2";
			this.webBrowser2.Size = new System.Drawing.Size (418, 283);
			this.webBrowser2.TabIndex = 0;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF (6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size (418, 567);
			this.Controls.Add (this.panel3);
			this.Controls.Add (this.splitter1);
			this.Controls.Add (this.panel2);
			this.Controls.Add (this.panel1);
			this.Name = "Form1";
			this.Text = "Form1";
			this.panel1.ResumeLayout (false);
			this.panel1.PerformLayout ();
			this.panel2.ResumeLayout (false);
			this.panel3.ResumeLayout (false);
			this.ResumeLayout (false);

		}

		#endregion

		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.TextBox textBox1;
		private System.Windows.Forms.Panel panel1;
		private System.Windows.Forms.Panel panel2;
		private System.Windows.Forms.Splitter splitter1;
		private System.Windows.Forms.Panel panel3;
		//private Mono.Tests.WebBrowser webBrowser1;
		private System.Windows.Forms.WebBrowser webBrowser1;
		//private Mono.Tests.WebBrowser webBrowser2;
		private System.Windows.Forms.WebBrowser webBrowser2;

	}
}
