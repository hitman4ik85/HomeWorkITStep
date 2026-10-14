namespace DZ3
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.TextBox textBoxLowerLimit;
        private System.Windows.Forms.TextBox textBoxUpperLimit;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.Button buttonStop;
        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.ListBox listBoxPrimes;
        private System.Windows.Forms.Label labelLowerLimit;
        private System.Windows.Forms.Label labelUpperLimit;

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
            buttonStart = new Button();
            buttonStop = new Button();
            buttonClear = new Button();
            listBoxPrimes = new ListBox();
            labelLowerLimit = new Label();
            labelUpperLimit = new Label();
            SuspendLayout();
            // 
            // textBoxLowerLimit
            // 
            textBoxLowerLimit.Location = new Point(20, 43);
            textBoxLowerLimit.Name = "textBoxLowerLimit";
            textBoxLowerLimit.Size = new Size(100, 27);
            textBoxLowerLimit.TabIndex = 0;
            // 
            // textBoxUpperLimit
            // 
            textBoxUpperLimit.Location = new Point(20, 107);
            textBoxUpperLimit.Name = "textBoxUpperLimit";
            textBoxUpperLimit.Size = new Size(100, 27);
            textBoxUpperLimit.TabIndex = 1;
            // 
            // buttonStart
            // 
            buttonStart.Location = new Point(20, 154);
            buttonStart.Name = "buttonStart";
            buttonStart.Size = new Size(100, 30);
            buttonStart.TabIndex = 2;
            buttonStart.Text = "Старт";
            buttonStart.UseVisualStyleBackColor = true;
            buttonStart.Click += buttonStart_Click;
            // 
            // buttonStop
            // 
            buttonStop.Location = new Point(20, 201);
            buttonStop.Name = "buttonStop";
            buttonStop.Size = new Size(100, 30);
            buttonStop.TabIndex = 3;
            buttonStop.Text = "Стоп";
            buttonStop.UseVisualStyleBackColor = true;
            buttonStop.Click += buttonStop_Click;
            // 
            // buttonClear
            // 
            buttonClear.Location = new Point(20, 266);
            buttonClear.Name = "buttonClear";
            buttonClear.Size = new Size(100, 30);
            buttonClear.TabIndex = 4;
            buttonClear.Text = "Очистити";
            buttonClear.UseVisualStyleBackColor = true;
            buttonClear.Click += buttonClear_Click;
            // 
            // listBoxPrimes
            // 
            listBoxPrimes.FormattingEnabled = true;
            listBoxPrimes.Location = new Point(153, 20);
            listBoxPrimes.Name = "listBoxPrimes";
            listBoxPrimes.Size = new Size(138, 384);
            listBoxPrimes.TabIndex = 5;
            // 
            // labelLowerLimit
            // 
            labelLowerLimit.AutoSize = true;
            labelLowerLimit.Location = new Point(20, 20);
            labelLowerLimit.Name = "labelLowerLimit";
            labelLowerLimit.Size = new Size(102, 20);
            labelLowerLimit.TabIndex = 6;
            labelLowerLimit.Text = "Нижня межа:";
            // 
            // labelUpperLimit
            // 
            labelUpperLimit.AutoSize = true;
            labelUpperLimit.Location = new Point(20, 84);
            labelUpperLimit.Name = "labelUpperLimit";
            labelUpperLimit.Size = new Size(104, 20);
            labelUpperLimit.TabIndex = 7;
            labelUpperLimit.Text = "Верхня межа:";
            // 
            // Form1
            // 
            ClientSize = new Size(317, 450);
            Controls.Add(textBoxLowerLimit);
            Controls.Add(textBoxUpperLimit);
            Controls.Add(buttonStart);
            Controls.Add(buttonStop);
            Controls.Add(buttonClear);
            Controls.Add(listBoxPrimes);
            Controls.Add(labelLowerLimit);
            Controls.Add(labelUpperLimit);
            Name = "Form1";
            Text = "Генератор чисел";
            ResumeLayout(false);
            PerformLayout();
        }
    }
}
