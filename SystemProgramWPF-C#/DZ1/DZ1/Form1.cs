namespace DZ1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            labelCoordMouse.Text = $"Координати: X [{e.X}], Y [{e.Y}]";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

    }
}