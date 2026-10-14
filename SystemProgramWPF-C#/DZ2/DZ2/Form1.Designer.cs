namespace DZ2
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            richTextBox1 = new RichTextBox();
            progressBar1 = new ProgressBar();
            labelProgress = new Label();
            toolTip1 = new ToolTip(components);
            SuspendLayout();
            // 
            // richTextBox1
            // 
            richTextBox1.Location = new Point(30, 30);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(494, 150);
            richTextBox1.TabIndex = 0;
            richTextBox1.Text = "";
            toolTip1.SetToolTip(richTextBox1, "Введіть якийсь текст"); // Додаємо підказку для RichTextBox
            // 
            // progressBar1
            // 
            progressBar1.Location = new Point(30, 200);
            progressBar1.Name = "progressBar1";
            progressBar1.Size = new Size(494, 30);
            progressBar1.TabIndex = 1;
            // 
            // labelProgress
            // 
            labelProgress.AutoSize = true;
            labelProgress.Location = new Point(163, 233);
            labelProgress.Name = "labelProgress";
            labelProgress.Size = new Size(0, 20);
            labelProgress.TabIndex = 2;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(548, 300);
            Controls.Add(richTextBox1);
            Controls.Add(progressBar1);
            Controls.Add(labelProgress);
            Name = "Form1";
            Text = "Підрахунок літер/символів введеного тексту";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.Label labelProgress;
        private System.Windows.Forms.ToolTip toolTip1;
    }
}