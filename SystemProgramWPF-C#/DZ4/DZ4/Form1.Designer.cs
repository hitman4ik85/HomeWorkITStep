using static System.Net.Mime.MediaTypeNames;
using System.Windows.Forms;
using System.Xml.Linq;

namespace DZ4
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.TextBox textBoxLowerLimit;
        private System.Windows.Forms.TextBox textBoxUpperLimit;
        private System.Windows.Forms.Button buttonStartPrime;
        private System.Windows.Forms.Button buttonStopPrime;
        private System.Windows.Forms.Button buttonStartFibonacci;
        private System.Windows.Forms.Button buttonStopFibonacci;
        private System.Windows.Forms.Button buttonClearPrimes;
        private System.Windows.Forms.Button buttonClearFibonacci;
        private System.Windows.Forms.ListBox listBoxPrimes;
        private System.Windows.Forms.ListBox listBoxFibonacci;
        private System.Windows.Forms.Label labelLowerLimit;
        private System.Windows.Forms.Label labelUpperLimit;
        private System.Windows.Forms.Label labelPrimes;
        private System.Windows.Forms.Label labelFibonacci;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            textBoxLowerLimit = new TextBox();
            textBoxUpperLimit = new TextBox();
            buttonStartPrime = new Button();
            buttonStopPrime = new Button();
            buttonStartFibonacci = new Button();
            buttonStopFibonacci = new Button();
            buttonClearPrimes = new Button();
            buttonClearFibonacci = new Button();
            listBoxPrimes = new ListBox();
            listBoxFibonacci = new ListBox();
            labelLowerLimit = new Label();
            labelUpperLimit = new Label();
            labelPrimes = new Label();
            labelFibonacci = new Label();
            SuspendLayout();
            // 
            // textBoxLowerLimit
            // 
            textBoxLowerLimit.Location = new Point(28, 89);
            textBoxLowerLimit.Name = "textBoxLowerLimit";
            textBoxLowerLimit.Size = new Size(100, 27);
            textBoxLowerLimit.TabIndex = 0;
            // 
            // textBoxUpperLimit
            // 
            textBoxUpperLimit.Location = new Point(28, 153);
            textBoxUpperLimit.Name = "textBoxUpperLimit";
            textBoxUpperLimit.Size = new Size(100, 27);
            textBoxUpperLimit.TabIndex = 1;
            // 
            // buttonStartPrime
            // 
            buttonStartPrime.BackColor = Color.Cyan;
            buttonStartPrime.Location = new Point(28, 200);
            buttonStartPrime.Name = "buttonStartPrime";
            buttonStartPrime.Size = new Size(100, 30);
            buttonStartPrime.TabIndex = 2;
            buttonStartPrime.Text = "Старт прості";
            buttonStartPrime.UseVisualStyleBackColor = false;
            buttonStartPrime.Click += buttonStartPrime_Click;
            // 
            // buttonStopPrime
            // 
            buttonStopPrime.BackColor = Color.LightSalmon;
            buttonStopPrime.Location = new Point(28, 247);
            buttonStopPrime.Name = "buttonStopPrime";
            buttonStopPrime.Size = new Size(100, 30);
            buttonStopPrime.TabIndex = 3;
            buttonStopPrime.Text = "Стоп";
            buttonStopPrime.UseVisualStyleBackColor = false;
            buttonStopPrime.Click += buttonStopPrime_Click;
            // 
            // buttonStartFibonacci
            // 
            buttonStartFibonacci.BackColor = Color.Cyan;
            buttonStartFibonacci.Location = new Point(305, 200);
            buttonStartFibonacci.Name = "buttonStartFibonacci";
            buttonStartFibonacci.Size = new Size(100, 30);
            buttonStartFibonacci.TabIndex = 5;
            buttonStartFibonacci.Text = "Старт Фібоначчі";
            buttonStartFibonacci.UseVisualStyleBackColor = false;
            buttonStartFibonacci.Click += buttonStartFibonacci_Click;
            // 
            // buttonStopFibonacci
            // 
            buttonStopFibonacci.BackColor = Color.LightSalmon;
            buttonStopFibonacci.Location = new Point(305, 247);
            buttonStopFibonacci.Name = "buttonStopFibonacci";
            buttonStopFibonacci.Size = new Size(100, 30);
            buttonStopFibonacci.TabIndex = 6;
            buttonStopFibonacci.Text = "Стоп Фібоначчі";
            buttonStopFibonacci.UseVisualStyleBackColor = false;
            buttonStopFibonacci.Click += buttonStopFibonacci_Click;
            // 
            // buttonClearPrimes
            // 
            buttonClearPrimes.BackColor = SystemColors.ControlLightLight;
            buttonClearPrimes.Location = new Point(28, 297);
            buttonClearPrimes.Name = "buttonClearPrimes";
            buttonClearPrimes.Size = new Size(100, 30);
            buttonClearPrimes.TabIndex = 4;
            buttonClearPrimes.Text = "Очистити прості";
            buttonClearPrimes.UseVisualStyleBackColor = false;
            buttonClearPrimes.Click += buttonClearPrimes_Click;
            // 
            // buttonClearFibonacci
            // 
            buttonClearFibonacci.BackColor = SystemColors.ControlLightLight;
            buttonClearFibonacci.Location = new Point(305, 297);
            buttonClearFibonacci.Name = "buttonClearFibonacci";
            buttonClearFibonacci.Size = new Size(100, 30);
            buttonClearFibonacci.TabIndex = 7;
            buttonClearFibonacci.Text = "Очистити Фібоначчі";
            buttonClearFibonacci.UseVisualStyleBackColor = false;
            buttonClearFibonacci.Click += buttonClearFibonacci_Click;
            // 
            // listBoxPrimes
            // 
            listBoxPrimes.FormattingEnabled = true;
            listBoxPrimes.Location = new Point(138, 63);
            listBoxPrimes.Name = "listBoxPrimes";
            listBoxPrimes.Size = new Size(141, 264);
            listBoxPrimes.TabIndex = 8;
            // 
            // listBoxFibonacci
            // 
            listBoxFibonacci.FormattingEnabled = true;
            listBoxFibonacci.Location = new Point(411, 63);
            listBoxFibonacci.Name = "listBoxFibonacci";
            listBoxFibonacci.Size = new Size(146, 264);
            listBoxFibonacci.TabIndex = 9;
            // 
            // labelLowerLimit
            // 
            labelLowerLimit.AutoSize = true;
            labelLowerLimit.Location = new Point(28, 66);
            labelLowerLimit.Name = "labelLowerLimit";
            labelLowerLimit.Size = new Size(102, 20);
            labelLowerLimit.TabIndex = 10;
            labelLowerLimit.Text = "Нижня межа:";
            // 
            // labelUpperLimit
            // 
            labelUpperLimit.AutoSize = true;
            labelUpperLimit.Location = new Point(28, 130);
            labelUpperLimit.Name = "labelUpperLimit";
            labelUpperLimit.Size = new Size(104, 20);
            labelUpperLimit.TabIndex = 11;
            labelUpperLimit.Text = "Верхня межа:";
            // 
            // labelPrimes
            // 
            labelPrimes.AutoSize = true;
            labelPrimes.BackColor = Color.LightGreen;
            labelPrimes.Location = new Point(70, 20);
            labelPrimes.Name = "labelPrimes";
            labelPrimes.Size = new Size(131, 20);
            labelPrimes.TabIndex = 12;
            labelPrimes.Text = "-=Прості числа=-";
            // 
            // labelFibonacci
            // 
            labelFibonacci.AutoSize = true;
            labelFibonacci.BackColor = Color.LightBlue;
            labelFibonacci.Location = new Point(352, 20);
            labelFibonacci.Name = "labelFibonacci";
            labelFibonacci.Size = new Size(157, 20);
            labelFibonacci.TabIndex = 13;
            labelFibonacci.Text = "-=Числа Фібоначчі=-";
            // 
            // Form1
            // 
            ClientSize = new Size(582, 363);
            Controls.Add(textBoxLowerLimit);
            Controls.Add(textBoxUpperLimit);
            Controls.Add(buttonStartPrime);
            Controls.Add(buttonStopPrime);
            Controls.Add(buttonClearPrimes);
            Controls.Add(buttonStartFibonacci);
            Controls.Add(buttonStopFibonacci);
            Controls.Add(buttonClearFibonacci);
            Controls.Add(listBoxPrimes);
            Controls.Add(listBoxFibonacci);
            Controls.Add(labelLowerLimit);
            Controls.Add(labelUpperLimit);
            Controls.Add(labelPrimes);
            Controls.Add(labelFibonacci);
            Name = "Form1";
            Text = "Генератор чисел";
            ResumeLayout(false);
            PerformLayout();
        }
    }
}
