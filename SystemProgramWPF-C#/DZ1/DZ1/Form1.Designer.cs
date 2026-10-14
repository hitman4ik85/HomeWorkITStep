namespace DZ1
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
            labelCoordMouse = new Label();
            SuspendLayout();
            // 
            // labelCoordMouse
            // 
            labelCoordMouse.AutoSize = true;
            labelCoordMouse.BackColor = SystemColors.ControlLightLight;
            labelCoordMouse.ForeColor = Color.OrangeRed;
            labelCoordMouse.Location = new Point(20, 20);
            labelCoordMouse.Name = "labelCoordMouse";
            labelCoordMouse.Size = new Size(209, 20);
            labelCoordMouse.TabIndex = 0;
            labelCoordMouse.Text = "Координати: X [0], Y [0]";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(labelCoordMouse);
            Name = "Form1";
            Text = "Координати миші"; //Назва форми
            MouseMove += Form1_MouseMove;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label labelCoordMouse;
    }
}