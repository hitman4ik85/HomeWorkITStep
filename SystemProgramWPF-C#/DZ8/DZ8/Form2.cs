using System.Globalization;

namespace DZ8
{
    public partial class Form2 : Form
    {
        public Product Product { get; private set; }

        public Form2()
        {
            InitializeComponent();
        }

        public Form2(Product product) : this()
        {
            textBoxName.Text = product.Name;
            textBoxCountry.Text = product.Country;
            textBoxPrice.Text = product.Price.ToString("F2", System.Globalization.CultureInfo.InvariantCulture);
        }

        public void SetStartPosition(Form owner)
        {
            // Встановлюємо позицію по центру відносно форми-основи
            StartPosition = FormStartPosition.Manual;
            Location = new Point(owner.Location.X + (owner.Width - Width) / 2,
                                 owner.Location.Y + (owner.Height - Height) / 2);
        }

        private void buttonOk_Click(object sender, EventArgs e)
        {
            string name = textBoxName.Text.Trim();
            string country = textBoxCountry.Text.Trim();
            string priceText = textBoxPrice.Text.Trim();

            if (string.IsNullOrWhiteSpace(name) || string.IsNullOrWhiteSpace(country) || string.IsNullOrWhiteSpace(priceText))
            {
                MessageBox.Show("Усі поля повинні бути заповнені.");
                return;
            }

            priceText = priceText.Replace(',', '.');

            if (!double.TryParse(priceText, System.Globalization.NumberStyles.Any, System.Globalization.CultureInfo.InvariantCulture, out double price))
            {
                MessageBox.Show("Введіть коректру ціну на товар.");
                return;
            }

            Product = new Product(name, country, price);
            DialogResult = DialogResult.OK;
        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
        }
    }
}