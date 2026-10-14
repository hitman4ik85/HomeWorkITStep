using System.Windows.Forms;

namespace DZ2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            richTextBox1.TextChanged += richTextBox1_TextChanged;
            toolTip1.SetToolTip(richTextBox1, "Введіть якийсь текст"); // Додаємо підказку для RichTextBox
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            int textLength = richTextBox1.Text.Length;
            progressBar1.Value = Math.Min(textLength, progressBar1.Maximum);
            labelProgress.Text = $"Довжина тексту: {textLength} символів";
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}