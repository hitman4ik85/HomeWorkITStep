namespace DZ7
{
    public partial class Form1 : Form
    {
        Color defaultColor;

        public Form1()
        {
            InitializeComponent();
            defaultColor = this.BackColor;
        }

        private void newWindowToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form1 newForm = new Form1();
            newForm.Show();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void changeBackgroundToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (ColorDialog colorDialog = new ColorDialog())
            {
                if (colorDialog.ShowDialog() == DialogResult.OK)
                {
                    this.BackColor = colorDialog.Color;
                }
            }
        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Ця програма демонструє меню, зміну фону, відкриття нових вікон та інформацію про програму.",
                "Про програму", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
    }
}
